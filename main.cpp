//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    MonObj = new(C9111);
}

void __fastcall TForm1::INITIALISATIONClick(TObject *Sender)
{
	MonObj->Initialisation();
}

void __fastcall TForm1::RAZClick(TObject *Sender)   //RAZ pointeur de carte
{
	Release_Card(ID_CARD);
}

void __fastcall TForm1::Sortie_10VClick(TObject *Sender)    //Active la sortie ana à +10V
{
	AO_VWriteChannel(ID_CARD,0,10.0);
}

void __fastcall TForm1::Sortie_5VClick(TObject *Sender)     //Active la sortie ana à +5V
{
	AO_VWriteChannel(ID_CARD,0,5.0);
}

void __fastcall TForm1::Sortie_0VClick(TObject *Sender)     //Active la sortie ana à 0V
{
	 AO_VWriteChannel(ID_CARD,0,0);
}

void __fastcall TForm1::AffichageClick(TObject *Sender)     /* Lecture et affichage la tension à l’entrée analogique N° 0*/
{
	F64 Tension_lu;
	AI_VReadChannel(ID_CARD,0, AD_B_10_V, &Tension_lu);
	Edit1->Text=Tension_lu;
}
//---------------------------------------------------------------------------

