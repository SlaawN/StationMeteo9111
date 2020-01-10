//---------------------------------------------------------------------------

#ifndef FonctionH
#define FonctionH

class Fonction
{
private:
	// Déclaration des attributs :
			long adr;		// Attribut adr

					// Attribut etat

public:
		bool etat;
	// Déclaration des méthodes :
	// Déclaration du constructeur :
		Fonction();

	// Déclaration du destructeur :
		~Fonction();

		int Connexion(long adr);

	// Déclaration de getEtat :
		bool getEtat();

	// Déclaration de lireAna :
		long ReadAnalogChannel(long channel);
};

//---------------------------------------------------------------------------
#endif
