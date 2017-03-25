#ifndef C_MATRICE_H
#define C_MATRICE_H


template <class Type> class CMatrice
{
	// Attributs
private:
	Type ** ppqMATMatrice;
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;

public:
	// Constructeur et destructeur
	CMatrice();
	~CMatrice();
	CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);
	CMatrice(CMatrice & MATMatrice);

	// Accesseurs
	inline void MATEcrireNbLignes(unsigned int uiNbLignes);
	inline unsigned int MATLireNbLignes();
	inline void MATEcrireNbColonnes(unsigned int uiNbColonnes);
	inline unsigned int MATLireNbColonnes();

	// Calculs mathématiques
	CMatrice<Type> & MATCalculerTransposee();
	void MATAfficherMatrice();
	CMatrice<Type> & MATPPuissanceMatrice(unsigned int uiNombre);

	// Gérer les éléments de la matrice
	void MATModifierElement(unsigned int uiNumLigne, unsigned int uiNumColonne, Type tElement);
	Type MATLireElement(unsigned int uiNumLigne, unsigned int uiNumColonne);
	
	void MATAjouterColonnesFin(unsigned int uiNbColonnes);
	void MATAjouterLignesFin(unsigned int uiNbLignes);
	void MATSupprimerColonneFin(unsigned int uiNbColonnes);
	void MATSupprimerLigneFin(unsigned int uiNbLignes);
	void MATAjouterColonnePrecis(unsigned int uiNumColonne);
	void MATAjouterLignePrecis(unsigned int uiNumLigne);
	void MATSupprimerColonnePrecis(unsigned int uiNumColonne);
	void MATSupprimerLignePrecis(unsigned int uiNumLigne);

	void MATVerifierPortee(unsigned int uiNumLigne, unsigned int uiNumColonne);
	void MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	// Surchage
	CMatrice<Type> & operator+(CMatrice<Type> & MATMatrice);
	CMatrice<Type> & operator-(CMatrice<Type> & MATMatrice);
	CMatrice<Type> & operator*(Type & qMATparam);
	CMatrice<Type> & operator*(CMatrice<Type> & MATMatrice);
	CMatrice<Type> & operator/(Type & qMATparam);
	CMatrice<Type> & operator/(CMatrice<Type> & MATMatrice);
	CMatrice<Type> & operator=(CMatrice<Type> & MATMatrice);
};

template<class Type>
CMatrice<Type> & operator*(Type qMATparam, CMatrice<Type> & MATMatrice);

#include "CMatrice.cpp"

#endif
