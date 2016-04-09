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

#ifndef _PILE_
#define _PILE_

/**
 * @file Pile.h
 * Le Puzzle
 * @brief Composant de pile � capacit� extensible suivant un pas d'extension
 */

#include "ConteneurTDE.h"

/* Type pile � capacit� (>0) extensible suivant un pas d'extension (p>0) */
struct Pile {
	ConteneurTDE tab;		// tableau des �l�ments de pile en m�moire dynamique
	int sommet;				// indice de sommet de pile dans tab
};

 /**
 * @brief Initialiser une pile vide
 * la pile est allou�e en m�moire dynamique
 * @see detruire, pour une d�sallocation en fin d'utilisation
 * @param[out] p : la pile � initialiser
 * @param[in] capa : capacit� initiale de la pile
 * @param[in] pas : pas d'extension de la pile
 * @pre capa>0 et pas >0
 */
void initialiser(Pile& p, unsigned int capa, unsigned int pas);

/**
 * @brief D�sallouer une pile
 * @see initialiser, la pile a d�j� �t� initialis�e
 * @param[out] p : la pile � d�sallouer
 */
void detruire(Pile& p);

/**
 * @brief Test de pile vide
 * @param[in] p : la pile test�e
 * @return true si p est vide, false sinon
 */
bool estVide(const Pile& p);

/**
 * @brief Lire l'item au sommet de pile
 * @param[in] p : la pile
 * @return la valeur de l'item au sommet de pile
 * @pre la pile n'est pas vide
 */
Item sommet(const Pile& p);

/**
 * @brief Empiler un item sur une pile
 * @param[in,out] p : la pile
 * @param[in] it : l'item � empiler
 * @pre la pile n'est pas pleine
 */
void empiler(Pile& p, const Item& it);

/**
 * @brief D�piler l'item au sommet de pile
 * @param[in,out] p : la pile
 * @pre la pile n'est pas vide
 */
void depiler(Pile& p);

#endif
