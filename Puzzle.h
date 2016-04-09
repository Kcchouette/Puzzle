/*
Copyright (c) 2013, Kcchouette and b-dauphin on GitHub

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

	Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
	Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
*/

#ifndef _PUZZLE_
#define _PUZZLE_

/**
 * @file Puzzle.h
 * Le Puzzle
 * @brief mémorisation des états nécessaire à la planification
 * de l'exploration des solutions
 * les nombres de ligne et de colonnes caractéristiques du damier considéré
 */
#include <istream>
#include <ctime>

#include "Liste.h"

struct Puzzle {
	Liste lEE;  //Liste des états explorés
	Liste lEAE; //Liste des états à explorer
};

/**
 * @brief Initialise un puzzle
 * @param[out] p le puzzle à initialiser
 */
void initialiser(Puzzle& p);

/**
 * @brief Détruit le puzzle
 * @see initialiser Le Puzzle doit déjà avoir été initialisé
 * @param[in,out] p le puzzle à détruire
 */
void detruire(Puzzle& p);

/**
 * @brief Résout un puzzle
 * @param[in,out] p le puzzle à résoudre
 * @param[in] t le damier initial
 * @param[in,out] os flux de sortie
 */
void jouer(Puzzle& p, const Tab2D& t, std::ostream& os);

/**
 * @brief Recherche un Etat dans une liste
 * @param[in] e l'Etat a rechercher
 * @param[in,out] l la Liste dans laquelle chercher
 * @return true si l'Etat a été trouvé, false sinon
 */
bool rechercher(const Etat& e, Liste& l);

/**
 * @brief Définit le damier but du Puzzle
 * @param[out] t Tab2D dans lequel stocker le but
 * @param[in] nbl le nombre de lignes
 * @param[in] nbc le nombre de colonnes
 */
void but(Tab2D& t, const unsigned int nbl, const unsigned int nbc);

/**
 * @brief Affiche un puzzle
 * @param[in,out] p le Puzzle à afficher
 * @param[in,out] os le flux de sortie où afficher
 */
void afficher(Puzzle& p, std::ostream& os);

/**
 * @brief Cherche l'Etat optimal à traiter dans une liste
 * @param[in,out] l liste des états à explorer
 * @return position de l'Etat optimal à traiter dans l
 */
unsigned int minimal(Liste& l);

/**
 * @brief Renvoie une valeur approchée du temps CPU (en seconde) utilisé par
 * le programme depuis le début de son exécution.
 */
double getTime();

#endif
