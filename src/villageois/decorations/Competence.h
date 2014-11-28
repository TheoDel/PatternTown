/**
 *@file Competence.h
 *@brief Fichier contenant la definition de la classe Competence
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef COMPETENCE_H
#define COMPETENCE_H

#include "../../village/Village.h"
#include "../Villageois.h"


//--------------------------------------------------------
/**
 *@class Competence
 *@brief Classe abstraite heritant de Villageois et représentant les competences/décorations applicables aux villageois
 */

class Competence : public Villageois {

	protected :

		Villageois& villageois_; /**< Villageois decoré */


	public :

		// Constructeurs/Destructeurs
		Competence( Villageois& v );
		virtual ~Competence() = 0;

		// Getters
		int get_id();						//@Override
		std::string get_Nom();				//@Override
		std::string get_Description();		//@Override
		int get_Energie();					//@Override
		int get_Satisfaction();				//@Override
		Villageois* get_Villageois(); 		//@Override

		// Setters
		void set_Description( std::string d );	//@Override
		void change_Energie( int val );			//@Override
		void change_Satisfaction( int val );	//@Override

		////////////////////////////////////////////////////////////
		// Méthodes liées aux pattern Observer
		Observable* get_Observable();			//@Override
		int get_indiceBatiment();				//@Override
		void set_Observable( Observable* obs ); //@Override
		void actualiser( int newIndice );		//@Override
		////////////////////////////////////////////////////////////

		// Actions de jeu
		virtual int recolter_Bois();							//@Override
		virtual int recolter_Nourriture();						//@Override
		virtual Batiment* construire_Batiment( Batiment* b );	//@Override

};

//--------------------------------------------------------
#endif
