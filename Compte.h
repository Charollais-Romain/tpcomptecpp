#pragma once
#include <iostream>
#include <string>

class Compte{
	private:
		std::string nomCompte;
		double solde;
		std::string libelle;
		std::string mdp;
	public:
		Compte();
		Compte(std::string nomCompte, double solde, std::string libelle, std::string mdp);
		std::string getCompte();
		std::string getMdp();
		std::string consulter();
		std::string getLibelle();
		double getSolde();
		void setLibelle(std::string libelle);
		void setSolde(double solde);
		void deposer(double somme);
		void retirer(double somme);
		void débiterFrais(double frais);
		double calculerAggios(double taux, double montantDecouvert, int jours);
		void effectuerVirement(Compte& compteDest, double montant);
};




