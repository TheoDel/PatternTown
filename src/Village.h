#ifndef VILLAGE_H
#define VILLAGE_H

class Villageois;
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

		bool existe_Batiment( int id );
		bool existe_Villageois( int id );

		void set_Villageois( Villageois* v );
		void set_Batiments( Batiment* b );
		void set_Ressource( int id, int quantite );
		
		std::vector<Villageois*> get_Villageois();
		Villageois* get_Villageois( int id );
		std::vector<Batiment*> get_Batiments();
		Batiment* get_Batiment( int id );
		int get_Ressource( int id );





};

#endif
