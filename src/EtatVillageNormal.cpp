#include "EtatVillageNormal.h"

#include "Village.h"
#include "Villageois.h"
#include "Batiment.h"
#include "Ressource.h"
#include <iostream>

using namespace std;

EtatVillageNormal::EtatVillageNormal(Village* v) :
	EtatVillage(v) {}

EtatVillageNormal::~EtatVillageNormal(){

}

void EtatVillageNormal::faire_Recolter_Villageois(int idRessource, int idVillageois){
	Villageois* v = village_->get_Villageois(idVillageois);
	if ( village_->existe_Villageois( v->get_id() ) ) {
		if		(idRessource == 1)	{ village_->change_Ressource(1,v->recolter_Bois()); }
		else if (idRessource == 2)	{ village_->change_Ressource(2,v->recolter_Nourriture()); }
	}
}

void EtatVillageNormal::faire_Construire( Batiment* b, int idVillageois){
	if ( village_->existe_Villageois(idVillageois) ) {
		village_->add_Batiment( village_->get_Villageois(idVillageois)->construire_Batiment(b) );
	}
}
