#ifndef BUCHERON_H
#define BUCHERON_H

#include "Competence.h"


// Decorator concret
class Bucheron : public Competence {

	public :

		// Constructeurs/Destructeurs
			Bucheron( Villageois& v );
			~Bucheron();

		// Getters
			int recolter_Bois();			//@Override

};

#endif
