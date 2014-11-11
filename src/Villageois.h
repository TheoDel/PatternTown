#ifndef VILLAGEOIS_H
#define VILLAGEOIS_H

#include "Observable.h"
#include "Observer.h"
#include <string>


// Classe ( Abstraite ) de Villageois
class Villageois : public Observer {

    private:

		int id_;
		std::string nom_;
		int vie_;
    	int energie_;
		int satisfaction_;


    protected:

		std::string description_;


    public:

		// Constructeurs/Destructeurs
			Villageois();
			Villageois( int id, std::string nom, std::string description );
			Villageois( int id, std::string nom, std::string description, Observable* obs );
			virtual ~Villageois() = 0;

		// Getters
			virtual int get_id();
			virtual std::string get_Nom();
			virtual std::string get_Description();
			virtual int get_Vie();
			virtual int get_Energie();
			virtual int get_Satisfaction();
			virtual Villageois* get_Villageois();

		// Setters
			virtual void set_Description( std::string d );
			virtual void change_Vie( int val );
			virtual void change_Energie( int val );
			virtual void change_Satisfaction( int val );

		// Actions de jeu
			virtual int recolter_Bois();
			virtual int recolter_Nourriture();
			virtual void construire_Batiment();

		void afficher();

};

#endif
