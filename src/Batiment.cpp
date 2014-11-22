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
std::unordered_map<int,Observer*> Batiment::get_Observers() {
	return observers_;
}


// modifie la donnee
void Batiment::set_Donnee( string donnee ) {
	donnee_ = donnee;
	notifierObs();
}


// ajoute un observer
void Batiment::enregistrerObs( Observer* observer ) {
	observers_.emplace( observer->get_id(), observer );
	observers_[ observer->get_id() ]->actualiser(donnee_);
}


// supprime l'observer de la liste
void Batiment::supprimerObs( Observer* observer ) {
	if ( observers_.find( observer->get_id() ) != observers_.end() ) {
		observers_.erase( observer->get_id() );
		observer->set_Observable( nullptr );
	}
}


// notifie la modification de la donnee aux observers
void Batiment::notifierObs() {
	for( auto o : observers_ ) {
		o.second->actualiser( donnee_ );
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// affiche le batiment
void Batiment::afficher() {
	 cout << "(ID:" << get_id() << ") " << get_Nom() << " : " << get_Description() << endl;
}
