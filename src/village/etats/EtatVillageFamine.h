#ifndef ETATVILLAGEFAMINE_H_
#define ETATVILLAGEFAMINE_H_

#include "EtatVillage.h"

class EtatVillageFamine : public EtatVillage {
	public :
		// Constructeurs/Destructeurs
		EtatVillageFamine(Village* v);
		~EtatVillageFamine();

		// Actions de jeu
		void faire_Recolter_Villageois(int idRessource, int idVillageois);
		void faire_Construire( Batiment* b, int idVillageois );
};

#endif /* ETATVILLAGEFAMINE_H_ */
