#include "Villageois.h"

#include <iostream>

using namespace std;







Villageois::Villageois( int id, std::string n, std::string d, Village* v ) :
	id_(id), nom_(n), vie_(100), energie_(5),
	satisfaction_(0), village_(v), description_(d) {}

Villageois::Villageois() {}

Villageois::~Villageois() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// retourne l'id du villageois
int Villageois::get_id() {
	return id_;
}


// retourne le nom du villageois
string Villageois::get_Nom() {
	return nom_;
}


// retourne la description complete du villageois
string Villageois::get_Description() {
	return description_;
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


// retourne le villageois racine
Villageois* Villageois::get_Villageois() {
	return this;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// modifie la description du villageois
void Villageois::set_Description( string d ){
	description_ = d;
}


// modifie le village de rattachement
void Villageois::set_Village( Village* v ) {
	village_ = v;
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



// renvoie un entier lié a la quantite de bois coupé
int Villageois::recolter_Bois() {
    if (energie_ < 1){
        cout << nom_ << ", non content d'etre incompetent pour couper du bois, est trop fatigue..." << endl;
        return 0;
    } else {
        cout << nom_ << " coupe du bois comme un souillon..." << endl;
        --energie_;
        return 1;
    }
}


// renvoie un entier lié a la quantite de nourriture recoltée
int Villageois::recolter_Nourriture() {
    if (energie_ < 1){
        cout << nom_ << ", non content d'etre incompetent pour récolter de la nourriture, est trop fatigue..." << endl;
        return 0;
    } else {
        cout << nom_ << " recolte de la nourriture comme un souillon..." << endl;
        --energie_;
        return 1;
    }
}


// cree un nouveau batiment
void Villageois::construire_Batiment() {
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void Villageois::afficher() {
	cout << get_id() << "-" << get_Nom() << " : " << get_Description() << endl;
}
