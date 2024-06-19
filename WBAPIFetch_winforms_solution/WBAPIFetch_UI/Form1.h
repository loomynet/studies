#pragma once

namespace CppCLRWinFormsProject 
{

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

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

        private: System::Windows::Forms::Button^ button2;
        private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
        private: System::Windows::Forms::Label^ label1;
        private: System::Windows::Forms::CheckedListBox^ checkedListBox2;
        private: System::Windows::Forms::Label^ label2;
        private: System::Windows::Forms::Button^ button1;
        private: System::Windows::Forms::TextBox^ textBox1;
        private: System::Windows::Forms::Label^ label3;
        private: System::Windows::Forms::ToolTip^ toolTip1;
        private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
        private: System::Windows::Forms::TextBox^ textBox2;
        private: System::Windows::Forms::Label^ label4;
        private: System::Windows::Forms::Button^ button3;
        private: System::ComponentModel::IContainer^ components;
        
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(144, 482);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(312, 73);
            this->button2->TabIndex = 1;
            this->button2->Text = L"Fetch!";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
            // 
            // checkedListBox1
            // 
            this->checkedListBox1->FormattingEnabled = true;
            this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
                L"USA", L"RUS", L"CAN", L"BRA", L"IND", L"CHN",
                    L"AUS"
            });
            this->checkedListBox1->Location = System::Drawing::Point(35, 87);
            this->checkedListBox1->Name = L"checkedListBox1";
            this->checkedListBox1->Size = System::Drawing::Size(256, 116);
            this->checkedListBox1->TabIndex = 4;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(70, 59);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(180, 25);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Choose countries";
            // 
            // checkedListBox2
            // 
            this->checkedListBox2->FormattingEnabled = true;
            this->checkedListBox2->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
                L"GDP Growth", L"Unemployment", L"Inflation",
                    L"Gov Debt", L"Current Account Balance", L"FDI Net Inflows", L"PPP Conversion Factor"
            });
            this->checkedListBox2->Location = System::Drawing::Point(313, 87);
            this->checkedListBox2->Name = L"checkedListBox2";
            this->checkedListBox2->Size = System::Drawing::Size(252, 116);
            this->checkedListBox2->TabIndex = 6;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(348, 59);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(185, 25);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Choose indicators";
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6));
            this->button1->Location = System::Drawing::Point(529, 209);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(36, 32);
            this->button1->TabIndex = 8;
            this->button1->Text = L"\?";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(35, 283);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(256, 30);
            this->textBox1->TabIndex = 9;
            this->toolTip1->SetToolTip(this->textBox1, L"e.g. 2000-2020 (max range is 1980-2020)");
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(70, 255);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(183, 25);
            this->label3->TabIndex = 10;
            this->label3->Text = L"Enter years range";
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(313, 283);
            this->textBox2->Multiline = true;
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(256, 30);
            this->textBox2->TabIndex = 11;
            this->toolTip1->SetToolTip(this->textBox2, L"Choose the folder to save the file");
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(348, 255);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(201, 25);
            this->label4->TabIndex = 12;
            this->label4->Text = L"Choose file location";
            // 
            // button3
            // 
            this->button3->Location = System::Drawing::Point(529, 278);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(46, 40);
            this->button3->TabIndex = 13;
            this->button3->Text = L"...";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(601, 567);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->checkedListBox2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->checkedListBox1);
            this->Controls->Add(this->button2);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
        private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
        private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
    };
}