#if !define VILLAGE_H
#define VILLAGE_H

#include<vector>


class Village {


	private :
		std::vector<Villageois> villageois_;
		std::vector<Batiment> batiments_;
		std::vector<Ressource> ressources_;
		int population;


	public :
		Village();
		~Village();

		void set_Villageois( Villageois & v );
		void set_Batiments( Batiment & b );
 		void set_Ressources( Ressource & r );

		std::vector<Villageois> & get_Villageois() const;
		std::vector<Batiment> & get_Batiments() const;
		std::vector<Ressource> & get_Ressources() const;

};

#endif
