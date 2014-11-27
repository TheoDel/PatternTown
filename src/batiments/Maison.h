/**
 *@file Maison.h
 *@brief Fichier contenant la definition de la classe Maison
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef MAISON_H
#define MAISON_H

#include "Observable.h"
#include "Batiment.h"
#include <string>


//--------------------------------------------------------
/**
 *@class Maison
 *@brief Classe concrete heritant de Batiment et représentant les maisons
 */

class Maison : public Batiment {

	public:

		Maison( std::string nom, std::string description );
		~Maison();

};

//--------------------------------------------------------
#endif
