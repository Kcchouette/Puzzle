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


#ifndef LISTE_H_
#define LISTE_H_

/**
 * @file Liste.h
 * Le Puzzle
 * @brief Composant de liste d'items stockés dans une chaîne à simple chaînage
 */

#include "Chaine.h"

/**
 * @brief Liste gérée dans une chaîne d'items
 */
 struct Liste {
    Chaine ch;        // Stockage des éléments de liste dans une chaîne d'items
	unsigned int nb;    // nombre d'éléments dans la liste
	unsigned int index; // index de la position courante dans la chaîne
};

/**
 * @brief Initialiser une liste vide
 * la liste est allouée en mémoire dynamique
 * @see detruire, elle est à désallouer en fin dutilisation
 * @param[out] l : la liste à initialiser (vide)
 */
void initialiser(Liste& l);

/**
 * @brief Désallouer une liste
 * @see initialiser, la liste a déjà été allouée en mémoire dynamique
 * @param[out] l : la liste
 */
void detruire(Liste& l);

/**
 * @brief Longueur de liste
 * @param[in] l : la liste
 * @return la longueur
 */
unsigned int longueur(const Liste& l);

/**
 * @brief Lire un élément de liste
 * @param[in] l : la liste
 * @return l'item lu
 * @pre 0<=i<=longueur(l)
 */
Item lire(Liste& l, unsigned int i);

/**
 * @brief Ecrire un item dans la liste
 * @param[in,out] l : la liste
 * @param[in] i : position de l'élément à écrire
 * @param[in] it : l'item
 * @pre 0<=i<=longueur(l)
 */
void ecrire(Liste& l, unsigned int i, const Item& it);

/**
 * @brief Insérer un élément dans une liste
 * @param[in,out] l : la liste
 * @param[in] i : la position avant laquelle l'élément est inséré
 * @param[in] it : l'élément inséré
 * @pre 0<=i<=longueur(l)+1
 */
void inserer(Liste& l, unsigned int i, const Item& it);

/**
 * @brief Supprimer un élément dans une liste
 * @param[in,out] l : la liste
 * @param[in] i : la position de l'élément à supprimer
 * @pre 0<=i<=longueur(l)
 */
void supprimer(Liste& l, unsigned int i);

#endif /*LISTE_H_*/
