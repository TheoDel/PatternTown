#include "Competence.h"

#include <iostream>

using namespace std;



Competence::Competence( Villageois& v ) : villageois_(v) {}


Competence::~Competence() {
	delete &villageois_;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// @Override
// retourne l'id du villageois
int Competence::get_id() {
	return villageois_.get_id();
}


// @Override
// retourne le nom du villageois
string Competence::get_Nom() {
	return villageois_.get_Nom();
}


// @Override
// retourne la description complete du villageois
string Competence::get_Description() {
	return ( villageois_.get_Description() + ", " + description_ );
}


// @Override
// retourne le vie du villageois
int Competence::get_Vie() {
	return villageois_.get_Vie();
}


// @Override
// retourne l'energie ( = points d'action ) du villageois
int Competence::get_Energie() {
	return villageois_.get_Energie();
}


// @Override
// retourne la satisfaction ( positif=heureux, negatif=mecontent ) du villageois
int Competence::get_Satisfaction() {
	return villageois_.get_Satisfaction();
}


// @Override
// retourne le villageois décoré (par ex. pour supprimer la competence actuelle)
Villageois* Competence::get_Villageois() {
	return &villageois_;
}


// @Override
// retourne la donnee
string Competence::get_Donnee() {
	return villageois_.get_Donnee();
}


// @Override
// retourne l'observable associé
Observable* Competence::get_Observable() {
	return villageois_.get_Observable();
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// @Override
// modifie la description du villageois
void Competence::set_Description( string d ){
	villageois_.set_Description(d);
}


// @Override
// incremente ou decremente la vie du villageois
void Competence::change_Vie( int val ) {
	villageois_.change_Vie(val);
}


// @Override
// incremente ou decremente l'energie ( = points d'action ) du villageois
void Competence::change_Energie( int val ) {
	villageois_.change_Energie(val);
}


// @Override
// incremente ou decremente la satisfaction ( = points d'action ) du villageois
void Competence::change_Satisfaction( int val ) {
	villageois_.change_Satisfaction(val);
}


// @Override
// modifie l'observable actuel
void Competence::set_Observable( Observable* obs ) {
	villageois_.set_Observable(obs);
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// @Override
// renvoie un entier lié a la quantite de bois coupé
int Competence::recolter_Bois() {
	return villageois_.recolter_Bois();
}


// @Override
// renvoie un entier lié a la quantite de nourriture recoltée
int Competence::recolter_Nourriture() {
	return villageois_.recolter_Nourriture();
}


// @Override
// cree un nouveau batiment
Batiment* Competence::construire_Batiment( Batiment* b ) {
	return villageois_.construire_Batiment( b );
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// @Override
// actualise la donnee
void Competence::actualiser( string d ) {
	villageois_.actualiser(d);
}
