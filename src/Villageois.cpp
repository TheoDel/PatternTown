#include "Villageois.h"

#include <iostream>

using namespace std;



Villageois::Villageois( Village* v ) : vie_(100), energie_(5), satisfaction_(0), village_(v) {}


Villageois::~Villageois() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// retourne le nom du villageois
string Villageois::get_Nom() {
	return nom_;
}


// retourne la description du villageois
string Villageois::get_Description() {
	return ( "\n" + description_ );
}


// retourne l'id du villageois
int Villageois::get_id() {
	return id_;
}


// retourne le vie du villageois
int Villageois::get_Vie() {
	return vie_;
}

// retourne l'energie ( = points d'action ) du villageois
int Villageois::get_Energie() {
	return energie_;
}


// retourne la satisfaction ( positif=heureux, negatif=mecontent ) du villageois
int Villageois::get_Satisfaction() {
	return satisfaction_;
}


// retourne un pointeur sur le village auquel appartient le villageois
Village* Villageois::get_Village() {
	return village_;
}


Villageois* Villageois::get_Villageois() {
	return this;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// modifie la decription du villageois
void Villageois::set_Description( string d ){
	description_ = d;
}


// incremente ou decremente la vie du villageois
void Villageois::change_Vie( int val ) {
	vie_ += val;
}


// incremente ou decremente l'energie ( = points d'action ) du villageois
void Villageois::change_Energie( int val ) {
	energie_ += val;
}


// incremente ou decremente la satisfaction ( = points d'action ) du villageois
void Villageois::change_Satisfaction( int val ) {
	satisfaction_ += val;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



int Villageois::recolter_Bois() {
	return 1;
}


int Villageois::recolter_Nourriture() {
	return 1;
}


void Villageois::construire_Batiment() {
}


void Villageois::afficher() {
	cout << endl << nom_ << " : " << description_;
}
