#ifndef ETATVILLAGE_H_
#define ETATVILLAGE_H_

#include "Villageois.h"
#include "Batiment.h"
class Village;

class EtatVillage {
	private :
		Village* village_;

	public :
		// Constructeurs/Destructeurs
		EtatVillage(Village* v);
		~EtatVillage();

		// Actions de jeu
		void faire_Recolter_Villageois(int idRessource, int idVillageois);
		void faire_Construire( Batiment* b, int idVillageois );
};



#endif /* ETATVILLAGE_H_ */
