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
 * @file Chaine.cpp
 * Le Puzzle
 * @brief Composant de chaîne d'items avec simple chaînage
 */

#include <cassert>

#include "Chaine.h"

/**
 * @brief Initialisation d'une chaîne vide
 * la liste est allouée en mémoire dynamique
 * @see detruire, la liste est à désallouer en fin d'utilisation
 * @param[out] c : la chaîne
 */
void initialiser(Chaine& c) {
    c.tete = NULL;
    c.courant = &c.tete;
}

/**
 * @brief Désallocation d'une chaîne
 * @see initialiser, la liste a déjà été allouée en mémoire dynamique
 * @param[out] c : la chaîne
 */
void detruire(Chaine& c) {
    debut(c);
    while (!estVide(c))
        supprimer(c);
}

/**
 * @brief Test de chaîne vide
 * @param[in] c : la chaîne testée
 * @return true si c est vide, false sinon
 */
bool estVide(const Chaine& c) {
    return c.tete == NULL;
}

/**
 * @brief Insertion d'un élément avant le maillon courant
 * Le nouveau maillon devient le maillon courant
 * @param[in,out] c : la chaîne
 * @param[in] elem : l'élément inséré
 */
void inserer(Chaine& c, const Item& elem) {
    Maillon* m = new Maillon;
    m->elem = elem;
    m->suiv = *(c.courant);
    *(c.courant) = m;
}

/**
 * @brief Suppression du maillon courant
 * @param[in,out] c : la chaîne
 * @pre Le maillon courant existe et ce n'est pas la fin de la chaîne
 */
void supprimer(Chaine& c) {
    assert(!estFin(c));
    Maillon* m = *(c.courant);
    *(c.courant) = (*(c.courant))->suiv;
    delete m;
}

/**
 * @brief Modification de l'élément stocké dans le maillon courant
 * @param[in,out] c : la chaîne
 * @param[in] elem : l'élément à écrire
 * @pre Le maillon courant existe et ce n'est pas la fin de la chaîne
 */
void ecrire(Chaine& c, const Item& elem) {
    assert(!estFin(c));
    (*(c.courant))->elem = elem;
}

/**
 * @brief Lecture de l'élément stocké dans le maillon courant
 * @param[in] c : la chaîne
 * @return l'élément lu
 * @pre Le maillon courant existe et ce n'est pas la fin de la chaîne
 */
Item lire(const Chaine& c) {
    assert(!estFin(c));
    return (*(c.courant))->elem;
}

/**
 * @brief Positionnement du maillon courant en début de chaîne
 * @param[in,out] c : la chaîne
 */
void debut(Chaine& c) {
    c.courant = &(c.tete);
}

/**
 * @brief Test de debut de chaine
 * @param[in] c : la chaîne testée
 * @return true si le maillon courant est le début de chaîne, false sinon
 */
bool estDebut(const Chaine& c) {
    return c.courant == &(c.tete);
}

/**
 * @brief Positionnement du maillon courant en fin de chaîne
 * @param[in,out] c : la chaîne
 * @return true si le maillon courant est la fin de chaîne, false sinon
 */
void fin(Chaine& c) {
    while (!estFin(c))
        suivant(c);
}

/**
 * @brief Test de fin de chaîne
 * @param[in] c : la chaîne testée
 * @return true si le maillon courant est la fin de chaîne, false sinon.
 */
bool estFin(const Chaine& c) {
    return *(c.courant) == NULL;
}

/**
 * @brief Positionnement du maillon courant au maillon suivant
 * @param[in,out] c : la chaîne
 * @pre Le maillon courant existe et ce n'est pas la fin de la chaîne
 */
void suivant(Chaine& c) {
    assert(!estFin(c));
    c.courant = &((*(c.courant))->suiv);
}
