#ifndef C_MATRICE_H
#define C_MATRICE_H

#define ECHECALLOCATION 1
#define DIMENSIONHORSPORTEE 2
#define DIMENSIONINEGALE 3

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
	CMatrice<Type> MATCalculerTransposee();
	void MATAfficherMatrice();
	CMatrice<Type> MATPPuissanceMatrice(double dNombre);

	// Gérer les éléments de la matrice
	void MATModifierElement(unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement);
	Type MATLireElement(unsigned int uiNbLignes, unsigned int uiNbColonnes);
	
	void MATAjouterColonnesFin(unsigned int uiNbColonnes);
	void MATAjouterLignesFin(unsigned int uiNbLignes);
	void MATSupprimerColonneFin(unsigned int uiNbColonnes);
	void MATSupprimerLigneFin(unsigned int uiNbLignes);
	void MATAjouterColonnesPrecis(unsigned int uiNumColonnes);
	void MATAjouterLignesPrecis(unsigned int uiNumLignes);
	void MATSupprimerColonnePrecis(unsigned int uiNumColonnes);
	void MATSupprimerLignePrecis(unsigned int uiNumLignes);

	void MATVerifierPortee(unsigned int uiNumLignes, unsigned int uiNumColonnes);
	void MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes);

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


