/**
 *@file Maison.hpp
 *@brief Fichier contenant la definition de la classe Maison
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#ifndef MAISON_HPP
#define MAISON_HPP

#include "Batiment.hpp"
#include "Observable.hpp"
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
#endif /* MAISON_HPP */
