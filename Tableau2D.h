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

#ifndef _TABLEAU2D_
#define _TABLEAU2D_
/**
 * @file Tableau2D.h
 * Le Puzzle
 * @brief le tableau bidimensionnel géré en mémoire dynamique
 * le nombre de lignes
 * le nombres de colonnes
 */

#include <iostream>
#include <fstream>
using namespace std;

/**
 * @brief Conteneur d'items alloués en mémoire dynamique
 * de capacité extensible suivant un pas d'extension
 */
struct Tab2D {
	unsigned int nbL;  // nombre de ligne de la matrice
	unsigned int nbC;  // nombre de colonne de la matrice
	char** tab;        //adresse du tableau bidimensionnel
                       //en mémoire dynamique
};


/**
 * @brief Lire une matrice depuis un flux entrant
 * @param[in,out] is, flux d'entrée
 * @param[in,out] matrice, variable Tab2D où stocker le résultat
 */
void lire(std::istream& is, Tab2D& matrice);

/**
 * @brief Initialiser un Tab2D (l lignes, c colonnes)
 * @param[in,out] t, variable Tab2D à initialiser
 * @param[in] l nombre de lignes du tableau2D
 * @param[in] c nombre de colonnes du tableau2D
 * @pre l != 0 && c != 0
 */
void initialiser(Tab2D& t, const unsigned int l, const unsigned int c);

/**
 * @brief Affiche en mode texte une matrice dans un flot
 * @param [in,out] fE : flot en écriture
 * @param [in] t : la matrice
 */
void afficher(std::ostream& fE, const Tab2D& t);

/**
 * @brief Compare deux damiers
 * @param[in] d1 : le premier damier à comparer
 * @param[in] d2 : le second damier à comparer
 * @pre Les deux damiers sont de memes dimentions
 * @return true si les deux damiers sont identiques, false sinon
 */
bool comparer(const Tab2D& d1, const Tab2D& d2);

/**
 * @brief Désalloue un tableau2D
 * @see initialiser, le tableau2D a déjà été alloué
 * @param[out] tab, le tableau2D à détruire
 */
void detruire(Tab2D& tab);

/**
 * @brief Calcul la distance de Manhattan entre deux damiers
 * @param[in] d1 premier damier
 * @param[in] d2 second damier
 * @return la distance de Manhattan des deux damiers
 */
unsigned int manhattan(const Tab2D& d1, const Tab2D& d2);

#endif
