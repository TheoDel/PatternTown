#include "Village.h"

using namespace std;



Village::Village() : population_(0) {}


Village::~Village() {
	for (size_t i=0 ; i<villageois_.size() ; ++i ) {
			delete villageois_[i];
	}		
}




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




//ajoute un villageois
void Village::set_Villageois( Villageois* v ) {
	if ( !existe_Villageois( v->get_id() ) ) {
		villageois_.push_back(v);
		++population_;
	}
}






// ajout un batiment
void Village::set_Batiments( Batiment* b ) {
	if ( !existe_Batiment( b->get_id() ) ) {
		batiments_.push_back(b);
		++constructions_;
	}
}




// retourne le vector de villageois
std::vector<Villageois*> Village::get_Villageois() {
	return villageois_;
}




// retourne le villageois correspondant à id
// id existe dans le vector !
Villageois* Village::get_Villageois( int id ) {
	for ( Villageois* v : villageois_ ) {
		if ( v->get_id() == id ) {
			return v;
		}
	}
}




// retourne le vector de batiments
std::vector<Batiment*> Village::get_Batiments() {
	return batiments_;
}




// retourne le batiments correspondant à id
// id existe dans le vector !
Batiment* Village::get_Batiment( int id ) {
	for ( Batiment* b : batiments_ ) {
		if ( b->get_id() == id ) {
			return b;
		}
	}
}




int Village::get_Ressource( int id ) {
	return ressources_.get_Ressource(id);
}


void Village::set_Ressource( int id, int quantite ) {
	ressources_.set_Ressource(id,quantite);
}
