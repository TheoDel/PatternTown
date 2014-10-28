#ifndef VILLAGEOIS_C_H
#define VILLAGEOIS_C_H

#include "Villageois.h"


// Classe concrete de villageois
class VillageoisConcret : public Villageois {

    public :

		VillageoisConcret( int id, std::string nom, std::string d, Village* v );
		virtual ~VillageoisConcret();

};

#endif
