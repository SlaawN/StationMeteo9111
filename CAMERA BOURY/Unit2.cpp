//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	unsigned char * trame = actions.allumer(0x02);

	serbe.ecriture(trame, 6);

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	unsigned char * trame = actions.allumer(0x03);

	serbe.ecriture(trame, 6);

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	unsigned char * trame = actions.deplaceY(0x01);

	serbe.ecriture(trame, 9);

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	unsigned char * trame = actions.deplaceY(0x02);

	serbe.ecriture(trame, 9);

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
	unsigned char * trame = actions.deplaceX(0x01);

	serbe.ecriture(trame, 9);

	TrackBar1->Position=0;

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
	unsigned char * trame = actions.deplaceX(0x02);

	serbe.ecriture(trame, 9);

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button7Click(TObject *Sender)
{
	unsigned char * trame = actions.deplaceY(0x03);

	serbe.ecriture(trame, 9);
	//lblPositionValeur->Caption="100";

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button8Click(TObject *Sender)
{
	unsigned char * trame = actions.zoom(0x23);

	serbe.ecriture(trame, 6);                                    //Zoom

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender)
{
	unsigned char * trame = actions.zoom(0x33);     //Dezoom

	serbe.ecriture(trame, 6);

	delete trame;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button10Click(TObject *Sender)
{
	unsigned char * trame = actions.zoom(0x00);          //StopZoom

	serbe.ecriture(trame, 6);

	delete trame;
}
//---------------------------------------------------------------------------
