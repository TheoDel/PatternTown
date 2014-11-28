/**
 *@file Fermier.h
 *@brief Fichier contenant la definition de la classe Fermier
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef FERMIER_H
#define FERMIER_H

#include "Competence.h"


//--------------------------------------------------------
/**
 *@class Fermier
 *@brief Classe concrete heritant de Competence et représentant la competence Fermier applicable aux villageois
 */

class Fermier : public Competence {

	public :

		// Constructeurs/Destructeurs
		Fermier( Villageois& v );
		~Fermier();

		// Actions de jeu
		int recolter_Nourriture();		//@Override

};

//--------------------------------------------------------
#endif
