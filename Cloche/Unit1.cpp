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
		/* Création du socket */
		sock = socket(AF_INET, SOCK_STREAM, 0);

		/* Connexion aux cloches */
		sin.sin_addr.s_addr = inet_addr("192.168.64.124");
		sin.sin_family = AF_INET;
			sin.sin_port = htons(502);

		/* Si la connexion réussie */
		if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
		{
            // affichage des boutons
			Button1->Visible=false;
			Button2->Visible=true;
			Button3->Visible=true;
			Button4->Visible=true;
			Button5->Visible=true;
			Button6->Visible=true;
			Button7->Visible=true;
			Edit1->Visible=true;
            test = new cloche(sock);
		}
		else
		{
		 // connexion non valide
		}

	}
}
//---------------------------------------------------------------------------
// activation cloche 1
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	test->cloche1();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
  /* On ferme la socket précédemment ouverte */
	closesocket(sock);
	delete test;
	#if defined (WIN32)
		WSACleanup();
	#endif
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	test->cloche2();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	test->cloche3();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	test->cloche4();
}
//---------------------------------------------------------------------------


//Permet d'activer les cloches via les touches "F1,F2,F3,F4 et F5" dans la carré gris
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
  if (Key==VK_F1) {
		test->cloche1();
  }
  if (Key==VK_F2) {
	   test->cloche2();
  }
  if (Key==VK_F3) {
	   test->cloche3();
  }
  if (Key==VK_F4) {
		test->cloche4();
  }
  if (Key==VK_F5) {
		test->toutCloche();
  }

}
//---------------------------------------------------------------------------

//Bouton 7 -> Mélodie des cloches
void __fastcall TForm1::Button7Click(TObject *Sender)
{

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

