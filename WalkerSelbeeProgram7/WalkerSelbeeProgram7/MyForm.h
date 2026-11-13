#pragma once

// Libraries
#include "Game.h"

Game game;

namespace WalkerSelbeeProgram7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	protected:

	private: System::Windows::Forms::TextBox^ txtBet;
	private: System::Windows::Forms::Label^ lblBet;
	private: System::Windows::Forms::Button^ btnBet;
	private: System::Windows::Forms::Button^ btnNewGame;
	private: System::Windows::Forms::TextBox^ txtStatus;
	private: System::Windows::Forms::Label^ lblStatus;
	private: System::Windows::Forms::Label^ lblP1;
	private: System::Windows::Forms::TextBox^ txtP1;
	private: System::Windows::Forms::Label^ lblDealer;
	private: System::Windows::Forms::TextBox^ txtDealer;
	private: System::Windows::Forms::TextBox^ txtHeader;
	private: System::Windows::Forms::Button^ btnHit;
	private: System::Windows::Forms::Button^ btnStand;



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
			System::Windows::Forms::ToolStripMenuItem^ menuRules;
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->txtBet = (gcnew System::Windows::Forms::TextBox());
			this->lblBet = (gcnew System::Windows::Forms::Label());
			this->btnBet = (gcnew System::Windows::Forms::Button());
			this->btnNewGame = (gcnew System::Windows::Forms::Button());
			this->txtStatus = (gcnew System::Windows::Forms::TextBox());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->lblP1 = (gcnew System::Windows::Forms::Label());
			this->txtP1 = (gcnew System::Windows::Forms::TextBox());
			this->lblDealer = (gcnew System::Windows::Forms::Label());
			this->txtDealer = (gcnew System::Windows::Forms::TextBox());
			this->txtHeader = (gcnew System::Windows::Forms::TextBox());
			this->btnHit = (gcnew System::Windows::Forms::Button());
			this->btnStand = (gcnew System::Windows::Forms::Button());
			menuRules = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuRules
			// 
			menuRules->ForeColor = System::Drawing::Color::White;
			menuRules->Name = L"menuRules";
			menuRules->Size = System::Drawing::Size(53, 23);
			menuRules->Text = L"Rules";
			menuRules->Click += gcnew System::EventHandler(this, &MyForm::menuRules_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Black;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { menuRules });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(533, 27);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"Rules";
			// 
			// txtBet
			// 
			this->txtBet->Location = System::Drawing::Point(90, 417);
			this->txtBet->Name = L"txtBet";
			this->txtBet->Size = System::Drawing::Size(100, 20);
			this->txtBet->TabIndex = 1;
			// 
			// lblBet
			// 
			this->lblBet->AutoSize = true;
			this->lblBet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBet->Location = System::Drawing::Point(18, 413);
			this->lblBet->Name = L"lblBet";
			this->lblBet->Size = System::Drawing::Size(66, 24);
			this->lblBet->TabIndex = 2;
			this->lblBet->Text = L"Wager";
			// 
			// btnBet
			// 
			this->btnBet->Location = System::Drawing::Point(196, 415);
			this->btnBet->Name = L"btnBet";
			this->btnBet->Size = System::Drawing::Size(75, 23);
			this->btnBet->TabIndex = 3;
			this->btnBet->Text = L"Place Bet";
			this->btnBet->UseVisualStyleBackColor = true;
			this->btnBet->Click += gcnew System::EventHandler(this, &MyForm::btnBet_Click);
			// 
			// btnNewGame
			// 
			this->btnNewGame->Location = System::Drawing::Point(442, 424);
			this->btnNewGame->Name = L"btnNewGame";
			this->btnNewGame->Size = System::Drawing::Size(75, 23);
			this->btnNewGame->TabIndex = 4;
			this->btnNewGame->Text = L"Play Again";
			this->btnNewGame->UseVisualStyleBackColor = true;
			this->btnNewGame->Click += gcnew System::EventHandler(this, &MyForm::btnNewGame_Click);
			// 
			// txtStatus
			// 
			this->txtStatus->Location = System::Drawing::Point(291, 148);
			this->txtStatus->Multiline = true;
			this->txtStatus->Name = L"txtStatus";
			this->txtStatus->ReadOnly = true;
			this->txtStatus->Size = System::Drawing::Size(226, 270);
			this->txtStatus->TabIndex = 5;
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->Location = System::Drawing::Point(287, 121);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(60, 24);
			this->lblStatus->TabIndex = 6;
			this->lblStatus->Text = L"Status";
			// 
			// lblP1
			// 
			this->lblP1->AutoSize = true;
			this->lblP1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblP1->Location = System::Drawing::Point(18, 270);
			this->lblP1->Name = L"lblP1";
			this->lblP1->Size = System::Drawing::Size(83, 24);
			this->lblP1->TabIndex = 7;
			this->lblP1->Text = L"P1 Hand";
			// 
			// txtP1
			// 
			this->txtP1->Location = System::Drawing::Point(22, 297);
			this->txtP1->Multiline = true;
			this->txtP1->Name = L"txtP1";
			this->txtP1->ReadOnly = true;
			this->txtP1->Size = System::Drawing::Size(226, 112);
			this->txtP1->TabIndex = 8;
			// 
			// lblDealer
			// 
			this->lblDealer->AutoSize = true;
			this->lblDealer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDealer->Location = System::Drawing::Point(18, 121);
			this->lblDealer->Name = L"lblDealer";
			this->lblDealer->Size = System::Drawing::Size(116, 24);
			this->lblDealer->TabIndex = 9;
			this->lblDealer->Text = L"Dealer Hand";
			// 
			// txtDealer
			// 
			this->txtDealer->Location = System::Drawing::Point(22, 148);
			this->txtDealer->Multiline = true;
			this->txtDealer->Name = L"txtDealer";
			this->txtDealer->ReadOnly = true;
			this->txtDealer->Size = System::Drawing::Size(226, 112);
			this->txtDealer->TabIndex = 10;
			// 
			// txtHeader
			// 
			this->txtHeader->BackColor = System::Drawing::Color::Green;
			this->txtHeader->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtHeader->ForeColor = System::Drawing::Color::White;
			this->txtHeader->Location = System::Drawing::Point(22, 35);
			this->txtHeader->Multiline = true;
			this->txtHeader->Name = L"txtHeader";
			this->txtHeader->ReadOnly = true;
			this->txtHeader->Size = System::Drawing::Size(495, 83);
			this->txtHeader->TabIndex = 11;
			// 
			// btnHit
			// 
			this->btnHit->Location = System::Drawing::Point(22, 415);
			this->btnHit->Name = L"btnHit";
			this->btnHit->Size = System::Drawing::Size(75, 23);
			this->btnHit->TabIndex = 12;
			this->btnHit->Text = L"Hit";
			this->btnHit->UseVisualStyleBackColor = true;
			this->btnHit->Click += gcnew System::EventHandler(this, &MyForm::btnHit_Click);
			// 
			// btnStand
			// 
			this->btnStand->Location = System::Drawing::Point(103, 415);
			this->btnStand->Name = L"btnStand";
			this->btnStand->Size = System::Drawing::Size(75, 23);
			this->btnStand->TabIndex = 13;
			this->btnStand->Text = L"Stand";
			this->btnStand->UseVisualStyleBackColor = true;
			this->btnStand->Click += gcnew System::EventHandler(this, &MyForm::btnStand_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Green;
			this->ClientSize = System::Drawing::Size(533, 459);
			this->Controls->Add(this->btnStand);
			this->Controls->Add(this->btnHit);
			this->Controls->Add(this->txtHeader);
			this->Controls->Add(this->txtDealer);
			this->Controls->Add(this->lblDealer);
			this->Controls->Add(this->txtP1);
			this->Controls->Add(this->lblP1);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->txtStatus);
			this->Controls->Add(this->btnNewGame);
			this->Controls->Add(this->btnBet);
			this->Controls->Add(this->lblBet);
			this->Controls->Add(this->txtBet);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"C++ Blackjack: SW/RS";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// -=>-=>-=> EVENT HANDLERS <=-<=-<=-
		// -=> Lifecyle
		// On Form Load
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			// Show the header text
			txtHeader->Text = GetHeader();

			// Hide the 'new game' button
			btnNewGame->Visible = false;
			
			// Hide the 'action' buttons
			btnHit->Visible = false;
			btnStand->Visible = false;

			// Check for logger file
			if (!game.IsLogOpened()) {
				txtStatus->Text = "Unable to Create Log File.";
			}
		}

		// On Form Closing
		private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			game.EndGame();		
		}

		// -=> User Events
		// On Bet Click
		private: System::Void btnBet_Click(System::Object^ sender, System::EventArgs^ e) {
			int bet;

			// Clear Status Message
			txtStatus->Text = "";

			// Validate: must be a whole number
			if (!Int32::TryParse(txtBet->Text, bet))
			{
				txtStatus->Text = "Please enter a whole number for your bet.";
				return;
			}

			// Validate: Game Object checks for negative bets or bets over the balance
			if (!game.SetBet(bet))
			{
				txtStatus->Text = "Invalid bet. Bet must be more than 0 and no more than your balance.";
				return;
			}

			// Deal and show
			game.InitialDeal();
			txtP1->Text = ToNetStr(game.ShowPlayerHand());
			txtDealer->Text = ToNetStr(game.ShowDealerHand(true));

			// Hide the bet controls
			lblBet->Visible = false;
			txtBet->Visible = false;
			btnBet->Visible = false;

			if (game.IsBlackJack())	{
				EndHand();
			}
			else
			{
				// Play continues
				btnHit->Visible = true;
				btnStand->Visible = true;
			}
		}

		private: System::Void btnHit_Click(System::Object^ sender, System::EventArgs^ e) {
			if (!game.PlayerContinues()) { return; }
			game.PlayerHits();
			txtP1->Text = ToNetStr(game.ShowPlayerHand());
			if (game.PlayerBusted()) { EndHand(); }
		}

		private: System::Void btnStand_Click(System::Object^ sender, System::EventArgs^ e) {
			while (game.DealerContinues()) {

			}
			EndHand();
		}
		
		private: System::Void btnNewGame_Click(System::Object^ sender, System::EventArgs^ e) {
			game.ClearHands();
			txtP1->Text= String::Empty;
			txtDealer->Text = String::Empty;
			txtStatus->Text = "Place your bet.";
			
			lblBet->Visible = true;
			txtBet->Visible = true;
			btnBet->Visible = true;
			btnHit->Visible = false;
			btnStand->Visible = false;
			btnNewGame->Visible = false;
			txtBet->Focus();
		}

		private: System::Void menuRules_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(GetRules(), "Rules");
		}

		// -=>-=>-=> HELPERS <=-<=-<=-
		// Accepts a c++ string and returns a .net string
		String^ ToNetStr(string s) { return gcnew String(s.c_str()); }

		// A function to DRY out the end hand proc.
		void EndHand()
		{
			txtDealer->Text = ToNetStr(game.ShowDealerHand(false));
			txtStatus->Text = ToNetStr(game.ShowResults());
			btnHit->Visible = false;
			btnStand->Visible = false;
			btnNewGame->Visible = true;
		}
		
		// Returns the Header String
		String^ GetHeader()
	    {
			return
				"C++ BlackJack!\r\n"
				"Click 'Rules' To Learn how to play.\r\n"
				"Starting Bankroll : $1000.00";
		}

		// Returns the rules of the game for the Rules menu item
		String^ GetRules()
		{
		   return
			   "OBJECTIVE\n"
			   "Get closer to 21 than the dealer without going over.\n\n"

			   "CARD VALUES\n"
			   "Number cards are worth their face value.\n"
			   "Jack, Queen, and King are worth 10.\n"
			   "An Ace is worth 1 or 11, whichever helps your hand more.\n\n"

			   "HOW TO PLAY\n"
			   "1. Enter a bet and press Place Bet.\n"
			   "2. You and the dealer each get two cards. One dealer card is hidden.\n"
			   "3. Press Hit to take another card, or Stay to keep your hand.\n"
			   "4. If you go over 21, you bust and lose your bet.\n"
			   "5. When you stay, the dealer reveals the hidden card and must hit\n"
			   "    until reaching 17 or more.\n\n"

			   "PAYOUTS\n"
			   "Win: you win the amount of your bet.\n"
			   "BlackJack (Ace + 10-point card on the deal): you win 1.5 x your bet.\n"
			   "Tie: no money changes hands.\n"
			   "Lose: you lose your bet.\n\n"

			   "Press Play Again to start a new hand.";
		}

	};
}
