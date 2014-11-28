/**
 *@file Bucheron.h
 *@brief Fichier contenant la definition de la classe Bucheron
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef BUCHERON_H
#define BUCHERON_H

#include "Competence.h"


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
#endif
