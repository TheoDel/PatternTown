#include "Villageois.h"

#include <iostream>

using namespace std;



// constructeur par défaut
Villageois::Villageois() :
	id_(0), nom_(""), vie_(0), energie_(0), satisfaction_(0), description_("") {}


Villageois::Villageois( int id, std::string nom, std::string description ) :
	id_(id), nom_(nom), vie_(100), energie_(50), satisfaction_(0), description_(description) {}


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


// ici, ne sert � rien !! (se retourne lui-m�me)
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
    if ( energie_ < 1){
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
    if ( energie_ < 1){
        cout << nom_ << ", non content d'etre incompetent pour r�colter de la nourriture, est trop fatigue..." << endl;
        return 0;
    } else {
        cout << nom_ << " recolte de la nourriture comme un souillon..." << endl;
        --energie_;
        return 1;
    }
}


// cree un nouveau batiment
Batiment* Villageois::construire_Batiment( Batiment* b ) {
	cout << nom_ << " n'est pas un ouvrier" << endl;
	return nullptr;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void Villageois::afficher() {
	cout << get_id() << "-" << get_Nom() << " : " << get_Description() << endl;
}
