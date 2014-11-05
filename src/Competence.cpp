#include "Competence.h"

#include <iostream>

using namespace std;



Competence::Competence( Villageois* v ) {
	villageois_ = v;
}


Competence::~Competence() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// @Override
// retourne l'id du villageois
int Competence::get_id() {
	return villageois_->get_id();
}


// @Override
// retourne le nom du villageois
string Competence::get_Nom() {
	return villageois_->get_Nom();
}


// @Override
// retourne la description complete du villageois
string Competence::get_Description() {
	return ( villageois_->get_Description() + ", " + description_ );
}


// @Override
// retourne le vie du villageois
int Competence::get_Vie() {
	return villageois_->get_Vie();
}


// @Override
// retourne l'energie ( = points d'action ) du villageois
int Competence::get_Energie() {
	return villageois_->get_Energie();
}


// @Override
// retourne la satisfaction ( positif=heureux, negatif=mecontent ) du villageois
int Competence::get_Satisfaction() {
	return villageois_->get_Satisfaction();
}


// @Override
// retourne un pointeur sur le village auquel appartient le villageois
Village* Competence::get_Village() {
	return villageois_->get_Village();
}


// @Override
// retourne le villageois racine
Villageois* Competence::get_Villageois() {
	return villageois_->get_Villageois();
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



/*
// @Override
// modifie la description du villageois
void Competence::set_Description( string d ){

}
*/


// @Override
// modifie le village de rattachement
void Competence::set_Village( Village* v ) {
	villageois_->set_Village(v);
}


// incremente ou decremente la vie du villageois
void Competence::change_Vie( int val ) {
	villageois_->change_Vie(val);
}


// incremente ou decremente l'energie ( = points d'action ) du villageois
void Competence::change_Energie( int val ) {
	villageois_->change_Energie(val);
}


// incremente ou decremente la satisfaction ( = points d'action ) du villageois
void Competence::change_Satisfaction( int val ) {
	villageois_->change_Satisfaction(val);
}
