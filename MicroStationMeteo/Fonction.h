//---------------------------------------------------------------------------

#ifndef FonctionH
#define FonctionH

class Fonction
{
private:
	// D�claration des attributs :
			long adr;		// Attribut adr

					// Attribut etat

public:
		bool etat;
	// D�claration des m�thodes :
	// D�claration du constructeur :
		Fonction();

	// D�claration du destructeur :
		~Fonction();

		int Connexion(long adr);

	// D�claration de getEtat :
		bool getEtat();

	// D�claration de lireAna :
		long ReadAnalogChannel(long channel);
};

//---------------------------------------------------------------------------
#endif
