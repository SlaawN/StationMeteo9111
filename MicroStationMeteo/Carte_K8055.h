//---------------------------------------------------------------------------

#ifndef Carte_K8055H
#define Carte_K8055H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Fonction.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *connexion;
	TEdit *Edit1;
	void __fastcall connexionClick(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
private:
	Fonction* carte;	// Déclarations utilisateur
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
	int success;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
