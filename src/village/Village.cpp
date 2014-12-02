/**
 *@file Village.cpp
 *@brief Fichier contenant l'implementation de la classe Village
 *@author Thomas Chevrel
 *@author Theo Delalande
 *@date 27 novembre 2014
 */

#include "Village.hpp"

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

std::vector<std::string> Village::liste_noms { "Amelia", "Bobby", "Caroline", "Denis", "Eloise", "Fred", "Georgie", "Hubert", "Inigo", "Janet", "Klervi", "Laurent", "Mariette", "Nadine", "Olivier", "Patric", "Quentin", "Robert", "Suzon", "Yvonne" };



//--------------------------------------------------------
/**
 *@brief Constructeur de base
 *@param nom Nom à donner au Village
 */
Village::Village( string nom ) {
	nom_ = nom;
	etatVillageNormal_= new EtatVillageNormal(this);
	etatVillageFamine_ = new EtatVillageFamine(this);
	EtatVillageFete_ = new EtatVillageFete(this);
	etatVillage_ = etatVillageNormal_;
	srand(time(NULL));
}





//--------------------------------------------------------
/**
 *@brief Destructeur
 */
Village::~Village() {
	for ( auto v : villageois_ ) { delete v.second; }
	for ( auto b : batiments_ )  { delete b.second; }
	delete etatVillageNormal_;
	delete etatVillageFamine_;
}





//--------------------------------------------------------
/**
 *@brief Méthode verifiant si un villageois est present
 *@param id Identifiant du villageois
 *@return Un booleen vrai si le villageois est present, faux sinon
 */
bool Village::existe_Batiment( int id ) {
	if ( batiments_.find(id) == batiments_.end() ) {
			return false;
		}
	return true;
}





//--------------------------------------------------------
/**
 *@brief Méthode verifiant si un batiment existe
 *@param id Identifiant du batiment
 *@return Un booleen vrai si le batiment existe, faux sinon
 */
bool Village::existe_Villageois( int id ) {
	if ( villageois_.find(id) == villageois_.end() ) {
		return false;
	}
	return true;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le nom du village
 *@return Une std::string representant le nom du village
 */
string Village::get_Nom() {
	return nom_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant un villageois
 *@param id Identifiant du villageois
 *@return Un pointeur vers ce villageois, ou nullptr s'il n'est pas present
 */
Villageois* Village::get_Villageois( int id ) {
	if ( villageois_.find(id) != villageois_.end() ) {
		return villageois_[id];
	}
	return nullptr;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant un batiment
 *@param id Identifiant du batiment
 *@return Un pointeur vers ce batiment, ou nullptr s'il n'existe pas
 */
Batiment* Village::get_Batiment( int id ) {
	if ( batiments_.find(id) != batiments_.end() ) {
			return batiments_[id];
		}
	return nullptr;
	}





//--------------------------------------------------------
/**
 *@brief Méthode retournant une ressource particulière
 *@param id Identifiant de la ressource
 *@return La quantité de la ressource
 */
int Village::get_Ressource( int id ) {
	return ressources_.get_Ressource(id);
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant les ressources du village
 *@return Un pointeur vers l'objet Ressources_ du village
 */
Ressource* Village::get_Ressources() {
	return &ressources_;
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le nombre de villageois
 *@return Un entier representant le nombre de villageois
 */
int Village::get_Population() {
	return villageois_.size();
}





//--------------------------------------------------------
/**
 *@brief Méthode retournant le nombre de batiments
 *@return Un entier representant le nombre de batiments
 */
int Village::get_Constructions() {
	return batiments_.size();
}





//--------------------------------------------------------
/**
 *@brief Méthode ajoutant un villageois
 *@param v Pointeur vers le villageois à ajouter
 */
void Village::add_Villageois( Villageois* v ) {
	if ( v != nullptr ) {
		villageois_.emplace( v->get_id(), v );
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant un villageois, c'est-à-dire lui ajoutant une competence/decoration
 *@param nv Pointeur vers le villageois à décorer
 */
void Village::change_Villageois( Villageois* nv ) {
	villageois_[ nv->get_id() ] = nv;
}





//--------------------------------------------------------
/**
 *@brief Méthode ajoutant un batiment
 *@param b Pointeur vers le batiment à ajouter
 */
void Village::add_Batiment( Batiment* b ) {
	if ( b != nullptr ) {
		batiments_.emplace( b->get_id(), b );
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode supprimant un villageois
 *@param id Identifiant du villageois à supprimer
 */
void Village::remove_Villageois( int id ) {
	if ( villageois_.find(id) != villageois_.end() ) {
		if ( villageois_[id]->get_Observable() != nullptr ) {
			//si ce villageois observe un sujet, on le supprime de la liste des observateurs de ce sujet
			villageois_[id]->get_Observable()->supprimerObs( villageois_[id] );
		}
		delete villageois_[id];
		villageois_.erase(id);
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode supprimant un batiment
 *@param id Identifiant du batiment à supprimer
 */
void Village::remove_Batiment( int id ) {
	if ( batiments_.find(id) != batiments_.end() ) {
		for ( auto o : batiments_[id]->get_Observers() ) {
			//pour chaque observateur de ce batiment/sujet, on supprime ce sujet
			o.second->set_Observable( nullptr );
		}
		delete batiments_[id];
		batiments_.erase(id);
		}
}





//--------------------------------------------------------
/**
 *@brief Méthode modifiant la quantité d'une ressource
 *@param id Identifiant de la ressource à modifier
 *@param quantite Quantité à ajouter/retirer à la ressource
 */
void Village::change_Ressource(int id, int quantite) {
	ressources_.change_Ressource(id, quantite);
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant effectuer de la recolte à un villageois
 *@details Le cas écheant, la ressource recoltée est ajoutée aux ressources du village
 *@param idRessource Identifiant de la ressource à recolter
 *@param idVillageois Identifiant du villageois recoltant
 */
void Village::faire_Recolter_Villageois(int idRessource, int idVillageois){
	etatVillage_->faire_Recolter_Villageois(idRessource, idVillageois);
}





//--------------------------------------------------------
/**
 *@brief Méthode faisant construire un batiment à un villageois
 *@details Le cas écheant, le batiment est ajouté à la liste des batiment
 *@param b Pointeur vers le batiment à construire
 *@param idVillageois Identifiant du villageois construisant
 */
void Village::faire_Construire( Batiment* b, int idVillageois ) {
	etatVillage_->faire_Construire(b, idVillageois);
}





//--------------------------------------------------------
/**
 *@brief Méthode effectuant toutes les actions suivant le fin d'un tour
 */
void Village::jour_Suivant() {
	//Retablissement d'energie
	for ( auto v : villageois_ ) {
		v.second->set_Energie(1);
	}

	//Prélèvement de la nourriture
	cout << "\n...Prelevement de la nourriture... ";
	int nourritureNecessaire = get_Population()*ration_hebdo_;

	// Si elle est insuffisante...
	if ( get_Ressource(2) < nourritureNecessaire ) {
		cout << " il n'y a pas assez de nourriture, le village est en famine ! Les villageois ne sont pas contents...";
		ressources_.set_Ressource(2,0);
		//Le village passe dans l'etat Famine
		etatVillage_ = etatVillageFamine_;
		//on modifie la satisfaction de tous les villageois
		for ( auto v : villageois_ ) {
			v.second->change_Satisfaction(-1);
			if ( v.second->get_Satisfaction() <= 0 ) {
				cout << "Las, "<< v.second->get_Nom() << " a quitte le village...";
				remove_Villageois( v.second->get_id() );
			}
		}
	}

	else {
		cout << nourritureNecessaire << " rations de nourriture prelevees !";
		ressources_.change_Ressource(2,-nourritureNecessaire);
		etatVillage_ = etatVillageNormal_;

		// Test s'il faut passer dans l'état fête en calculant la satisfaction moyenne (on peut penser à un observateur à l'avenir pour éviter ceci)
		int somme_satisf = 0;
		for ( auto v : villageois_ ) {
					somme_satisf += v.second->get_Satisfaction();
			}
		if ((somme_satisf/get_Population())>= satisf_moy_pour_fete){
			etatVillage_ = EtatVillageFete_;
			cout << "On dirait que les villageois sont tres contents, c'est la fete !"<<endl;

			//Ajoute aléatoirement ou pas un nouveau villageois
			int aleat = rand() % 100 + 1;

            if (aleat<=proba_nouveau_villageois) {
                std::string nomNouveau = donner_un_nom();

                Villageois* v = new VillageoisConcret( nomNouveau, "villageois nouveau" );
                add_Villageois(v);
                cout << "Un nouveau villageois ! "<< nomNouveau << " vient de s'installer à " << nom_ <<endl;
            }
			//Décrémente la satisfaction pour éviter une fête infinie
			for ( auto v : villageois_ ) {
				if ( v.second->get_Satisfaction() >= satisf_moy_pour_fete ) {
					v.second->change_Satisfaction(-1);
				}
			}
		}
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode affichant la liste des villageois
 */
void Village::afficher_Villageois() {
	for ( auto v : villageois_ ) {
		v.second->afficher();
	}
}





//--------------------------------------------------------
/**
 *@brief Méthode affichant la liste des batiments
 */
void Village::afficher_Batiments() {
	for ( auto b : batiments_ ) {
		b.second->afficher();
	}
}


//--------------------------------------------------------
/**
 *@brief Méthode tirant aléatoirement un nom de villageois dans une liste définie
 */
std::string Village::donner_un_nom() {
    int aleat = rand() % (liste_noms.size()-1) + 0;
    return liste_noms.at(aleat);
}

