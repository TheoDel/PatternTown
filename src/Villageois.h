#ifndef VILLAGEOIS_H
#define VILLAGEOIS_H

class Village;
#include "Village.h"
#include <string>


class Villageois {

    protected:

		std::string nom_;
		std::string description_;
	
		int id_;
    	int vie_;
    	int energie_;
		int satisfaction_;
		Village* village_; // village auquel il appartient

    public:

		Villageois();
		Villageois( Village *v );
		virtual ~Villageois() = 0;


		std::string get_Nom();
		virtual std::string get_Description();
	
		int get_id();
		int get_Vie();
		int get_Energie();
		int get_Satisfaction();
		Village* get_Village();

		virtual int recolter_Bois();
		virtual int recolter_Nourriture();
		virtual void construire_Batiment();

};

#endif
