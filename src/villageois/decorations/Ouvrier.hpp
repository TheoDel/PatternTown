/**
 *@file Ouvrier.hpp
 *@brief Fichier contenant la definition de la classe Ouvrier
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef OUVRIER_HPP
#define OUVRIER_HPP

#include "Competence.hpp"


//--------------------------------------------------------
/**
 *@class Ouvrier
 *@brief Classe concrete heritant de Competence et représentant la competence Ouvrier applicable aux villageois
 */

class Ouvrier : public Competence {

	public :

		// Constructeurs/Destructeurs
		Ouvrier( Villageois& v );
		~Ouvrier();

		// Actions de jeu
		Batiment* construire_Batiment( Batiment* b );	//@Override

};

//--------------------------------------------------------
#endif /* OUVRIER_HPP */
