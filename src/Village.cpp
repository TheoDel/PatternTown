#include "Village.h"

#include "EtatVillage.h"
#include "Villageois.h"
#include "Batiment.h"
#include "Ressource.h"
#include <iostream>
#include <vector>

using namespace std;



Village::Village( string nom ) {
	nom_ = nom;
	etatVillage_= new EtatVillage(this);
}


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
	return nullptr;
}


// retourne le batiment correspondant a id
// id doit exister dans le vector !
Batiment* Village::get_Batiment( int id ) {
	for ( Batiment* b : batiments_ ) {
		if ( b->get_id() == id ) {
			return b;
		}
	}
	return nullptr;
}


// retourne la quantité de la ressource id
int Village::get_Ressource( int id ) {
	return ressources_.get_Ressource(id);
}

std::vector<Villageois*> Village::get_villageois(){
	return villageois_;
}

std::vector<Batiment*> Village::get_batiments(){
	return batiments_;
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
// si d�ja present, ne fait rien
void Village::add_Villageois( Villageois* v ) {
	if ( !existe_Villageois( v->get_id() ) ) {
		villageois_.push_back(v);
	}
}


// modifie un villageois (decoration)
void Village::change_Villageois( Villageois* nv ) {
	size_t i = 0;
	while ( i<villageois_.size() and villageois_[i]->get_id() != nv->get_id() ) { ++i; }
	villageois_[i] = nv;
}


// ajoute un batiment
// si d�ja present, ne fait rien
void Village::add_Batiment( Batiment* b ) {
	if ( !existe_Batiment( b->get_id() ) ) {
		batiments_.push_back(b);
	}
}


// supprime le villageois correspondant à id
// si absent, ne fait rien
void Village::remove_Villageois( int id ) {
	for( size_t i=0 ; i<villageois_.size() ; ++i ) {
		if ( villageois_[i]->get_id() == id ) {
			if ( villageois_[i]->get_Observable() != nullptr ) {
				villageois_[i]->get_Observable()->supprimerObs( villageois_[i] );
			}
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
			for ( Observer* o : batiments_[i]->get_Observers() ) {
				o->set_Observable( nullptr );
			}
			delete batiments_[i];
			batiments_.erase( batiments_.begin() + i );
		}
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// faire recolter la ressource idRessource par le villageois idVillageois
// le cas écheant, l'ajoute aux ressources et modifie l'energie du villageois
void Village::faire_Recolter_Villageois(int idRessource, int idVillageois){
	Villageois* v = get_Villageois(idVillageois);
	if ( existe_Villageois( v->get_id() ) ) {
		if		(idRessource == 1)	{ ressources_.change_Ressource(1,v->recolter_Bois()); }
		else if (idRessource == 2)	{ ressources_.change_Ressource(2,v->recolter_Nourriture()); }
	}
}


// si possible, faire recolter le batiment b par le villageois idVillageois
//
void Village::faire_Construire( Batiment* b, int idVillageois ) {
	Villageois* v = get_Villageois(idVillageois);
	if ( existe_Villageois( v->get_id() ) ) {
		if ( v->construire_Batiment(b) != nullptr ) {
			cout << v->get_Nom() << " a construit " << b->get_Nom() << endl;
			add_Batiment(b);
		}
	}
}



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



// affiche la liste des villageois
void Village::afficher_Villageois() {
	for ( Villageois* v : villageois_ ) {
		v->afficher();
	}
}


// affiche la liste des batiments
void Village::afficher_Batiments() {
	for ( Batiment* b : batiments_ ) {
		b->afficher();
	}
}
