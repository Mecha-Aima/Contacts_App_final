#pragma once
#include "ContactsBook.h"
#include "Contact.h"
#include <iostream>

namespace ContactsApp {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Groups_form {
    private:
        ContactsBook* ptr;
        Button^ button1;
        Button^ buttonGoBack;
        Button^ buttonDeleteGroup;
        TextBox^ textBoxSearch;

    public:
        Groups_form(ContactsBook* b) {
            ptr = b;
            InitializeComponent();
        }

        Groups_form(Contact& contact) {
            // Initialize data members from contact
            id = contact.get_contact_id();
            f_name = gcnew String((contact.get_first_name() + " " + contact.get_last_name()).c_str());
            mobile_no = gcnew String(contact.get_mobile_number().c_str());
            email_id = gcnew String(contact.get_email_address().c_str());
            house = gcnew String(contact.get_address()->get_house().c_str());
            street = gcnew String(contact.get_address()->get_street().c_str());
            city_ = gcnew String(contact.get_address()->get_city().c_str());
            country_ = gcnew String(contact.get_address()->get_country().c_str());
            InitializeComponent();
        }

        void Display() {
            Console::WriteLine("Contact Details:");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("Name: " + f_name);
            Console::WriteLine("Mobile Number: " + mobile_no);
            Console::WriteLine("Email Address: " + email_id);
            Console::WriteLine("Address: " + house + ", " + street + ", " + city_ + ", " + country_);
        }

        void DeleteGroup() {
            Console::WriteLine("Are you sure you want to delete this group? (Yes/No)");
            String^ response = Console::ReadLine();
            if (response->ToLower() == "yes") {
                // Delete the group logic here
                // Example: Remove the group from the list of groups
                // groups->Remove(groupToDelete);
                Console::WriteLine("Group deleted successfully.");
            }
            else {
                Console::WriteLine("Deletion cancelled.");
            }
        }

    private:
        int id;
        String^ f_name;
        String^ mobile_no;
        String^ email_id;
        String^ house;
        String^ street;
        String^ city_;
        String^ country_;

        void InitializeComponent(void) {
            this->button1 = gcnew Button();
            this->buttonGoBack = gcnew Button();
            this->buttonDeleteGroup = gcnew Button();
            this->textBoxSearch = gcnew TextBox();
            this->textBoxSearch->SuspendLayout();

            // button1
            this->button1->Location = Drawing::Point(47, 12);
            this->button1->Name = L"button1";
            this->button1->Size = Drawing::Size(204, 42);
            this->button1->TabIndex = 0;
            this->button1->Text = L"Create Group";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew EventHandler(this, &Groups_form::button1_Click);

            // buttonGoBack
            this->buttonGoBack->BackColor = Drawing::Color::AliceBlue;
            this->buttonGoBack->Location = Drawing::Point(10, 10);
            this->buttonGoBack->Name = L"buttonGoBack";
            this->buttonGoBack->Size = Drawing::Size(30, 30);
            this->buttonGoBack->TabIndex = 3;
            this->buttonGoBack->Text = L"<";
            this->buttonGoBack->UseVisualStyleBackColor = true;
            this->buttonGoBack->Click += gcnew EventHandler(this, &Groups_form::buttonGoBack_Click);

            // buttonDeleteGroup
            this->buttonDeleteGroup->BackColor = Drawing::Color::AliceBlue;
            this->buttonDeleteGroup->Location = Drawing::Point(369, 12);
            this->buttonDeleteGroup->Name = L"buttonDeleteGroup";
            this->buttonDeleteGroup->Size = Drawing::Size(172, 42);
            this->buttonDeleteGroup->TabIndex = 1;
            this->buttonDeleteGroup->Text = L"Delete Group";
            this->buttonDeleteGroup->UseVisualStyleBackColor = true;
            this->buttonDeleteGroup->Click += gcnew EventHandler(this, &Groups_form::buttonDeleteGroup_Click);

            // textBoxSearch
            this->textBoxSearch->BackColor = Drawing::Color::AliceBlue;
            this->textBoxSearch->Location = Drawing::Point(47, 69);
            this->textBoxSearch->Name = L"textBoxSearch";
            this->textBoxSearch->Size = Drawing::Size(204, 22);
            this->textBoxSearch->TabIndex = 1;
            this->textBoxSearch->Visible = false;

            // Groups_form
            /*this->AutoScaleDimensions = Drawing::SizeF(8, 16);
            this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
            this->BackColor = Drawing::Color::AliceBlue;
            this->ClientSize = Drawing::Size(553, 411);
            this->Controls->Add(this->textBoxSearch);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->buttonGoBack);
            this->Controls->Add(this->buttonDeleteGroup);
            this->Name = L"Groups_form";
            this->Text = L"Groups_form";
            this->textBoxSearch->ResumeLayout(false);
            this->textBoxSearch->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();*/
        }

#pragma endregion

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            textBoxSearch->Visible = true;
        }

        System::Void buttonGoBack_Click(System::Object^ sender, System::EventArgs^ e) {
            textBoxSearch->Visible = false;
        }

        System::Void buttonDeleteGroup_Click(System::Object^ sender, System::EventArgs^ e) {
            // Prompt the user to confirm deletion
            Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to delete this group?", "Delete Group", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            // If user confirms, delete the group
            if (result == Windows::Forms::DialogResult::Yes) {
                // Delete the group logic here
                // Example: Remove the group from the list of groups
                // groups->Remove(groupToDelete);
            }
        }
    };
}
