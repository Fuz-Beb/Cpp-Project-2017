#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <iostream>

template <class Type> class CMatrice
{
private:
	// Attributs
	Type ** ppqMATMatrice;
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;

public:
	// Constructeurs et destructeur

	/*****************************
	Constructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CMatrice();

	/*****************************
	Destructeur par défaut
	******************************
	Entrée : néant
	Necessité : Pré-condition : La libération des pointeurs avant la suppression de la matrice est à la charge de l'utilisateur
	Sortie : néant
	Entraine : l'objet est détruit
	*****************************/
	~CMatrice();

	/*****************************
	Constructeur à deux arguments
	******************************
	Entrée : unsigned int uiNbLignes, unsigned int uiNbColonnes
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	/*****************************
	Constructeur de recopie
	******************************
	Entrée : CMatrice<Type> & MATMatrice
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé/recopié
	*****************************/
	CMatrice(CMatrice & MATMatrice);

	// Accesseurs

	/*****************************
	Methode : Ecrire nombre de lignes
	******************************
	Entrée : unsigned int uiNbLignes
	Necessité : néant
	Sortie : néant
	Entraine : modification nombre de lignes
	*****************************/
	void MATEcrireNbLignes(unsigned int uiNbLignes);

	/*****************************
	Methode : Lire nombre de lignes
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int
	Entraine : retourne nombre de lignes
	*****************************/
	unsigned int MATLireNbLignes();

	/*****************************
	Methode : Ecrire nombre de colonnes
	******************************
	Entrée : unsigned int uiNbColonnes
	Necessité : néant
	Sortie : néant
	Entraine : modification nombre de colonnes
	*****************************/
	void MATEcrireNbColonnes(unsigned int uiNbColonnes);

	/*****************************
	Methode : Lire nombre de colonnes
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int
	Entraine : retourne nombre de colonnes
	*****************************/
	unsigned int MATLireNbColonnes();

	// Calculs mathématiques

	/*****************************
	Methode : Calculer la transposée d'une matrice
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en calculant la transposée
	*****************************/
	CMatrice<Type> MATCalculerTransposee();

	/*****************************
	Methode : Mettre une matrice à la puissance
	******************************
	Entrée : unsigned int uiNombre
	Necessité : néant
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en mettant la puissance de la matrice
	*****************************/
	CMatrice<Type> MATPPuissanceMatrice(unsigned int uiNombre);

	// Gérer les éléments de la matrice

	/*****************************
	Methode : Modifier l'élèment à l'endroit de la matrice
	******************************
	Entrée : unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement
	Necessité : néant
	Sortie : néant
	Entraine : modification de l'élèment
	*****************************/
	void MATModifierElement(unsigned int uiNumLigne, unsigned int uiNumColonne, Type tElement);

	/*****************************
	Methode : Lire l'élèment à l'endroit de la matrice
	******************************
	Entrée : unsigned int uiNbLignes, unsigned int uiNbColonnes
	Necessité : néant
	Sortie : Type
	Entraine : retourne l'element à l'endroit de la matrice
	*****************************/
	Type MATLireElement(unsigned int uiNumLigne, unsigned int uiNumColonne);

	/*****************************
	Methode : Initialise l'ensemble des valeurs de la matrice à la valeur 0
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : nénant
	Entraine : mise à la valeur 0 à l'ensemble des cases de la matrice
	*****************************/
	void MATInit();
	
	 /*****************************
	Methode : Afficher la matrice à l'écran
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : Afficher la matrice de l'objet à l'écran
	*****************************/
	void MATAfficherMatrice();
	
	/*****************************
	Methode : Ajouter une/des colonnes à la droite de la matrice
	******************************
	Entrée : unsigned int uiNbColonnes
	Necessité : néant
	Sortie : néant
	Entraine : réallouer selon ajout nb colonnes
	*****************************/
	void MATAjouterColonnesFin(unsigned int uiNbColonnes);

	/*****************************
	Methode : Ajouter une/des lignes en bas de la matrice
	******************************
	Entrée : unsigned int uiNbLignes
	Necessité : néant
	Sortie : néant
	Entraine : réallouer selon ajout nb lignes
	*****************************/
	void MATAjouterLignesFin(unsigned int uiNbLignes);

	/*****************************
	Methode : Supprimer une/des colonnes à droite de la matrice
	******************************
	Entrée : unsigned int uiNbColonnes
	Necessité : Pré-condition : La libération des pointeurs avant la suppression de la colonne est à la charge de l'utilisateur
	Sortie : néant
	Entraine : réallouer selon suppression nb colonnes
	*****************************/
	void MATSupprimerColonneFin(unsigned int uiNbColonnes);

	/*****************************
	Methode : Supprimer une/des ligne en bas de la matrice
	******************************
	Entrée : unsigned int uiNbLignes
	Necessité : Pré-condition : La libération des pointeurs avant la suppression de la ligne est à la charge de l'utilisateur
	Sortie : néant
	Entraine : réallouer selon suppression nb lignes
	*****************************/
	void MATSupprimerLigneFin(unsigned int uiNbLignes);
	
	/*****************************
	Methode : Ajouter une colonne à un endroit précis de la matrice
	******************************
	Entrée : unsigned int uiNumColonnes
	Necessité : néant
	Sortie : néant
	Entraine : réallouer et ajout d'une colonne
	*****************************/
	void MATAjouterColonnePrecis(unsigned int uiNumColonne);

	/*****************************
	Methode : Ajouter une ligne à un endroit précis de la matrice
	******************************
	Entrée : unsigned int uiNumLignes
	Necessité : néant
	Sortie : néant
	Entraine : réallouer et ajout d'une ligne
	*****************************/
	void MATAjouterLignePrecis(unsigned int uiNumLigne);

	/*****************************
	Methode : Supprimer une colonne à un endroit précis de la matrice
	******************************
	Entrée : unsigned int uiNumColonnes
	Necessité : Pré-condition : La libération des pointeurs avant la suppression de la colonne est à la charge de l'utilisateur
	Sortie : néant
	Entraine : réallouer et suppression d'une colonne
	*****************************/
	void MATSupprimerColonnePrecis(unsigned int uiNumColonne);

	/*****************************
	Methode : Supprimer une ligne à un endroit précis de la matrice
	******************************
	Entrée : unsigned int uiNumLignes
	Necessité : Pré-condition : La libération des pointeurs avant la suppression de la ligne est à la charge de l'utilisateur
	Sortie : néant
	Entraine : Réallocation et suppression d'une ligne
	*****************************/
	void MATSupprimerLignePrecis(unsigned int uiNumLigne);

	/*****************************
	Methode : Vérifier la portée de l'action dans la matrice
	******************************
	Entrée : unsigned int uiNumLignes, unsigned int uiNumColonnes
	Necessité : néant
	Sortie : néant
	Entraine : (néant) ou (Exception DIMENSIONHORSPORTEE : les paramètres fournis sont incorrectes)
	*****************************/
	void MATVerifierPortee(unsigned int uiNumLigne, unsigned int uiNumColonne);

	/*****************************
	Methode : Vérifier la dimension de la matrice
	******************************
	Entrée : unsigned int uiNumLignes, unsigned int uiNumColonnes
	Necessité : néant
	Sortie : néant
	Entraine : (néant) ou (Exception DIMENSIONINEGALE : les dimensions fournies ne correspondent pas à la matrice)
	*****************************/
	void MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	// Surchages d'opérateurs
	
	/*****************************
	Methode : Surcharge operateur +
	******************************
	Entrée : CMatrice<Type> & MATMatrice
	Necessité : Pré-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'opérateur + doit être présente dans la classe concernée
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre à membre
	*****************************/
	CMatrice<Type> operator+(CMatrice<Type> & MATMatrice);

	/*****************************
	Methode : Surcharge operateur -
	******************************
	Entrée : CMatrice<Type> & MATMatrice
	Necessité : Pré-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'opérateur - doit être présente dans la classe concernée
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre à membre
	*****************************/
	CMatrice<Type> operator-(CMatrice<Type> & MATMatrice);

	/*****************************
	Methode : Surcharge operateur * par constante
	******************************
	Entrée : Type & MATMatrice
	Necessité : Précondition : Nécessite la présence de la surcharge de l'opérateur * pour une matrice contenant des objets
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre à membre
	*****************************/
	CMatrice<Type> operator*(Type & qMATparam);

	/*****************************
	Methode : Surcharge operateur *
	******************************
	Entrée : CMatrice<Type> & MATMatrice
	Necessité : Pré-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'opérateur * doit être présente dans la classe concernée
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre à membre
	*****************************/
	CMatrice<Type> operator*(CMatrice<Type> & MATMatrice);

	/*****************************
	Methode : Surcharge operateur / par constante
	******************************
	Entrée : Type & MATMatrice
	Necessité : Précondition : Nécessite la présence de la surcharge de l'opérateur / pour une matrice contenant des objets
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre à membre
	*****************************/
	CMatrice<Type> operator/(Type & qMATparam);

	/*****************************
	Methode : Surcharge operateur =
	******************************
	Entrée : CMatrice<Type> & MATMatrice
	Necessité : Pré-condition : La libération des pointeurs avant l'affectation est à la charge de l'utilisateur
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre à membre
	*****************************/
	CMatrice<Type> & operator=(CMatrice<Type> & MATMatrice);

	/*****************************
	Methode : Surcharge de l'opérateur de différence entre deux matrices
	******************************
	Entrée : CMatrice<Type> & MATMatrice
	Necessité : néant
	Sortie : CMatrice<Type>
	Entraine : Recherche de différence entre les deux matrices
	*****************************/
	bool operator!=(CMatrice<Type> & MATMatrice);
};

/*****************************
Methode : Surcharge operateur * avec deux arguments
******************************
Entrée : Type qMATparam, CMatrice<Type> & MATparam
Necessité : néant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur * (pour avoir la commutativité)
*****************************/
template<class Type>
CMatrice<Type> operator*(Type qMATparam, CMatrice<Type> & MATMatrice);

#include "CMatrice.cpp"

#endif
