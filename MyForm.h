#pragma once

namespace Zadanie7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ rysuj;
	private: System::Windows::Forms::Button^ czysc;

	protected:

	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->rysuj = (gcnew System::Windows::Forms::Button());
			this->czysc = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rysuj
			// 
			this->rysuj->Location = System::Drawing::Point(13, 13);
			this->rysuj->Name = L"rysuj";
			this->rysuj->Size = System::Drawing::Size(75, 23);
			this->rysuj->TabIndex = 0;
			this->rysuj->Text = L"Rysuj";
			this->rysuj->UseVisualStyleBackColor = true;
			this->rysuj->Click += gcnew System::EventHandler(this, &MyForm::rysuj_Click);
			// 
			// czysc
			// 
			this->czysc->Location = System::Drawing::Point(13, 42);
			this->czysc->Name = L"czysc";
			this->czysc->Size = System::Drawing::Size(75, 23);
			this->czysc->TabIndex = 1;
			this->czysc->Text = L"Czyœæ";
			this->czysc->UseVisualStyleBackColor = true;
			this->czysc->Click += gcnew System::EventHandler(this, &MyForm::czysc_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 402);
			this->Controls->Add(this->czysc);
			this->Controls->Add(this->rysuj);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::maluj);
			this->ResumeLayout(false);

		}
#pragma endregion
		bool help;
	private: System::Void rysuj_Click(System::Object^ sender, System::EventArgs^ e) {
		rysuj2(System::Drawing::Color::Orange);
		help = true;
	}
	private: System::Void czysc_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g1 = this->CreateGraphics();
		g1->Clear(System::Drawing::SystemColors::Control);
		help = false;
	}
	private: System::Void rysuj2(System::Drawing::Color kolor)
	{
		Graphics^ g1 = this->CreateGraphics();
		SolidBrush^ pedzel = gcnew SolidBrush(kolor);
		int x0 = 50, y0 = 100, szer = 450, wys = 250;
		g1->FillRectangle(pedzel, x0, y0, szer, wys);
	}private: System::Void maluj(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {	
		if (help==true)
		{
			rysuj2(System::Drawing::Color::Orange);
		}
	}
};
}
