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
 * @file Pile.cpp
 * Le Puzzle
 * @brief Composant de pile à capacité extensible suivant un pas d'extension
 */

#include <cassert>

#include "Pile.h"

/**
 * @brief Initialiser une pile vide
 * la pile est allouée en mémoire dynamique
 * @see detruire, pour une désallocation en fin d'utilisation
 * @param[out] p : la pile à initialiser
 * @param[in] capa : capacité initiale de la pile
 * @param[in] pas : pas d'extension de la pile
 * @pre capa>0 et pas >0
 */
void initialiser(Pile& p, unsigned int capa, unsigned int pas) {
	assert((capa>0) && (pas >0));
	initialiser(p.tab, capa, pas);
	p.sommet = -1;
}

/**
 * @brief Désallouer une pile
 * @see initialiser, la pile a déjà été initialisée
 * @param[out] p : la pile à désallouer
 */
void detruire(Pile& p) {
	detruire(p.tab);
}

/**
 * @brief Test de pile vide
 * @param[in] p : la pile testée
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p) {
	return (p.sommet == -1);
}

/**
 * @brief Lire l'item au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'item au sommet de pile
 * @pre la pile n'est pas vide
 */
Item sommet(const Pile& p) {
	assert(!estVide(p));
	return (lire(p.tab, p.sommet));
}

/**
 * @brief Empiler un item sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : l'item à empiler
 * @pre la pile n'est pas pleine
 */
void empiler(Pile& p, const Item& it) {
	p.sommet++;
	ecrire(p.tab, p.sommet, it);
}

/**
 * @brief Dépiler l'item au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n'est pas vide
 */
void depiler(Pile& p) {
	assert(!estVide(p));
	p.sommet--;
}
