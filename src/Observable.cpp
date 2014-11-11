#include "Observable.h"

#include "Observer.h"

using namespace std;



Observable::Observable() : donnee_("<vide>") {}


Observable::~Observable() {}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// retourne la donnee
string Observable::get_Donnee() {
	return donnee_;
}


// retourne la liste des observers
std::vector<Observer*> Observable::get_Observers() {
	return observers_;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// modifie la donnee
void Observable::set_Donnee( string donnee ) {
	donnee_ = donnee;
	notifierObs();
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// ajoute un observer
void Observable::enregistrerObs( Observer* observer ) {
	for( Observer* o : observers_ ) {
		if ( o->get_id() == observer->get_id() ) {
			return;
		}
	}
	observers_.push_back( observer );
	observers_[ observers_.size()-1 ]->actualiser(donnee_);
}


// supprime l'observer de la liste
void Observable::supprimerObs( Observer* observer ) {
	for( size_t i=0 ; i<observers_.size() ; ++i ) {
		if ( observers_[i]->get_id() == observer->get_id() ) {
			observers_.erase( observers_.begin() + i );
			observer->set_Observable( nullptr );
		}
	}
}


// notifie la modification de la donnee aux observers
void Observable::notifierObs() {
	for( Observer* o : observers_ ) {
		o->actualiser( donnee_ );
	}
}
