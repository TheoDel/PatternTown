/**
 *@file Bucheron.hpp
 *@brief Fichier contenant la definition de la classe Bucheron
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef BUCHERON_HPP
#define BUCHERON_HPP

#include "Competence.hpp"


//--------------------------------------------------------
/**
 *@class Bucheron
 *@brief Classe concrete heritant de Competence et représentant la competence Bucheron applicable aux villageois
 */

class Bucheron : public Competence {

	public :

		// Constructeurs/Destructeurs
		Bucheron( Villageois& v );
		~Bucheron();

		// Actions de jeu
		int recolter_Bois();	//@Override

};

//--------------------------------------------------------
#endif /* BUCHERON_HPP */
