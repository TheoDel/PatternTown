#ifndef MAISON_H
#define MAISON_H

#include "Observable.h"
#include "Batiment.h"
#include <string>


// Classe concrete de Batiment
class Maison : public Batiment {

	private :

		// vide ( pour l'instant ? )


	public:

		// Constructeurs/Destructeurs
			Maison( int id, std::string nom, std::string description );
			~Maison();

};

#endif
