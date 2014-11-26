#ifndef BUCHERON_H
#define BUCHERON_H

#include "Competence.h"


// Decorator concret
class Bucheron : public Competence {

	public :

		// Constructeurs/Destructeurs
			Bucheron( Villageois& v );
			~Bucheron();

		// Actions de jeu
			int recolter_Bois();			//@Override

};

#endif
