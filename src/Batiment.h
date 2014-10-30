#ifndef BATIMENT_H
#define BATIMENT_H

#include <string>


class Batiment {

	protected :

		int id_;
		std::string nom_;


	public :

		Batiment( int id, std::string nom );
		~Batiment();

		int get_id();
		std::string get_Nom();

};

#endif
