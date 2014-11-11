#include "VillageoisConcret.h"

#include <iostream>

using namespace std;



VillageoisConcret::VillageoisConcret( int id, string nom, string description ) :
	Villageois( id, nom, description ) {}


VillageoisConcret::VillageoisConcret( int id, string nom, string description, Observable* obs) :
	Villageois( id, nom, description, obs) {}


VillageoisConcret::~VillageoisConcret() {}
