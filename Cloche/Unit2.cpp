//---------------------------------------------------------------------------
#include <winsock2.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
cloche::cloche(SOCKET sock)
{
    this->sock = sock;
}
cloche::~cloche()
{

}

void cloche::cloche1()
{

	char buffer[11]; //Initialisation de la trame pour faire fonctionner la cloche n°1
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;
	buffer[5]=0x06;
	buffer[6]=0x00;
	buffer[7]=0x06;
	buffer[8]=0x00;
	buffer[9]=0x02;
	buffer[10]=0x00;
	buffer[11]=0x01;

	char marteau[11]; //Initialisation de la trame pour arreter la cloche n°1
	marteau[0]=0x00;
	marteau[1]=0x00;
	marteau[2]=0x00;
	marteau[3]=0x00;
	marteau[4]=0x00;
	marteau[5]=0x06;
	marteau[6]=0x00;
	marteau[7]=0x06;
	marteau[8]=0x00;
	marteau[9]=0x02;
	marteau[10]=0x00;
	marteau[11]=0x00;

	send(sock, buffer, 12, 0); //Znvoie de toute la trame buffer pour actionner la cloche
	send(sock, marteau, 12, 0); //Envoie de toute la trame marteau pour arrêter la cloche
	Sleep(250);      //Delai de 250ms

}
void cloche::cloche2()
{

	char buffer[11]; //Initialisation de la trame pour faire fonctionner la cloche n°2
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;
	buffer[5]=0x06;
	buffer[6]=0x00;
	buffer[7]=0x06;
	buffer[8]=0x00;
	buffer[9]=0x02;
	buffer[10]=0x00;
	buffer[11]=0x02;

	char marteau[11]; //Initialisation de la trame pour arreter la cloche n°2
	marteau[0]=0x00;
	marteau[1]=0x00;
	marteau[2]=0x00;
	marteau[3]=0x00;
	marteau[4]=0x00;
	marteau[5]=0x06;
	marteau[6]=0x00;
	marteau[7]=0x06;
	marteau[8]=0x00;
	marteau[9]=0x02;
	marteau[10]=0x00;
	marteau[11]=0x00;

	send(sock, buffer, 12, 0); //Znvoie de toute la trame buffer pour actionner la cloche
	send(sock, marteau, 12, 0);  //Envoie de toute la trame marteau pour arrêter la cloche
	Sleep(250);

}
void cloche::cloche3()
{

	char buffer[11];  //Initialisation de la trame pour faire fonctionner la cloche n°3
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;
	buffer[5]=0x06;
	buffer[6]=0x00;
	buffer[7]=0x06;
	buffer[8]=0x00;
	buffer[9]=0x02;
	buffer[10]=0x00;
	buffer[11]=0x04;
	char marteau[11];  //Initialisation de la trame pour arreter la cloche n°3
	marteau[0]=0x00;
	marteau[1]=0x00;
	marteau[2]=0x00;
	marteau[3]=0x00;
	marteau[4]=0x00;
	marteau[5]=0x06;
	marteau[6]=0x00;
	marteau[7]=0x06;
	marteau[8]=0x00;
	marteau[9]=0x02;
	marteau[10]=0x00;
	marteau[11]=0x00;

	send(sock, buffer, 12, 0); //Znvoie de toute la trame buffer pour actionner la cloche
	send(sock, marteau, 12, 0); //Envoie de toute la trame marteau pour arrêter la cloche
	Sleep(250);  //Pause

}
void cloche::cloche4()
{

	char buffer[11];  //Initialisation de la trame pour faire fonctionner la cloche n°4
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;
	buffer[5]=0x06;
	buffer[6]=0x00;
	buffer[7]=0x06;
	buffer[8]=0x00;
	buffer[9]=0x02;
	buffer[10]=0x00;
	buffer[11]=0x08;

	char marteau[11]; //Initialisation de la trame pour arreter la cloche n°4
	marteau[0]=0x00;
	marteau[1]=0x00;
	marteau[2]=0x00;
	marteau[3]=0x00;
	marteau[4]=0x00;
	marteau[5]=0x06;
	marteau[6]=0x00;
	marteau[7]=0x06;
	marteau[8]=0x00;
	marteau[9]=0x02;
	marteau[10]=0x00;
	marteau[11]=0x00;

	send(sock, buffer, 12, 0);     //Envoie de toute la trame buffer pour faire sonner la cloche
	send(sock, marteau, 12, 0);    //Envoie de toute la trame marteau pour arrêter la cloche
	Sleep(250);

}
void cloche::toutCloche()
{

	char buffer[11]; //Initialisation de la trame pour faire fonctionner toutes les cloches
	buffer[0]=0x00;
	buffer[1]=0x00;
	buffer[2]=0x00;
	buffer[3]=0x00;
	buffer[4]=0x00;
	buffer[5]=0x06;
	buffer[6]=0x00;
	buffer[7]=0x06;
	buffer[8]=0x00;
	buffer[9]=0x02;
	buffer[10]=0x00;
	buffer[11]=0x0F;

	char marteau[11];//Initialisation de la trame pour arreter toutes les cloches
	marteau[0]=0x00;
	marteau[1]=0x00;
	marteau[2]=0x00;
	marteau[3]=0x00;
	marteau[4]=0x00;
	marteau[5]=0x06;
	marteau[6]=0x00;
	marteau[7]=0x06;
	marteau[8]=0x00;
	marteau[9]=0x02;
	marteau[10]=0x00;
	marteau[11]=0x00;

	send(sock, buffer, 12, 0); //Envoie de toute la trame pour faire sonner toutes les cloches
	send(sock, marteau, 12, 0); //Envoie de toute la trame pour arrêter les cloches
	Sleep(250);
}
