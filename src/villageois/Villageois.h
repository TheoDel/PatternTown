#ifndef VILLAGEOIS_H
#define VILLAGEOIS_H

#include "../batiments/Observable.h"
#include "Observer.h"
#include "../batiments/Batiment.h"
#include <string>


// Classe ( Abstraite ) de Villageois
class Villageois : public Observer {

    private:

		// pour l'attribution automatique de id
		static int NEXTID_;

		// < Observer >
		Observable* observable_;
		std::string donnee_;

		// Attributs propres
		int id_;
		std::string nom_;
    	int energie_;
		int satisfaction_;


    protected:

		std::string description_;


    public:

		// Constructeurs/Destructeurs
			Villageois();
			Villageois( std::string nom, std::string description );
			virtual ~Villageois() = 0;

		// Getters
			virtual int get_id();
			virtual std::string get_Nom();
			virtual std::string get_Description();
			virtual int get_Energie();
			virtual int get_Satisfaction();
			virtual Villageois* get_Villageois();

		// Setters
			virtual void set_Description( std::string d );
			virtual void change_Energie( int val );
			virtual void change_Satisfaction( int val );

		// < Observer >
			virtual Observable* get_Observable();
			virtual std::string get_Donnee();
			virtual void set_Observable( Observable* obs );
			void actualiser( std::string donnee );

		// Actions de jeu
			virtual int recolter_Bois();
			virtual int recolter_Nourriture();
			virtual Batiment* construire_Batiment( Batiment* b );

		void afficher();

};

#endif
