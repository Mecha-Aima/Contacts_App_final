#pragma once
#include "ContactList.h"
namespace ContactsApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for History
	/// </summary>
	public ref class History : public System::Windows::Forms::Form
	{
	public:
		History(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~History()
		{
			if (components)
			{
				delete components;
				
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::PictureBox^ back;
	private: System::Windows::Forms::Label^ heading;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(History::typeid));
			   this->heading = (gcnew System::Windows::Forms::Label());
			   this->back = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // heading
			   // 
			   this->heading->AutoSize = true;
			   this->heading->Font = (gcnew System::Drawing::Font(L"Montserrat ExtraBold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->heading->ForeColor = System::Drawing::Color::White;
			   this->heading->Location = System::Drawing::Point(232, 36);
			   this->heading->Name = L"heading";
			   this->heading->Size = System::Drawing::Size(226, 37);
			   this->heading->TabIndex = 23;
			   this->heading->Text = L"Search History";
			   // 
			   // back
			   // 
			   this->back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back.Image")));
			   this->back->Location = System::Drawing::Point(48, 51);
			   this->back->Name = L"back";
			   this->back->Size = System::Drawing::Size(27, 22);
			   this->back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->back->TabIndex = 24;
			   this->back->TabStop = false;
			   this->back->Click += gcnew System::EventHandler(this, &History::back_Click);
			   // 
			   // History
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoScroll = true;
			   this->BackColor = System::Drawing::Color::DarkSlateGray;
			   this->ClientSize = System::Drawing::Size(704, 441);
			   this->Controls->Add(this->back);
			   this->Controls->Add(this->heading);
			   this->Name = L"History";
			   this->Text = L"History";
			   this->Load += gcnew System::EventHandler(this, &History::History_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void History_Load(System::Object^ sender, System::EventArgs^ e) {

		display_history();
	}

		   System::Void display_history()
		   {
			   List<HistoryObject> history = sh->get_search_history();
			   for (int i = 0; i < history.size(); ++i)
			   {
				   // Create a new Panel control for each contact
				   Panel^ contactPanel = gcnew Panel();
				   contactPanel->BackColor = System::Drawing::Color::White;
				   contactPanel->Location = System::Drawing::Point(17, 130 + i * 120); // Adjust the Y position based on the index
				   contactPanel->Size = System::Drawing::Size(658, 104);
				   this->Controls->Add(contactPanel); // Add the panel to the form

				   // Create and configure PictureBox
				   PictureBox^ pictureBox = gcnew PictureBox();
				   pictureBox->Location = System::Drawing::Point(17, 22);
				   pictureBox->Size = System::Drawing::Size(48, 48);
				   pictureBox->SizeMode = PictureBoxSizeMode::Zoom;
				   pictureBox->ImageLocation = "user.png"; // Adjust the image location
				   contactPanel->Controls->Add(pictureBox); // Add PictureBox to the panel

				   // Create and configure Label for full name
				   Label^ fullNameLabel = gcnew Label();
				   fullNameLabel->AutoSize = true;
				   fullNameLabel->Font = gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0));
				   fullNameLabel->ForeColor = System::Drawing::Color::MidnightBlue;
				   fullNameLabel->Location = System::Drawing::Point(99, 22);
				   fullNameLabel->Text = gcnew String((history[i].get_contact().get_first_name() + " " + history[i].get_contact().get_last_name()).c_str());
				   contactPanel->Controls->Add(fullNameLabel); // Add Label to the panel

				   // Create and configure Label for time
				   Label^ TimeLabel = gcnew Label();
				   TimeLabel->AutoSize = true;
				   TimeLabel->Font = gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0));
				   TimeLabel->Location = System::Drawing::Point(99, 52);
				   TimeLabel->Text = gcnew String((to_string(history[i].get_time().get_hours()) + ":" + to_string(history[i].get_time().get_minutes()) + ":" + to_string(history[i].get_time().get_seconds())).c_str()); // Assuming get_mobile_number() returns a string
				   contactPanel->Controls->Add(TimeLabel); // Add Label to the panel

				   // Create and configure label for date
				   Label^ DateLabel = gcnew Label();
				   DateLabel->AutoSize = true;
				   DateLabel->Font = gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					   static_cast<System::Byte>(0));
				   DateLabel->Location = System::Drawing::Point(99, 70);
				   DateLabel->Text = gcnew String((to_string(history[i].get_date().get_year()) + "/" + to_string(history[i].get_date().get_month()) + "/" + to_string(history[i].get_date().get_day())).c_str()); // Assuming get_mobile_number() returns a string
				   contactPanel->Controls->Add(DateLabel); // Add Label to the panel
			   }
		   }


	private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
		History::Close();
	}
};
}