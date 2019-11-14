/****************************************************************************

*****************************************************************************
*
*  	BUT : R�cuperer des trames NMEA et les trait� afin d'obtenir seulement
*         la temp�rature, la profondeur, la latitude et la longitude.
*
*****************************************************************************/
#include <vcl.h>
#pragma hdrstop

#include "ihm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnConnectClick(TObject *Sender)
{
    //Si la connection RS232 marche :
	if (rs232.Ouverture(4800,8))
	{
		PanelConnect->Color=clLime;
		BtnReceive->Visible=true;
		BtnConnect->Visible=false;
		BtnDeconnect->Visible=true;

		//this->monsql = new MySQL();
        //Mettre en 127.0.0.1 par défaut
		//EtatConnect=monsql->Connect("127.0.0.1","root","root","caracteristiques");
		MemoRecu->Visible=true;
        MemoTri->Visible=true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnDeconnectClick(TObject *Sender)  //Lorsqu'on click sur Déconnexion
{
	rs232.fermeture();
	PanelConnect->Color=clRed;
	BtnReceive->Visible=false;
	BtnConnect->Visible=true;
	BtnDeconnect->Visible=false;
	MemoRecu->Visible=false;
	MemoTri->Visible=false;
   //	this->monsql->Disconnect();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnReceiveClick(TObject *Sender)  //Lorsqu'on click sur Recevoir
{
	Thread=CreateThread(
						NULL,
						0,
						MonThread,
						this,
						0,
						&dwThreadIdArray);
}
//---------------------------------------------------------------------------
 DWORD WINAPI TForm1::MonThread(LPVOID params)  //THREAD
 {
	TForm1 * hmi = (TForm1*) params;
	char trame_recue[700];
	char trame_traite[700];
	char trame_requete[700];

   std::string request="INSERT INTO `caracteristiques`(`temperature`, `profondeur_eau`, `latitude`, `longitude`) VALUES (";

	strcpy(trame_recue,hmi->rs232.lecture());
	hmi->MemoRecu->Lines->Add(trame_recue);   //On récupére la trame reçue
	hmi->MemoTri->Lines->Add("Temperature : ");         //On affiche la température
	strcpy(trame_traite,(strstr(trame_recue,"$SDMTW"))+7);  //On récupére que ce qu'on a besoin
	strcpy(trame_requete,(strstr(trame_recue,"$SDMTW"))+7);
	trame_traite[4]='\0';                             //On stocke la trame traitée
	request+=trame_traite;
	request+=",";
	hmi->MemoTri->Lines->Add(strcat(trame_traite," °C"));   //Suite affichage température
	hmi->MemoTri->Lines->Add("Profondeur : ");                 //On affiche la pronfondeur
	strcpy(trame_traite,(strstr(trame_recue,"$SDDPT"))+9);  // On récupére que ce qu'on a besoin
	strcpy(trame_requete,(strstr(trame_recue,"$SDDPT"))+9);         // //
	trame_traite[3]='\0';     //Stockage dans un tableau
    request+=trame_traite;
	request+=",";
	hmi->MemoTri->Lines->Add(strcat(trame_traite," m"));   //Suite affichage pronfondeur
	hmi->MemoTri->Lines->Add("Latitude  : ");               //Affichage Latitude
	strcpy(trame_traite,(strstr(trame_recue,"$GPRMC"))+16);   //On récupére que ce qu'on a besoin
	strcpy(trame_requete,(strstr(trame_recue,"$GPRMC"))+16); // //
	trame_traite[9]='\0';  //Stochage dans un tableau
	request+=trame_traite;
	request+=",";
	hmi->MemoTri->Lines->Add(trame_traite);
	strcpy(trame_traite,(strstr(trame_recue,"$GPRMC"))+28);
	strcpy(trame_requete,(strstr(trame_recue,"$GPRMC"))+28);
	trame_traite[9]='\0';
	request+=trame_traite;
	request+=");";

	//hmi->monsql->Insert(request);

	hmi->MemoTri->Lines->Add("Longitude  : ");
	hmi->MemoTri->Lines->Add(trame_traite);

 	return 0;
 }

//---------------------------------------------------------------------------








void __fastcall TForm1::MemoRecuChange(TObject *Sender)
{
	//this->monsql->Disconnect();

}
//---------------------------------------------------------------------------

