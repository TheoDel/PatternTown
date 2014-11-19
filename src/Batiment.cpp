#include "Batiment.h"
#include "Observer.h"

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


// retourne la description du batiment
string Batiment::get_Description() {
	return description_;
}


// modifie la description du batiment
void Batiment::set_Description( string d ) {
	description_ = d;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// < Observable >



// retourne la donnee
string Batiment::get_Donnee() {
	return donnee_;
}


// retourne la liste des observers
std::vector<Observer*> Batiment::get_Observers() {
	return observers_;
}


// modifie la donnee
void Batiment::set_Donnee( string donnee ) {
	donnee_ = donnee;
	notifierObs();
}


// ajoute un observer
void Batiment::enregistrerObs( Observer* observer ) {
	for( Observer* o : observers_ ) {
		if ( o->get_id() == observer->get_id() ) {
			return;
		}
	}
	observers_.push_back( observer );
	observers_[ observers_.size()-1 ]->actualiser(donnee_);
}


// supprime l'observer de la liste
void Batiment::supprimerObs( Observer* observer ) {
	for( size_t i=0 ; i<observers_.size() ; ++i ) {
		if ( observers_[i]->get_id() == observer->get_id() ) {
			observers_.erase( observers_.begin() + i );
			observer->set_Observable( nullptr );
		}
	}
}


// notifie la modification de la donnee aux observers
void Batiment::notifierObs() {
	for( Observer* o : observers_ ) {
		o->actualiser( donnee_ );
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// affiche le batiment
void Batiment::afficher() {
	 cout << "(ID:" << get_id() << ") " << get_Nom() << " : " << get_Description() << endl;
}
