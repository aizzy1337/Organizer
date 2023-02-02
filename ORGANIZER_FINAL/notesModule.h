#pragma once
//FORM - MODU£ NOTATEK

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

public ref class moduleNotes : public System::Windows::Forms::FlowLayoutPanel {

public:

	moduleNotes(void)
	{
		InitializeComponent();
	}

protected:

	~moduleNotes()
	{
		if (components)
		{
			delete components;
		}
	}

	//DEKLARACJA OBIEKTÓW
private:

	System::Windows::Forms::FlowLayoutPanel^ listNotes;
	System::Windows::Forms::FlowLayoutPanel^ pickedNote;
	System::Windows::Forms::FlowLayoutPanel^ addButtonPanel;
	System::Windows::Forms::FlowLayoutPanel^ modifyButtonPanel;
	System::ComponentModel::Container^ components;
	int activeNote = -1;

	void InitializeComponent(void)
	{

		//	INICJALIZACJA OBIEKTÓW

		this->listNotes = (gcnew System::Windows::Forms::FlowLayoutPanel());
		this->pickedNote = (gcnew System::Windows::Forms::FlowLayoutPanel());
		this->addButtonPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
		this->modifyButtonPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());

		this->addButtonPanel->SuspendLayout();
		this->modifyButtonPanel->SuspendLayout();
		this->listNotes->SuspendLayout();
		this->pickedNote->SuspendLayout();
		this->SuspendLayout();

		//	CALY LAYOUT NOTATEK
		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
		this->Location = System::Drawing::Point(300, 0);
		this->Name = L"mainScreenNotes";
		this->Size = System::Drawing::Size(980, 720);
		this->TabIndex = 0;
		this->Visible = false;

		//	LAYOUT LISTNOTES
		this->listNotes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(40)));
		this->listNotes->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->listNotes->Location = System::Drawing::Point(300, 0);
		this->listNotes->Name = L"listNotes";
		this->listNotes->Size = System::Drawing::Size(400, 720);
		this->listNotes->TabIndex = 1;
		this->listNotes->Visible = false;

		//	LAYOUT PICKEDNOTE
		this->pickedNote->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->pickedNote->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->pickedNote->Location = System::Drawing::Point(900, 0);
		this->pickedNote->Name = L"pickedNote";
		this->pickedNote->Size = System::Drawing::Size(568, 720);
		this->pickedNote->TabIndex = 2;
		this->pickedNote->Visible = false;

		// ADD LAYOUT
		this->addButtonPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->addButtonPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->addButtonPanel->Location = System::Drawing::Point(900, 0);
		this->addButtonPanel->Name = L"addButtonPanel";
		this->addButtonPanel->Size = System::Drawing::Size(568, 720);
		this->addButtonPanel->TabIndex = 3;
		this->addButtonPanel->Visible = false;

		System::Windows::Forms::Label^ labelNoteName = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ noteName = (gcnew System::Windows::Forms::TextBox());
		System::Windows::Forms::Label^ labelText = (gcnew System::Windows::Forms::Label());
		System::Windows::Forms::TextBox^ text = (gcnew System::Windows::Forms::TextBox());
		System::Windows::Forms::RadioButton^ inMain = (gcnew System::Windows::Forms::RadioButton());

		labelNoteName->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelNoteName->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelNoteName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelNoteName->Size = System::Drawing::Size(568, 50);
		labelNoteName->Text = L"Podaj nazwê notatki";

		noteName->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		noteName->Name = L"noteName";
		noteName->Size = System::Drawing::Size(568, 100);
		noteName->TabIndex = 0;

		labelText->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelText->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelText->Size = System::Drawing::Size(568, 50);
		labelText->Text = L"Wpisz treœæ notatki";

		text->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		text->Name = L"text";
		text->Size = System::Drawing::Size(568, 300);
		text->TabIndex = 0;

		inMain->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		inMain->ForeColor = System::Drawing::SystemColors::HighlightText;
		inMain->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		inMain->Size = System::Drawing::Size(568, 100);
		inMain->Name = L"inMain";
		inMain->Text = L"Czy chcesz, aby notatka wyœwietla³a siê na ekranie g³ównym?";

		addButtonPanel->Controls->Add(labelNoteName);
		addButtonPanel->Controls->Add(noteName);
		addButtonPanel->Controls->Add(labelText);
		addButtonPanel->Controls->Add(text);
		addButtonPanel->Controls->Add(inMain);

		System::Windows::Forms::Button^ addNoteButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ addNoteButtonBack = gcnew System::Windows::Forms::Button();

		addNoteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addNoteButton->Name = L"addButtonPanel";
		addNoteButton->Size = System::Drawing::Size(568, 50);
		addNoteButton->Text = L"Dodaj";
		addNoteButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addNoteButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addNoteButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addNoteButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addNoteButton->Click += gcnew System::EventHandler(this, &moduleNotes::checkInputAdd);

		addNoteButtonBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addNoteButtonBack->Name = L"addNoteButtonBack";
		addNoteButtonBack->Size = System::Drawing::Size(568, 50);
		addNoteButtonBack->Text = L"Powrót";
		addNoteButtonBack->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addNoteButtonBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addNoteButtonBack->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addNoteButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addNoteButtonBack->Click += gcnew System::EventHandler(this, &moduleNotes::addNoteButtonBack_Click);

		addButtonPanel->Controls->Add(addNoteButton);
		addButtonPanel->Controls->Add(addNoteButtonBack);

		addButtonPanel->Visible = false;

		// MODIFY LAYOUT
		this->modifyButtonPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(60)));
		this->modifyButtonPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
		this->modifyButtonPanel->Location = System::Drawing::Point(900, 0);
		this->modifyButtonPanel->Name = L"modifyButtonPanel";
		this->modifyButtonPanel->Size = System::Drawing::Size(568, 720);
		this->modifyButtonPanel->TabIndex = 4;
		this->modifyButtonPanel->Visible = false;

		labelNoteName = (gcnew System::Windows::Forms::Label());
		noteName = (gcnew System::Windows::Forms::TextBox());
		labelText = (gcnew System::Windows::Forms::Label());
		text = (gcnew System::Windows::Forms::TextBox());
		inMain = (gcnew System::Windows::Forms::RadioButton());

		labelNoteName->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelNoteName->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelNoteName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelNoteName->Size = System::Drawing::Size(568, 50);
		labelNoteName->Text = L"Podaj nazwê notatki";

		noteName->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		noteName->Name = L"noteName2";
		noteName->Size = System::Drawing::Size(568, 100);
		noteName->TabIndex = 0;

		labelText->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		labelText->ForeColor = System::Drawing::SystemColors::HighlightText;
		labelText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		labelText->Size = System::Drawing::Size(568, 50);
		labelText->Text = L"Wpisz treœæ notatki";

		text->Font = (gcnew System::Drawing::Font(L"Calibri", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		text->Name = L"text2";
		text->Size = System::Drawing::Size(568, 300);
		text->TabIndex = 0;

		inMain->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		inMain->ForeColor = System::Drawing::SystemColors::HighlightText;
		inMain->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		inMain->Size = System::Drawing::Size(568, 100);
		inMain->Name = L"inMain2";
		inMain->Text = L"Czy chcesz, aby notatka wyœwietla³a siê na ekranie g³ównym?";

		modifyButtonPanel->Controls->Add(labelNoteName);
		modifyButtonPanel->Controls->Add(noteName);
		modifyButtonPanel->Controls->Add(labelText);
		modifyButtonPanel->Controls->Add(text);
		modifyButtonPanel->Controls->Add(inMain);

		System::Windows::Forms::Button^ modifyNoteButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ modifyNoteButtonBack = gcnew System::Windows::Forms::Button();

		modifyNoteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		modifyNoteButton->Name = L"modifyNoteButton";
		modifyNoteButton->Size = System::Drawing::Size(568, 50);
		modifyNoteButton->Text = L"Edytuj";
		modifyNoteButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyNoteButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyNoteButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyNoteButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyNoteButton->Click += gcnew System::EventHandler(this, &moduleNotes::checkInputModify);

		modifyNoteButtonBack->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		modifyNoteButtonBack->Name = L"modifyNoteButtonBack";
		modifyNoteButtonBack->Size = System::Drawing::Size(568, 50);
		modifyNoteButtonBack->Text = L"Powrót";
		modifyNoteButtonBack->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyNoteButtonBack->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyNoteButtonBack->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyNoteButtonBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyNoteButtonBack->Click += gcnew System::EventHandler(this, &moduleNotes::modifyNoteButtonBack_Click);

		modifyButtonPanel->Controls->Add(modifyNoteButton);
		modifyButtonPanel->Controls->Add(modifyNoteButtonBack);

		modifyButtonPanel->Visible = false;

		//	DODANIE DO GLOWNEGO LAYOUTU
		this->Controls->Add(this->listNotes);
		this->Controls->Add(this->pickedNote);
		this->Controls->Add(this->addButtonPanel);
		this->Controls->Add(this->modifyButtonPanel);
		this->addButtonPanel->ResumeLayout(false);
		this->modifyButtonPanel->ResumeLayout(false);
		this->listNotes->ResumeLayout(false);
		this->pickedNote->ResumeLayout(false);
		this->ResumeLayout(false);

	}

public:
	
	void moduleLoad() {

		listNotes->Visible = true;
		pickedNote->Visible = true;
		this->Visible = true;

		listNotesLoad();
		pickedNoteLoad();

	}

	void moduleUnload() {

		listNotes->Visible = false;
		pickedNote->Visible = false;
		this->Visible = false;

	}

	void listNotesLoad() {

		listNotes->Controls->Clear();

		System::Windows::Forms::Label^ listNotesLabel = gcnew System::Windows::Forms::Label();

		listNotesLabel->Font = (gcnew System::Drawing::Font(L"Roboto", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		listNotesLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		listNotesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		listNotesLabel->Size = System::Drawing::Size(400, 150);
		listNotesLabel->Text = L"Lista notatek";

		listNotes->Controls->Add(listNotesLabel);

		databaseSelect.selectDataNotes();

		for (int i = 0; i < databaseSelect.dataNotes.id.size(); i++)
		{

			System::Windows::Forms::Button^ notes = gcnew System::Windows::Forms::Button();

			notes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			notes->Name = i.ToString();
			notes->Size = System::Drawing::Size(400, 50);
			notes->Text = msclr::interop::marshal_as<String^>(databaseSelect.dataNotes.title[i]);
			notes->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			notes->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			notes->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			notes->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			notes->Click += gcnew System::EventHandler(this, &moduleNotes::pickedNote_Click);

			listNotes->Controls->Add(notes);

		}


	}

	void pickedNote_Click(System::Object^ sender, System::EventArgs^ e) {

		Button^ clicked = (Button^)sender;
		activeNote = Int32::Parse(clicked->Name);
		pickedNoteLoad();

	}

	void pickedNoteLoad() {

		pickedNote->Controls->Clear();

		System::Windows::Forms::Label^ pickedNoteText = gcnew System::Windows::Forms::Label();

		pickedNoteText->Font = (gcnew System::Drawing::Font(L"Roboto", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		pickedNoteText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		pickedNoteText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		pickedNoteText->Size = System::Drawing::Size(568, 568);
		if (activeNote != -1) {
			pickedNoteText->Text = msclr::interop::marshal_as<String^>(databaseSelect.dataNotes.text[activeNote]);
		}

		pickedNote->Controls->Add(pickedNoteText);

		System::Windows::Forms::Button^ addButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ deleteButton = gcnew System::Windows::Forms::Button();
		System::Windows::Forms::Button^ modifyButton = gcnew System::Windows::Forms::Button();

		addButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		addButton->Name = L"addButton";
		addButton->Size = System::Drawing::Size(568, 35);
		addButton->Text = L"Dodaj notatkê";
		addButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		addButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		addButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		addButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		addButton->Click += gcnew System::EventHandler(this, &moduleNotes::addButton_Click);

		deleteButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		deleteButton->Name = L"deleteButton";
		deleteButton->Size = System::Drawing::Size(568, 35);
		deleteButton->Text = L"Usuñ notatkê";
		deleteButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		deleteButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		deleteButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		deleteButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		deleteButton->Click += gcnew System::EventHandler(this, &moduleNotes::deleteButton_Click);

		modifyButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(100)));
		modifyButton->Name = L"modifyButton";
		modifyButton->Size = System::Drawing::Size(568, 35);
		modifyButton->Text = L"Edytuj notatkê";
		modifyButton->Font = (gcnew System::Drawing::Font(L"ROBOTO", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		modifyButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		modifyButton->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		modifyButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		modifyButton->Click += gcnew System::EventHandler(this, &moduleNotes::modifyButton_Click);

		pickedNote->Controls->Add(addButton);
		pickedNote->Controls->Add(deleteButton);
		pickedNote->Controls->Add(modifyButton);

	}

	void addButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->addButtonPanel->Visible = true;
		this->pickedNote->Visible = false;

		pickedNoteLoad();

	}

	void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (activeNote != -1) {
			databaseDelete.deleteData(databaseSelect.dataNotes.id[activeNote], L"notes");
			activeNote = -1;
			moduleLoad();
		}
		else {
			MessageBox::Show("Nale¿y wybraæ notatkê!");
		}

	}

	void modifyButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (activeNote != -1) {
			
			this->modifyButtonPanel->Visible = true;
			this->pickedNote->Visible = false;

		}
		else {
			MessageBox::Show("Nale¿y wybraæ notatkê!");
		}

		pickedNoteLoad();

	}

	void addNoteButtonBack_Click(System::Object^ sender, System::EventArgs^ e) {

		this->addButtonPanel->Visible = false;
		this->pickedNote->Visible = true;

		pickedNoteLoad();

	}

	void modifyNoteButtonBack_Click(System::Object^ sender, System::EventArgs^ e) {

		this->modifyButtonPanel->Visible = false;
		this->pickedNote->Visible = true;

		pickedNoteLoad();

	}

	void checkInputAdd(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"addButtonPanel", true)[0];
		System::Windows::Forms::TextBox^ noteName = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"noteName", true)[0];
		System::Windows::Forms::TextBox^ text = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"text", true)[0];
		System::Windows::Forms::RadioButton^ inMain = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"inMain", true)[0];

		int flag = 0;

		if (noteName->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y nadaæ tytu³!");
		}

		if (text->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y wpisaæ tekst!");
		}

		if (flag == 2) {
			databaseInsert.insertData(
				msclr::interop::marshal_as<std::wstring>(noteName->Text),
				msclr::interop::marshal_as<std::wstring>(text->Text),
				inMain->Checked
			);
		}

		layout->Visible = false;

		moduleLoad();

	}

	void checkInputModify(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::FlowLayoutPanel^ layout = (System::Windows::Forms::FlowLayoutPanel^)this->Controls->Find(L"modifyButtonPanel", true)[0];
		System::Windows::Forms::TextBox^ noteName = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"noteName2", true)[0];
		System::Windows::Forms::TextBox^ text = (System::Windows::Forms::TextBox^)layout->Controls->Find(L"text2", true)[0];
		System::Windows::Forms::RadioButton^ inMain = (System::Windows::Forms::RadioButton^)layout->Controls->Find(L"inMain2", true)[0];

		int flag = 0;

		if (noteName->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y nadaæ tytu³!");
		}

		if (text->Text->Empty) {
			flag++;
		}
		else {
			MessageBox::Show("Nale¿y wpisaæ tekst!");
		}

		if (flag == 2) {
			databaseUpdate.updateData(
				databaseSelect.dataNotes.id[activeNote],
				msclr::interop::marshal_as<std::wstring>(noteName->Text),
				msclr::interop::marshal_as<std::wstring>(text->Text),
				inMain->Checked
			);
		}

		layout->Visible = false;

		moduleLoad();

	}

};