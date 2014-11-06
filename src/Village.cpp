#include "Village.h"

#include "Villageois.h"
#include "Batiment.h"
#include "Ressource.h"
#include <iostream>

using namespace std;



Village::Village( string nom ) : nom_(nom) {}


Village::~Village() {
	for ( size_t i=0 ; i<villageois_.size() ; ++i ) {
			delete villageois_[i];
	}
	for ( size_t i=0 ; i<batiments_.size() ; ++i ) {
			delete batiments_[i];
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// renvoie vrai si id est present dans le vector de batiments
bool Village::existe_Batiment( int id ) {
	for( Batiment* b : batiments_ ) {
		if ( b->get_id() == id ) {
			return true;
		}
	}
	return false;
}


// renvoie vrai si id est present dans le vector de villageois
bool Village::existe_Villageois( int id ) {
	for( Villageois* v : villageois_ ) {
		if ( v->get_id() == id ) {
			return true;
		}
	}
	return false;
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// retourne le nom du village
string Village::get_Nom() {
	return nom_;
}


// retourne le villageois correspondant a id
// id doit exister dans le vector !
Villageois* Village::get_Villageois( int id ) {
	for ( Villageois* v : villageois_ ) {
		if ( v->get_id() == id ) {
			return v;
		}
	}
	return 0;
}


// retourne le batiment correspondant a id
// id doit exister dans le vector !
Batiment* Village::get_Batiment( int id ) {
	for ( Batiment* b : batiments_ ) {
		if ( b->get_id() == id ) {
			return b;
		}
	}
	return 0;
}


// retourne la quantité de la ressource id
int Village::get_Ressource( int id ) {
	return ressources_.get_Ressource(id);
}

// retourne les ressources
Ressource* Village::get_Ressources() {
	return &ressources_;
}


// retourne le nombre d'habitants du village
int Village::get_Population() {
	return villageois_.size();
}


// retourne le nombre de batiments du village
int Village::get_Constructions() {
	return batiments_.size();
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// ajoute un villageois
// si déja present, ne fait rien
void Village::add_Villageois( Villageois* v ) {
	if ( !existe_Villageois( v->get_id() ) ) {
		villageois_.push_back(v);
	}
}


// modifie un villageois (decoration)
void Village::change_Villageois( Villageois* nv ) {
	int i = 0;
	while ( i<villageois_.size() and villageois_[i]->get_id() != nv->get_id() ) { ++i; }
	villageois_[i] = nv;
}


// ajoute un batiment
// si déja present, ne fait rien
void Village::add_Batiments( Batiment* b ) {
	if ( !existe_Batiment( b->get_id() ) ) {
		batiments_.push_back(b);
	}
}


// supprime le villageois correspondant à id
// si absent, ne fait rien
void Village::remove_Villageois( int id ) {
	for( size_t i=0 ; i<villageois_.size() ; ++i ) {
		if ( villageois_[i]->get_id() == id ) {
			delete villageois_[i];
			villageois_.erase( villageois_.begin() + i );
		}
	}
}


// supprime le batiment correspondant à id
// si absent, ne fait rien
void Village::remove_Batiment( int id ) {
	for( size_t i=0 ; i<batiments_.size() ; ++i ) {
		if ( batiments_[i]->get_id() == id ) {
			delete batiments_[i];
			batiments_.erase( batiments_.begin() + i );
		}
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void Village::afficher_Villageois() {
	for ( Villageois* v : villageois_ ) {
		v->afficher();
	}
}
