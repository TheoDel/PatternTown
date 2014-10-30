#include "Bucheron.h"

#include <string>
#include <iostream>

using namespace std;



Bucheron::Bucheron( Villageois* v ) : Competence( v->get_Village() ) {
	id_ = v->get_id();
	nom_ = v->get_Nom();
	description_ = "Bucheron";
	villageois_ = v;
}


Bucheron::~Bucheron() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



string Bucheron::get_Description() {
	return ( villageois_->get_Description() + ", " + description_ );
}

int Bucheron::recolter_Bois() {
    cout << endl << nom_ << " coupe du bois comme un pro !";
	return 5;
}

void Bucheron::afficher() {
	villageois_->afficher();
	cout << ", " << description_;
}
