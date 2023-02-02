#pragma once
#pragma comment(lib, "user32.lib")

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//TABELA KONFIGURACYJNA
	int moduleConfigurationTable[4] = { 0,0,0,0 };

	//TABELA NAZW
	System::String^ getModuleNameFromNumber(int a) {
		switch (a) {
		case 0:
			return gcnew System::String("Kalendarz");
			break;
		case 1:
			return gcnew System::String("Lista Zadañ");
			break;
		case 2:
			return gcnew System::String("Notatki");
			break;
		case 3:
			return gcnew System::String("Bud¿et");
			break;
		}
	}

	//FORM1 - OKNOG£OWNE
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			
		}

	protected:
		
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	//DEKLARACJA OBIEKTÓW
	private: System::Windows::Forms::FlowLayoutPanel^ mainScreen;
	private: System::Windows::Forms::FlowLayoutPanel^ moduleChange;
	private: System::Windows::Forms::FlowLayoutPanel^ moduleScreen;
	private: System::Windows::Forms::Label^ formTitle;
	private: System::ComponentModel::Container ^components;

	private: moduleCalendar^ moduleCalendarObject;
	private: moduleNotes^ moduleNotesObject;
	private: moduleBudget^ moduleBudgetObject;
	private: moduleTasks^ moduleTasksObject;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			//inicjalizacja

			this->moduleCalendarObject = gcnew moduleCalendar();
			this->moduleNotesObject = gcnew moduleNotes();
			this->moduleBudgetObject = gcnew moduleBudget();
			this->moduleTasksObject = gcnew moduleTasks();

			this->mainScreen = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->formTitle = (gcnew System::Windows::Forms::Label());
			this->moduleChange = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->moduleScreen = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->mainScreen->SuspendLayout();
			this->moduleScreen->SuspendLayout();
			this->moduleChange->SuspendLayout();
			this->SuspendLayout();

			// moduleScreen - panel z modu³ami

			this->moduleScreen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->moduleScreen->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
			this->moduleScreen->Location = System::Drawing::Point(300, 0);
			this->moduleScreen->Name = L"moduleScreen";
			this->moduleScreen->Size = System::Drawing::Size(980, 720);
			this->moduleScreen->TabIndex = 0;
			this->moduleScreen->Visible = true;

			// moduleChange - panel ustawiania widocznosci modu³ów
			// 
			this->moduleChange->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->moduleChange->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->moduleChange->Location = System::Drawing::Point(300, 0);
			this->moduleChange->Name = L"moduleChange";
			this->moduleChange->Size = System::Drawing::Size(980, 720);
			this->moduleChange->TabIndex = 1;
			this->moduleChange->Visible = false;

			// 
			// mainScreen - ekran glowny
			// 
			this->mainScreen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->mainScreen->Controls->Add(this->formTitle);
			this->mainScreen->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->mainScreen->Location = System::Drawing::Point(0, 0);
			this->mainScreen->Name = L"mainScreen";
			this->mainScreen->Size = System::Drawing::Size(300, 720);
			this->mainScreen->TabIndex = 2;

			// 
			// 
			// CA£E OKNO
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->mainScreen);
			this->Controls->Add(this->moduleChange);
			this->Controls->Add(this->moduleScreen);
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(1280, 720);
			this->Name = L"Form1";
			this->Text = L"Organizer";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->mainScreen->ResumeLayout(false);
			this->moduleChange->ResumeLayout(false);
			this->moduleScreen->ResumeLayout(false);
			this->ResumeLayout(false);

		}

#pragma endregion
	// £ADOWANIE EKRANU G£ÓWNEGO
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

		mainScreen->Controls->Clear();

		//pobranie konfiguracji modu³ów

		std::fstream plik;
		plik.open("conf.txt");
		int i = 0;

		if (plik.good()) {

			while (plik >> moduleConfigurationTable[i]) {
				i++;
			}

		}
		else {

			exit(0);

		}

		//zaladowanie przyciskow

		console.openConsole();
		Form1_Load_Buttons();
		ModuleScreen_Load();

	}

	// £ADOWANIE EKRANU G£ÓWNEGO - rêcznie
	private: System::Void Form1_Load_() {

		mainScreen->Controls->Clear();

		//pobranie konfiguracji modu³ów

		std::fstream plik;
		plik.open("conf.txt");
		int i = 0;

		if (plik.good()) {

			while (plik >> moduleConfigurationTable[i]) {
				i++;
			}

		}
		else {

			exit(0);

		}

		//zaladowanie przyciskow

		ModuleScreen_Load();
		Form1_Load_Buttons();

	}

	// PRZYCISK KALENDARZ
	private: System::Void buttonCalednar_Click(System::Object^ sender, System::EventArgs^ e) {

		this->moduleChange->Visible = false;
		moduleTasksObject->moduleUnload();
		moduleNotesObject->moduleUnload();
		moduleBudgetObject->moduleUnload();
		this->moduleScreen->Visible = false;
		moduleCalendarObject->moduleLoad();
		this->Controls->Add(moduleCalendarObject);

	}

    // PRZYCISK KALENDARZ - ustawianie modu³ów
	private: System::Void buttonCalednarCheck_Click(System::Object^ sender, System::EventArgs^ e) {

		std::fstream plik;
		plik.open("conf.txt");

		if (plik.good()) {

			if (moduleConfigurationTable[0] == 0) {

				moduleConfigurationTable[0] = 1;

				plik << 1;

			}
			else {

				moduleConfigurationTable[0] = 0;

				plik << 0;

			}

		}
		else {

			exit(0);

		}

		Form1_Load_();
		ModuleChange_Load();

	}

	// PRZYCISK LISTA ZADAN
	private: System::Void buttonList_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->moduleChange->Visible = false;
		moduleCalendarObject->moduleUnload();
		moduleNotesObject->moduleUnload();
		moduleTasksObject->moduleLoad();
		this->moduleScreen->Visible = false;
		moduleBudgetObject->moduleUnload();
		this->Controls->Add(moduleTasksObject);

	}

	// PRZYCISK LISTA ZADAN - ustawianie modu³ów
	private: System::Void buttonListCheck_Click(System::Object^ sender, System::EventArgs^ e) {

		std::fstream plik;
		plik.open("conf.txt");

		if (plik.good()) {

			if (moduleConfigurationTable[1] == 0) {

				moduleConfigurationTable[1] = 1;

				plik << moduleConfigurationTable[0] << std::endl;
				plik << 1;

			}
			else {

				moduleConfigurationTable[1] = 0;

				plik << moduleConfigurationTable[0] << std::endl;
				plik << 0;

			}

		}
		else {

			exit(0);

		}

		Form1_Load_();
		ModuleChange_Load();

	}
	
	// PRZYCISK NOTATKI
	private: System::Void buttonNotes_Click(System::Object^ sender, System::EventArgs^ e) {

		this->moduleChange->Visible = false;
		moduleCalendarObject->moduleUnload();
		moduleBudgetObject->moduleUnload();
		moduleTasksObject->moduleUnload();
		this->moduleScreen->Visible = false;
		moduleNotesObject->moduleLoad();
		this->Controls->Add(moduleNotesObject);

	}

	// PRZYCISK NOTATKI - ustawianie modu³ów
	private: System::Void buttonNotesCheck_Click(System::Object^ sender, System::EventArgs^ e) {
	
		std::fstream plik;
		plik.open("conf.txt");

		if (plik.good()) {

			if (moduleConfigurationTable[2] == 0) {

				moduleConfigurationTable[2] = 1;

				plik << moduleConfigurationTable[0] << std::endl;
				plik << moduleConfigurationTable[1] << std::endl;
				plik << 1;

			}
			else {

				moduleConfigurationTable[2] = 0;

				plik << moduleConfigurationTable[0] << std::endl;
				plik << moduleConfigurationTable[1] << std::endl;
				plik << 0;

			}

		}
		else {

			exit(0);

		}

		Form1_Load_();
		ModuleChange_Load();

	}

	// PRZYCISK BUD¯ET
	private: System::Void buttonBudget_Click(System::Object^ sender, System::EventArgs^ e) {

		this->moduleChange->Visible = false;
		moduleCalendarObject->moduleUnload();
		moduleNotesObject->moduleUnload();
		moduleTasksObject->moduleUnload();
		this->moduleScreen->Visible = false;
		moduleBudgetObject->moduleLoad();
		this->Controls->Add(moduleBudgetObject);

	}

	// PRZYCISK BUD¯ET - ustawianie modu³ów
	private: System::Void buttonBudgetCheck_Click(System::Object^ sender, System::EventArgs^ e) {

		std::fstream plik;
		plik.open("conf.txt");

		if (plik.good()) {

			if (moduleConfigurationTable[3] == 0) {

				moduleConfigurationTable[3] = 1;

				plik << moduleConfigurationTable[0] << std::endl;
				plik << moduleConfigurationTable[1] << std::endl;
				plik << moduleConfigurationTable[2] << std::endl;
				plik << 1;

			}
			else {

				moduleConfigurationTable[3] = 0;

				plik << moduleConfigurationTable[0] << std::endl;
				plik << moduleConfigurationTable[1] << std::endl;
				plik << moduleConfigurationTable[2] << std::endl;
				plik << 0;

			}

		}
		else {

			exit(0);

		}

		Form1_Load_();
		ModuleChange_Load();

	}

	// PRZYCISK ORGANIZER
	private: System::Void buttonMain_Click(System::Object^ sender, System::EventArgs^ e) {

		this->moduleChange->Visible = false;
		moduleCalendarObject->moduleUnload();
		moduleNotesObject->moduleUnload();
		moduleTasksObject->moduleUnload();
		moduleBudgetObject->moduleUnload();
		this->moduleScreen->Visible = true;

		ModuleScreen_Load();

	}

	// PRZYCISK ZARZ¥DZANIA MODU£AMI
	private: System::Void buttonModuleChange_Click(System::Object^ sender, System::EventArgs^ e) {

		this->moduleChange->Visible = true;
		moduleCalendarObject->moduleUnload();
		moduleNotesObject->moduleUnload();
		moduleTasksObject->moduleUnload();
		moduleBudgetObject->moduleUnload();
		this->moduleScreen->Visible = false;

		ModuleChange_Load();

	}

	// £ADOWANIE OKNA Z MODU£AMI
	private: System::Void ModuleScreen_Load() {

		moduleScreen->Controls->Clear();

		for (size_t i = 0; i < 4; i++)
		{
			
			System::Windows::Forms::FlowLayoutPanel^ a = gcnew System::Windows::Forms::FlowLayoutPanel();

			a->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			a->Location = System::Drawing::Point(300, 0);
			a->Name = "Module" + i.ToString();
			a->Size = System::Drawing::Size(480, 360);
			a->Visible = true;

			moduleScreen->Controls->Add(a);

			System::Windows::Forms::Label^ b = gcnew System::Windows::Forms::Label();

			if (moduleConfigurationTable[i] == 1) {

				a->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
					static_cast<System::Int32>(static_cast<System::Byte>(45)));
				b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;

			}
			else {

				a->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
					static_cast<System::Int32>(static_cast<System::Byte>(40)));
				b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
					static_cast<System::Int32>(static_cast<System::Byte>(60)));

			}

			b->Text = getModuleNameFromNumber(i);
			b->Font = (gcnew System::Drawing::Font(L"Roboto", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			b->Size = System::Drawing::Size(480, 60);

			a->Controls->Add(b);

		}

		if(moduleConfigurationTable[0] == 1) { Calendar_Load(); }
		if(moduleConfigurationTable[1] == 1) { List_Load(); }
		if (moduleConfigurationTable[2] == 1) { Notes_Load(); }
		if (moduleConfigurationTable[3] == 1) { Budget_Load(); }

		Notification_Load();

	}

	// £ADOWANIE OKNA ZARZADZANIA MODULAMI
	private: System::Void ModuleChange_Load() {

		moduleChange->Controls->Clear();

		System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

		l->Font = (gcnew System::Drawing::Font(L"Roboto", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		l->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		l->Size = System::Drawing::Size(980, 120);
		l->Text = L"Zarz¹dzaj modu³ami";
		l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

		this->moduleChange->Controls->Add(l);

		l = gcnew System::Windows::Forms::Label();

		l->Font = (gcnew System::Drawing::Font(L"Roboto", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		l->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		l->Size = System::Drawing::Size(980, 120);
		l->Text = L"Naciœnij dwukrotnie, aby w³¹czyæ lub wy³¹czyæ modu³.";
		l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

		this->moduleChange->Controls->Add(l);

		System::Windows::Forms::Button^ b = gcnew System::Windows::Forms::Button();

		b->Name = "kalendarzCheck";
		b->Text = "KALENDARZ";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		b->Click += gcnew System::EventHandler(this, &Form1::buttonCalednarCheck_Click);
		if (moduleConfigurationTable[0] == 1) {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}
		else {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		}
		b->Size = System::Drawing::Size(980, 75);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;

		this->moduleChange->Controls->Add(b);

		b = gcnew System::Windows::Forms::Button();

		b->Name = "listazadanCheck";
		b->Text = "LISTA ZADAÑ";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		b->Click += gcnew System::EventHandler(this, &Form1::buttonListCheck_Click);
		if (moduleConfigurationTable[1] == 1) {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}
		else {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		}
		b->Size = System::Drawing::Size(980, 75);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;

		this->moduleChange->Controls->Add(b);

		b = gcnew System::Windows::Forms::Button();

		b->Name = "notatkiCheck";
		b->Text = "NOTATKI";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		b->Click += gcnew System::EventHandler(this, &Form1::buttonNotesCheck_Click);
		if (moduleConfigurationTable[2] == 1) {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}
		else {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		}
		b->Size = System::Drawing::Size(980, 75);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;

		this->moduleChange->Controls->Add(b);

		b = gcnew System::Windows::Forms::Button();

		b->Name = "budzetCheck";
		b->Text = "BUD¯ET";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		b->Click += gcnew System::EventHandler(this, &Form1::buttonBudgetCheck_Click);
		if (moduleConfigurationTable[3] == 1) {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		}
		else {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		}
		b->Size = System::Drawing::Size(980, 75);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;

		this->moduleChange->Controls->Add(b);

	}

	// £ADOWANIE PRZYCISKÓW EKRAN G£ÓWNY
	private: System::Void Form1_Load_Buttons() {

		mainScreen->Controls->Clear();

		System::Windows::Forms::Button^ b = gcnew System::Windows::Forms::Button();

		b->Name = "mainScreen";
		b->Text = "ORGANIZER";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 30, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		b->Size = System::Drawing::Size(300, 210);
		b->Location = System::Drawing::Point(0, 0);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		b->Click += gcnew System::EventHandler(this, &Form1::buttonMain_Click);

		mainScreen->Controls->Add(b);

		b = gcnew System::Windows::Forms::Button();

		b->Name = "kalendarz";
		b->Text = "KALENDARZ";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		if (moduleConfigurationTable[0] == 1) {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			b->Click += gcnew System::EventHandler(this, &Form1::buttonCalednar_Click);
		}
		else {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		}
		b->Size = System::Drawing::Size(300, 75);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;

		mainScreen->Controls->Add(b);

		b = gcnew System::Windows::Forms::Button();

		b->Name = "lista_zadan";
		b->Text = "LISTA ZADAÑ";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		if (moduleConfigurationTable[1] == 1) {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			b->Click += gcnew System::EventHandler(this, &Form1::buttonList_Click);
		}
		else {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		}
		b->Size = System::Drawing::Size(300, 75);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;

		mainScreen->Controls->Add(b);

		b = gcnew System::Windows::Forms::Button();

		b->Name = "notatki";
		b->Text = "NOTATKI";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		if (moduleConfigurationTable[2] == 1) {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			b->Click += gcnew System::EventHandler(this, &Form1::buttonNotes_Click);
		}
		else {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		}
		b->Size = System::Drawing::Size(300, 75);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;

		mainScreen->Controls->Add(b);

		b = gcnew System::Windows::Forms::Button();

		b->Name = "budzet";
		b->Text = "BUD¯ET";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		if (moduleConfigurationTable[3] == 1) {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			b->Click += gcnew System::EventHandler(this, &Form1::buttonBudget_Click);
		}
		else {
			b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			b->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
		}
		b->Size = System::Drawing::Size(300, 75);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;

		mainScreen->Controls->Add(b);

		b = gcnew System::Windows::Forms::Button();

		b->Name = "moduleChange";
		b->Text = "ZARZ¥DZAJ MODU£AMI";
		b->Font = (gcnew System::Drawing::Font(L"ROBOTO", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		b->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		b->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		b->Size = System::Drawing::Size(300, 210);
		b->Margin = System::Windows::Forms::Padding(0);
		b->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		b->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		b->Click += gcnew System::EventHandler(this, &Form1::buttonModuleChange_Click);

		mainScreen->Controls->Add(b);


	}

	// £ADOWANIE MODU£U KALENDARZ - EKRAN G£ÓWNY
	private: System::Void Calendar_Load() {

		databaseSelect.selectDataCalednar();

		DateTime todayDate = System::DateTime::Now;
		int year = todayDate.Year;
		int month = todayDate.Month;
		int day = todayDate.Day;
		std::string date = std::to_string(day) + std::to_string(month) + std::to_string(year);
		std::string dateShow = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
		std::cout << date;

		bool flag = 0;

		System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

		System::Windows::Forms::FlowLayoutPanel^ p = (System::Windows::Forms::FlowLayoutPanel^)moduleScreen->Controls->Find(L"Module0", true)[0];

		l->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		l->Size = System::Drawing::Size(480, 50);

		l->Text = msclr::interop::marshal_as<String^>(dateShow);

		p->Controls->Add(l);

		for (size_t i = 0; i < databaseSelect.dataCalendar.id.size(); i++)
		{

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 30);

			if (databaseSelect.dataCalendar.date_col[i] == date) {

				std::string final_str = databaseSelect.dataCalendar.hourS_col[i] + " : " + databaseSelect.dataCalendar.hourF_col[i] + " - " + databaseSelect.dataCalendar.event[i];
				
				l->Text = msclr::interop::marshal_as<String^>(final_str);

				p->Controls->Add(l);

				flag = 1;

			}
		}

		if (!flag) {

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 15, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 200);

			l->Text = L"Brak wydarzeñ na dzisiaj!";

			p->Controls->Add(l);

		}

	}

	// £ADOWANIE MODU£U LISTA ZADAÑ - EKRAN G£ÓWNY
	private: System::Void List_Load() {

		databaseSelect.selectDataTasks();

		System::Windows::Forms::FlowLayoutPanel^ p = (System::Windows::Forms::FlowLayoutPanel^)moduleScreen->Controls->Find(L"Module1", true)[0];

		System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

		bool flag = 0;

		std::string forbiddenText = "AAnewlistAA";

		for (size_t i = 0; i < databaseSelect.dataTasks.id.size(); i++)
		{

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 30);

			if (databaseSelect.dataTasks.inMain[i] == 1 && databaseSelect.dataTasks.task[i] != forbiddenText) {

				std::string final_str = databaseSelect.dataTasks.list[i] + ":   " + databaseSelect.dataTasks.task[i];

				switch (databaseSelect.dataTasks.priority[i]) {
					case 1: l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
						static_cast<System::Int32>(static_cast<System::Byte>(0)));
						break;
					case 2: l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
						static_cast<System::Int32>(static_cast<System::Byte>(0)));
						break;
					case 3: l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
						static_cast<System::Int32>(static_cast<System::Byte>(0)));
						break;
				}
				
				l->Text = msclr::interop::marshal_as<String^>(final_str);

				p->Controls->Add(l);

				flag = 1;

			}
		}

		if (!flag) {

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 15, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 200);

			l->Text = L"Brak zadañ dodanych do ekranu g³ównego!";

			p->Controls->Add(l);

		}

	}

	// £ADOWANIE MODU£U NOTATKI - EKRAN G£ÓWNY
	private: System::Void Notes_Load() {

		databaseSelect.selectDataNotes();

		System::Windows::Forms::FlowLayoutPanel^ p = (System::Windows::Forms::FlowLayoutPanel^)moduleScreen->Controls->Find(L"Module2", true)[0];

		System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

		bool flag = 0;

		int x = 1;
		if (databaseSelect.dataNotes.id.empty()) { x = 0; }
		else { x = databaseSelect.dataNotes.id.size(); }
		
		for (size_t i = 0; i < x; i++)
		{

			if (databaseSelect.dataNotes.inMain[i] == 1) {

				l = gcnew System::Windows::Forms::Label();

				l->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				l->Size = System::Drawing::Size(480, 50);
				l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
					static_cast<System::Int32>(static_cast<System::Byte>(250)));

				std::string final_str = databaseSelect.dataNotes.title[i];

				l->Text = msclr::interop::marshal_as<String^>(final_str);

				p->Controls->Add(l);

				l = gcnew System::Windows::Forms::Label();

				l->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(238)));
				l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				l->Size = System::Drawing::Size(480, 180);
				l->ForeColor = System::Drawing::SystemColors::HighlightText;

				final_str = databaseSelect.dataNotes.text[i];

				l->Text = msclr::interop::marshal_as<String^>(final_str);

				p->Controls->Add(l);

				flag = 1;

			}
		}

		if (!flag) {

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 15, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 200);

			l->Text = L"Brak notatek dodanych do ekranu g³ównego!";

			p->Controls->Add(l);

		}

	}

	// £ADOWANIE MODU£U BUD¯ET - EKRAN G£ÓWNY
	private: System::Void Budget_Load() {

		databaseSelect.selectDataBudget();

		System::Windows::Forms::FlowLayoutPanel^ p = (System::Windows::Forms::FlowLayoutPanel^)moduleScreen->Controls->Find(L"Module3", true)[0];

		System::Windows::Forms::Label^ l = gcnew System::Windows::Forms::Label();

		DateTime todayDate = System::DateTime::Now;
		int year = todayDate.Year;
		int month = todayDate.Month;
		std::string date = std::to_string(month) + std::to_string(year);
		std::string dateShow = std::to_string(month) + "." + std::to_string(year);
		std::cout << date;

		l->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		l->Size = System::Drawing::Size(480, 50);

		l->Text = msclr::interop::marshal_as<String^>(dateShow);

		p->Controls->Add(l);

		bool flag = 0;

		int income = 0, outcome = 0;

		for (size_t i = 0; i < databaseSelect.dataBudget.id.size(); i++)
		{

			if (databaseSelect.dataBudget.date_col[i] == date) {

				income += databaseSelect.dataBudget.income[i];
				outcome += databaseSelect.dataBudget.outcome[i];

				flag = 1;

			}
		}

		if (flag) {

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 50);
			l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));

			l->Text = "Przychód: " + income.ToString();

			p->Controls->Add(l);

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 50);
			l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));

			l->Text = "Wydatki: " + outcome.ToString();

			p->Controls->Add(l);

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 100);

			if (income > outcome) {
				l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
			}
			else if (outcome > income) {
				l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(175)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
					static_cast<System::Int32>(static_cast<System::Byte>(0)));
			}
			else {
				l->ForeColor = System::Drawing::SystemColors::HighlightText;
			}

			l->Text = "Bilans: " + (income - outcome).ToString();

			p->Controls->Add(l);

		}

		if (!flag) {

			l = gcnew System::Windows::Forms::Label();

			l->Font = (gcnew System::Drawing::Font(L"Roboto", 15, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			l->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(250)));
			l->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			l->Size = System::Drawing::Size(480, 200);

			l->Text = L"Brak wydatków i przychodów w tym miesi¹cu!";

			p->Controls->Add(l);

		}

	}

	// £ADOWANIE MODU£U POWIADOMIEÑ
	private: System::Void Notification_Load() {

		databaseSelect.selectDataCalednar();

		DateTime todayDate = System::DateTime::Now;

		int activeMonth = todayDate.Month;
		int activeYear = todayDate.Year;
		int activeDay = todayDate.Day;

		for (size_t i = 0; i < databaseSelect.dataCalendar.id.size(); i++)
		{
			std::string date = std::to_string(todayDate.Day) + std::to_string(todayDate.Month) + std::to_string(todayDate.Year);

			if (date == databaseSelect.dataCalendar.date_col[i] && databaseSelect.dataCalendar.notification[i] == 1) {

				String^ message = "Masz powiadomienie!\nW godzinach "
					+ msclr::interop::marshal_as<String^>(databaseSelect.dataCalendar.hourS_col[i])
					+ "-" + msclr::interop::marshal_as<String^>(databaseSelect.dataCalendar.hourF_col[i])
					+ " " + msclr::interop::marshal_as<String^>(databaseSelect.dataCalendar.event[i]);

				MessageBeep(0x00000040L);
				MessageBox::Show(message);

			}

		}

	}

	};
}
