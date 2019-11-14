/****************************************************************************
*

*****************************************************************************
*
*  	BUT : R�cuperer des trames NMEA et les trait� afin d'obtenir seulement
*         la temp�rature, la profondeur, la latitude et la longitude.
*
*****************************************************************************/

#ifndef ihmH
#define ihmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "com.h"
#include <windows.h>
#include "MySQL.h"
#include "BDD.h"
#include <string>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants g�r�s par l'EDI
	TButton *BtnReceive; //bouton pour recevoir les donn�es
	TButton *BtnConnect; //bouton pour se connecter au port s�rie
	TLabel *Connect�;
	TPanel *PanelConnect; //donne l'etat de la connexion au port avec une couleur rouge ou verte
	TMemo *MemoTri; //affiche les donn�es trier
	TMemo *MemoRecu; //affiche les donn�e re�ue
	TButton *BtnDeconnect; // bouton pour se deconnecter
	void __fastcall BtnConnectClick(TObject *Sender);
	void __fastcall BtnDeconnectClick(TObject *Sender);
	void __fastcall BtnReceiveClick(TObject *Sender);
	void __fastcall MemoRecuChange(TObject *Sender);

private:	// D�clarations utilisateur
	static DWORD WINAPI MonThread(LPVOID params);   // fonction thread
		MySQL *monsql;
		bool EtatConnect;

public:
	__fastcall TForm1(TComponent* Owner);
	Com rs232;   //objet qui pont sur la classe com
	HANDLE Thread;    //objet permetant de cr�er un thread
	DWORD dwThreadIdArray;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
