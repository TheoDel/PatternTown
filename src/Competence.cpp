#include "Competence.h"
#include <iostream>

using namespace std;



Competence::Competence( Village* v ) : Villageois(v) {}

Competence::~Competence() {}


Villageois* Competence::get_Villageois() {
	return villageois_;
}

void Competence::afficher() { cout<< "et"; }

string Competence::get_Description() {}
