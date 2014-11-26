#ifndef OUVRIER_H
#define OUVRIER_H

#include "Competence.h"


// Decorator concret
class Ouvrier : public Competence {

	public :

		// Constructeurs/Destructeurs
			Ouvrier( Villageois& v );
			~Ouvrier();

		// Actions de jeu
			Batiment* construire_Batiment( Batiment* b );	//@Override

};

#endif
