#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtDisplay;
	protected:

	protected:

	private: System::Windows::Forms::Button^ btnPercent;
	private: System::Windows::Forms::Button^ btnCE;
	private: System::Windows::Forms::Button^ btnC;
	private: System::Windows::Forms::Button^ btnDel;
	private: System::Windows::Forms::Button^ btnDivide;

	protected:





	private: System::Windows::Forms::Button^ btnSqrt;

	private: System::Windows::Forms::Button^ btnPower;

	private: System::Windows::Forms::Button^ btnFraction;
	private: System::Windows::Forms::Button^ btnMult;



	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ btnMinus;

	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ btnPlus;

	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ btnEquals;

	private: System::Windows::Forms::Button^ btnDot;



	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ btnPlusMinus;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtDisplay = (gcnew System::Windows::Forms::TextBox());
			this->btnPercent = (gcnew System::Windows::Forms::Button());
			this->btnCE = (gcnew System::Windows::Forms::Button());
			this->btnC = (gcnew System::Windows::Forms::Button());
			this->btnDel = (gcnew System::Windows::Forms::Button());
			this->btnDivide = (gcnew System::Windows::Forms::Button());
			this->btnSqrt = (gcnew System::Windows::Forms::Button());
			this->btnPower = (gcnew System::Windows::Forms::Button());
			this->btnFraction = (gcnew System::Windows::Forms::Button());
			this->btnMult = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->btnMinus = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->btnPlus = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->btnEquals = (gcnew System::Windows::Forms::Button());
			this->btnDot = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->btnPlusMinus = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtDisplay
			// 
			this->txtDisplay->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->txtDisplay->Font = (gcnew System::Drawing::Font(L"Times New Roman", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDisplay->Location = System::Drawing::Point(12, 12);
			this->txtDisplay->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtDisplay->Multiline = true;
			this->txtDisplay->Name = L"txtDisplay";
			this->txtDisplay->Size = System::Drawing::Size(562, 85);
			this->txtDisplay->TabIndex = 0;
			this->txtDisplay->Text = L"0";
			this->txtDisplay->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txtDisplay->TextChanged += gcnew System::EventHandler(this, &Form1::txtDisplay_TextChanged);
			// 
			// btnPercent
			// 
			this->btnPercent->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btnPercent->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPercent->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnPercent->Location = System::Drawing::Point(12, 102);
			this->btnPercent->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnPercent->Name = L"btnPercent";
			this->btnPercent->Size = System::Drawing::Size(136, 90);
			this->btnPercent->TabIndex = 1;
			this->btnPercent->Text = L"%";
			this->btnPercent->UseVisualStyleBackColor = true;
			this->btnPercent->Click += gcnew System::EventHandler(this, &Form1::ArithmeticOP);
			// 
			// btnCE
			// 
			this->btnCE->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCE->Location = System::Drawing::Point(154, 102);
			this->btnCE->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnCE->Name = L"btnCE";
			this->btnCE->Size = System::Drawing::Size(136, 90);
			this->btnCE->TabIndex = 2;
			this->btnCE->Text = L"CE";
			this->btnCE->UseVisualStyleBackColor = true;
			this->btnCE->Click += gcnew System::EventHandler(this, &Form1::btnCE_Click);
			// 
			// btnC
			// 
			this->btnC->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnC->Location = System::Drawing::Point(296, 102);
			this->btnC->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnC->Name = L"btnC";
			this->btnC->Size = System::Drawing::Size(136, 90);
			this->btnC->TabIndex = 3;
			this->btnC->Text = L"C";
			this->btnC->UseVisualStyleBackColor = true;
			this->btnC->Click += gcnew System::EventHandler(this, &Form1::btnC_Click);
			// 
			// btnDel
			// 
			this->btnDel->Font = (gcnew System::Drawing::Font(L"Wingdings", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btnDel->Location = System::Drawing::Point(438, 102);
			this->btnDel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnDel->Name = L"btnDel";
			this->btnDel->Padding = System::Windows::Forms::Padding(0, 19, 0, 0);
			this->btnDel->Size = System::Drawing::Size(136, 90);
			this->btnDel->TabIndex = 4;
			this->btnDel->Text = L"";
			this->btnDel->UseVisualStyleBackColor = true;
			this->btnDel->Click += gcnew System::EventHandler(this, &Form1::btnDel_Click);
			// 
			// btnDivide
			// 
			this->btnDivide->Font = (gcnew System::Drawing::Font(L"Times New Roman", 19.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDivide->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnDivide->Location = System::Drawing::Point(438, 198);
			this->btnDivide->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnDivide->Name = L"btnDivide";
			this->btnDivide->Size = System::Drawing::Size(136, 90);
			this->btnDivide->TabIndex = 8;
			this->btnDivide->Text = L"÷";
			this->btnDivide->UseVisualStyleBackColor = true;
			this->btnDivide->Click += gcnew System::EventHandler(this, &Form1::ArithmeticOP);
			// 
			// btnSqrt
			// 
			this->btnSqrt->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSqrt->Location = System::Drawing::Point(296, 198);
			this->btnSqrt->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnSqrt->Name = L"btnSqrt";
			this->btnSqrt->Size = System::Drawing::Size(136, 90);
			this->btnSqrt->TabIndex = 7;
			this->btnSqrt->Text = L"sqrt";
			this->btnSqrt->UseVisualStyleBackColor = true;
			this->btnSqrt->Click += gcnew System::EventHandler(this, &Form1::ArithmeticOP);
			// 
			// btnPower
			// 
			this->btnPower->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPower->Location = System::Drawing::Point(154, 198);
			this->btnPower->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnPower->Name = L"btnPower";
			this->btnPower->Size = System::Drawing::Size(136, 90);
			this->btnPower->TabIndex = 6;
			this->btnPower->Text = L"x^2";
			this->btnPower->UseVisualStyleBackColor = true;
			this->btnPower->Click += gcnew System::EventHandler(this, &Form1::ArithmeticOP);
			// 
			// btnFraction
			// 
			this->btnFraction->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnFraction->Location = System::Drawing::Point(12, 198);
			this->btnFraction->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnFraction->Name = L"btnFraction";
			this->btnFraction->Size = System::Drawing::Size(136, 90);
			this->btnFraction->TabIndex = 5;
			this->btnFraction->Text = L"1/x";
			this->btnFraction->UseVisualStyleBackColor = true;
			this->btnFraction->Click += gcnew System::EventHandler(this, &Form1::ArithmeticOP);
			// 
			// btnMult
			// 
			this->btnMult->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMult->Location = System::Drawing::Point(436, 294);
			this->btnMult->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnMult->Name = L"btnMult";
			this->btnMult->Size = System::Drawing::Size(136, 90);
			this->btnMult->TabIndex = 12;
			this->btnMult->Text = L"×";
			this->btnMult->UseVisualStyleBackColor = true;
			this->btnMult->Click += gcnew System::EventHandler(this, &Form1::ArithmeticOP);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(296, 294);
			this->button10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(136, 90);
			this->button10->TabIndex = 11;
			this->button10->Text = L"9";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(152, 294);
			this->button11->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(136, 90);
			this->button11->TabIndex = 10;
			this->button11->Text = L"8";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(12, 294);
			this->button12->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(136, 90);
			this->button12->TabIndex = 9;
			this->button12->Text = L"7";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// btnMinus
			// 
			this->btnMinus->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMinus->Location = System::Drawing::Point(436, 390);
			this->btnMinus->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnMinus->Name = L"btnMinus";
			this->btnMinus->Size = System::Drawing::Size(136, 90);
			this->btnMinus->TabIndex = 16;
			this->btnMinus->Text = L"-";
			this->btnMinus->UseVisualStyleBackColor = true;
			this->btnMinus->Click += gcnew System::EventHandler(this, &Form1::ArithmeticOP);
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(296, 390);
			this->button14->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(136, 90);
			this->button14->TabIndex = 15;
			this->button14->Text = L"6";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(154, 390);
			this->button15->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(136, 90);
			this->button15->TabIndex = 14;
			this->button15->Text = L"5";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(12, 390);
			this->button16->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(136, 90);
			this->button16->TabIndex = 13;
			this->button16->Text = L"4";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// btnPlus
			// 
			this->btnPlus->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlus->Location = System::Drawing::Point(438, 487);
			this->btnPlus->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnPlus->Name = L"btnPlus";
			this->btnPlus->Size = System::Drawing::Size(136, 90);
			this->btnPlus->TabIndex = 20;
			this->btnPlus->Text = L"+";
			this->btnPlus->UseVisualStyleBackColor = true;
			this->btnPlus->Click += gcnew System::EventHandler(this, &Form1::ArithmeticOP);
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(296, 487);
			this->button18->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(136, 90);
			this->button18->TabIndex = 19;
			this->button18->Text = L"3";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// button19
			// 
			this->button19->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->Location = System::Drawing::Point(154, 487);
			this->button19->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(136, 90);
			this->button19->TabIndex = 18;
			this->button19->Text = L"2";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// button20
			// 
			this->button20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(12, 487);
			this->button20->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(136, 90);
			this->button20->TabIndex = 17;
			this->button20->Text = L"1";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// btnEquals
			// 
			this->btnEquals->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEquals->Location = System::Drawing::Point(436, 583);
			this->btnEquals->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnEquals->Name = L"btnEquals";
			this->btnEquals->Size = System::Drawing::Size(136, 90);
			this->btnEquals->TabIndex = 24;
			this->btnEquals->Text = L"=";
			this->btnEquals->UseVisualStyleBackColor = true;
			this->btnEquals->Click += gcnew System::EventHandler(this, &Form1::btnEquals_Click);
			// 
			// btnDot
			// 
			this->btnDot->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDot->Location = System::Drawing::Point(296, 583);
			this->btnDot->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnDot->Name = L"btnDot";
			this->btnDot->Size = System::Drawing::Size(136, 90);
			this->btnDot->TabIndex = 23;
			this->btnDot->Text = L".";
			this->btnDot->UseVisualStyleBackColor = true;
			this->btnDot->Click += gcnew System::EventHandler(this, &Form1::btnDot_Click);
			// 
			// button23
			// 
			this->button23->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->Location = System::Drawing::Point(152, 583);
			this->button23->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(136, 90);
			this->button23->TabIndex = 22;
			this->button23->Text = L"0";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &Form1::NumbersOnly);
			// 
			// btnPlusMinus
			// 
			this->btnPlusMinus->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlusMinus->Location = System::Drawing::Point(12, 583);
			this->btnPlusMinus->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnPlusMinus->Name = L"btnPlusMinus";
			this->btnPlusMinus->Size = System::Drawing::Size(136, 90);
			this->btnPlusMinus->TabIndex = 21;
			this->btnPlusMinus->Text = L"±";
			this->btnPlusMinus->UseVisualStyleBackColor = true;
			this->btnPlusMinus->Click += gcnew System::EventHandler(this, &Form1::btnPlusMinus_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 683);
			this->Controls->Add(this->btnEquals);
			this->Controls->Add(this->btnDot);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->btnPlusMinus);
			this->Controls->Add(this->btnPlus);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->btnMinus);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->btnMult);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->btnDivide);
			this->Controls->Add(this->btnSqrt);
			this->Controls->Add(this->btnPower);
			this->Controls->Add(this->btnFraction);
			this->Controls->Add(this->btnDel);
			this->Controls->Add(this->btnC);
			this->Controls->Add(this->btnCE);
			this->Controls->Add(this->btnPercent);
			this->Controls->Add(this->txtDisplay);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		double firstnum, secondnum, answer;
		String^ charOP;
#pragma endregion
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void NumbersOnly(System::Object^ sender, System::EventArgs^ e) {
	
	Button^ numb = safe_cast<Button^>(sender);

	if (txtDisplay->Text == "0") 
	{
		txtDisplay->Text = numb->Text;
	}
	else 
	{
		txtDisplay->Text = txtDisplay->Text + numb->Text;
	}
}
private: System::Void ArithmeticOP(System::Object^ sender, System::EventArgs^ e) {
	Button^ Aop = safe_cast<Button^>(sender);
	firstnum = Double::Parse(txtDisplay->Text);
	txtDisplay->Text = "";
	charOP = Aop->Text;

	// Immediate operations
	if (charOP == "sqrt") {
		answer = Math::Sqrt(firstnum);
		txtDisplay->Text = System::Convert::ToString(answer);
	}
	else if (charOP == "x^2") {
		answer = firstnum * firstnum;
		txtDisplay->Text = System::Convert::ToString(answer);
	}
	else if (charOP == "1/x") {
		answer = 1 / firstnum;
		txtDisplay->Text = System::Convert::ToString(answer);
	}
}

private: System::Void btnC_Click(System::Object^ sender, System::EventArgs^ e) {
	txtDisplay->Text = "0";
}

private: System::Void btnCE_Click(System::Object^ sender, System::EventArgs^ e) {
	txtDisplay->Text = "0";
}
private: System::Void btnDot_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (!txtDisplay->Text->Contains(".")) 
	{
		txtDisplay->Text = txtDisplay->Text + ".";
	}
}
private: System::Void btnDel_Click(System::Object^ sender, System::EventArgs^ e) {

	if (txtDisplay->Text->Length > 0)
	{
		txtDisplay->Text = txtDisplay->Text->Remove(txtDisplay->Text->Length - 1, 1);
	}
}
private: System::Void txtDisplay_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
	if (txtDisplay->Text == "")
	{
		txtDisplay->Text = txtDisplay->Text + "0";
	}
}
private: System::Void btnPlusMinus_Click(System::Object^ sender, System::EventArgs^ e) {

	if (txtDisplay->Text->Contains("-"))
	{
		txtDisplay->Text = txtDisplay->Text->Remove(0, 1);
	}
	else
	{
		txtDisplay->Text = "-" + txtDisplay->Text;
	}
}

private: System::Void btnEquals_Click(System::Object^ sender, System::EventArgs^ e) {
	secondnum = Double::Parse(txtDisplay->Text);

	if (charOP == "+") {
		answer = firstnum + secondnum;
		txtDisplay->Text = System::Convert::ToString(answer);
	}
	else if (charOP == "-") {
		answer = firstnum - secondnum;
		txtDisplay->Text = System::Convert::ToString(answer);
	}
	else if (charOP == "×") {
		answer = firstnum * secondnum;
		txtDisplay->Text = System::Convert::ToString(answer);
	}
	else if (charOP == "÷") {
		answer = firstnum / secondnum;
		txtDisplay->Text = System::Convert::ToString(answer);
	}
	else if (charOP == "%") {
		answer = (firstnum * secondnum) / 100;
		txtDisplay->Text = System::Convert::ToString(answer);
	}
}
};
}
