#ifndef COMPETENCE_H
#define COMPETENCE_H

#include "Villageois.h"


// Decorator
class Competence : public Villageois { 

	protected :
		Villageois* villageois_;
	

	public :
		Competence( Village* v );
		~Competence();		

};

#endif
