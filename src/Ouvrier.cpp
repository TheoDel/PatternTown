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
	if ( get_Energie() < 50 ) {
		cout << get_Nom() << " est trop fatigué pour construire !" << endl;
		return nullptr;
	} else {
		change_Energie(-50);
		return b;
	}
}
