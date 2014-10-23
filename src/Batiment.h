#ifndef BATIMENT_H
#define BATIMENT_H

#include <string>


class Batiment {

	protected :
		int id_;
		std::string nom_;

	public :
		Batiment( std::string nom );	
		~Batiment();

		int get_id();
		std::string get_Nom();

};

#endif
