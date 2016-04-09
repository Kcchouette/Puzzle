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
 * @file ConteneurTDE.cpp
 * Le Puzzle
 * @brief Composant de conteneur d'items de capacit� extensible
 */

#include <cassert>

#include "ConteneurTDE.h"

/**
 * @brief Initialise un conteneur d'items
 * Allocation en m�moire dynamique du conteneur d'items
 * de capacit� (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa d�sallocation en fin d'utilisation
 * @param[out] c : le conteneur d'items
 * @param [in] capa : capacit� du conteneur
 * @param [in] p : pas d'extension de capacit�
 * @pre capa>0 et p>0
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa>0) && (p>0));
	c.capacite = capa;
	c.pasExtension = p;
	// arr�t du programme en cas d'erreur d'allocation
	c.tab = new Item[capa];
	/* Affichage pour une trace de l'allocation en TP
	 * Affichage � supprimer apr�s le test du conteneur */
	//cout << "Allocation initiale de " << capa*sizeof(Item) << " octets ("
	//	 << capa << " item(s))" << endl;
}

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique
 * @see initialiser, le conteneur d'items a d�j� �t� allou�
 * @param[in,out] c : le conteneur d'items
 */
void detruire(ConteneurTDE& c) {
	delete [] c.tab;
	c.tab = NULL;
}

/**
 * @brief Lecture d'un item d'un conteneur d'items
 * @param[in] c : le conteneur d'items
 * @param[in] i : la position de l'item dans le conteneur
 * @return l'item � la position i
 * @pre i < c.capacite
 */
 Item lire(const ConteneurTDE& c, unsigned int i) {
	assert(i < c.capacite);
	return c.tab[i];
}

/**
 * @brief Ecrire un item dans un conteneur d'items
 * @param[in,out] c : le conteneur d'items
 * @param[in] i : la position o� ajouter/modifier l'item
 * @param[in] it : l'item � �crire
 */
void ecrire(ConteneurTDE& c, unsigned int i, const Item& it) {
	if (i>=c.capacite) {
		/* Strat�gie de r�allocation proportionnelle au pas d'extension :
		 * initialisez la nouvelle taille du conteneur (newTaille)
		 * � i * c.pasExtension */
		unsigned int newTaille = (i+1) * c.pasExtension;
		/* Allouez en m�moire dynamique un nouveau tableau (newT)
		 * � cette nouvelle taille*/
		Item* newT = new Item[newTaille];
		/* Recopiez les items d�j� stock�s dans le conteneur */
    	for (unsigned int i = 0; i < c.capacite; ++i)
      		newT[i] = c.tab[i];
      	/* D�sallouez l'ancien tableau support du conteneur */
    	delete [] c.tab;
    	/* Actualiser la mise � jour du conteneur en m�moire dynamique
    	 * Faites pointer le tableau support du conteneur
    	 * sur le nouveau tableau en m�moire dynamique */
    	c.tab = newT;
    	/* Actualisez la taille du conteneur */
    	c.capacite = newTaille;
    		/* Affichage pour une trace de l'allocation en TP
	 	* En TP, pour tracer l'extension de l'allocation en m�moire,
	 	* affichez les informations qui suivent.
	 	* Cet affichage sera supprim� apr�s le test du conteneur */
		//cout << "Extension - Allocaton/R�allocation de "
		// << newTaille*sizeof(Item)<< " octets (" << newTaille << " items)."
		//<< endl;
	}
	/* Ecriture de l'item (it) � la position i dans le conteneur */
	c.tab[i] = it;
}
