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

		Villageois* get_Villageois();

		virtual std::string get_Description();
		virtual void afficher();
};

#endif
