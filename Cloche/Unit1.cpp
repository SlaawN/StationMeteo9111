//---------------------------------------------------------------------------
// Programme : TP5- Carillon 4 Cloches                     Date :18/11/2019
//---------------------------------------------------------------------------
// Programmeur :  BOURY Aurélien                         classe : BTSSN2
//---------------------------------------------------------------------------
// BUT : "Pilotage" des cloches à distance via communication TCP/IP
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#if defined (WIN32)
	#include <winsock2.h>
	typedef int socklen_t;
#endif
#include <stdio.h>
#include <vector>
 #include "Windows.h"
#include "windows.h"
#include <stdlib.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
#define BUFFERSIZE 25
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)    //Tant qu'on appuie pas sur "Connexion" les boutons ne sont pas visibles
	: TForm(Owner)
{
	Button2->Visible=false;
	Button3->Visible=false;
	Button4->Visible=false;
	Button5->Visible=false;
	Button6->Visible=false;
	Button7->Visible=false;
	Edit1->Visible=false;
    Label1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	#if defined (WIN32)
		WSADATA WSAData;
		int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
		int erreur = 0;
	#endif

	SOCKADDR_IN sin;
	if(!erreur)
	{

		sock = socket(AF_INET, SOCK_STREAM, 0);    //création du socket


		sin.sin_addr.s_addr = inet_addr("192.168.64.124"); //Connexion à l'adresse IP des cloches
		sin.sin_family = AF_INET;
			sin.sin_port = htons(502); //Port de connexion


		if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR) //condition si la connexion se fait et qu'il n'y a pas d'erreur
		{
			// affichage des boutons ou non
			Button1->Visible=false;
			Button2->Visible=true;
			Button3->Visible=true;
			Button4->Visible=true;
			Button5->Visible=true;
			Button6->Visible=true;
			Button7->Visible=true;
			Edit1->Visible=true;
			Label1->Visible=true;
			test = new cloche(sock);
		}


	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	test->cloche1(); //activation de la cloche n°1

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{

	closesocket(sock); //Fermeture du socket
	delete test;
	#if defined (WIN32)
		WSACleanup();
	#endif
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	test->cloche2();   //activation de la cloche n°2
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	test->cloche3();   //activation de la cloche n°3
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	test->cloche4();  //activation de la cloche n°4
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{     //Permet d'activer les cloches via les touches "F1,F2,F3,F4 et F5" dans la carré gris
  if (Key==VK_F1) {           //Appuie sur F1 -> Activation de la cloche n°1
		test->cloche1();
  }
  if (Key==VK_F2) {           //Appuie sur F2 -> Activation de la cloche n°2
	   test->cloche2();
  }
  if (Key==VK_F3) {           //Appuie sur F3 -> Activation de la cloche n°3
	   test->cloche3();
  }
  if (Key==VK_F4) {           //Appuie sur F4 -> Activation de la cloche n°4
		test->cloche4();
  }
  if (Key==VK_F5) {           //Appuie sur F5 -> Activation de toutes les cloches
		test->toutCloche();
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
     //Bouton 7 -> Activation de la mélodie des cloches
	test->cloche3();
	test->cloche1();
	test->cloche4();
	test->cloche2();
	test->cloche1();
	test->cloche4();
	test->cloche2();
	test->cloche3();
	test->toutCloche();

}
//---------------------------------------------------------------------------

