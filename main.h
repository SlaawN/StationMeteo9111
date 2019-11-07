//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "C9111.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TButton *INITIALISATION;
	TButton *RAZ;
	TButton *Sortie_10V;
	TButton *Sortie_5V;
	TButton *Sortie_0V;
	TButton *Affichage;
	void __fastcall INITIALISATIONClick(TObject *Sender);
	void __fastcall RAZClick(TObject *Sender);
	void __fastcall Sortie_10VClick(TObject *Sender);
	void __fastcall Sortie_5VClick(TObject *Sender);
	void __fastcall Sortie_0VClick(TObject *Sender);
	void __fastcall AffichageClick(TObject *Sender);
private:	// Déclarations utilisateur
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);

	C9111 *MonObj;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
