#include "Batiment.h"

#include <iostream>

using namespace std;
int Batiment::NEXTID_ = 1;



Batiment::Batiment( string nom, string description ) :
		id_(NEXTID_), nom_(nom), description_(description) { ++NEXTID_; }


Batiment::~Batiment() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// retourne l'id du batiment
int Batiment::get_id(){
	return id_;
}


// retourne le nom (type) du batiment
string Batiment::get_Nom(){
	return nom_;
}


// retourne la description du atiment
string Batiment::get_Description() {
	return description_;
}


// modifie la descriptiondu batiment
void Batiment::set_Description( string d ) {
	description_ = d;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void Batiment::afficher() {
	cout << get_id() << "-" << get_Nom() << " : " << get_Description() << endl;
}
