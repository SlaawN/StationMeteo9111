//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include <string.h>
#include <deque>
#include <vector>
#include <sstream>
#define __WIN__
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
// Thread permettant de recuperer les donn�es du gps en boucle afin d'avoir
// toutes les trames en meme temps
DWORD WINAPI TForm1::RecvThread(LPVOID params)
{
	TForm1 * form = (TForm1*)params;

	while(1)
	{
		WaitForSingleObject(form->sync, INFINITE);
		form->port->lireport();

		std::deque<char> & buf = form->port->getRecvBuf();
		std::vector<char> trame;

		bool bFound = false;
		int idx = -1;
		// test si on est en fin de ligne de trame
		for(int i = 0; i < buf.size(); i++)
		{
			trame.push_back(buf[i]);
			if(buf[i] == '\n' || buf[i] == '\r')
			{
				idx = i + 1;
				bFound = true;
				break;
			}
		}
		// si on est en fin de ligne supprime la 1ere valeur
		if(bFound)
		{
			for(int i = 0; i < idx; i++)
			{
				buf.pop_front();
			}

			while(buf.size() > 0 && buf[0] != '$')
			{
                buf.pop_front();
            }

			form->trames.push_back(trame);
        }

		ReleaseMutex(form->sync);
	}
}

//---------------------------------------------------------------------------
// ouverture de l'IHM
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	port = new PortRS();


	Label2->Visible = false;
	Label3->Visible = false;
    Label4->Visible = false;
	Memo1->Visible = false;
	Memo2->Visible = false;
	Memo3->Visible = false;
	sync = CreateMutex(NULL, FALSE, NULL);

}
//---------------------------------------------------------------------------


// bouton ouvrir port
// permet la connexion avec le port com
void __fastcall TForm1::OuvrirPort1Click(TObject *Sender)
{
	int error;
	error = port->ouvrirport();
	if(error != 0)
	{
		char buffer[20];

		itoa(GetLastError(),buffer,10);   // here 10 means decimal
		//printf("Decimal value = %s\n", buffer);


		MessageBox(NULL, buffer, "Fail", 0);
	}
	Button3->Enabled = false;
	Label2->Visible = true;
	Label3->Visible = true;
	Label4->Visible = true;
	Memo1->Visible = true;
	Memo2->Visible = true;
	Memo3->Visible = true;


	DWORD threadId;
	CreateThread(NULL, 0, &RecvThread, this, 0, &threadId);
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
// fonction permettant de recuperer les donn�es depuis le port RS232
void __fastcall TForm1::LirePort1Click(TObject *Sender)
{

	int i=0;
	port->lireport();
	std::deque<char> & buf = port->getRecvBuf();

	UnicodeString str = "";
	Memo1->Visible = true;

	/*
	do
	{
		str +=buf[i];
		i++;
		Label2->Caption = str;

	}
	while (i != buf.size());
	*/
}
//---------------------------------------------------------------------------



//envoie de trames pour le logiciel hercules
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
//	char * buffer;
//	int value;
//	if (Key == VK_RETURN)
//	{
//		buffer = (char*) malloc (100);
//		wcstombs ( buffer, Edit1->Text.c_str(), sizeof(buffer) )  ;
//		port->ecrireport(buffer, strlen(buffer) + 1);
//		Edit1->Visible = false;
//		Label1->Visible = false;
//	}
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------



// fermeture de l'IHM
void __fastcall TForm1::FermerPort1Click(TObject *Sender)
{
	Button4->Enabled = false;
	Button3->Enabled = true;
	Form1->Close();
}
//---------------------------------------------------------------------------




// initilasation � la BDD de la VM
// Traduction de la trame pour recuperer uniquement les coordonn�es
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	WaitForSingleObject(sync, INFINITE);
	UnicodeString longitudedegres = "";
	UnicodeString longitudesecondes = "";
	UnicodeString longitudeminutes = "";
	UnicodeString latitudedegres = "";
	UnicodeString latitudesecondes = "";
	UnicodeString latitudeminutes = "";
	UnicodeString str = "";
	UnicodeString Temperature = "";
	UnicodeString Profondeur = "";
 // connexion � la base


	for(int j = 0; j < trames.size(); j++)
	{
		std::vector<char> buf = trames[j];
		int i = 0;
		do
		{
		// verification de la trame  des cordonn�es puis d�coupage
		if (buf[i] == '$' && buf[i+1] == 'G' && buf[i+2] == 'P' && buf[i+3] == 'G' && buf[i+4] == 'G' && buf[i+5] == 'A') {
			int j=i+6;
			if (buf[j]== ','){
				int z=j+8;
				for (int k = 0; k < 10; k++)
				{
					if (k==1){
						latitudedegres +=buf[z-1];
					}
					if (k==2) {
					  // z++;
						latitudedegres +=buf[z-1];
					}
					if (k==3)  {
						latitudeminutes += buf[z-1];
					}
					if (k==4) {
						latitudeminutes += buf[z-1];
						latitudeminutes = (latitudeminutes/60);
					}
					if (k==6) {
						latitudesecondes += buf[z-1];
					}
					if (k==7) {
						latitudesecondes += buf[z-1];
						latitudesecondes = (latitudesecondes/3600);
					}
					if (k==9) {
						z++;
					}
					z++;
				}
				z++;
				//ajout des trames d�coup�s dans une nouvelle variable
				latitude = (latitudedegres.ToDouble()+latitudeminutes.ToDouble()+latitudesecondes.ToDouble());
				for (int k = 10; k < 21; k++)
				{

					if (k==11){
						longitudedegres +=buf[z-1];
					}
					if (k==12) {
						longitudedegres +=buf[z-1];
					}
					if (k==13)  {
						longitudedegres += buf[z-1];
					}
					if (k==14) {
						longitudeminutes += buf[z-1];
					}
					if (k==15) {
						longitudeminutes += buf[z-1];
						longitudeminutes = (longitudeminutes/60);
					}
					if (k==17) {
						longitudesecondes += buf[z-1];
					}
					if (k==18) {
						longitudesecondes +=buf[z-1];
						longitudesecondes = (longitudesecondes/3600);
					}
					z++;
				}
			//ajout des trames d�coup�s dans une nouvelle variable
			longitude = (longitudedegres.ToDouble()+longitudeminutes.ToDouble()+longitudesecondes.ToDouble());
			}
		// ajout des coordonn�es dans 2 memo diff�rent
		Memo2->Lines->Add(latitude);
		Memo3->Lines->Add(longitude);
		}
		// verification de la trame de la temp�rature
		if (buf[i] == '$' && buf[i+1] == 'S' && buf[i+2] == 'D' && buf[i+3] == 'M' && buf[i+4] == 'T' && buf[i+5] == 'W') {
			j=i+8;
			for (int z = 0; z<5; z++){
			   Temperature += buf[j];
			   j++;
			}
			Memo5->Lines->Add(Temperature);
		}
		// verification de la trame de la profondeur
		if (buf[i] == '$' && buf[i+1] == 'S' && buf[i+2] == 'D' && buf[i+3] == 'D' && buf[i+4] == 'P' && buf[i+5] == 'T') {
			int a=i+9;
			for (int z = 0; z <3; z++){
				Profondeur  += buf[a];
				a++;
			}
			Memo4->Lines->Add(Profondeur);
	  }

	str += buf[i];
	i++;

	}while (i < buf.size());
	Memo1->Lines->Add(str);
	}

	trames.clear();

	ReleaseMutex(sync);
}
//---------------------------------------------------------------------------





