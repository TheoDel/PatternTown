#include "SystemeJeu.hpp"
#include "village/Village.hpp"
#include "villageois/Observer.hpp"
#include "villageois/Villageois.hpp"
#include "villageois/VillageoisConcret.hpp"
#include "villageois/decorations/Competence.hpp"
#include "villageois/decorations/Bucheron.hpp"
#include "villageois/decorations/Fermier.hpp"
#include "villageois/decorations/Ouvrier.hpp"
#include "batiments/Observable.hpp"
#include "batiments/Batiment.hpp"
#include "batiments/Maison.hpp"
#include "village/Ressource.hpp"

#include <iostream>

using namespace std;



int main() {

	SystemeJeu s("Trifouilly les trois oies");
	s.lancerJeu();
}
