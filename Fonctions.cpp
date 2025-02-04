#include <iostream>
#include <string>
#include <vector>
#include "Fonctions.h"
#include "Compte.h"

void connexion(std::vector<Compte>& comptes){
	std::string nomCompte;
	std::string mdp;
	std::cout << "Veuillez entrer votre nom de compte" << std::endl;
	std::cin >> nomCompte;
	std::cout << "Veuillez entrer votre mot de passe" << std::endl;
	std::cin >> mdp;

	for (auto compte : comptes) {
		if (nomCompte == compte.getCompte() && mdp == compte.getMdp()) {
			std::cout << "Connexion réussie" << std::endl;
			gestionnaireCompte();
		}
		else {
			std::cout << "Nom de compte ou mot de passe incorrect" << std::endl;
		}
	}
}

void gestionnaireCompte() {
	std::cout << "test" << std::endl;
}
void creationCompte(std::vector<Compte>& comptes) {
	std::string nomCompte;
	std::string mdp;
	std::cout << "Veuillez entrer votre nom de compte" << std::endl;
	std::cin >> nomCompte;
	std::cout << "Veuillez entrer votre mot de passe" << std::endl;
	std::cin >> mdp;
	Compte compte(nomCompte, 0, "Compte courant", mdp);
	comptes.push_back(compte);
	std::cout << "Compte créé" << std::endl;
	connexion(comptes);
	
}

void accueil(std::vector<Compte>& comptes){
	std::cout << "Bienvenue sur le gestionnaire de compte bancaire" << std::endl;
	std::cout << "Avez-vous un compte chez notre banque Ro-main de fer ?" << std::endl;
	std::cout << "1. Oui" << std::endl;
	std::cout << "2. Non" << std::endl;
	std::cout << "3. Quitter" << std::endl;

	int choix;
	std::cin >> choix;

	switch (choix) {
	case 1:
		connexion(comptes);
	case 2:
		creationCompte(comptes);
		break;
	case 3:
		std::cout << "Au revoir" << std::endl;
		break;
	default:
		std::cout << "Veuillez entrer un choix valide" << std::endl;
		accueil(comptes);
		break;
	}
}