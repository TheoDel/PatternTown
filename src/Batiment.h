#if !define BATIMENT_H
#define BATIMENT_H

#include <string>


class Batiment {	// Classe abstraite

	protected :
		string nom_;

	public :
		Batiment();					//constructeur
		virtual ~Batiment() = 0 ;	//destructeur virtuel pur

};

#endif
