#ifndef C_MATRICE_H
#define C_MATRICE_H
#define ECHECALLOCATION 1
#define DIMENSIONHORSPORTEE 2

template <typename Type> class CMatrice
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
	CMatrice<Type> MATAfficherMatrice();
	CMatrice<Type> MATPPuissanceMatrice(double dNombre);

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


