/****************************************************************************
*

*****************************************************************************
*
*  	BUT : Etablire une connexion avec le port serie, lire des information ou en
*         envoyer .
*
*****************************************************************************/

#ifndef comH
#define comH
//---------------------------------------------------------------------------
#endif

#include <windows.h>
class Com       // Classe qui permet de se connecter au port RS232
{
	HANDLE hcom;
	DCB serie;
	OVERLAPPED over;
	public :
	bool Ouverture(int vitesse_Bit,int data_Size); //ouvre la connexion au port com
	void fermeture(); //ferme la connexion au port com
	void ecriture(char *t); //envoie un char
	char * lecture();   // retourne un char
};
