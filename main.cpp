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
 * @file main.cpp
 * Le Puzzle
 * @brief Fichier principal du programme pour la résolution du
 * Puzzle
 */


#include <cstdlib>

#include "Puzzle.h"


int main () {
	ifstream ficL;
	char nomF[80];
	Puzzle p;
	// Ouverture d'un flot en lecture
	cout << "Saisir le nom du fichier à lire : \t";
	cin >> nomF;
	ficL.open(nomF, ios::in);
	Tab2D tab;
	if (ficL.fail()) {
		cerr << "Impossible de lire le fichier "<< nomF <<"."<< endl;
		exit(1);
	}
	ficL.seekg(0); //Se positionner au début
	lire(ficL, tab);
	ficL.close();
	initialiser(p);

	/* Ouverture d'un flot en écriture */
	ofstream ficE;
	cout << endl << endl << "Saisir le nom du fichier de sauvegarde: \t";
	cin >> nomF;
	ficE.open(nomF, ios::out);
	if (ficE.fail()) {
		cerr << "Impossible d'écrire dans le fichier"<< nomF <<"."<< endl;
		exit(1);
	}
	jouer(p, tab, ficE);
	cout << "La sauvegarde du fichier "<< nomF << " s'est bien déroulée."
          << endl;

	// Fermeture du flot
	ficE.close();

	// Destruction du tableau2D
	detruire(tab);
	return 0;
}
