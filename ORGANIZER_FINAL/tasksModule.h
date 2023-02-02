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

public ref class moduleTasks : public System::Windows::Forms::FlowLayoutPanel {

public:

	moduleTasks(void)
	{
		InitializeComponent();
	}

protected:

	~moduleTasks()
	{
		if (components)
		{
			delete components;
		}
	}

	//DEKLARACJA OBIEKTÓW
private:

	System::ComponentModel::Container^ components;
	System::Windows::Forms::FlowLayoutPanel^ listPanel;
	System::Windows::Forms::FlowLayoutPanel^ taskPanel;

	System::Windows::Forms::FlowLayoutPanel^ addListPanel;
	System::Windows::Forms::FlowLayoutPanel^ modifyListPanel;

	System::Windows::Forms::FlowLayoutPanel^ addTaskPanel;
	System::Windows::Forms::FlowLayoutPanel^ modifyTaskPanel;

	String^ activeList = " ";
	int activeTask = -1;

	void InitializeComponent(void)
	{

		this->listPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
		this->taskPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());

		this->addListPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
		this->modifyListPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());

		this->addTaskPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
		this->modifyTaskPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
		
		this->addListPanel->SuspendLayout();
		this->modifyListPanel->SuspendLayout();
		this->addTaskPanel->SuspendLayout();
		this->modifyTaskPanel->SuspendLayout();
		this->listPanel->SuspendLayout();
		this->taskPanel->SuspendLayout();
		this->SuspendLayout();

		//	CALY LAYOUT TASKS
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
		this->Location = System::Drawing::Point(300, 0);
		this->Name = L"mainScreenTasks";
		this->Size = System::Drawing::Size(980, 720);
		this->TabIndex = 0;
		this->Visible = false;

		//	LAYOUT LEWY
		this->listPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->listPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->listPanel->Location = System::Drawing::Point(300, 0);
		this->listPanel->Name = L"listPanel";
		this->listPanel->Size = System::Drawing::Size(480, 720);
		this->listPanel->TabIndex = 1;
		this->listPanel->Visible = false;

		//	LAYOUT PRAWY
		this->taskPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->taskPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->taskPanel->Location = System::Drawing::Point(780, 0);
		this->taskPanel->Name = L"taskPanel";
		this->taskPanel->Size = System::Drawing::Size(480, 720);
		this->taskPanel->TabIndex = 2;
		this->taskPanel->Visible = false;

		//	LAYOUT ADD LIST
		this->addListPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->addListPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->addListPanel->Location = System::Drawing::Point(300, 0);
		this->addListPanel->Name = L"addListPanel";
		this->addListPanel->Size = System::Drawing::Size(480, 720);
		this->addListPanel->TabIndex = 1;
		this->addListPanel->Visible = false;

		//	LAYOUT MODIFY LIST
		this->modifyListPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->modifyListPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->modifyListPanel->Location = System::Drawing::Point(300, 0);
		this->modifyListPanel->Name = L"modifyListPanel";
		this->modifyListPanel->Size = System::Drawing::Size(480, 720);
		this->modifyListPanel->TabIndex = 2;
		this->modifyListPanel->Visible = false;

		//	LAYOUT ADD TASK
		this->addTaskPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->addTaskPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->addTaskPanel->Location = System::Drawing::Point(780, 0);
		this->addTaskPanel->Name = L"addTaskPanel";
		this->addTaskPanel->Size = System::Drawing::Size(480, 720);
		this->addTaskPanel->TabIndex = 1;
		this->addTaskPanel->Visible = false;

		//	LAYOUT MODIFY TASK
		this->modifyTaskPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->modifyTaskPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->modifyTaskPanel->Location = System::Drawing::Point(780, 0);
		this->modifyTaskPanel->Name = L"modifyTaskPanel";
		this->modifyTaskPanel->Size = System::Drawing::Size(480, 720);
		this->modifyTaskPanel->TabIndex = 2;
		this->modifyTaskPanel->Visible = false;

		//	DODANIE DO GLOWNEGO LAYOUTU
		this->Controls->Add(this->listPanel);
		this->Controls->Add(this->addListPanel);
		this->Controls->Add(this->modifyListPanel);
		this->Controls->Add(this->taskPanel);
		this->Controls->Add(this->addTaskPanel);
		this->Controls->Add(this->modifyTaskPanel);
		this->addListPanel->ResumeLayout(false);
		this->modifyListPanel->ResumeLayout(false);
		this->addTaskPanel->ResumeLayout(false);
		this->modifyTaskPanel->ResumeLayout(false);
		this->listPanel->ResumeLayout(false);
		this->taskPanel->ResumeLayout(false);
		this->ResumeLayout(false);

	}

public:

	void moduleLoad() {

		taskPanel->Visible = true;
		listPanel->Visible = true;
		this->Visible = true;

		moduleTaskLoad();
		moduleListLoad();

	}

	void moduleUnload() {

		taskPanel->Visible = false;
		listPanel->Visible = false;
		this->Visible = false;

	}

	void moduleListLoad() {

		//LISTY

		this->listPanel->Controls->Clear();

		databaseSelect.selectDataTasks();

		int flag = 0;

		for (size_t i = 0; i < databaseSelect.dataTasks.id.size(); i++)
		{
			if (databaseSelect.dataTasks.inMain[i] == 2) {
				System::Windows::Forms::Button^ b = gcnew System::Windows::Forms::Button();
				b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
					static_cast<System::Int32>(static_cast<System::Byte>(60)));
				b->Name = msclr::interop::marshal_as<String^>(databaseSelect.dataTasks.list[i]);
				b->Size = System::Drawing::Size(480, 50);
				b->Text = msclr::interop::marshal_as<String^>(databaseSelect.dataTasks.list[i]);
				b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				b->Click += gcnew System::EventHandler(this, &moduleTasks::activeList_Click);
				listPanel->Controls->Add(b);
				flag++;
			}
		}

		if (flag == 0) {
			System::Windows::Forms::Label^ b = gcnew System::Windows::Forms::Label();
			b->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			b->ForeColor = System::Drawing::SystemColors::HighlightText;
			b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			b->Size = System::Drawing::Size(480, 200);
			b->Text = L"Brak utworzonych list";
			listPanel->Controls->Add(b);
		}

		//PRZYCISKI LIST
		System::Windows::Forms::Button^ addListButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ modifyListButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ deleteListButton = gcnew System::Windows::Forms::Button();

		addListButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addListButton->Name = L"addListButton";
		addListButton->Size = System::Drawing::Size(480, 50);
		addListButton->Text = L"Dodaj listê";
		addListButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addListButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addListButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addListButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addListButton->Click += gcnew System::EventHandler(this, &moduleTasks::addListButton_Click);

		deleteListButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		deleteListButton->Name = L"deleteListButton";
		deleteListButton->Size = System::Drawing::Size(480, 50);
		deleteListButton->Text = L"Usuñ listê";
		deleteListButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		deleteListButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		deleteListButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		deleteListButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		deleteListButton->Click += gcnew System::EventHandler(this, &moduleTasks::deleteListButton_Click);

		modifyListButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		modifyListButton->Name = L"modifyListButton";
		modifyListButton->Size = System::Drawing::Size(480, 50);
		modifyListButton->Text = L"Edytuj listê";
		modifyListButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyListButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyListButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyListButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyListButton->Click += gcnew System::EventHandler(this, &moduleTasks::modifyListButton_Click);

		this->listPanel->Controls->Add(addListButton);
		this->listPanel->Controls->Add(deleteListButton);
		this->listPanel->Controls->Add(modifyListButton);

	}

	void moduleTaskLoad() {

		// ZADANIA

		this->taskPanel->Controls->Clear();

		databaseSelect.selectDataTasks();

		int flag = 0;

		for (size_t i = 0; i < databaseSelect.dataTasks.id.size(); i++)
		{
			char cStr[50] = { 0 };
			String^ clrString = activeList;
			if (clrString->Length < sizeof(cStr))
				sprintf(cStr, "%s", clrString);
			std::string stlString(cStr);
			if (databaseSelect.dataTasks.list[i] == stlString && databaseSelect.dataTasks.inMain[i] != 2) {
				System::Windows::Forms::Button^ b = gcnew System::Windows::Forms::Button();
				if (databaseSelect.dataTasks.priority[i] == 1) {
					b->BackColor = System::Drawing::Color::Green;
				}
				if (databaseSelect.dataTasks.priority[i] == 2) {
					b->BackColor = System::Drawing::Color::Orange;
				}
				if (databaseSelect.dataTasks.priority[i] == 3) {
					b->BackColor = System::Drawing::Color::Red;
				}
				b->Name = databaseSelect.dataTasks.id[i].ToString();
				b->Size = System::Drawing::Size(480, 50);
				b->Text = msclr::interop::marshal_as<String^>(databaseSelect.dataTasks.task[i]);
				b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				b->Click += gcnew System::EventHandler(this, &moduleTasks::activeTask_Click);
				taskPanel->Controls->Add(b);
				flag++;
			}
		}

		if (flag == 0) {
			System::Windows::Forms::Label^ b = gcnew System::Windows::Forms::Label();
			b->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			b->ForeColor = System::Drawing::SystemColors::HighlightText;
			b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			b->Size = System::Drawing::Size(480, 200);
			b->Text = L"Brak zadañ";
			taskPanel->Controls->Add(b);
		}

		//PRZYCISKI TASK
		System::Windows::Forms::Button^ addTaskButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ modifyTaskButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ deleteTaskButton = gcnew System::Windows::Forms::Button();

		addTaskButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addTaskButton->Name = L"addTaskButton";
		addTaskButton->Size = System::Drawing::Size(480, 50);
		addTaskButton->Text = L"Dodaj zadanie";
		addTaskButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addTaskButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addTaskButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addTaskButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addTaskButton->Click += gcnew System::EventHandler(this, &moduleTasks::addTaskButton_Click);

		deleteTaskButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		deleteTaskButton->Name = L"deleteTaskButton";
		deleteTaskButton->Size = System::Drawing::Size(480, 50);
		deleteTaskButton->Text = L"Usuñ zadanie";
		deleteTaskButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		deleteTaskButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		deleteTaskButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		deleteTaskButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		deleteTaskButton->Click += gcnew System::EventHandler(this, &moduleTasks::deleteTaskButton_Click);

		modifyTaskButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		modifyTaskButton->Name = L"modifyTaskButton";
		modifyTaskButton->Size = System::Drawing::Size(480, 50);
		modifyTaskButton->Text = L"Edytuj zadanie";
		modifyTaskButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyTaskButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyTaskButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyTaskButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyTaskButton->Click += gcnew System::EventHandler(this, &moduleTasks::modifyTaskButton_Click);

		this->taskPanel->Controls->Add(addTaskButton);
		this->taskPanel->Controls->Add(deleteTaskButton);
		this->taskPanel->Controls->Add(modifyTaskButton);

	}

	void activeList_Click(System::Object^ sender, System::EventArgs^ e) {

		Button^ clicked = (Button^)sender;
		activeList = clicked->Name;
		moduleTaskLoad();
		moduleListLoad();

	}

	void activeTask_Click(System::Object^ sender, System::EventArgs^ e) {

		Button^ clicked = (Button^)sender;
		activeTask = Int32::Parse(clicked->Name);
		moduleTaskLoad();
		moduleListLoad();

	}

	void addListButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->listPanel->Visible = false;
		this->addListPanel->Visible = true;

		this->addListPanel->Controls->Clear();

		//PRZYCISKI LIST ADD
		System::Windows::Forms::Button^ addListButtonIn = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ addListButtonBack = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Label^ addListButtonInLabel = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ addListButtonInText = (gcnew System::Windows::Forms::TextBox());

		addListButtonInLabel->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		addListButtonInLabel->ForeColor = System::Drawing::SystemColors::HighlightText;
		addListButtonInLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addListButtonInLabel->Size = System::Drawing::Size(480, 50);
		addListButtonInLabel->Text = L"Podaj nazwê listy";

		addListButtonInText->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		addListButtonInText->Name = L"addListButtonInText";
		addListButtonInText->Size = System::Drawing::Size(480, 100);
		addListButtonInText->TabIndex = 0;

		addListButtonIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addListButtonIn->Name = L"addListButtonIn";
		addListButtonIn->Size = System::Drawing::Size(480, 50);
		addListButtonIn->Text = L"Dodaj liste";
		addListButtonIn->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addListButtonIn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addListButtonIn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addListButtonIn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addListButtonIn->Click += gcnew System::EventHandler(this, &moduleTasks::addListButtonIn_Click);

		addListButtonBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addListButtonBack->Name = L"addListButtonBack";
		addListButtonBack->Size = System::Drawing::Size(480, 50);
		addListButtonBack->Text = L"Powrót";
		addListButtonBack->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addListButtonBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addListButtonBack->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addListButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addListButtonBack->Click += gcnew System::EventHandler(this, &moduleTasks::addListButtonBack_Click);

		this->addListPanel->Controls->Add(addListButtonInLabel);
		this->addListPanel->Controls->Add(addListButtonInText);
		this->addListPanel->Controls->Add(addListButtonIn);
		this->addListPanel->Controls->Add(addListButtonBack);

	}

	void addListButtonIn_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"addListPanel", true)[0];
		System::Windows::Forms::TextBox^ text = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"addListButtonInText", true)[0];

		int flag = 0;

		if (text->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y nadaæ tytu³!");
		}

		if (flag == 1) {
			databaseInsert.insertData(
				msclr::interop::marshal_as<std::wstring>(text->Text),
				L" ",
				0,
				2
			);
		}

		layout->Visible = false;

		moduleLoad();

	}

	void addListButtonBack_Click(System::Object^ sender, System::EventArgs^ e) {

		this->listPanel->Visible = true;
		this->addListPanel->Visible = false;

		moduleLoad();

	}

	void modifyListButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->listPanel->Visible = false;
		this->modifyListPanel->Visible = true;

		this->modifyListPanel->Controls->Clear();

		//PRZYCISKI LIST MODIFY
		System::Windows::Forms::Button^ modifyListButtonIn = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ modifyListButtonBack = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Label^ modifyListButtonInLabel = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ modifyListButtonInText = (gcnew System::Windows::Forms::TextBox());

		modifyListButtonInLabel->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		modifyListButtonInLabel->ForeColor = System::Drawing::SystemColors::HighlightText;
		modifyListButtonInLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyListButtonInLabel->Size = System::Drawing::Size(480, 50);
		modifyListButtonInLabel->Text = L"Podaj nazwê listy";

		modifyListButtonInText->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		modifyListButtonInText->Name = L"modifyListButtonInText";
		modifyListButtonInText->Size = System::Drawing::Size(480, 100);
		modifyListButtonInText->TabIndex = 0;

		modifyListButtonIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		modifyListButtonIn->Name = L"modifyListButtonIn";
		modifyListButtonIn->Size = System::Drawing::Size(480, 50);
		modifyListButtonIn->Text = L"Edytuj liste";
		modifyListButtonIn->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyListButtonIn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyListButtonIn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyListButtonIn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyListButtonIn->Click += gcnew System::EventHandler(this, &moduleTasks::modifyListButtonIn_Click);

		modifyListButtonBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		modifyListButtonBack->Name = L"modifyListButtonBack";
		modifyListButtonBack->Size = System::Drawing::Size(480, 50);
		modifyListButtonBack->Text = L"Powrót";
		modifyListButtonBack->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyListButtonBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyListButtonBack->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyListButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyListButtonBack->Click += gcnew System::EventHandler(this, &moduleTasks::modifyListButtonBack_Click);

		this->modifyListPanel->Controls->Add(modifyListButtonInLabel);
		this->modifyListPanel->Controls->Add(modifyListButtonInText);
		this->modifyListPanel->Controls->Add(modifyListButtonIn);
		this->modifyListPanel->Controls->Add(modifyListButtonBack);

	}

	void modifyListButtonIn_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"modifyListPanel", true)[0];
		System::Windows::Forms::TextBox^ text = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"modifyListButtonInText", true)[0];

		int flag = 0;

		if (text->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y nadaæ tytu³!");
		}

		int a = 0;

		databaseSelect.selectDataTasks();

		for (size_t i = 0; i < databaseSelect.dataTasks.id.size(); i++)
		{
			char cStr[50] = { 0 };
			String^ clrString = activeList;
			if (clrString->Length < sizeof(cStr))
				sprintf(cStr, "%s", clrString);
			std::string stlString(cStr);
			if (databaseSelect.dataTasks.list[i] == stlString && databaseSelect.dataTasks.inMain[i] == 2) {

				a = databaseSelect.dataTasks.id[i];

			}
		}

		if (flag == 1) {
			databaseUpdate.updateData(
				a,
				msclr::interop::marshal_as<std::wstring>(text->Text),
				L" ",
				0,
				2
			);
		}

		layout->Visible = false;

		moduleLoad();

	}

	void modifyListButtonBack_Click(System::Object^ sender, System::EventArgs^ e) {

		this->listPanel->Visible = true;
		this->modifyListPanel->Visible = false;

		moduleLoad();

	}

	void deleteListButton_Click(System::Object^ sender, System::EventArgs^ e) {

		int a = 0;

		databaseSelect.selectDataTasks();

		for (size_t i = 0; i < databaseSelect.dataTasks.id.size(); i++)
		{
			char cStr[50] = { 0 };
			String^ clrString = activeList;
			if (clrString->Length < sizeof(cStr))
				sprintf(cStr, "%s", clrString);
			std::string stlString(cStr);
			if (databaseSelect.dataTasks.list[i] == stlString && databaseSelect.dataTasks.inMain[i] == 2) {

				a = databaseSelect.dataTasks.id[i];

			}
		}

		databaseDelete.deleteData(a, L"tasks");

		this->listPanel->Visible = true;

		moduleLoad();

	}

	void addTaskButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (activeList != " ") {

			this->listPanel->Visible = false;
			this->addTaskPanel->Visible = true;

			this->addTaskPanel->Controls->Clear();

			//PRZYCISKI LIST ADD
			System::Windows::Forms::Button^ addTaskButtonIn = gcnew System::Windows::Forms::Button();
			System::Windows::Forms::Button^ addTaskButtonBack = gcnew System::Windows::Forms::Button();
			System::Windows::Forms::Label^ addTaskButtonInLabel = (gcnew System::Windows::Forms::Label());
			System::Windows::Forms::TextBox^ addTaskButtonInText = (gcnew System::Windows::Forms::TextBox());
			System::Windows::Forms::Label^ addTaskButtonInPriority = (gcnew System::Windows::Forms::Label());
			System::Windows::Forms::RadioButton^ addTaskButtonInPriority1 = (gcnew System::Windows::Forms::RadioButton());
			System::Windows::Forms::RadioButton^ addTaskButtonInPriority2 = (gcnew System::Windows::Forms::RadioButton());
			System::Windows::Forms::RadioButton^ addTaskButtonInPriority3 = (gcnew System::Windows::Forms::RadioButton());
			System::Windows::Forms::CheckBox^ addTaskButtonInMain = (gcnew System::Windows::Forms::CheckBox());

			addTaskButtonInLabel->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			addTaskButtonInLabel->ForeColor = System::Drawing::SystemColors::HighlightText;
			addTaskButtonInLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			addTaskButtonInLabel->Size = System::Drawing::Size(480, 50);
			addTaskButtonInLabel->Text = L"Podaj nazwê zadania";

			addTaskButtonInText->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			addTaskButtonInText->Name = L"addTaskButtonInText";
			addTaskButtonInText->Size = System::Drawing::Size(480, 100);
			addTaskButtonInText->TabIndex = 0;

			addTaskButtonIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			addTaskButtonIn->Name = L"addTaskButtonIn";
			addTaskButtonIn->Size = System::Drawing::Size(480, 50);
			addTaskButtonIn->Text = L"Dodaj zadanie";
			addTaskButtonIn->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			addTaskButtonIn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			addTaskButtonIn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			addTaskButtonIn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			addTaskButtonIn->Click += gcnew System::EventHandler(this, &moduleTasks::addTaskButtonIn_Click);

			addTaskButtonBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			addTaskButtonBack->Name = L"addTaskButtonBack";
			addTaskButtonBack->Size = System::Drawing::Size(480, 50);
			addTaskButtonBack->Text = L"Powrót";
			addTaskButtonBack->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			addTaskButtonBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			addTaskButtonBack->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			addTaskButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			addTaskButtonBack->Click += gcnew System::EventHandler(this, &moduleTasks::addTaskButtonBack_Click);

			addTaskButtonInPriority->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			addTaskButtonInPriority->ForeColor = System::Drawing::SystemColors::HighlightText;
			addTaskButtonInPriority->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			addTaskButtonInPriority->Size = System::Drawing::Size(480, 50);
			addTaskButtonInPriority->Text = L"Priorytet";

			addTaskButtonInPriority1->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			addTaskButtonInPriority1->ForeColor = System::Drawing::SystemColors::HighlightText;
			addTaskButtonInPriority1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			addTaskButtonInPriority1->Size = System::Drawing::Size(480, 50);
			addTaskButtonInPriority1->Name = L"addTaskButtonInPriority1";
			addTaskButtonInPriority1->Text = L"Niski";

			addTaskButtonInPriority2->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			addTaskButtonInPriority2->ForeColor = System::Drawing::SystemColors::HighlightText;
			addTaskButtonInPriority2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			addTaskButtonInPriority2->Size = System::Drawing::Size(480, 50);
			addTaskButtonInPriority2->Name = L"addTaskButtonInPriority2";
			addTaskButtonInPriority2->Text = L"Œredni";

			addTaskButtonInPriority3->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			addTaskButtonInPriority3->ForeColor = System::Drawing::SystemColors::HighlightText;
			addTaskButtonInPriority3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			addTaskButtonInPriority3->Size = System::Drawing::Size(480, 50);
			addTaskButtonInPriority3->Name = L"addTaskButtonInPriority3";
			addTaskButtonInPriority3->Text = L"Wysoki";

			addTaskButtonInMain->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			addTaskButtonInMain->ForeColor = System::Drawing::SystemColors::HighlightText;
			addTaskButtonInMain->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			addTaskButtonInMain->Size = System::Drawing::Size(480, 100);
			addTaskButtonInMain->Name = L"addTaskButtonInMain";
			addTaskButtonInMain->Text = L"Czy chcesz, aby zadnie wyœwietla³o siê na ekranie g³ównym?";

			this->addTaskPanel->Controls->Add(addTaskButtonInLabel);
			this->addTaskPanel->Controls->Add(addTaskButtonInText);
			this->addTaskPanel->Controls->Add(addTaskButtonInPriority);
			this->addTaskPanel->Controls->Add(addTaskButtonInPriority1);
			this->addTaskPanel->Controls->Add(addTaskButtonInPriority2);
			this->addTaskPanel->Controls->Add(addTaskButtonInPriority3);
			this->addTaskPanel->Controls->Add(addTaskButtonInMain);
			this->addTaskPanel->Controls->Add(addTaskButtonIn);
			this->addTaskPanel->Controls->Add(addTaskButtonBack);

		}
		else {

			MessageBox::Show("Nale¿y wybraæ listê!");

		}

	}

	void addTaskButtonIn_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"addTaskPanel", true)[0];
		System::Windows::Forms::TextBox^ text = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"addTaskButtonInText", true)[0];
		System::Windows::Forms::RadioButton^ p1 = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"addTaskButtonInPriority1", true)[0];
		System::Windows::Forms::RadioButton^ p2 = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"addTaskButtonInPriority2", true)[0];
		System::Windows::Forms::RadioButton^ p3 = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"addTaskButtonInPriority3", true)[0];
		System::Windows::Forms::CheckBox^ inMain = (System::Windows::Forms::CheckBox^)layout->Controls->Find(L"addTaskButtonInMain", true)[0];

		int flag = 0;
		int priority = 1;

		if (text->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y nadaæ tytu³!");
		}

		if (!p1->Checked && !p2->Checked && !p3->Checked) {
			MessageBox::Show("Nie wybrano priorytetu - nadano najni¿szy!");
		}

		if (p2->Checked) { priority = 2; }
		else if (p3->Checked) { priority = 3; }

		if (flag == 1) {
			char cStr[50] = { 0 };
			String^ clrString = activeList;
			if (clrString->Length < sizeof(cStr))
				sprintf(cStr, "%s", clrString);
			std::string stlString(cStr);
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			databaseInsert.insertData(
				converter.from_bytes(stlString),
				msclr::interop::marshal_as<std::wstring>(text->Text),
				priority,
				inMain->Checked
			);
		}

		this->taskPanel->Visible = true;
		this->addTaskPanel->Visible = false;

		moduleLoad();

	}

	void addTaskButtonBack_Click(System::Object^ sender, System::EventArgs^ e) {

		this->taskPanel->Visible = true;
		this->addTaskPanel->Visible = false;

		moduleLoad();

	}

	void modifyTaskButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (activeList != " ") {

			if (activeTask != -1) {

				this->listPanel->Visible = false;
				this->modifyTaskPanel->Visible = true;

				this->modifyTaskPanel->Controls->Clear();

				//PRZYCISKI LIST ADD
				System::Windows::Forms::Button^ modifyTaskButtonIn = gcnew System::Windows::Forms::Button();
				System::Windows::Forms::Button^ modifyTaskButtonBack = gcnew System::Windows::Forms::Button();
				System::Windows::Forms::Label^ modifyTaskButtonInLabel = (gcnew System::Windows::Forms::Label());
				System::Windows::Forms::TextBox^ modifyTaskButtonInText = (gcnew System::Windows::Forms::TextBox());
				System::Windows::Forms::Label^ modifyTaskButtonInPriority = (gcnew System::Windows::Forms::Label());
				System::Windows::Forms::RadioButton^ modifyTaskButtonInPriority1 = (gcnew System::Windows::Forms::RadioButton());
				System::Windows::Forms::RadioButton^ modifyTaskButtonInPriority2 = (gcnew System::Windows::Forms::RadioButton());
				System::Windows::Forms::RadioButton^ modifyTaskButtonInPriority3 = (gcnew System::Windows::Forms::RadioButton());
				System::Windows::Forms::CheckBox^ modifyTaskButtonInMain = (gcnew System::Windows::Forms::CheckBox());

				modifyTaskButtonInLabel->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				modifyTaskButtonInLabel->ForeColor = System::Drawing::SystemColors::HighlightText;
				modifyTaskButtonInLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				modifyTaskButtonInLabel->Size = System::Drawing::Size(480, 50);
				modifyTaskButtonInLabel->Text = L"Podaj nazwê zadania";

				modifyTaskButtonInText->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				modifyTaskButtonInText->Name = L"modifyTaskButtonInText";
				modifyTaskButtonInText->Size = System::Drawing::Size(480, 100);
				modifyTaskButtonInText->TabIndex = 0;

				modifyTaskButtonIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
					static_cast<System::Int32>(static_cast<System::Byte>(100)));
				modifyTaskButtonIn->Name = L"modifyTaskButtonIn";
				modifyTaskButtonIn->Size = System::Drawing::Size(480, 50);
				modifyTaskButtonIn->Text = L"Edytuj zadanie";
				modifyTaskButtonIn->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				modifyTaskButtonIn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				modifyTaskButtonIn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				modifyTaskButtonIn->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				modifyTaskButtonIn->Click += gcnew System::EventHandler(this, &moduleTasks::modifyTaskButtonIn_Click);

				modifyTaskButtonBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
					static_cast<System::Int32>(static_cast<System::Byte>(100)));
				modifyTaskButtonBack->Name = L"modifyTaskButtonBack";
				modifyTaskButtonBack->Size = System::Drawing::Size(480, 50);
				modifyTaskButtonBack->Text = L"Powrót";
				modifyTaskButtonBack->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				modifyTaskButtonBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				modifyTaskButtonBack->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				modifyTaskButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				modifyTaskButtonBack->Click += gcnew System::EventHandler(this, &moduleTasks::modifyTaskButtonBack_Click);

				modifyTaskButtonInPriority->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				modifyTaskButtonInPriority->ForeColor = System::Drawing::SystemColors::HighlightText;
				modifyTaskButtonInPriority->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				modifyTaskButtonInPriority->Size = System::Drawing::Size(480, 50);
				modifyTaskButtonInPriority->Text = L"Priorytet";

				modifyTaskButtonInPriority1->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				modifyTaskButtonInPriority1->ForeColor = System::Drawing::SystemColors::HighlightText;
				modifyTaskButtonInPriority1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				modifyTaskButtonInPriority1->Size = System::Drawing::Size(480, 50);
				modifyTaskButtonInPriority1->Name = L"modifyTaskButtonInPriority1";
				modifyTaskButtonInPriority1->Text = L"Niski";

				modifyTaskButtonInPriority2->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				modifyTaskButtonInPriority2->ForeColor = System::Drawing::SystemColors::HighlightText;
				modifyTaskButtonInPriority2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				modifyTaskButtonInPriority2->Size = System::Drawing::Size(480, 50);
				modifyTaskButtonInPriority2->Name = L"modifyTaskButtonInPriority2";
				modifyTaskButtonInPriority2->Text = L"Œredni";

				modifyTaskButtonInPriority3->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				modifyTaskButtonInPriority3->ForeColor = System::Drawing::SystemColors::HighlightText;
				modifyTaskButtonInPriority3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				modifyTaskButtonInPriority3->Size = System::Drawing::Size(480, 50);
				modifyTaskButtonInPriority3->Name = L"modifyTaskButtonInPriority3";
				modifyTaskButtonInPriority3->Text = L"Wysoki";

				modifyTaskButtonInMain->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				modifyTaskButtonInMain->ForeColor = System::Drawing::SystemColors::HighlightText;
				modifyTaskButtonInMain->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				modifyTaskButtonInMain->Size = System::Drawing::Size(480, 100);
				modifyTaskButtonInMain->Name = L"modifyTaskButtonInMain";
				modifyTaskButtonInMain->Text = L"Czy chcesz, aby zadnie wyœwietla³o siê na ekranie g³ównym?";

				this->modifyTaskPanel->Controls->Add(modifyTaskButtonInLabel);
				this->modifyTaskPanel->Controls->Add(modifyTaskButtonInText);
				this->modifyTaskPanel->Controls->Add(modifyTaskButtonInPriority);
				this->modifyTaskPanel->Controls->Add(modifyTaskButtonInPriority1);
				this->modifyTaskPanel->Controls->Add(modifyTaskButtonInPriority2);
				this->modifyTaskPanel->Controls->Add(modifyTaskButtonInPriority3);
				this->modifyTaskPanel->Controls->Add(modifyTaskButtonInMain);
				this->modifyTaskPanel->Controls->Add(modifyTaskButtonIn);
				this->modifyTaskPanel->Controls->Add(modifyTaskButtonBack);

			}
			else {

				MessageBox::Show("Nale¿y wybraæ zadanie!");

			}

		}
		else {

			MessageBox::Show("Nale¿y wybraæ listê!");

		}

	}

	void modifyTaskButtonIn_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"modifyTaskPanel", true)[0];
		System::Windows::Forms::TextBox^ text = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"modifyTaskButtonInText", true)[0];
		System::Windows::Forms::RadioButton^ p1 = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"modifyTaskButtonInPriority1", true)[0];
		System::Windows::Forms::RadioButton^ p2 = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"modifyTaskButtonInPriority2", true)[0];
		System::Windows::Forms::RadioButton^ p3 = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"modifyTaskButtonInPriority3", true)[0];
		System::Windows::Forms::CheckBox^ inMain = (System::Windows::Forms::CheckBox^)layout->Controls->Find(L"modifyTaskButtonInMain", true)[0];

		int flag = 0;
		int priority = 1;

		if (text->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y nadaæ tytu³!");
		}

		if (!p1->Checked && !p2->Checked && !p3->Checked) {
			MessageBox::Show("Nie wybrano priorytetu - nadano najni¿szy!");
		}

		if (p2->Checked) { priority = 2; }
		else if (p3->Checked) { priority = 3; }

		if (flag == 1) {
			char cStr[50] = { 0 };
			String^ clrString = activeList;
			if (clrString->Length < sizeof(cStr))
				sprintf(cStr, "%s", clrString);
			std::string stlString(cStr);
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			databaseUpdate.updateData(
				activeTask,
				converter.from_bytes(stlString),
				msclr::interop::marshal_as<std::wstring>(text->Text),
				priority,
				inMain->Checked
			);
		}

		this->taskPanel->Visible = true;
		this->modifyTaskPanel->Visible = false;

		activeTask = -1;

		moduleLoad();

	}

	void modifyTaskButtonBack_Click(System::Object^ sender, System::EventArgs^ e) {

		this->taskPanel->Visible = true;
		this->modifyTaskPanel->Visible = false;

		moduleLoad();

	}

	void deleteTaskButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (activeList != " ") {

			if (activeTask != -1) {

				databaseDelete.deleteData(activeTask, L"tasks");

			}
			else {

				MessageBox::Show("Nale¿y wybraæ zadanie!");

			}

		}
		else {

			MessageBox::Show("Nale¿y wybraæ listê!");

		}

		activeTask = -1;

		moduleLoad();

	}

};