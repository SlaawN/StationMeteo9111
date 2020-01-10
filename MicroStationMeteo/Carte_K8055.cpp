//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Carte_K8055.h"
#include "Fonction.h"
#include "K8055D.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    success = -1;
	carte = new Fonction();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::connexionClick(TObject *Sender)
{

	success = carte->Connexion(1);
	if (success == 1)
	{
        connexion->Caption = "connecté";
	}

}


void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    Edit1->Text = carte->ReadAnalogChannel(2);
}
//---------------------------------------------------------------------------

