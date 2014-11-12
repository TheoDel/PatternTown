#ifndef VILLAGEOIS_C_H
#define VILLAGEOIS_C_H

#include "Villageois.h"


// Classe concrete de villageois
class VillageoisConcret : public Villageois {

	private :

		// vide ( pour l'instant ? )


    public :

		// Constructeurs/Destructeurs
			VillageoisConcret( int id, std::string nom, std::string description );
			~VillageoisConcret();

};

#endif
