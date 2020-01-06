//---------------------------------------------------------------------------
// Programme : TP4- FOUR                     			Date :25/11/2019
//---------------------------------------------------------------------------
// Programmeur :  BOURY Aurélien                         classe : BTSSN2
//---------------------------------------------------------------------------
// BUT : "Pilotage" du four à distance : choisir la température de chauffe et son pourcentage
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#pragma hdrstop

#include "PILOTFOUR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

four::four()
{
		IdCarte=Register_Card(PCI_9111DG,0);     // On initie la carte

		AO_9111_Config(IdCarte,P9111_AO_UNIPOLAR);  // On paramètre notre sortie

		AO_VWriteChannel(IdCarte,1,0);       // On envoie 0v sur la sortie

		AI_9111_Config(IdCarte,TRIG_INT_PACER,P9111_TRGMOD_SOFT,0); // on configure notre entrée

}

four::~four()
{
	Release_Card(IdCarte);

}

int four::Lecture()
{
	  double tension;
		AI_VReadChannel(IdCarte,1, AD_B_10_V, &tension);    // lecture sur le port 1
	return  (51*tension)-73;
;

}

void four::Ecriture(float tension)
{
		AO_VWriteChannel(IdCarte,0,tension);
}
