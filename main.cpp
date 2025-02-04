#include <iostream>
#include <vector>
#include "Compte.h"
#include "Fonctions.h"

int main() {
	Compte compte1("Romain",0,"87charollaisromain","salut");
	Compte compte2("Antoine", 0, "69brissaudantoine", "raton");
	Compte compte3("Nathan", 0, "87nathanchaumerliat", "tournesol");
	Compte compte4("Cyprien", 0, "87cyprienlizzy", "colline");
	std::vector<Compte> comptes = {compte1,compte2,compte3,compte4};

	Compte compteUser;
	accueil(comptes);


	return 0;
}