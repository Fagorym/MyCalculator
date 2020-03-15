#pragma once
#include<string>
#include<conio.h>
#include<math.h>
namespace Project3 {

	float a;
	enum eDirection{NOTHING,PLUS, MINUS, MULTIPUL, SLASH };
	eDirection dir = NOTHING;
	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;



	private: System::Windows::Forms::Button^ button11;

	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::TextBox^ num1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ num2;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button18;
	protected:







	protected:

	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->num1 = (gcnew System::Windows::Forms::TextBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->num2 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 325);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(189, 45);
			this->button1->TabIndex = 0;
			this->button1->Text = L"0";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(15, 244);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(58, 58);
			this->button2->TabIndex = 1;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(79, 244);
			this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(58, 58);
			this->button3->TabIndex = 2;
			this->button3->Text = L"2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(143, 244);
			this->button4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(58, 58);
			this->button4->TabIndex = 3;
			this->button4->Text = L"3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(15, 178);
			this->button5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(58, 58);
			this->button5->TabIndex = 4;
			this->button5->Text = L"4";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(79, 178);
			this->button6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(58, 58);
			this->button6->TabIndex = 5;
			this->button6->Text = L"5";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(143, 178);
			this->button7->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(58, 58);
			this->button7->TabIndex = 6;
			this->button7->Text = L"6";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(15, 112);
			this->button8->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(58, 58);
			this->button8->TabIndex = 7;
			this->button8->Text = L"7";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(79, 112);
			this->button9->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(58, 58);
			this->button9->TabIndex = 8;
			this->button9->Text = L"8";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(143, 112);
			this->button10->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(58, 58);
			this->button10->TabIndex = 9;
			this->button10->Text = L"9";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// num1
			// 
			this->num1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->num1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->num1->Location = System::Drawing::Point(15, 66);
			this->num1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->num1->Name = L"num1";
			this->num1->ReadOnly = true;
			this->num1->Size = System::Drawing::Size(296, 30);
			this->num1->TabIndex = 10;
			this->num1->TabStop = false;
			this->num1->Text = L"0";
			this->num1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->num1->WordWrap = false;
			this->num1->TextChanged += gcnew System::EventHandler(this, &MyForm::num1_TextChanged_1);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->button11->Location = System::Drawing::Point(211, 104);
			this->button11->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(100, 46);
			this->button11->TabIndex = 15;
			this->button11->Text = L"←";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button13->Location = System::Drawing::Point(211, 217);
			this->button13->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(47, 46);
			this->button13->TabIndex = 13;
			this->button13->Text = L"*";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button14->Location = System::Drawing::Point(262, 217);
			this->button14->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(47, 46);
			this->button14->TabIndex = 14;
			this->button14->Text = L"/";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button15->Location = System::Drawing::Point(211, 271);
			this->button15->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(47, 46);
			this->button15->TabIndex = 15;
			this->button15->Text = L"+";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button16->Location = System::Drawing::Point(262, 271);
			this->button16->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(47, 46);
			this->button16->TabIndex = 16;
			this->button16->Text = L"-";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button17->Location = System::Drawing::Point(211, 325);
			this->button17->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(100, 45);
			this->button17->TabIndex = 17;
			this->button17->Text = L"=";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoEllipsis = true;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label1->Location = System::Drawing::Point(206, 18);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(0, 0, 5, 0);
			this->label1->Size = System::Drawing::Size(5, 26);
			this->label1->TabIndex = 18;
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// num2
			// 
			this->num2->AutoSize = true;
			this->num2->Location = System::Drawing::Point(256, 18);
			this->num2->Name = L"num2";
			this->num2->Size = System::Drawing::Size(0, 15);
			this->num2->TabIndex = 19;
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button12->Location = System::Drawing::Point(211, 163);
			this->button12->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(47, 46);
			this->button12->TabIndex = 20;
			this->button12->Text = L"√";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button18->Location = System::Drawing::Point(262, 163);
			this->button18->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(47, 46);
			this->button18->TabIndex = 21;
			this->button18->Text = L",";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(331, 383);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->num2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->num1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void num1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void num2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	
}
private: System::Void num3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (num1->Text!="0")
		num1->Text = num1->Text + L"0";

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (num1->Text != "0")
		num1->Text = num1->Text +  L"1";
		else num1->Text = L"1";
	}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text != "0")
		num1->Text = num1->Text + L"5";
	else num1->Text = L"5";
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (num1->Text == "" || num1->Text == " ") {

		
	}
	else {

		label1->Text = num1->Text + L'+';

		a = Convert::ToDouble(num1->Text);

		num1->Text = L"";

		dir = PLUS;
	}
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text == "" || num1->Text == " ") {


	}
	else {

		label1->Text = num1->Text + L'-';

		a = Convert::ToDouble(num1->Text);

		num1->Text = L"";

		dir = MINUS;
	}
	

}
private: System::Void num1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text != "0")
	num1->Text = num1->Text +  L"2";
	else num1->Text = L"2";
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text != "0")
	num1->Text = num1->Text + L"3";
	else num1->Text = L"3";
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text != "0")
	num1->Text = num1->Text + L"4";
	else num1->Text = L"4";
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text != "0")
	num1->Text = num1->Text + L"6";
	else num1->Text = L"6";
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text != "0")
	num1->Text = num1->Text + L"7";  
	else num1->Text = L"7";
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text != "0")
	num1->Text = num1->Text + L"8";
	else num1->Text = L"8";
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text != "0")
	num1->Text = num1->Text + L"9";
	else num1->Text = L"9";
}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	if (num1->Text == "" || num1->Text == " ") {


	}
	else {
		float b;
		switch (dir)
		{
		case Project3::PLUS:
			label1->Text = label1->Text + num1->Text + L"=";
			num1->Text = num1->Text->Replace("+", "");
			b = Convert::ToDouble(num1->Text);
			a += b;
			break;
		case Project3::MINUS:
			label1->Text = label1->Text + num1->Text + L"=";
			num1->Text = num1->Text->Replace("-", "");
			b = Convert::ToDouble(num1->Text);
			a -= b;
			break;
		case Project3::MULTIPUL:
			label1->Text = label1->Text + num1->Text + L"=";
			num1->Text = num1->Text->Replace("*", "");
			b = Convert::ToDouble(num1->Text);
			a *= b;
			break;
		case Project3::SLASH:
			label1->Text = label1->Text + num1->Text + L"=";
			num1->Text = num1->Text->Replace("/", "");
			b = Convert::ToDouble(num1->Text);
			a /= b;
			break;
		default:
			break;
		}
		num1->Text = String::Format("{0}", a); // Вот эту строку  не забывай
		dir = NOTHING;
		a = b = 0;
	}
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {

	if (num1->Text == "" || num1->Text == " ") {


	}
	else {
		label1->Text = num1->Text + L'/';

		a = Convert::ToDouble(num1->Text);

		num1->Text = L"";

		dir = SLASH;
	}
	
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {


	if (num1->Text == "" || num1->Text == " ") {


	}
	else {
		label1->Text = num1->Text + L'*';

		a = Convert::ToDouble(num1->Text);

		num1->Text = L"";

		dir = MULTIPUL;
	}

}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	num1->Text = L"0";
	label1->Text = L"";
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	

	}
	   

		   

	  


private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {

	double b;

	label1->Text = L'√' + num1->Text + "=";

	a = Convert::ToDouble(num1->Text);
	
	b = sqrt(a);

	num1->Text = Convert::ToString(b);



}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {

	num1->Text += L",";
	
}
};
};

