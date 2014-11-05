#include "VillageoisConcret.h"

#include <iostream>

using namespace std;



VillageoisConcret::VillageoisConcret( int id, string n, string d, Village* v ) :
	Villageois( id, n, d, v ) {}


VillageoisConcret::~VillageoisConcret() {}
