#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

template <class Type> class CMatrice
{

	// Attributs
private:
	Type pMATMATMatrice[][];
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;
	char * psMATTypeMatrice;

public:
	// Constructeur et destructeur
	CMatrice<Type>();
	~CMatrice<Type>();
	CMatrice<Type>(unsigned int uiNbLignes, unsigned int uiNbColonnes);
	CMatrice<Type>(CMatrice & MATMatrice);

	// Accesseurs
	inline void MATEcrireNbLignes(unsigned int uiNbLignes);
	inline unsigned int MATLireNbLignes();
	inline void MATEcrireNbColonnes(unsigned int uiNbColonnes);
	inline unsigned int MATLireNbColonnes();

	// Calculs mathématiques
	CMatrice<Type> MATCalculerTransposee();
	CMatrice<Type> MATAfficherMatrice();
	CMatrice<Type> MATPPuissanceMatrices(double dNombre);

	// Gérer les éléments de la matrice
	void MATModifierElement(unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement);
	Type MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes);
	void MATAjouterColonnesM(unsigned int uiNbColonnes);
	void MATAjouterLignesM(unsigned int uiNbLignes);
	void MATSupprimerColonneM(unsigned int uiNumColonne);
	void MATSupprimerLigneM(unsigned int uiNumLigne);

	// Surchage
	CMatrice<Type> & operator+(CMatrice<Type> & MATMatrice);
	CMatrice<Type> & operator-(CMatrice<Type> & MATMatrice);
	CMatrice<Type> & operator*(Type & MATMatrice);
	CMatrice<Type> & operator*(CMatrice<Type> & MATMatrice);
	CMatrice<Type> & operator/(Type & MATMatrice);
	CMatrice<Type> & operator/(CMatrice<Type> & MATMatrice);
	CMatrice<Type> & operator=(CMatrice<Type> & MATMatrice);
};
#endif
