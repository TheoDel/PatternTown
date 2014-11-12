#ifndef FERMIER_H
#define FERMIER_H

#include "Competence.h"


// Decorator concret
class Fermier : public Competence {

	public :

		// Constructeurs/Destructeurs
			Fermier( Villageois& v );
			~Fermier();

		// Getters
			int recolter_Nourriture();		//@Override

};

#endif
