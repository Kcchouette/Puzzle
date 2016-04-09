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
 * @file Tableau2D.cpp
 * Le Puzzle
 * @brief le tableau bidimensionnel géré en mémoire dynamique
 * le nombre de lignes
 * le nombre de colonnes
 */

#include <cassert>
#include <cstring>
#include <cmath> //Pour la valeur absolue

#include "Tableau2D.h"

/**
 * @brief Lire une matrice depuis un flux entrant
 * @param[in,out] is, flux d'entrée
 * @param[in,out] matrice, variable Tab2D où stocker le résultat
 */
void lire (istream& is, Tab2D& matrice) {
	unsigned int nbl, nbc;
	is >> nbl;
	is >> nbc;
	initialiser(matrice, nbl, nbc);
	// Rappel : matrice[ligne][colonne]
	// c=colonne l=ligne
	for (unsigned int c = 0, l = 0; !( l == nbl-1 && c == nbc ); ++c) {
		if (c == nbc) {
			++l;
			c = 0; // La matrice compte à partir de 0
		}
		is >> matrice.tab[l][c];
	}
}

/**
 * @brief Initialiser un Tab2D
 * @param[out] t variable Tab2D à initialiser
 * @param[in] l nombre de lignes du tableau2D
 * @param[in] c nombre de colonnes du tableau2D
 * @pre l != 0 && c != 0
 */
void initialiser(Tab2D& t, const unsigned int l, const unsigned int c) {
	assert(l != 0 && c != 0);
	t.nbL = l;
	t.nbC = c;
	t.tab = new char* [(t.nbL)];
	for (unsigned int i=0; i < (t.nbL); ++i) {
		t.tab[i] = new char [(t.nbC)];
	}
}

/**
 * @brief Afficher en mode texte une matrice dans un flot
 * @param [in,out] fE flot en écriture
 * @param [in] t la matrice
 */
void afficher(std::ostream& fE, const Tab2D& t) {
	/* Inutile après l'itération1
	fE << t.nbL;
	fE << " ";
	fE << t.nbC;*/

	for (unsigned int i=0 ; i<t.nbL ; ++i) {
		fE << endl;
		for (unsigned int j=0 ; j<t.nbC ; ++j) {
			fE << "  "; //cf TraceItéation2
			fE << t.tab[i][j];
		}
	}
}

/**
 * @brief Compare deux damiers
 * @param[in] d1 : le premier damier à comparer
 * @param[in] d2 : le second damier à comparer
 * @pre Les deux damiers sont de mêmes dimensions
 * @return true si les deux damiers sont identiques, false sinon
 */
bool comparer(const Tab2D& d1, const Tab2D& d2) {
	assert(d1.nbL == d2.nbL && d1.nbC == d2.nbC);
	for (unsigned int l = 0 ; l < d1.nbL ; ++l) {
		for (unsigned int c = 0 ; c < d1.nbC ; ++c) {
			if ((d1.tab[l][c]) != (d2.tab[l][c]))
				return false;
		}
	}
	return true;
}

/**
 * @brief Désalloue un Tab2D
 * @see initialiser le Tab2D a déjà été alloué
 * @param[out] t le Tab2D à détruire
 */
void detruire(Tab2D& t) {
	for (unsigned int i=0 ; i < t.nbL ; ++i)
		delete [] t.tab[i];
	delete [] t.tab;
}

/**
 * @brief Calcul la distance de Manhattan entre deux damiers
 * @param[in] d1 premier damier
 * @param[in] d2 second damier
 * @pre les deux damiers sont de mêmes dimentions
 * @return la distance de Manhattan des deux damiers
 */
unsigned int manhattan(const Tab2D& d1, const Tab2D& d2) {
	assert(d1.nbL == d2.nbL && d1.nbC == d2.nbC);
	unsigned int dist = 0;
	char lettre = 'A';

	while (lettre < (char)('A'+(d1.nbL*d1.nbC))) {
		unsigned int l1 = 0, c1 = 0, l2 = 0, c2 = 0;
		//Recherche de la lettre dans d1
		while (l1 < d1.nbL && d1.tab[l1][c1] != lettre) {
			++c1;
			if (c1 == d1.nbC) {
				c1 = 0;
				++l1;
			}
		}
		//Recherche de la lettre dans d2
		while (l2 < d2.nbL && d2.tab[l2][c2] != lettre) {
			++c2;
			if (c2 == d2.nbC) {
				c2 = 0;
				++l2;
			}
		}
		dist += abs((int)l1 - (int)l2) + abs((int)c1 - (int)c2);
		++lettre;
	}
	return dist;
}
