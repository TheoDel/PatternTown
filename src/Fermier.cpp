#include "Fermier.h"

#include <string>
#include <iostream>

using namespace std;



Fermier::Fermier( Villageois& v ) :
	Competence(v) {
	description_ = "Fermier";
}


Fermier::~Fermier() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// @Override
// renvoie un entier lié a la quantite de nourriture recoltée
int Fermier::recolter_Nourriture() {
    if ( villageois_.get_Energie() < 1 ){
        cout << villageois_.get_Nom() << ", a beau etre un pro pour cultiver, il est trop fatigue..." << endl ;
        return 0;
    } else {
        cout << villageois_.get_Nom() << " recolte avec talent !" << endl ;
        villageois_.change_Energie(-1);
        return 5;
    }
}
