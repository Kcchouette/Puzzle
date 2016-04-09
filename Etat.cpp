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

/**
 * @file Etat.cpp
 * Le Puzzle
 * @brief le damier résultant d'un mouvement à partir d'un damier précédent
 * le mouvement
 * le damier précédent
 * l'heuristique h de l'état initial à l'état
 * l'heuristique g de l'état à l'état final
 */

#include "Etat.h"

/**
 * @brief Affiche un Etat dans un flux
 * @param[in] e l'Etat a afficher
 * @param[in,out] os le flux de sortie ou afficher l'Etat
 */
void afficher(const Etat& e, std::ostream& os) {
	switch (e.mouvement) {
		case 1:
			os << "NORD";
			break;
		case 2:
			os << "EST";
			break;
		case 3:
			os << "SUD";
			break;
		case 4:
			os << "OUEST";
			break;
		default:
			break;
	}
	afficher(os, e.damier);
}


/**
 * @brief Cree un Etat derive a partir d'un Etat et d'un mouvement;
 * retourne false si le mouvement est impossible
 * @param[in] eDep l'Etat de depart
 * @param[in] m le Mouvement
 * @param[out] eDeriv l'Etat derive
 */
bool deriver(const Etat& eDep, const Mouvement& m, Etat& eDeriv) {
	unsigned int   l = 0,
				c = 0;

	//Recherche du #
	while (l < eDep.damier.nbL && eDep.damier.tab[l][c] != '#') {
		++c;
		if (c == eDep.damier.nbC) {
			c = 0;
			++l;
		}
	}

	//Copie du damier
	initialiser(eDeriv.damier, eDep.damier.nbL, eDep.damier.nbC);
	for (unsigned int i = 0; i < eDep.damier.nbL; ++i)
		for (unsigned int j = 0; j < eDep.damier.nbC; ++j)
			eDeriv.damier.tab[i][j] = eDep.damier.tab[i][j];

	switch (m) {
		case NORD :
			if (l == 0) //impossible de faire le mouvement
				return false;
			eDeriv.damier.tab[l][c] = eDep.damier.tab[l-1][c];
			eDeriv.damier.tab[l-1][c] = '#';
			break;

		case EST :
			if (c == eDep.damier.nbC - 1) //impossible de faire le mouvement
				return false;
			eDeriv.damier.tab[l][c] = eDep.damier.tab[l][c+1];
			eDeriv.damier.tab[l][c+1] = '#';
			break;

		case SUD :
			if (l == eDep.damier.nbL - 1) //impossible de faire le mouvement
				return false;
			eDeriv.damier.tab[l][c] = eDep.damier.tab[l+1][c];
			eDeriv.damier.tab[l+1][c] = '#';
			break;

		case OUEST :
			if (c == 0) //impossible de faire le mouvement
				return false;
			eDeriv.damier.tab[l][c] = eDep.damier.tab[l][c-1];
			eDeriv.damier.tab[l][c-1] = '#';
			break;

		default:
			break;
	}
	eDeriv.mouvement = m;
	return true;
}
