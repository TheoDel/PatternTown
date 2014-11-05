#include "Bucheron.h"

#include <string>
#include <iostream>

using namespace std;



Bucheron::Bucheron( Villageois* v ) :
	Competence(v) {
	description_ = "Bucheron";
}


Bucheron::~Bucheron() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



/*
string Bucheron::get_Description() {
	return ( villageois_->get_Description() + ", " + description_ );
}
*/

int Bucheron::recolter_Bois() {
    if ( villageois_->get_Energie() < 1 ){
        cout << villageois_->get_Nom() << ", a beau etre un pro pour couper du bois, il est trop fatigue..." << endl ;
        return 0;
    } else {
        cout << villageois_->get_Nom() << " coupe du bois comme un pro !" << endl ;
        villageois_->change_Energie(-1);
        return 5;
    }
}

/*
void Bucheron::afficher() {
	villageois_->afficher();
	cout << ", " << description_;
}*/
