//---------------------------------------------------------------------------
// Programme : TP4- FOUR                     			Date :25/11/2019
//---------------------------------------------------------------------------
// Programmeur :  BOURY Aurélien                         classe : BTSSN2
//---------------------------------------------------------------------------
// BUT : "Pilotage" du four à distance : choisir la température de chauffe et son pourcentage
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IHMfour.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	 voltage=2;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
		temp=LEFOUR->Lecture();
		LblTemp->Caption=temp;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnInitisialisationClick(TObject *Sender)
{
	LEFOUR = new four();
	Timer1->Enabled=true;
	BtnInitisialisation->Visible=false;
	LblCommande->Visible=true;
    ListTemp->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	temp=LEFOUR->Lecture();



	LEFOUR->Ecriture(voltage);


	if(temp-2>tempcom)
	{
		voltage=0;
	}
	if(temp<tempcom)
	{
		voltage+=0.2;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnStartClick(TObject *Sender)
{
	tempcom=EdtTemp->Text.ToInt();
    switch(ListTemp->Text.ToInt())
{
	 case 0:
	 LEFOUR->Ecriture(0);
	 break;

	 case 25:
	 LEFOUR->Ecriture(2.5);
	 break;

	 case 50:
	 LEFOUR->Ecriture(5);
	 break;

	 case 75:
	 LEFOUR->Ecriture(7.5);
	 break;

	 case 100:
	 LEFOUR->Ecriture(10);
	 break;
}
		LblTemp->Visible=true;
		Label1->Visible=true;
		BtnStart->Visible=false;
        BtnStop->Visible=true;



}
//---------------------------------------------------------------------------


void __fastcall TForm1::BtnArretClick(TObject *Sender)
{
		LEFOUR->Ecriture(0);
		voltage = 2 ;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::FormCreate(TObject *Sender)
{
		BtnInitisialisation->Visible=true;

		LblCommandeTemp->Visible=false;
		ListTemp->Visible=false;
		LblCommande->Visible=false;
		LblTemp->Visible=false;
		EdtTemp->Visible=false;
		BtnStart->Visible=false;
		BtnStop->Visible=false;
        Label1->Visible=false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListTempChange(TObject *Sender)
{
	EdtTemp->Visible=true;
	LblCommandeTemp->Visible=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::EdtTempChange(TObject *Sender)
{
    BtnStart->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnStopClick(TObject *Sender)
{
	LEFOUR->Ecriture(0);
		voltage = 2 ;
}
//---------------------------------------------------------------------------


