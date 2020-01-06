//---------------------------------------------------------------------------
// Programme : TP6- DMX                     				Date :16/12/2019
//---------------------------------------------------------------------------
// Programmeur :  BOURY Aurélien                         classe : BTSSN2
//---------------------------------------------------------------------------
// BUT : "Pilotage" lumière DMX
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "include/DasHard.h.h"
#include <winsock2.h>
	typedef int socklen_t;
#include "Unit1.h"
#include "colors.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Web.Win.Sockets"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
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
		g_dasusbdll=LoadLibrary(L"DasHard2006.dll");
		if(g_dasusbdll)
		{
			DasUsbCommand=(DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll,"DasUsbCommand");
		}
		interface_open=DasUsbCommand(DHC_INIT,0,NULL);
		DasUsbCommand(DHC_OPEN,0,0);

		if (interface_open == 136)
		{
		   Connect->Color = clLime;
		}
		else
		{
			Connect->Color = clRed;
		}

		for (int i = 0; i < 512; i++)
		{
			dmxBlock[i]=0;
		}
		dmxBlock[0]=0xFF;
		dmxBlock[1]=0xFF;
		dmxBlock[2]=0xFF;
		dmxBlock[3]=0xFF;
		dmxBlock[4]=0xFF;
		dmxBlock[5]=0xFF;

	}
	dmx = new Couleurs(dmxBlock);  //instanciation d'un nouvel attribut de classe
}

//---------------------------------------------------------------------------
 void __fastcall TForm1::SendTrame()
 {
	if(interface_open>0)
	{
		try
		{
			DasUsbCommand(DHC_DMXOUT,DMX_MAXCHANNEL,dmxBlock);  //methode d'envoi de trames
		}
		catch(int x)
		{
		}
	}

 }

 void __fastcall TForm1::FormClose(TObject*Sender,TCloseAction&Action)
 {
 //FermetureduDMX�l'arretduprogramme
	if(interface_open>0)
	{
		DasUsbCommand(DHC_CLOSE,0,0);
		DasUsbCommand(DHC_EXIT,0,NULL);
	}
	if(g_dasusbdll!=NULL)
	FreeLibrary(g_dasusbdll);
 }

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	SendTrame();//on envoi en continu les trames dmxBlock[]
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BleuClick(TObject *Sender)
{
	dmx->Bleu();//appel fonction bleu
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BlancClick(TObject *Sender)
{
	dmx->Blanc(); //appel fonction blanc
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RougeClick(TObject *Sender)
{
	dmx->Rouge();//appel fonction rouge
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ONClick(TObject *Sender)
{
	dmx->ON();//appel fonction Allumage
	Connect->Color = clLime;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OFFClick(TObject *Sender)
{
	dmx->OFF();//appel fonction Fermeture
	Connect->Color = clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StroboscopeClick(TObject *Sender)
{
	dmx->Stroboscope();//appel fonction Stroboscope
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VertClick(TObject *Sender)
{
    dmx->Vert(); //appel fonction Vert
}
//---------------------------------------------------------------------------


