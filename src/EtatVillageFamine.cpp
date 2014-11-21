#include "EtatVillageFamine.h"

#include "Village.h"
#include "Villageois.h"
#include "Batiment.h"
#include "Ressource.h"
#include <iostream>

using namespace std;

EtatVillageFamine::EtatVillageFamine(Village* v) :
	EtatVillage(v) {}

EtatVillageFamine::~EtatVillageFamine(){

}

void EtatVillageFamine::faire_Recolter_Villageois(int idRessource, int idVillageois){
	cout << "Le villageois refuse de travailler, il a trop faim !";
}

void EtatVillageFamine::faire_Construire( Batiment* b, int idVillageois){
	cout << "Le villageois refuse de construire, il a trop faim !";
}
