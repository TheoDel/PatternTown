#ifndef COMPETENCE_H
#define COMPETENCE_H

#include "../../village/Village.h"
#include "../Villageois.h"


// Decorator Abstrait
class Competence : public Villageois {

	protected :

		Villageois& villageois_;


	public :

		// Constructeurs/Destructeurs
			Competence( Villageois& v );
			virtual ~Competence() = 0;

		// Getters
			int get_id();					//@Override
			std::string get_Nom();			//@Override
			std::string get_Description();	//@Override
			int get_Vie();					//@Override
			int get_Energie();				//@Override
			int get_Satisfaction();			//@Override
			Villageois* get_Villageois(); 	//@Override
			std::string get_Donnee();		//@Override
			Observable* get_Observable();	//@Override

		// Setters
			void set_Description( std::string d );	//@Override
			void change_Vie( int val );				//@Override
			void change_Energie( int val );			//@Override
			void change_Satisfaction( int val );	//@Override
			void set_Observable( Observable* obs ); //@Override

		// Actions de jeu
			virtual int recolter_Bois();
			virtual int recolter_Nourriture();
			virtual Batiment* construire_Batiment( Batiment* b );

		void actualiser( std::string d );	//@Override

};

#endif
