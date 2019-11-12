//---------------------------------------------------------------------------

#pragma hdrstop


#include "C9111.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)

C9111::C9111()
{

}

C9111::~C9111()
{

}

void C9111::Initialisation()
{
	ID_CARD=Register_Card(PCI_9111DG,0); // référencement de la carte
	if (ID_CARD>=0)
	{
		   //	Label1->Visible=true; // carte présente dans le PC
			AO_9111_Config(ID_CARD,P9111_AO_UNIPOLAR); // init sortie analogique
			AO_VWriteChannel(ID_CARD,0,0); // 0v en sortie analogique
			AI_9111_Config(ID_CARD,TRIG_INT_PACER,P9111_TRGMOD_SOFT,0);
	} //init Entrée analogique

	//else Label2->Visible=true; // erreur - carte inexistante
}




