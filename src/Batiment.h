#ifndef BATIMENT_H
#define BATIMENT_H

#include "Observable.h"
#include <string>


// Classe (Abstraite) de Batiment
class Batiment : public Observable {

	private:
		// pour l'attribution automatique de id
		static int NEXTID_;


	protected :

		int id_;
		std::string nom_;
		std::string description_;


	public :

		// Constructeurs/Destructeurs
			Batiment( std::string nom, std::string description );
			virtual ~Batiment() = 0;

		// Getters/Setters
			int get_id();
			std::string get_Nom();
			std::string get_Description();
			void set_Description( std::string d );

		void afficher();

};

#endif
