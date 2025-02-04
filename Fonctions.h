#pragma once
#include <iostream>
#include <string>
#include "Compte.h"

int accueil(std::vector<Compte>& comptes);
void creationCompte(std::vector<Compte>& comptes);
void connexion(std::vector<Compte>& comptes, Compte &compteUser);
void gestionnaireCompte(std::vector<Compte>& comptes, Compte &compteUser);