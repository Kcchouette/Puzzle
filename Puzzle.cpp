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
 * @file Puzzle.cpp
 * Le Puzzle
 * @brief mémorisation des états nécessaire à la planification de l'exploration
 * des solutions les nombres de ligne et de colonnes caractéristiques
 * du damier considéré
 */

#include "Puzzle.h"
#include "Pile.h"

/**
 * @brief Initialise un puzzle
 * @param[out] p le puzzle à initialiser
 */
void initialiser(Puzzle& p) {
	initialiser(p.lEE);
	initialiser(p.lEAE);
}

/**
 * @brief Détruit le puzzle
 * @see initialiser Le Puzzle doit déjà avoir été initialisé
 * @param[in,out] p le puzzle à détruire
 */
void detruire(Puzzle& p) {
	detruire(p.lEAE);
	detruire(p.lEE);
}

/**
 * @brief Résout un puzzle
 * @param[in,out] p le puzzle à résoudre
 * @param[in] t le damier initial
 * @param[in,out] os flux de sortie
 */
void jouer(Puzzle& p, const Tab2D& t, std::ostream& os) {
	Etat etatInitial;
	Etat etatCourant;
	Tab2D damierFinal;
	Etat etatDerive;

	double tempsDebutRecherche = getTime();

	but(damierFinal, t.nbL, t.nbC);
	initialiser(etatInitial.damier, t.nbL, t.nbC);
	etatInitial.mouvement = FIXE;
	etatInitial.precedent = 0;
	etatInitial.g = 0;

	//Copie du damier inititial dans etatInitial
	for (unsigned int l = 0; l < t.nbL; ++l) {
		for (unsigned int c = 0; c < t.nbC; ++c) {
			etatInitial.damier.tab[l][c] = t.tab[l][c];
		}
	}
	etatInitial.h = manhattan(etatInitial.damier, damierFinal);

	initialiser(etatDerive.damier, t.nbL, t.nbC);

	inserer(p.lEAE, 0, etatInitial); //étatInitial dans LEAE

	bool solutionTrouvee = false;
	bool mvtPossible;
	unsigned int pos;

	while (p.lEAE.nb != 0) {
		pos = minimal(p.lEAE);
		etatCourant = lire(p.lEAE, pos); //on prend le 1er état à explorer
		//insérer étatCourant dans LEE
		inserer(p.lEE, longueur(p.lEE), etatCourant);
		supprimer(p.lEAE, pos); //supprimer étatCourant de LEAE

		if (etatCourant.h == 0) { // le damier de étatCourant est le damier but
			solutionTrouvee = true;
			break; //sortir de la boucle while
		}

		/*pour_tout (mouvement possible associé à étatCourant)
		mouvement possible relatif à damier de étatCourant (etatCourant.damier)
		ordre d'exploration (obligatoire) NORD, EST, SUD, OUEST */
		//initialiser un étatDérivé // d'après le mouvement

		for(int m = OUEST; m >= NORD; --m) {
			mvtPossible = deriver(etatCourant, (Mouvement) m, etatDerive);
			if (mvtPossible && !rechercher(etatDerive, p.lEAE)\
				&& !rechercher(etatDerive, p.lEE)) {
				etatDerive.precedent = longueur(p.lEE) - 1;
				etatDerive.h = manhattan(etatDerive.damier, damierFinal);
				etatDerive.g = etatCourant.g + 1;
				//insérer étatDérivé dans LEAE
				inserer(p.lEAE, longueur(p.lEAE), etatDerive);
			}
		}
	}

	double tempsFinRecherche = getTime();
	cout << "Durée de recherche : " << tempsFinRecherche - tempsDebutRecherche
		<<" seconde(s)."<< endl;

	if (solutionTrouvee) {
		Pile sol;
		Etat etatSol;
		initialiser(sol, 3, 2);
		initialiser(etatSol.damier, t.nbL, t.nbC);

		//Stockage de la solution
		etatSol = lire(p.lEE, longueur(p.lEE)-1);
		empiler(sol, etatSol);
		while (etatSol.precedent != 0) {
			etatSol = lire(p.lEE, etatSol.precedent);
			empiler(sol, etatSol);
		}
		empiler(sol, etatInitial);

		//Affichage de la solution
		os << "Damier : " << t.nbL << " lignes " << t.nbC << " colonnes"
			<< endl;
		os << "Solution en " << sol.sommet << " mouvements" << endl;
		while (!estVide(sol)) {
			afficher(sommet(sol), os);
			os << endl;
			depiler(sol);
		}
		detruire(sol);
		detruire(etatSol.damier);
	}
	else {
		os << "Solution non trouvée" << endl;
	}
	detruire(etatInitial.damier);
	detruire(etatCourant.damier);
	detruire(etatDerive.damier);
	detruire(damierFinal);
}

/**
 * @brief Recherche un Etat dans une liste
 * @param[in] e l'Etat a rechercher
 * @param[in,out] l la Liste dans laquelle chercher
 * @return true si l'Etat a été trouvé, false sinon
 */
bool rechercher(const Etat& e, Liste& l) {
	for (unsigned int i = 0; i< longueur(l); ++i) {
		if (comparer(e.damier, lire(l, i).damier))
			return true;
	}
	return false;
}

/**
 * @brief Définit le damier but du Puzzle
 * @param[out] t Tab2D dans lequel stocker le but
 * @param[in] nbl le nombre de lignes
 * @param[in] nbc le nombre de colonnes
 */
void but(Tab2D& t, const unsigned int nbl, const unsigned int nbc) {
	initialiser(t, nbl, nbc);
	char lettre = 'A';

	for (unsigned int l = 0; l < nbl; ++l) {
		for(unsigned int c = 0; c < nbc; ++c) {
			t.tab[l][c] = lettre;
			++lettre;
		}
	}
	t.tab[nbl-1][nbc-1] = '#';
}

/**
 * @brief Affiche un puzzle
 * @param[in,out] p le Puzzle à afficher
 * @param[in,out] os le flux de sortie où afficher
 */
void afficher(Puzzle& p, std::ostream& os) {
	os << "*** LEE - long : " << longueur(p.lEE) << endl;
	for (unsigned int i = 0; i < longueur(p.lEE); ++i) {
		afficher(lire(p.lEE, i), os);
		os << endl;
	}
	os << endl << "*** LEAE - long : " << longueur(p.lEAE) << endl;
	for (unsigned int i = 0; i < longueur(p.lEAE); ++i) {
		afficher(lire(p.lEAE, i), os);
		os << endl;
	}
}

/**
 * @brief Cherche l'Etat optimal à traiter dans une liste
 * @param[in,out] l liste des états à explorer
 * @return position de l'Etat optimal à traiter dans l
 */
unsigned int minimal(Liste& l) {
	unsigned int index = 0;
	Etat eMin = lire(l, index);
	for (unsigned int i = 1; i < longueur(l); ++i) {
		Etat e = lire(l, i);
		if (e.g + e.h < eMin.g + eMin.h ||
			(e.g + e.h == eMin.g + eMin.h && e.h <= eMin.h)) {
			eMin = e;
			index = i;
		}
	}
	return index;
}

/**
 * @brief Renvoie une valeur approchée du temps CPU (en seconde) utilisé par
 * le programme depuis le début de son exécution.
 */
double getTime() {
	clock_t t = clock();
	if (t == (clock_t)-1)
		return 0.;
	else
		return (double)t / CLOCKS_PER_SEC;
}
