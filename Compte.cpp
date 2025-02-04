#include "Compte.h"

Compte::Compte() {
	nomCompte = "inconnu";
	solde = 0;
	libelle = "Compte courant";
	mdp = "";
}

Compte::Compte(std::string nomCompteb, double soldeb, std::string lib, std::string mdpa){
	nomCompte = nomCompteb;
	solde = soldeb;
	libelle = lib;
	mdp = mdpa;
}

std::string Compte::getCompte()
{
	return nomCompte;
}

std::string Compte::getMdp()
{
	return mdp;
}

std::string Compte::consulter(){
	return std::to_string(solde);
}

std::string Compte::getLibelle(){
	return libelle;
}

double Compte::getSolde(){
	return solde;
}

void Compte::setLibelle(std::string lib){
	libelle = lib;
}

void Compte::setSolde(double soldb){
	solde = soldb;
}

void Compte::deposer(double somme){
	solde += somme;
}

void Compte::retirer(double somme){
	solde -= somme;
}

void Compte::débiterFrais(double frais) {
	solde -= frais;

	// A voir si on calcule les frais dans la fonction 
}

double Compte::calculerAggios(double taux, double montantDecouvert, int jours){
	return 0;
}

void Compte::effectuerVirement(Compte& compteDest, double montant){
	solde -= montant;
	compteDest.solde += montant;
}
