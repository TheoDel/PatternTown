#include "Batiment.h"
#include "../villageois/Observer.h"

#include <iostream>
#include <unordered_map>

using namespace std;
int Batiment::NEXTID_ = 1;



Batiment::Batiment( string nom, string description ) :
		id_(NEXTID_), nom_(nom), description_(description), indiceSatisfaction_(5) { ++NEXTID_; }


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
int Batiment::get_indiceSatisfaction() {
	return indiceSatisfaction_;
}


// retourne la liste des observers
std::unordered_map<int,Observer*> Batiment::get_Observers() {
	return observers_;
}


// modifie la donnee
void Batiment::set_indiceSatisfaction( int is ) {
	indiceSatisfaction_ = is;
	notifierObs();
}


// ajoute un observer
void Batiment::enregistrerObs( Observer* observer ) {
	observers_.emplace( observer->get_id(), observer );
	observers_[ observer->get_id() ]->actualiser(indiceSatisfaction_);
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
		o.second->actualiser( indiceSatisfaction_ );
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// affiche le batiment
void Batiment::afficher() {
	 cout << "(ID:" << get_id() << ") " << get_Nom() << " : " << get_Description() << endl;
}
