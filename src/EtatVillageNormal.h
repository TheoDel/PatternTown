#ifndef ETATVILLAGENORMAL_H_
#define ETATVILLAGENORMAL_H_

#include "EtatVillage.h"

class EtatVillageNormal : public EtatVillage {
	public :
		// Constructeurs/Destructeurs
		EtatVillageNormal(Village* v);
		~EtatVillageNormal();

		// Actions de jeu
		void faire_Recolter_Villageois(int idRessource, int idVillageois);
		void faire_Construire( Batiment* b, int idVillageois );
};

#endif /* ETATVILLAGENORMAL_H_ */
