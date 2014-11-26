#include "Villageois.h"
#include "../batiments/Maison.h"

#include <iostream>

using namespace std;
int Villageois::NEXTID_ = 1;



// constructeur par défaut
Villageois::Villageois() :
	observable_(nullptr), donnee_(""), id_(0), nom_(""),
	energie_(0), satisfaction_(0), description_("") {}


Villageois::Villageois( std::string nom, std::string description ) :
	observable_(nullptr), donnee_("<Aucun Observateur>"), id_(NEXTID_), nom_(nom),
	energie_(1), satisfaction_(3), description_(description) { ++NEXTID_; }


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
// < Observer >



// retourne l'observable associé
Observable* Villageois::get_Observable() {
	return observable_;
}


// retourne la donnee
string Villageois::get_Donnee() {
	if ( observable_ == nullptr ) { return "<Aucun Observateur>"; }
	return donnee_;
}


// modifie l'observable actuel
void Villageois::set_Observable( Observable* obs ) {
	if ( observable_ != nullptr ) {	// si deja enregistré dans observable
		observable_->supprimerObs( this );
	}
	observable_ = obs;
	if ( obs != nullptr ) {	// si le nouvel observable n'existe pas
		observable_->enregistrerObs( this );
	}
}


// actualise la donnee
void Villageois::actualiser( string donnee ) {
	donnee_ = donnee;
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
	delete b; // suppression du batiment créé
	b = nullptr;
	return b;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void Villageois::afficher() {
	cout << "(ID:" << get_id() << ")(Energie:"<< energie_ <<" - Satisfaction:"<< satisfaction_<< ") "<< get_Nom() << " : " << get_Description() << endl;
}
