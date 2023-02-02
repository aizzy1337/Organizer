#pragma once
//FORM - MODU£ KALENDARZA

#include "pch.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#include <string>
#include <locale>
#include <codecvt>

public ref class moduleCalendar : public System::Windows::Forms::FlowLayoutPanel {

public:

	moduleCalendar(void)
	{
		InitializeComponent();
	}

protected:

	~moduleCalendar()
	{
		if (components)
		{
			delete components;
		}
	}

	//DEKLARACJA OBIEKTÓW
private:
	
	int getNumberOfDays(int month, int year)
	{
		//luty
		if (month == 2)
		{
			if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
				return 29;
			else
				return 28;
		}
		//miesiace z 31 dniami
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12)
			return 31;
		//miesiace z 30 dniami
		else
			return 30;
	};

	String^ getNameOfMonth(int month) {
		switch (month) {
		case 1: return "Styczeñ"; break;
		case 2: return "Luty"; break;
		case 3: return "Marzec"; break;
		case 4: return "Kwiecieñ"; break;
		case 5: return "Maj"; break;
		case 6: return "Czerwiec"; break;
		case 7: return "Lipiec"; break;
		case 8: return "Sierpieñ"; break;
		case 9: return "Wrzesieñ"; break;
		case 10: return "PaŸdziernik"; break;
		case 11: return "Listopad"; break;
		case 12: return "Grudzieñ"; break;
		default: return "";  break;
		}
	};

	System::Windows::Forms::FlowLayoutPanel^ calendarPicker;
	System::Windows::Forms::FlowLayoutPanel^ calendarPicked;
	System::Windows::Forms::FlowLayoutPanel^ modifyEventPanel;
	System::Windows::Forms::FlowLayoutPanel^ addEventPanel;
	System::ComponentModel::Container^ components;

	DateTime todayDate = System::DateTime::Now;

	int activeDays;
	int activeMonth;
	int activeYear;
	int activeDay;
	int activeEvent = -1;

	void InitializeComponent(void)
	{

		//inicjalizacja

		this->calendarPicker = (gcnew System::Windows::Forms::FlowLayoutPanel());
		this->calendarPicked = (gcnew System::Windows::Forms::FlowLayoutPanel());

		this->activeDays = getNumberOfDays(todayDate.Month, todayDate.Year);
		this->activeMonth = todayDate.Month;
		this->activeYear = todayDate.Year;
		this->activeDay = todayDate.Day;
		this->activeEvent = -1;

		this->calendarPicker->SuspendLayout();
		this->calendarPicked->SuspendLayout();
		this->SuspendLayout();

		// mainScreenCalendar

		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
		this->Location = System::Drawing::Point(300, 0);
		this->Name = L"mainScreenCalendar";
		this->Size = System::Drawing::Size(980, 720);
		this->TabIndex = 0;
		this->Visible = false;

		// calendarPicker
		// 
		this->calendarPicker->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->calendarPicker->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->calendarPicker->Location = System::Drawing::Point(300, 0);
		this->calendarPicker->Name = L"calendarPicker";
		this->calendarPicker->Size = System::Drawing::Size(600, 720);
		this->calendarPicker->TabIndex = 1;
		this->calendarPicker->Visible = false;

		// calendarPicked
		// 
		this->calendarPicked->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->calendarPicked->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->calendarPicked->Location = System::Drawing::Point(900, 0);
		this->calendarPicked->Name = L"calendarPicked";
		this->calendarPicked->Size = System::Drawing::Size(368, 720);
		this->calendarPicked->TabIndex = 2;
		this->calendarPicked->Visible = false;

		this->Controls->Add(this->calendarPicker);
		this->Controls->Add(this->calendarPicked);

		//Modify
		modifyEventPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());

		this->modifyEventPanel->SuspendLayout();

		modifyEventPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		modifyEventPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		modifyEventPanel->Location = System::Drawing::Point(900, 0);
		modifyEventPanel->Name = L"modifyEventPanel";
		modifyEventPanel->Size = System::Drawing::Size(368, 720);
		modifyEventPanel->TabIndex = 0;
		modifyEventPanel->Visible = true;

		this->Controls->Add(modifyEventPanel);

		System::Windows::Forms::Label^ labelEventName = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ eventName = (gcnew System::Windows::Forms::TextBox());
		System::Windows::Forms::Label^ labelHourStart = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ hourStart = (gcnew System::Windows::Forms::TextBox());
		System::Windows::Forms::Label^ labelHourFinish = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ hourFinish = (gcnew System::Windows::Forms::TextBox());
		System::Windows::Forms::CheckBox^ notification = (gcnew System::Windows::Forms::CheckBox());

		labelEventName->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelEventName->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelEventName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelEventName->Size = System::Drawing::Size(368, 50);
		labelEventName->Text = L"Podaj nazwê wydarzenia";

		eventName->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		eventName->Name = L"eventName2";
		eventName->Size = System::Drawing::Size(368, 100);
		eventName->TabIndex = 0;

		labelHourStart->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelHourStart->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelHourStart->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelHourStart->Size = System::Drawing::Size(368, 50);
		labelHourStart->Text = L"Podaj godzinê rozpoczêcia";

		hourStart->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		hourStart->Name = L"hourStart2";
		hourStart->Size = System::Drawing::Size(368, 100);
		hourStart->TabIndex = 0;

		labelHourFinish->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelHourFinish->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelHourFinish->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelHourFinish->Size = System::Drawing::Size(368, 50);
		labelHourFinish->Text = L"Podaj godzinê zakoñczenia";

		hourFinish->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		hourFinish->Name = L"hourFinish2";
		hourFinish->Size = System::Drawing::Size(368, 100);
		hourFinish->TabIndex = 0;

		notification->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		notification->ForeColor = System::Drawing::SystemColors::HighlightText;
		notification->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		notification->Size = System::Drawing::Size(368, 100);
		notification->Name = L"notification2";
		notification->Text = L"Czy chcesz otrzymaæ powiadomienie?";

		modifyEventPanel->Controls->Add(labelEventName);
		modifyEventPanel->Controls->Add(eventName);
		modifyEventPanel->Controls->Add(labelHourStart);
		modifyEventPanel->Controls->Add(hourStart);
		modifyEventPanel->Controls->Add(labelHourFinish);
		modifyEventPanel->Controls->Add(hourFinish);
		modifyEventPanel->Controls->Add(notification);

		System::Windows::Forms::Button^ modifyEventButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ addEventButtonBack = gcnew System::Windows::Forms::Button();

		modifyEventButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		modifyEventButton->Name = L"modifyEventButton";
		modifyEventButton->Size = System::Drawing::Size(368, 100);
		modifyEventButton->Text = L"Edytuj";
		modifyEventButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyEventButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyEventButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyEventButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyEventButton->Click += gcnew System::EventHandler(this, &moduleCalendar::checkInputModify);

		addEventButtonBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addEventButtonBack->Name = L"addEventButtonBack2";
		addEventButtonBack->Size = System::Drawing::Size(368, 100);
		addEventButtonBack->Text = L"Powrót";
		addEventButtonBack->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addEventButtonBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addEventButtonBack->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addEventButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addEventButtonBack->Click += gcnew System::EventHandler(this, &moduleCalendar::modifyEventButtonBack_Click);

		modifyEventPanel->Controls->Add(modifyEventButton);
		modifyEventPanel->Controls->Add(addEventButtonBack);

		modifyEventPanel->Visible = false;

		//Add
		addEventPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());

		this->addEventPanel->SuspendLayout();

		addEventPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		addEventPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		addEventPanel->Location = System::Drawing::Point(900, 0);
		addEventPanel->Name = L"addEventPanel";
		addEventPanel->Size = System::Drawing::Size(368, 720);
		addEventPanel->TabIndex = 3;
		addEventPanel->Visible = true;

		this->Controls->Add(addEventPanel);

		System::Windows::Forms::RadioButton^ everyWeek = (gcnew System::Windows::Forms::RadioButton());
		System::Windows::Forms::RadioButton^ everyMonth = (gcnew System::Windows::Forms::RadioButton());

		labelEventName = (gcnew System::Windows::Forms::Label());
		eventName = (gcnew System::Windows::Forms::TextBox());
		labelHourStart = (gcnew System::Windows::Forms::Label());
		hourStart = (gcnew System::Windows::Forms::TextBox());
		labelHourFinish = (gcnew System::Windows::Forms::Label());
		hourFinish = (gcnew System::Windows::Forms::TextBox());
		notification = (gcnew System::Windows::Forms::CheckBox());

		labelEventName->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelEventName->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelEventName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelEventName->Size = System::Drawing::Size(368, 50);
		labelEventName->Text = L"Podaj nazwê wydarzenia";

		eventName->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		eventName->Name = L"eventName";
		eventName->Size = System::Drawing::Size(368, 100);
		eventName->TabIndex = 0;

		labelHourStart->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelHourStart->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelHourStart->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelHourStart->Size = System::Drawing::Size(368, 50);
		labelHourStart->Text = L"Podaj godzinê rozpoczêcia";

		hourStart->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		hourStart->Name = L"hourStart";
		hourStart->Size = System::Drawing::Size(368, 100);
		hourStart->TabIndex = 0;

		labelHourFinish->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelHourFinish->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelHourFinish->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelHourFinish->Size = System::Drawing::Size(368, 50);
		labelHourFinish->Text = L"Podaj godzinê zakoñczenia";

		hourFinish->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		hourFinish->Name = L"hourFinish";
		hourFinish->Size = System::Drawing::Size(368, 100);
		hourFinish->TabIndex = 0;

		notification->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		notification->ForeColor = System::Drawing::SystemColors::HighlightText;
		notification->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		notification->Size = System::Drawing::Size(368, 100);
		notification->Name = L"notification";
		notification->Text = L"Czy chcesz otrzymaæ powiadomienie?";

		everyWeek->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		everyWeek->ForeColor = System::Drawing::SystemColors::HighlightText;
		everyWeek->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		everyWeek->Size = System::Drawing::Size(368, 100);
		everyWeek->Name = L"everyWeek";
		everyWeek->Text = L"Powtarzaæ co tydzieñ?";

		everyMonth->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		everyMonth->ForeColor = System::Drawing::SystemColors::HighlightText;
		everyMonth->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		everyMonth->Size = System::Drawing::Size(368, 100);
		everyMonth->Name = L"everyMonth";
		everyMonth->Text = L"Powtarzaæ co miesi¹c?";

		addEventPanel->Controls->Add(labelEventName);
		addEventPanel->Controls->Add(eventName);
		addEventPanel->Controls->Add(labelHourStart);
		addEventPanel->Controls->Add(hourStart);
		addEventPanel->Controls->Add(labelHourFinish);
		addEventPanel->Controls->Add(hourFinish);
		addEventPanel->Controls->Add(notification);
		addEventPanel->Controls->Add(everyWeek);
		addEventPanel->Controls->Add(everyMonth);

		System::Windows::Forms::Button^ addEventButton = gcnew System::Windows::Forms::Button();
		addEventButtonBack = gcnew System::Windows::Forms::Button();

		addEventButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addEventButton->Name = L"addEventButton";
		addEventButton->Size = System::Drawing::Size(368, 100);
		addEventButton->Text = L"Dodaj";
		addEventButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addEventButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addEventButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addEventButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addEventButton->Click += gcnew System::EventHandler(this, &moduleCalendar::checkInputAdd);

		addEventButtonBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addEventButtonBack->Name = L"addEventButtonBack";
		addEventButtonBack->Size = System::Drawing::Size(368, 100);
		addEventButtonBack->Text = L"Powrót";
		addEventButtonBack->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addEventButtonBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addEventButtonBack->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addEventButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addEventButtonBack->Click += gcnew System::EventHandler(this, &moduleCalendar::addEventButtonBack_Click);

		addEventPanel->Controls->Add(addEventButton);
		addEventPanel->Controls->Add(addEventButtonBack);

		addEventPanel->Visible = false;

		this->calendarPicker->ResumeLayout(false);
		this->calendarPicked->ResumeLayout(false);
		this->modifyEventPanel->ResumeLayout(false);
		this->addEventPanel->ResumeLayout(false);
		this->ResumeLayout(false);

	}

public:

	void moduleLoad() {

		calendarPicked->Visible = true;
		calendarPicker->Visible = true;
		this->Visible = true;

		calendarPickerLoad();
		calendarPickedLoad();

	}

	void moduleUnload() {

		calendarPicked->Visible = false;
		calendarPicker->Visible = false;
		this->Visible = false;

	}

	void calendarPickerLoad() {

		calendarPicker->Controls->Clear();

		int year = todayDate.Year;
		int month = todayDate.Month;
		int day = todayDate.Day;

		//DZISIEJSZA DATA

		std::string dateShow = "Dzisiaj jest: " + std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);

		System::Windows::Forms::Label^ todaysDate = gcnew System::Windows::Forms::Label();

		todaysDate->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		todaysDate->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		todaysDate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		todaysDate->Size = System::Drawing::Size(600, 150);
		todaysDate->Text = msclr::interop::marshal_as<String^>(dateShow);

		calendarPicker->Controls->Add(todaysDate);

		// INICJALIZACJA OBSZARU Z PRZYCISKAMI

		System::Windows::Forms::FlowLayoutPanel^ up = gcnew System::Windows::Forms::FlowLayoutPanel();
		System::Windows::Forms::FlowLayoutPanel^ down = gcnew System::Windows::Forms::FlowLayoutPanel();

		// GÓRNA CZÊŒÆ

		up->Controls->Clear();

			//POLE Z PRZECISKAMI DO WYBORU DATY
		up->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		up->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
		up->Location = System::Drawing::Point(300, 0);
		up->Name = L"upperCalendarPicker";
		up->Size = System::Drawing::Size(600, 100);
		up->TabIndex = 0;
		up->Visible = true;

		calendarPicker->Controls->Add(up);

			//PRZYCISKI
		System::Windows::Forms::Button^ previousMonth = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ nextMonth = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Label^ currentMonth = gcnew System::Windows::Forms::Label();
		System::Windows::Forms::Label^ currentYear = gcnew System::Windows::Forms::Label();

		previousMonth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		previousMonth->Name = L"previousMonth";
		previousMonth->Size = System::Drawing::Size(100, 50);
		previousMonth->Text = L"<";
		previousMonth->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		previousMonth->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		previousMonth->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		previousMonth->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		previousMonth->Click += gcnew System::EventHandler(this, &moduleCalendar::buttonPreviousMonth_Click);

		nextMonth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		nextMonth->Name = L"previousMonth";
		nextMonth->Size = System::Drawing::Size(100, 50);
		nextMonth->Text = L">";
		nextMonth->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		nextMonth->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		nextMonth->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		nextMonth->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		nextMonth->Click += gcnew System::EventHandler(this, &moduleCalendar::buttonNextMonth_Click);

		currentMonth->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		currentMonth->ForeColor = System::Drawing::SystemColors::HighlightText;
		currentMonth->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		currentMonth->Size = System::Drawing::Size(185, 50);
		currentMonth->Text = getNameOfMonth(activeMonth);

		currentYear->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		currentYear->ForeColor = System::Drawing::SystemColors::HighlightText;
		currentYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		currentYear->Size = System::Drawing::Size(185, 50);
		currentYear->Text = activeYear.ToString();

		up->Controls->Add(previousMonth);
		up->Controls->Add(currentMonth);
		up->Controls->Add(currentYear);
		up->Controls->Add(nextMonth);

		//DOLNA CZÊŒÆ

		down->Controls->Clear();

			//POLE PRZYCISKOW
		down->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		down->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
		down->Location = System::Drawing::Point(300, 200);
		down->Name = L"downCalendarPicker";
		down->Size = System::Drawing::Size(600, 450);
		down->TabIndex = 1;
		down->Visible = true;

		calendarPicker->Controls->Add(down);

			//PRZYCISKI
		System::Windows::Forms::Button^ b;

		for (int i = 1; i <= activeDays; i++)
		{
			b = gcnew System::Windows::Forms::Button();

			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			std::string date = std::to_string(i) + std::to_string(activeMonth) + std::to_string(activeYear);
			b->Name = msclr::interop::marshal_as<String^>(date);
			b->Size = System::Drawing::Size(77, 77);
			b->Text = i.ToString();
			b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			b->Click += gcnew System::EventHandler(this, &moduleCalendar::buttonActiveDay_Click);

			down->Controls->Add(b);
		}

	}

	void calendarPickedLoad() {

		calendarPicked->Controls->Clear();

		databaseSelect.selectDataCalednar();

		System::Windows::Forms::Label^ pickedDate = gcnew System::Windows::Forms::Label();

		std::string dateShow = std::to_string(activeDay) + "." + std::to_string(activeMonth) + "." + std::to_string(activeYear);
		std::string date = std::to_string(activeDay) + std::to_string(activeMonth) + std::to_string(activeYear);

		pickedDate->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		pickedDate->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		pickedDate->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		pickedDate->Size = System::Drawing::Size(368, 70);
		pickedDate->Text = msclr::interop::marshal_as<String^>(dateShow);

		this->calendarPicked->Controls->Add(pickedDate);

		if (databaseSelect.dataCalendar.id.size() != NULL) {
		
			bool flag = 0;

			for (size_t i = 0; i < databaseSelect.dataCalendar.id.size(); i++)
			{
				if (databaseSelect.dataCalendar.date_col[i] == date) {

					System::Windows::Forms::Button^ data = gcnew System::Windows::Forms::Button();

					data->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
						static_cast<System::Int32>(static_cast<System::Byte>(100)));
					data->Name = databaseSelect.dataCalendar.id[i].ToString();
					data->Size = System::Drawing::Size(368, 30);
					std::string text = databaseSelect.dataCalendar.hourS_col[i] + "-" + databaseSelect.dataCalendar.hourF_col[i] + " " + databaseSelect.dataCalendar.event[i];
					data->Text = msclr::interop::marshal_as<String^>(text);
					data->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					data->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
					data->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
					data->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
					data->Click += gcnew System::EventHandler(this, &moduleCalendar::buttonActiveEvent_Click);
					
					this->calendarPicked->Controls->Add(data);

					flag = 1;

				}
			}

			if (!flag) {

				System::Windows::Forms::Label^ noData = gcnew System::Windows::Forms::Label();

				noData->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				noData->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				noData->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				noData->Size = System::Drawing::Size(368, 350);
				noData->Text = L"Brak wydarzeñ!";

				this->calendarPicked->Controls->Add(noData);

			}

		}
		else {

			System::Windows::Forms::Label^ noData = gcnew System::Windows::Forms::Label();

			noData->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			noData->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			noData->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			noData->Size = System::Drawing::Size(368, 350);
			noData->Text = L"Brak wydarzeñ!";

			this->calendarPicked->Controls->Add(noData);

		}

		System::Windows::Forms::Button^ addButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ deleteButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ modifyButton = gcnew System::Windows::Forms::Button();

		addButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		addButton->Name = L"addButton";
		addButton->Size = System::Drawing::Size(368, 33);
		addButton->Text = L"Dodaj wydarzenie";
		addButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addButton->Click += gcnew System::EventHandler(this, &moduleCalendar::buttonAdd_Click);
		addButton->Location = System::Drawing::Point(900, 620);

		deleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		deleteButton->Name = L"deleteButton";
		deleteButton->Size = System::Drawing::Size(368, 33);
		deleteButton->Text = L"Usuñ wydarzenie";
		deleteButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		deleteButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		deleteButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		deleteButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		deleteButton->Location = System::Drawing::Point(900, 653);
		deleteButton->Click += gcnew System::EventHandler(this, &moduleCalendar::buttonDelete_Click);


		modifyButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		modifyButton->Name = L"modifyButton";
		modifyButton->Size = System::Drawing::Size(368, 33);
		modifyButton->Text = L"Edytuj wydarzenie";
		modifyButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyButton->Location = System::Drawing::Point(900, 686);
		modifyButton->Click += gcnew System::EventHandler(this, &moduleCalendar::buttonModify_Click);

		this->calendarPicked->Controls->Add(addButton);
		this->calendarPicked->Controls->Add(deleteButton);
		this->calendarPicked->Controls->Add(modifyButton);

	}

	void buttonPreviousMonth_Click(System::Object^ sender, System::EventArgs^ e) {

		activeMonth--;
		if (activeMonth == 0) {
			activeMonth = 12;
			activeYear--;
		}
		activeDays = getNumberOfDays(activeMonth, activeYear);
		calendarPickerLoad();

	}

	void buttonNextMonth_Click(System::Object^ sender, System::EventArgs^ e) {

		activeMonth++;
		if (activeMonth == 13) {
			activeMonth = 1;
			activeYear++;
		}
		activeDays = getNumberOfDays(activeMonth, activeYear);
		calendarPickerLoad();

	}

	void buttonActiveDay_Click(System::Object^ sender, System::EventArgs^ e) {

		Button^ clicked = (Button^)sender;
		activeDay = Int32::Parse(clicked->Text);
		activeEvent = -1;

		calendarPickedLoad();

	}

	void buttonActiveEvent_Click(System::Object^ sender, System::EventArgs^ e) {
	
		Button^ clicked = (Button^)sender;
		activeEvent = Int32::Parse(clicked->Name);
		std::cout << activeEvent;
		calendarPickedLoad();

	}

	void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e) {

		calendarPicked->Visible = false;
		addEventPanel->Visible = true;
		calendarPickedLoad();

	}

	void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {

		if (activeEvent != -1) {
			databaseDelete.deleteData(activeEvent, L"calendar");
			activeEvent = -1;
		}
		else {
			MessageBox::Show("Nale¿y wybraæ wydarzenie!");
		}

		calendarPickedLoad();

	}

	void buttonModify_Click(System::Object^ sender, System::EventArgs^ e) {

		if (activeEvent != -1) {

			calendarPicked->Visible = false;
			modifyEventPanel->Visible = true;
			calendarPickedLoad();

		}
		else {
			MessageBox::Show("Nale¿y wybraæ wydarzenie!");
		}
	}

	void checkInputAdd(System::Object^ sender, System::EventArgs^ e) {

		int flag = 0;
		int flag2 = 0;
		std::string date = std::to_string(activeDay) + std::to_string(activeMonth) + std::to_string(activeYear);

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"addEventPanel", true)[0];

		System::Windows::Forms::TextBox^ eventName = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"eventName", true)[0];
		System::Windows::Forms::TextBox^ hourStart = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"hourStart", true)[0];
		System::Windows::Forms::TextBox^ hourFinish = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"hourFinish", true)[0];
		System::Windows::Forms::CheckBox^ notification = (System::Windows::Forms::CheckBox^)layout->Controls->Find(L"notification", true)[0];
		System::Windows::Forms::RadioButton^ everyWeek = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"everyWeek", true)[0];
		System::Windows::Forms::RadioButton^ everyMonth = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"everyMonth", true)[0];

		int number1 = 0;
		int number2 = 0;

		if (!int::TryParse(hourStart->Text, number1)) {
			MessageBox::Show("Nale¿y wpisaæ liczbê!");
		}
		else {
			flag++;
		}

		if (!int::TryParse(hourFinish->Text, number1)) {
			MessageBox::Show("Nale¿y wpisaæ liczbê!");
		}
		else {
			flag++;
		}

		if (flag == 2) {

			int::TryParse(hourStart->Text, number1);
			int::TryParse(hourFinish->Text, number2);

			if (number1 > 24 || number1 < 0) {
				MessageBox::Show("Nale¿y wpisaæ liczbê z przedzia³u 0-24!");
			}
			else {
				flag++;
			}

			if (number2 > 24 || number2 < 0) {
				MessageBox::Show("Nale¿y wpisaæ liczbê z przedzia³u 0-24!");
			}
			else {
				flag++;
			}

			if (number2 <= number1) {
				MessageBox::Show("Godzina zakonczenia powinna byæ wiêksza od godziny rozpoczêcia!");
			}
			else {
				flag++;
			}

			databaseSelect.selectDataCalednar();

			for (size_t i = 0; i < databaseSelect.dataCalendar.id.size(); i++)
			{
				if (databaseSelect.dataCalendar.date_col[i] == date) {

					if (!(databaseSelect.dataCalendar.id[i] == activeEvent)) {

						int number3 = std::stoi(databaseSelect.dataCalendar.hourS_col[i]);
						int number4 = std::stoi(databaseSelect.dataCalendar.hourF_col[i]);

						if (number1 > number3) {

							if (number1 < number4) {
								MessageBox::Show("Inne wydarzenie jest w tych godzinach!	1");
								flag2++;
							}

						}
						if (number4 > number2) {

							if (number2 > number3) {
								MessageBox::Show("Inne wydarzenie jest w tych godzinach!	2");
								flag2++;
							}

						}
						if (number3 == number1 && number4 == number2) {

							MessageBox::Show("Inne wydarzenie jest w tych godzinach!	3");
							flag2++;

						}
						if (number3 > number1 && number4 < number2) {

							MessageBox::Show("Inne wydarzenie jest w tych godzinach!	4");
							flag2++;

						}
						if (number3 < number1 && number4 > number2) {

							MessageBox::Show("Inne wydarzenie jest w tych godzinach!	5");
							flag2++;

						}
					}
				}
			}

		}

		if (!flag2) { flag++; }

		if (flag == 6) {
			int m = activeMonth;
			int y = activeYear;
			int d = activeDay;
			if (everyMonth->Checked) {
				for (size_t i = 0; i < 13; i++)
				{
					if (m == 13) { m = 1;  y++; }
					std::string dt = std::to_string(d) + std::to_string(m) + std::to_string(y);
					std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
					databaseInsert.insertData(
						converter.from_bytes(dt),
						std::to_wstring(number1),
						std::to_wstring(number2),
						msclr::interop::marshal_as<std::wstring>(eventName->Text),
						notification->Checked
					);
					m++;
				}
			}
			else if (everyWeek->Checked) {
				for (size_t i = 0; i < 49; i++)
				{
					if (d >= getNumberOfDays(m, y)) { d -= getNumberOfDays(m, y); m++; }
					if (m == 13) { m = 1;  y++; }
					std::string dt = std::to_string(d) + std::to_string(m) + std::to_string(y);
					std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
					databaseInsert.insertData(
						converter.from_bytes(dt),
						std::to_wstring(number1),
						std::to_wstring(number2),
						msclr::interop::marshal_as<std::wstring>(eventName->Text),
						notification->Checked
					);
					d += 7;
				}
			}
			else {
				std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
				databaseInsert.insertData(
					converter.from_bytes(date),
					std::to_wstring(number1),
					std::to_wstring(number2),
					msclr::interop::marshal_as<std::wstring>(eventName->Text),
					notification->Checked
				);
			}
		}

		layout->Visible = false;

		moduleLoad();

	}

	void checkInputModify(System::Object^ sender, System::EventArgs^ e) {

		int flag = 0;
		int flag2 = 0;
		std::string date = std::to_string(activeDay) + std::to_string(activeMonth) + std::to_string(activeYear);

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"modifyEventPanel", true)[0];

		System::Windows::Forms::TextBox^ eventName = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"eventName2", true)[0];
		System::Windows::Forms::TextBox^ hourStart = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"hourStart2", true)[0];
		System::Windows::Forms::TextBox^ hourFinish = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"hourFinish2", true)[0];
		System::Windows::Forms::RadioButton^ notification = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"notification2", true)[0];

		int number1 = 0;
		int number2 = 0;

		if (!int::TryParse(hourStart->Text, number1)) {
			MessageBox::Show("Nale¿y wpisaæ liczbê!");
		}
		else {
			flag++;
		}

		if (!int::TryParse(hourFinish->Text, number1)) {
			MessageBox::Show("Nale¿y wpisaæ liczbê!");
		}
		else {
			flag++;
		}

		if (flag == 2) {

			int::TryParse(hourStart->Text, number1);
			int::TryParse(hourFinish->Text, number2);

			if (number1 > 24 || number1 < 0) {
				MessageBox::Show("Nale¿y wpisaæ liczbê z przedzia³u 0-24!");
			}
			else {
				flag++;
			}

			if (number2 > 24 || number2 < 0) {
				MessageBox::Show("Nale¿y wpisaæ liczbê z przedzia³u 0-24!");
			}
			else {
				flag++;
			}

			if (number2 <= number1) {
				MessageBox::Show("Godzina zakonczenia powinna byæ wiêksza od godziny rozpoczêcia!");
			}
			else {
				flag++;
			}

			databaseSelect.selectDataCalednar();

			for (size_t i = 0; i < databaseSelect.dataCalendar.id.size(); i++)
			{
				if (databaseSelect.dataCalendar.date_col[i] == date) {

					if (!(databaseSelect.dataCalendar.id[i] == activeEvent)) {

						int number3 = std::stoi(databaseSelect.dataCalendar.hourS_col[i]);
						int number4 = std::stoi(databaseSelect.dataCalendar.hourF_col[i]);

						if (number1 > number3) {

							if (number1 < number4) {
								MessageBox::Show("Inne wydarzenie jest w tych godzinach!	1");
								flag2++;
							}

						}
						if (number4 > number2) {

							if (number2 > number3) {
								MessageBox::Show("Inne wydarzenie jest w tych godzinach!	2");
								flag2++;
							}

						}
						if (number3 == number1 && number4 == number2) {

							MessageBox::Show("Inne wydarzenie jest w tych godzinach!	3");
							flag2++;

						}
						if (number3 > number1 && number4 < number2) {

							MessageBox::Show("Inne wydarzenie jest w tych godzinach!	4");
							flag2++;

						}
						if (number3 < number1 && number4 > number2) {

							MessageBox::Show("Inne wydarzenie jest w tych godzinach!	5");
							flag2++;

						}
					}
				}
			}

		}

		if (!flag2) { flag++; }

		if (flag == 6) {
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			databaseUpdate.updateData(
				activeEvent,
				converter.from_bytes(date),
				std::to_wstring(number1),
				std::to_wstring(number2),
				msclr::interop::marshal_as<std::wstring>(eventName->Text),
				notification->Checked
			);
		}

		layout->Visible = false;

		moduleLoad();

	}

	void addEventButtonBack_Click(System::Object^ sender, System::EventArgs^ e) {

		activeEvent = -1;

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"addEventPanel", true)[0];

		layout->Visible = false;

		moduleLoad();

	}

	void modifyEventButtonBack_Click(System::Object^ sender, System::EventArgs^ e) {

		activeEvent = -1;

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"modifyEventPanel", true)[0];

		layout->Visible = false;

		moduleLoad();

	}

};