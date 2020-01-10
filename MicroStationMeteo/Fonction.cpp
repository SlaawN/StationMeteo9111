//---------------------------------------------------------------------------

#pragma hdrstop

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "Fonction.h"
#include "K8055D.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)


Fonction :: Fonction ()
{

}

Fonction :: ~Fonction ()
{
   if(this->etat == true)
   {
	   CloseDevice();
   }
}

int Fonction :: Connexion (long adr)
{
	 this->adr = adr;
	 long h = OpenDevice(adr);

	 if (h == -1)
	 {
		success = -1;
		return success;
	 }
	 else
	 {
		 success = 1;
		 return success;
     }
}


bool Fonction :: getEtat ()
{
	return this->etat;
}

long Fonction :: ReadAnalogChannel(long channel)
{
	if( etat && (channel == 2) )
	{
        return ReadAnalogChannel(channel);
	}

	return -1;
}