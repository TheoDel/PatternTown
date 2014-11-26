#ifndef BATIMENT_H
#define BATIMENT_H

class Observer;
#include "Observable.h"
#include <string>
#include <vector>
#include <unordered_map>


// Classe (Abstraite) de Batiment
class Batiment : public Observable {

	private:

		// pour l'attribution automatique de id
		static int NEXTID_;


	protected :

		int id_;
		std::string nom_;
		std::string description_;

		// < Observable >
		std::unordered_map< int, Observer* > observers_;
		int indiceSatisfaction_;


	public :

		// Constructeurs/Destructeurs
			Batiment( std::string nom, std::string description );
			virtual ~Batiment() = 0;

		// Getters/Setters
			int get_id();
			std::string get_Nom();
			std::string get_Description();
			void set_Description( std::string d );

		// < Observable >
			int get_indiceSatisfaction();
			void set_indiceSatisfaction( int is );
			std::unordered_map<int,Observer*> get_Observers();
			void enregistrerObs( Observer* observer );
			void supprimerObs( Observer* observer );
			void notifierObs();

		void afficher();

};

#endif
