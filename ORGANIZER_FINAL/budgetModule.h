#pragma once
//FORM - MODU£ BUD¯ETU

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

public ref class moduleBudget : public System::Windows::Forms::FlowLayoutPanel {

public:

	moduleBudget(void)
	{
		InitializeComponent();
	}

protected:

	~moduleBudget()
	{
		if (components)
		{
			delete components;
		}
	}

	//DEKLARACJA OBIEKTÓW
private:

	System::ComponentModel::Container^ components;
	System::Windows::Forms::FlowLayoutPanel^ budgetPanel;
	System::Windows::Forms::FlowLayoutPanel^ addingPanel;
	DateTime todayDate = System::DateTime::Now;
	int activeMonth;
	int activeYear;

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

	void InitializeComponent(void)
	{

		//	INICJALIZACJA OBIEKTÓW

		this->activeMonth = todayDate.Month;
		this->activeYear = todayDate.Year;

		this->budgetPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
		this->addingPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());

		this->budgetPanel->SuspendLayout();
		this->addingPanel->SuspendLayout();
		this->SuspendLayout();

		//	CALY LAYOUT BUDZETU
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
		this->Location = System::Drawing::Point(300, 0);
		this->Name = L"mainScreenBudget";
		this->Size = System::Drawing::Size(980, 720);
		this->TabIndex = 0;
		this->Visible = false;

		//	LAYOUT BUDGET PANEL
		this->budgetPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->budgetPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->budgetPanel->Location = System::Drawing::Point(300, 0);
		this->budgetPanel->Name = L"budgetPanel";
		this->budgetPanel->Size = System::Drawing::Size(760, 720);
		this->budgetPanel->TabIndex = 1;
		this->budgetPanel->Visible = false;

		//	LAYOUT BUDGET ADDING PANEL
		this->addingPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->addingPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->addingPanel->Location = System::Drawing::Point(900, 0);
		this->addingPanel->Name = L"addingPanel";
		this->addingPanel->Size = System::Drawing::Size(200, 720);
		this->addingPanel->TabIndex = 2;
		this->addingPanel->Visible = false;

		System::Windows::Forms::Label^ labelIncome = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ income = (gcnew System::Windows::Forms::TextBox());
		System::Windows::Forms::Button^ incomeButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Label^ labelOutcome = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ outcome = (gcnew System::Windows::Forms::TextBox());
		System::Windows::Forms::Button^ outcomeButton = gcnew System::Windows::Forms::Button();

		labelIncome->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelIncome->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelIncome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelIncome->Size = System::Drawing::Size(200, 100);
		labelIncome->Text = L"Podaj kwotê przychodu:";

		income->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		income->Name = L"income";
		income->Size = System::Drawing::Size(200, 100);
		income->TabIndex = 0;

		incomeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		incomeButton->Name = L"incomeButton";
		incomeButton->Size = System::Drawing::Size(200, 100);
		incomeButton->Text = L"Dodaj przychód";
		incomeButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		incomeButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		incomeButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		incomeButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		incomeButton->Click += gcnew System::EventHandler(this, &moduleBudget::checkInputIncome);

		labelOutcome->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelOutcome->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelOutcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelOutcome->Size = System::Drawing::Size(200, 100);
		labelOutcome->Text = L"Podaj kwotê wydatku:";

		outcome->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		outcome->Name = L"outcome";
		outcome->Size = System::Drawing::Size(200, 300);
		outcome->TabIndex = 0;

		outcomeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		outcomeButton->Name = L"outcomeButton";
		outcomeButton->Size = System::Drawing::Size(200, 100);
		outcomeButton->Text = L"Dodaj wydatek";
		outcomeButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		outcomeButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		outcomeButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		outcomeButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		outcomeButton->Click += gcnew System::EventHandler(this, &moduleBudget::checkInputOutcome);

		addingPanel->Controls->Add(labelIncome);
		addingPanel->Controls->Add(income);
		addingPanel->Controls->Add(incomeButton);
		addingPanel->Controls->Add(labelOutcome);
		addingPanel->Controls->Add(outcome);
		addingPanel->Controls->Add(outcomeButton);

		//	DODANIE DO GLOWNEGO LAYOUTU
		this->Controls->Add(this->budgetPanel);
		this->Controls->Add(this->addingPanel);
		this->budgetPanel->ResumeLayout(false);
		this->addingPanel->ResumeLayout(false);
		this->ResumeLayout(false);

	}

public:

	void moduleLoad() {

		budgetPanel->Visible = true;
		addingPanel->Visible = true;
		this->Visible = true;

		budgetPanelLoad();

	}

	void moduleUnload() {

		addingPanel->Visible = false;
		budgetPanel->Visible = false;
		this->Visible = false;

	}

	void checkInputIncome(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"addingPanel", true)[0];
		System::Windows::Forms::TextBox^ income = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"income", true)[0];

		int flag = 0;
		int number1;

		if (income->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y wpisaæ liczbê!");
		}

		if (!int::TryParse(income->Text, number1)) {
			MessageBox::Show("Nale¿y wpisaæ liczbê!");
		}
		else {
			flag++;
		}

		if (flag == 2) {
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			databaseInsert.insertData(
				converter.from_bytes(std::to_string(activeMonth)+ std::to_string(activeYear)),
				int::Parse(income->Text),
				0
			);
			income->Text = "";
		}

		moduleLoad();

	}

	void checkInputOutcome(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"addingPanel", true)[0];
		System::Windows::Forms::TextBox^ outcome = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"outcome", true)[0];

		int flag = 0;
		int number1;

		if (outcome->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y wpisaæ liczbê!");
		}

		if (!int::TryParse(outcome->Text, number1)) {
			MessageBox::Show("Nale¿y wpisaæ liczbê!");
		}
		else {
			flag++;
		}

		if (flag == 2) {
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			databaseInsert.insertData(
				converter.from_bytes(std::to_string(activeMonth) + std::to_string(activeYear)),
				0,
				int::Parse(outcome->Text)
			);
			outcome->Text = "";
		}

		moduleLoad();

	}

	void budgetPanelLoad() {

		budgetPanel->Controls->Clear();

		// INICJALIZACJA OBSZARU

		System::Windows::Forms::FlowLayoutPanel^ up = gcnew System::Windows::Forms::FlowLayoutPanel();
		System::Windows::Forms::FlowLayoutPanel^ down = gcnew System::Windows::Forms::FlowLayoutPanel();
		System::Windows::Forms::FlowLayoutPanel^ downLeft = gcnew System::Windows::Forms::FlowLayoutPanel();
		System::Windows::Forms::FlowLayoutPanel^ downRight = gcnew System::Windows::Forms::FlowLayoutPanel();

		// GÓRNA CZÊŒÆ

		up->Controls->Clear();

		//POLE Z PRZECISKAMI DO WYBORU DATY

		up->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		up->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
		up->Location = System::Drawing::Point(300, 0);
		up->Name = L"upperCalendarPicker";
		up->Size = System::Drawing::Size(780, 200);
		up->TabIndex = 0;
		up->Visible = true;

		budgetPanel->Controls->Add(up);

		//PRZYCISKI
		System::Windows::Forms::Button^ previousMonth = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ nextMonth = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Label^ currentMonth = gcnew System::Windows::Forms::Label();
		System::Windows::Forms::Label^ currentYear = gcnew System::Windows::Forms::Label();
		System::Windows::Forms::Label^ balance = gcnew System::Windows::Forms::Label();

		previousMonth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		previousMonth->Name = L"previousMonth";
		previousMonth->Size = System::Drawing::Size(160, 50);
		previousMonth->Text = L"<";
		previousMonth->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		previousMonth->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		previousMonth->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		previousMonth->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		previousMonth->Click += gcnew System::EventHandler(this, &moduleBudget::buttonPreviousMonth_Click);

		nextMonth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		nextMonth->Name = L"previousMonth";
		nextMonth->Size = System::Drawing::Size(160, 50);
		nextMonth->Text = L">";
		nextMonth->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		nextMonth->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		nextMonth->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		nextMonth->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		nextMonth->Click += gcnew System::EventHandler(this, &moduleBudget::buttonNextMonth_Click);

		currentMonth->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		currentMonth->ForeColor = System::Drawing::SystemColors::HighlightText;
		currentMonth->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
		currentMonth->Size = System::Drawing::Size(200, 50);
		currentMonth->Text = getNameOfMonth(activeMonth);

		currentYear->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		currentYear->ForeColor = System::Drawing::SystemColors::HighlightText;
		currentYear->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		currentYear->Size = System::Drawing::Size(200, 50);
		currentYear->Text = activeYear.ToString();

		balance->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		balance->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		balance->Size = System::Drawing::Size(760, 150);

		databaseSelect.selectDataBudget();

		int b = 0;
		std::string date = std::to_string(activeMonth) + std::to_string(activeYear);

		for (size_t i = 0; i < databaseSelect.dataBudget.id.size(); i++)
		{
			if (databaseSelect.dataBudget.date_col[i] == date) {
				b += databaseSelect.dataBudget.income[i];
				b -= databaseSelect.dataBudget.outcome[i];
			}
		}

		if(b > 0) { balance->ForeColor = System::Drawing::Color::Green; }
		if (b == 0) { balance->ForeColor = System::Drawing::Color::White; }
		if (b < 0) { balance->ForeColor = System::Drawing::Color::Red; }

		std::string bb = "Balans: " + std::to_string(b);

		balance->Text = msclr::interop::marshal_as<String^>(bb);

		up->Controls->Add(previousMonth);
		up->Controls->Add(currentMonth);
		up->Controls->Add(currentYear);
		up->Controls->Add(nextMonth);
		up->Controls->Add(balance);

		//DOLNA CZÊŒÆ

		downLeft->Controls->Clear();
		downRight->Controls->Clear();
		down->Controls->Clear();

		//POLE PRZYCISKOW

		down->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		down->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
		down->Location = System::Drawing::Point(300, 200);
		down->Name = L"down";
		down->Size = System::Drawing::Size(780, 500);
		down->TabIndex = 0;
		down->Visible = true;

		downLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(45)));
		downLeft->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		downLeft->Location = System::Drawing::Point(300, 200);
		downLeft->Name = L"downLeft";
		downLeft->Size = System::Drawing::Size(360, 500);
		downLeft->TabIndex = 0;
		downLeft->Visible = true;

		downRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(45)));
		downRight->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		downRight->Location = System::Drawing::Point(660, 200);
		downRight->Name = L"downRight";
		downRight->Size = System::Drawing::Size(360, 500);
		downRight->TabIndex = 1;
		downRight->Visible = true;

		budgetPanel->Controls->Add(down);
		down->Controls->Add(downLeft);
		down->Controls->Add(downRight);

		System::Windows::Forms::Label^ labelIncome = gcnew System::Windows::Forms::Label();
		System::Windows::Forms::Label^ labelOutcome = gcnew System::Windows::Forms::Label();

		labelIncome->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelIncome->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelIncome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelIncome->Size = System::Drawing::Size(360, 50);
		labelIncome->Text = L"Przychody";

		downLeft->Controls->Add(labelIncome);

		bool flag = 0;

		for (size_t i = 0; i < databaseSelect.dataBudget.id.size(); i++)
		{
			if (databaseSelect.dataBudget.date_col[i] == date && databaseSelect.dataBudget.income[i] != 0) {

				System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

				l->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				l->ForeColor = System::Drawing::Color::Green;
				l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				l->Size = System::Drawing::Size(360, 50);
				l->Text = databaseSelect.dataBudget.income[i].ToString();

				flag++;

				downLeft->Controls->Add(l);

				if (i == 10) { break; }

			}
		}

		if (flag == 0) {

			System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->ForeColor = System::Drawing::Color::Green;
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(360, 50);
			l->Text = L"Brak przychodów";

			downLeft->Controls->Add(l);

		}

		labelOutcome->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelOutcome->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelOutcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelOutcome->Size = System::Drawing::Size(360, 50);
		labelOutcome->Text = L"Wydatki";

		downRight->Controls->Add(labelOutcome);

		flag = 0;

		for (size_t i = 0; i < databaseSelect.dataBudget.id.size(); i++)
		{
			if (databaseSelect.dataBudget.date_col[i] == date && databaseSelect.dataBudget.outcome[i] != 0) {

				System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

				l->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				l->ForeColor = System::Drawing::Color::Red;
				l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				l->Size = System::Drawing::Size(360, 50);
				l->Text = databaseSelect.dataBudget.outcome[i].ToString();

				flag++;

				downRight->Controls->Add(l);

				if (i == 10) { break; }

			}
		}

		if (flag == 0) {

			System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->ForeColor = System::Drawing::Color::Red;
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(360, 50);
			l->Text = L"Brak wydatków";

			downRight->Controls->Add(l);

		}

	}

	void buttonPreviousMonth_Click(System::Object ^ sender, System::EventArgs ^ e) {

		activeMonth--;
		if (activeMonth == 0) {
			activeMonth = 12;
			activeYear--;
		}
		budgetPanelLoad();

	}

	void buttonNextMonth_Click(System::Object^ sender, System::EventArgs^ e) {

		activeMonth++;
		if (activeMonth == 13) {
			activeMonth = 1;
			activeYear++;
		}
		budgetPanelLoad();

	}

};