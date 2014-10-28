#ifndef VILLAGE_H
#define VILLAGE_H

class Competence;
class VillageoisConcret;
class Villageois;
class Bucheron;

#include "Villageois.h"
#include "Batiment.h"
#include "Ressource.h"
#include <vector>


class Village {


	private :

		std::vector<Villageois*> villageois_;
		std::vector<Batiment*> batiments_;
		Ressource ressources_;
		int population_;
		int constructions_;


	public :

		Village();
		~Village();

		void test();

		// Testing
			bool existe_Batiment( int id );
			bool existe_Villageois( int id );

		// Getters
			Villageois* get_Villageois( int id );
			Batiment* get_Batiment( int id );
			int get_Ressource( int id );
			//std::vector<Villageois*> get_Villageois();
			//std::vector<Batiment*> get_Batiments();

		// Setters
			void set_Villageois( Villageois* v );
			void change_Villageois( Villageois* v );
			void set_Batiments( Batiment* b );
			void change_Ressource( int id, int quantite );
			void remove_Villageois( int id );
			void remove_Batiment( int id );

		void afficher_Villageois();


};

#endif
