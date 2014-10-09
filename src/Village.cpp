#include "Village.h"

using namespace std;



Village::Village(){
	population = 0;
}

Village::~Village(){
}



void Village::set_Villageois( Villageois & v ) '
	villageois.push_back(v);
	++populations;
}

void Village::set_Batiments( Batiment & b ) '
	batiments.push_back(b);
}

void Village::set_Ressources( Ressource & r ) '
	ressources.push_back(r);
}



std::vector<Villageois> & Village::get_Villageois() const {
	return villageois;
}

std::vector<Batiment> & Village::get_Batiments() const {
	return batiments;
}	

std::vector<Ressource> & Village::get_Ressources() const {
	return ressources;
}
	
