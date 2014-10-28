#ifndef VILLAGEOIS_H
#define VILLAGEOIS_H

class Village;
#include "Village.h"
#include <string>


// Classe ABSTRAITE de villageois
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

		//Villageois();
		Villageois( Village *v );
		~Villageois();

		// Getters
			std::string get_Nom();
			virtual std::string get_Description();
			int get_id();
			int get_Vie();
			int get_Energie();
			int get_Satisfaction();
			Village* get_Village();
			virtual Villageois* get_Villageois();

		// Setters
			void set_Description( std::string d );
			void change_Vie( int val );
			void change_Energie( int val );
			void change_Satisfaction( int val );

		virtual int recolter_Bois();
		virtual int recolter_Nourriture();
		virtual void construire_Batiment();
		virtual void afficher();


};

#endif
