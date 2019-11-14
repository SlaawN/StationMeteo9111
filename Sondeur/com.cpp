#pragma hdrstop

#include "com.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



bool Com::Ouverture(int vitesse_Bit,int data_Size)    //ouvre la connexion au port com1
{
   bool retour = false;
   hcom = CreateFile(L"COM1",                      //nom du port com rs232 generalement com1
					 GENERIC_WRITE|GENERIC_READ,   // on veut ecrire et lire
					 0,        					   //0 -> ignore
					 NULL,OPEN_EXISTING,           //NULL -> ignore
					 FILE_FLAG_NO_BUFFERING,       // OPEN_EXISTING -> ignore
					 NULL);                        //   NULL  -> ignore

   if (hcom == INVALID_HANDLE_VALUE){ 		//si le HANDLE EST INVALIDE
		retour=false;
   }
   else{
		retour=true;
		GetCommState(hcom,&serie);
		serie.BaudRate = vitesse_Bit;    	//vitesse port serie
		serie.ByteSize = data_Size;         //nombre de bit
		serie.Parity = NOPARITY;            //parité  ici : non
		serie.StopBits =ONESTOPBIT;         //nombre de bit de stop max2
		SetCommState(hcom,&serie);          //sauvgarde la config
   }

   return retour;
}
void Com::fermeture() //ferme la connexion au port com1
{
	CloseHandle(hcom);
}
void Com::ecriture(char *t) //envoie un char
{
	unsigned long pt=0;
	WriteFile(hcom,t,strlen(t),&pt,NULL);
	PurgeComm(hcom,PURGE_TXCLEAR);
}
char * Com::lecture()  // retourne un char
{
	int size=700;
	char *chaine;
	unsigned long pt;
	pt=0;
	chaine=new char[size+1];
	chaine[0]='\0';
	ReadFile(hcom,chaine,size,&pt, NULL);
	PurgeComm(hcom,PURGE_RXCLEAR);

	return chaine;
}
