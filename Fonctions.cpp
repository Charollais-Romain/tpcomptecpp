#include <iostream>
#include <string>
#include <vector>
#include "Fonctions.h"
#include "Compte.h"

Compte compteUser;

void connexion(std::vector<Compte>& comptes, Compte &compteUser){
	std::string nomCompte;
	std::string mdp;
	std::cout << "Veuillez entrer votre nom de compte" << std::endl;
	std::cin >> nomCompte;
	std::cout << "Veuillez entrer votre mot de passe" << std::endl;
	std::cin >> mdp;

	for (auto compte : comptes) {
		if (nomCompte == compte.getCompte() && mdp == compte.getMdp()) {
			compteUser = compte;
			std::cout << "Connexion réussie" << std::endl;
			break;
		}
		else {
			std::cout << "Nom de compte ou mot de passe incorrect" << std::endl;
		}
	}
	gestionnaireCompte(comptes, compteUser);
}

void gestionnaireCompte(std::vector<Compte>& comptes, Compte &compteUser) {
	int choix;
	std::cout << "Bienvenue sur votre compte " << compteUser.getCompte() << std::endl;
	std::cout << "1. Consulter le solde" << std::endl;
	std::cout << "2. Déposer de l'argent" << std::endl;
	std::cout << "3. Retirer de l'argent" << std::endl;
	std::cout << "4. Effectuer un virement" << std::endl;
	std::cout << "5. Changer de compte" << std::endl;
	std::cout << "6. Quitter" << std::endl;
	std::cin >> choix;
	
	std::string nomCompteDest;
	switch (choix){
	case 1:
		std::cout << "Votre solde est de " << compteUser.consulter() << std::endl;
		break;
	case 2:
		double somme;
		std::cout << "Veuillez entrer la somme à déposer" << std::endl;
		std::cin >> somme;
		compteUser.deposer(somme);
		std::cout << "Votre solde est de " << compteUser.consulter() << std::endl;
		break;
	case 3:
		double sommeRetirer;
		std::cout << "Veuillez entrer la somme à retirer" << std::endl;
		std::cin >> sommeRetirer;
		compteUser.retirer(sommeRetirer);
		std::cout << "Votre solde est de " << compteUser.consulter() << std::endl;
		break;
	case 4:
		double montant;
		std::cout << "Veuillez entrer le nom du compte destinataire" << std::endl;
		std::cin >> nomCompteDest;
		std::cout << "Veuillez entrer le montant du virement" << std::endl;
		std::cin >> montant;
		for (auto compte : comptes) {
			if (nomCompteDest == compte.getCompte()) {
				compteUser.effectuerVirement(compte, montant);
				std::cout << "Virement effectué" << std::endl;
			}
			else {
				std::cout << "Compte destinataire introuvable" << std::endl;
			}
		}
		break;
	case 5:
		connexion(comptes, compteUser);
		break;
	case 6:
		std::cout << "bye" << std::endl;
		accueil(comptes);
		break;
	}
}

void creationCompte(std::vector<Compte>& comptes){
	std::string nomCompte;
	std::string mdp;
	std::cout << "Veuillez entrer votre nom de compte" << std::endl;
	std::cin >> nomCompte;
	std::cout << "Veuillez entrer votre mot de passe" << std::endl;
	std::cin >> mdp;
	Compte compte(nomCompte, 0, "Compte courant", mdp);
	comptes.push_back(compte);
	std::cout << "Compte créé" << std::endl;
	connexion(comptes, compteUser);
	
}

int accueil(std::vector<Compte>& comptes){
	std::cout << "Bienvenue sur le gestionnaire de compte bancaire" << std::endl;
	std::cout << "Avez-vous un compte chez notre banque Ro-main de fer ?" << std::endl;
	std::cout << "1. Oui" << std::endl;
	std::cout << "2. Non" << std::endl;
	std::cout << "3. Quitter" << std::endl;

	int choix;
	std::cin >> choix;

	while (true) {
		switch (choix) {
		case 1:
			connexion(comptes, compteUser);
			break;
		case 2:
			creationCompte(comptes);
			break;
		case 3:
			std::cout << "Au revoir" << std::endl;
			return 0;
			break;
		default:
			std::cout << "Veuillez entrer un choix valide" << std::endl;
			break;
		}
	}
	return 0;
}