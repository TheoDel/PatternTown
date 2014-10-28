#ifndef VILLAGEOIS_C_H
#define VILLAGEOIS_C_H

#include "Villageois.h"


// classe CONCRETE de villageois
class VillageoisConcret : public Villageois {

    private:


	public :

		VillageoisConcret( int id, std::string nom, std::string d, Village* v );
		~VillageoisConcret();

};

#endif
