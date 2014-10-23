#include "Villageois.h"
#include <string>

using namespace std;
//static int NEXTID_V = 0;



Villageois::Villageois( Village* v ) : vie_(10), energie_(10), satisfaction_(10), village_(v) {}

Villageois::~Villageois() {}


 
string Villageois::get_Description() {
	return description_;
}

string Villageois::get_Nom() {
	return nom_;
}

int Villageois::get_id() {
	return id_;
}

int Villageois::get_Vie() {
	return vie_;
}

int Villageois::get_Energie() {
	return energie_;
}

int Villageois::get_Satisfaction() {
	return satisfaction_;
}

Village* Villageois::get_Village() {
	return village_;
}




int Villageois::recolter_Bois() {
	return 1;
}

int Villageois::recolter_Nourriture() {
	return 1;
}

void Villageois::construire_Batiment() {
}
