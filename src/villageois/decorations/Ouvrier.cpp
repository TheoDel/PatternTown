#include "Ouvrier.h"

#include <string>
#include <iostream>

using namespace std;



Ouvrier::Ouvrier( Villageois& v ) :
	Competence(v) {
	description_ = "Ouvrier du batiment";
}


Ouvrier::~Ouvrier() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// @Override
// cree un nouveau batiment
Batiment* Ouvrier::construire_Batiment( Batiment* b ) {
	if ( get_Energie() < 10 ) {
		cout << get_Nom() << " est trop fatigué pour construire !" << endl;
		delete b; // suppression du batiment créé
		b = nullptr;
		return b;
	} else {
		cout << get_Nom() << " a construit le batiment !" << endl;
		change_Energie(-10);
		return b;
	}
}
