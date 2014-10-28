#ifndef BUCHERON_H
#define BUCHERON_H

#include "Competence.h"


// Decorator concret
class Bucheron : public Competence {

	public :

		Bucheron( Villageois* v );
		~Bucheron();

		int recolter_Bois();
		std::string get_Description();
		void afficher();

};

#endif
