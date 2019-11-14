/****************************************************************************
*

*****************************************************************************
*
*  	BUT : Récuperer des trames NMEA et les traité afin d'obtenir seulement
*         la température, la profondeur, la latitude et la longitude.
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
__published:	// Composants gérés par l'EDI
	TButton *BtnReceive; //bouton pour recevoir les données
	TButton *BtnConnect; //bouton pour se connecter au port série
	TLabel *Connecté;
	TPanel *PanelConnect; //donne l'etat de la connexion au port avec une couleur rouge ou verte
	TMemo *MemoTri; //affiche les données trier
	TMemo *MemoRecu; //affiche les donnée reçue
	TButton *BtnDeconnect; // bouton pour se deconnecter
	void __fastcall BtnConnectClick(TObject *Sender);
	void __fastcall BtnDeconnectClick(TObject *Sender);
	void __fastcall BtnReceiveClick(TObject *Sender);
	void __fastcall MemoRecuChange(TObject *Sender);

private:	// Déclarations utilisateur
	static DWORD WINAPI MonThread(LPVOID params);   // fonction thread
		MySQL *monsql;
		bool EtatConnect;

public:
	__fastcall TForm1(TComponent* Owner);
	Com rs232;   //objet qui pont sur la classe com
	HANDLE Thread;    //objet permetant de créer un thread
	DWORD dwThreadIdArray;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
