#pragma once
#include "Time.h"

int count = 0;
int sec = 0;
Time MyTime;

namespace StopWatch {

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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label2;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 72, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(-13, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(364, 108);
			this->label1->TabIndex = 0;
			this->label1->Text = L"0:00:00";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Location = System::Drawing::Point(48, 230);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Location = System::Drawing::Point(183, 230);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Reset";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(55, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(203, 60);
			this->label2->TabIndex = 4;
			this->label2->Text = L"ASSOCIATE PRODUCER\r\n\r\nGRACE KOUNTHOUSE";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(332, 352);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Stop Watch";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 if (MyTime.get_sec() < 10)
				 {
					 if (MyTime.get_min() < 10)
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":0" + Convert::ToString(MyTime.get_min()) + ":0" + Convert::ToString(MyTime.get_sec());
					 else
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":" + Convert::ToString(MyTime.get_min()) + ":0" + Convert::ToString(MyTime.get_sec());
				 }
				 else
				 {
					 if (MyTime.get_min() < 10)
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":0" + Convert::ToString(MyTime.get_min()) + ":" + Convert::ToString(MyTime.get_sec());
					 else
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":" + Convert::ToString(MyTime.get_min()) + ":" + Convert::ToString(MyTime.get_sec());
				 }
				 button2->Enabled = false;
				 label2->Visible = false;
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (button1->Text == "Stop")
				 {
					 button1->Text = "Resume";
					 timer1->Enabled = false;
				 }
				 else
				 {
					 timer1->Enabled = true;
					 button2->Enabled = true;
					 button1->Text = "Stop";
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 MyTime.Reset();
				 if (MyTime.get_sec() < 10)
				 {
					 if (MyTime.get_min() < 10)
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":0" + Convert::ToString(MyTime.get_min()) + ":0" + Convert::ToString(MyTime.get_sec());
					 else
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":" + Convert::ToString(MyTime.get_min()) + ":0" + Convert::ToString(MyTime.get_sec());
				 }
				 else
				 {
					 if (MyTime.get_min() < 10)
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":0" + Convert::ToString(MyTime.get_min()) + ":" + Convert::ToString(MyTime.get_sec());
					 else
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":" + Convert::ToString(MyTime.get_min()) + ":" + Convert::ToString(MyTime.get_sec());
				 }
				 button1->Text = "Start";
				 button2->Enabled = false;
				 timer1->Enabled = false;
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if (label1->Text == "6:00:00")
				 {
					 
					 //label2->Visible = true;
					 //label1->Visible = false;
					 //timer1->Enabled = false;
					 if (count == 2)
					 {
						 label1->Visible = false;
						 label2->Visible = true;
						 timer1->Enabled = false;
					 }

					 count++;
				 }
				 else
				 {
					 MyTime++;

				 if (MyTime.get_sec() < 10)
				 {
					 if (MyTime.get_min() < 10)
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":0" + Convert::ToString(MyTime.get_min()) + ":0" + Convert::ToString(MyTime.get_sec());
					 else
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":" + Convert::ToString(MyTime.get_min()) + ":0" + Convert::ToString(MyTime.get_sec());
				 }
				 else
				 {
					 if (MyTime.get_min() < 10)
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":0" + Convert::ToString(MyTime.get_min()) + ":" + Convert::ToString(MyTime.get_sec());
					 else
						 label1->Text = Convert::ToString(MyTime.get_hour()) + ":" + Convert::ToString(MyTime.get_min()) + ":" + Convert::ToString(MyTime.get_sec());
				 }
				 }
			 }
};
}

