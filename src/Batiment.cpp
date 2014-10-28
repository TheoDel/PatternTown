#include "Batiment.h"
#include <string>

using namespace std;
static int NEXTID_B = 0;



Batiment::Batiment( string nom ) : nom_(nom) { ++NEXTID_B; }

Batiment::~Batiment() {}

int Batiment::get_id(){}

string Batiment::get_Nom(){}
