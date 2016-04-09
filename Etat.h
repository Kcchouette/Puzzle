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

#ifndef _ETAT_
#define _ETAT_

/**
 * @file Etat.h
 * Le Puzzle
 * @brief le damier résultant d'un mouvement à partir d'un damier précédent
 * le mouvement
 * le damier précédent
 * l'heuristique h de l'état initial à l'état
 * l'heuristique g de l'état à l'état final
 */

#include "Tableau2D.h"

enum Mouvement {
	NORD = 1,
	EST = 2,
	SUD = 3,
	OUEST = 4,
	FIXE = 5
}; // type mouvement basé sur l'énumération

struct Etat {			 // définit une structure de type Etat
	Tab2D damier;		 // matrice (m,n) ? //damier résultant
	Mouvement mouvement; // mouvement ayant permis d'atteindre l'état
	unsigned int precedent; // index du précédent dans lEE
	unsigned int g;		 // heuristique g de l'état initial à e
	unsigned int h;		 // heuristique h de e à l'état but
};

/**
 * @brief Affiche un Etat dans un flux
 * @param[in] e l'Etat à afficher
 * @param[in,out] os le flux de sortie où afficher l'Etat
 */
void afficher(const Etat& e, std::ostream& os);


/**
 * @brief Cree un Etat derive a partir d'un Etat et d'un mouvement;
 * retourne false si le mouvement est impossible
 * @param[in] eDep l'Etat de depart
 * @param[in] m le Mouvement
 * @param[out] eDeriv l'Etat derive
 */
bool deriver(const Etat& eDep, const Mouvement& m, Etat& eDeriv);

#endif
