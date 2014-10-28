#include "VillageoisConcret.h"

using namespace std;



VillageoisConcret::VillageoisConcret( int id, string nom, string d, Village* v ) : Villageois(v) {
	id_ = id;
	nom_ = nom;
	description_ = d;
}

VillageoisConcret::~VillageoisConcret() {}
