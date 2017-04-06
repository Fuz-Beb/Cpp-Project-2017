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
	Constructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CMatrice();

	/*****************************
	Destructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : Pr�-condition : La lib�ration des pointeurs avant la suppression de la matrice est � la charge de l'utilisateur
	Sortie : n�ant
	Entraine : l'objet est d�truit
	*****************************/
	~CMatrice();

	/*****************************
	Constructeur � deux arguments
	******************************
	Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	/*****************************
	Constructeur de recopie
	******************************
	Entr�e : CMatrice<Type> & MATMatrice
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�/recopi�
	*****************************/
	CMatrice(CMatrice & MATMatrice);

	// Accesseurs

	/*****************************
	Methode : Ecrire nombre de lignes
	******************************
	Entr�e : unsigned int uiNbLignes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modification nombre de lignes
	*****************************/
	void MATEcrireNbLignes(unsigned int uiNbLignes);

	/*****************************
	Methode : Lire nombre de lignes
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : retourne nombre de lignes
	*****************************/
	unsigned int MATLireNbLignes();

	/*****************************
	Methode : Ecrire nombre de colonnes
	******************************
	Entr�e : unsigned int uiNbColonnes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modification nombre de colonnes
	*****************************/
	void MATEcrireNbColonnes(unsigned int uiNbColonnes);

	/*****************************
	Methode : Lire nombre de colonnes
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : retourne nombre de colonnes
	*****************************/
	unsigned int MATLireNbColonnes();

	// Calculs math�matiques

	/*****************************
	Methode : Calculer la transpos�e d'une matrice
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en calculant la transpos�e
	*****************************/
	CMatrice<Type> MATCalculerTransposee();

	/*****************************
	Methode : Mettre une matrice � la puissance
	******************************
	Entr�e : unsigned int uiNombre
	Necessit� : n�ant
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en mettant la puissance de la matrice
	*****************************/
	CMatrice<Type> MATPPuissanceMatrice(unsigned int uiNombre);

	// G�rer les �l�ments de la matrice

	/*****************************
	Methode : Modifier l'�l�ment � l'endroit de la matrice
	******************************
	Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes, Type tElement
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modification de l'�l�ment
	*****************************/
	void MATModifierElement(unsigned int uiNumLigne, unsigned int uiNumColonne, Type tElement);

	/*****************************
	Methode : Lire l'�l�ment � l'endroit de la matrice
	******************************
	Entr�e : unsigned int uiNbLignes, unsigned int uiNbColonnes
	Necessit� : n�ant
	Sortie : Type
	Entraine : retourne l'element � l'endroit de la matrice
	*****************************/
	Type MATLireElement(unsigned int uiNumLigne, unsigned int uiNumColonne);

	/*****************************
	Methode : Initialise l'ensemble des valeurs de la matrice � la valeur 0
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�nant
	Entraine : mise � la valeur 0 � l'ensemble des cases de la matrice
	*****************************/
	void MATInit();
	
	 /*****************************
	Methode : Afficher la matrice � l'�cran
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : Afficher la matrice de l'objet � l'�cran
	*****************************/
	void MATAfficherMatrice();
	
	/*****************************
	Methode : Ajouter une/des colonnes � la droite de la matrice
	******************************
	Entr�e : unsigned int uiNbColonnes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : r�allouer selon ajout nb colonnes
	*****************************/
	void MATAjouterColonnesFin(unsigned int uiNbColonnes);

	/*****************************
	Methode : Ajouter une/des lignes en bas de la matrice
	******************************
	Entr�e : unsigned int uiNbLignes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : r�allouer selon ajout nb lignes
	*****************************/
	void MATAjouterLignesFin(unsigned int uiNbLignes);

	/*****************************
	Methode : Supprimer une/des colonnes � droite de la matrice
	******************************
	Entr�e : unsigned int uiNbColonnes
	Necessit� : Pr�-condition : La lib�ration des pointeurs avant la suppression de la colonne est � la charge de l'utilisateur
	Sortie : n�ant
	Entraine : r�allouer selon suppression nb colonnes
	*****************************/
	void MATSupprimerColonneFin(unsigned int uiNbColonnes);

	/*****************************
	Methode : Supprimer une/des ligne en bas de la matrice
	******************************
	Entr�e : unsigned int uiNbLignes
	Necessit� : Pr�-condition : La lib�ration des pointeurs avant la suppression de la ligne est � la charge de l'utilisateur
	Sortie : n�ant
	Entraine : r�allouer selon suppression nb lignes
	*****************************/
	void MATSupprimerLigneFin(unsigned int uiNbLignes);
	
	/*****************************
	Methode : Ajouter une colonne � un endroit pr�cis de la matrice
	******************************
	Entr�e : unsigned int uiNumColonnes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : r�allouer et ajout d'une colonne
	*****************************/
	void MATAjouterColonnePrecis(unsigned int uiNumColonne);

	/*****************************
	Methode : Ajouter une ligne � un endroit pr�cis de la matrice
	******************************
	Entr�e : unsigned int uiNumLignes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : r�allouer et ajout d'une ligne
	*****************************/
	void MATAjouterLignePrecis(unsigned int uiNumLigne);

	/*****************************
	Methode : Supprimer une colonne � un endroit pr�cis de la matrice
	******************************
	Entr�e : unsigned int uiNumColonnes
	Necessit� : Pr�-condition : La lib�ration des pointeurs avant la suppression de la colonne est � la charge de l'utilisateur
	Sortie : n�ant
	Entraine : r�allouer et suppression d'une colonne
	*****************************/
	void MATSupprimerColonnePrecis(unsigned int uiNumColonne);

	/*****************************
	Methode : Supprimer une ligne � un endroit pr�cis de la matrice
	******************************
	Entr�e : unsigned int uiNumLignes
	Necessit� : Pr�-condition : La lib�ration des pointeurs avant la suppression de la ligne est � la charge de l'utilisateur
	Sortie : n�ant
	Entraine : R�allocation et suppression d'une ligne
	*****************************/
	void MATSupprimerLignePrecis(unsigned int uiNumLigne);

	/*****************************
	Methode : V�rifier la port�e de l'action dans la matrice
	******************************
	Entr�e : unsigned int uiNumLignes, unsigned int uiNumColonnes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : (n�ant) ou (Exception DIMENSIONHORSPORTEE : les param�tres fournis sont incorrectes)
	*****************************/
	void MATVerifierPortee(unsigned int uiNumLigne, unsigned int uiNumColonne);

	/*****************************
	Methode : V�rifier la dimension de la matrice
	******************************
	Entr�e : unsigned int uiNumLignes, unsigned int uiNumColonnes
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : (n�ant) ou (Exception DIMENSIONINEGALE : les dimensions fournies ne correspondent pas � la matrice)
	*****************************/
	void MATVerifierDimension(unsigned int uiNbLignes, unsigned int uiNbColonnes);

	// Surchages d'op�rateurs
	
	/*****************************
	Methode : Surcharge operateur +
	******************************
	Entr�e : CMatrice<Type> & MATMatrice
	Necessit� : Pr�-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'op�rateur + doit �tre pr�sente dans la classe concern�e
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre � membre
	*****************************/
	CMatrice<Type> operator+(CMatrice<Type> & MATMatrice);

	/*****************************
	Methode : Surcharge operateur -
	******************************
	Entr�e : CMatrice<Type> & MATMatrice
	Necessit� : Pr�-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'op�rateur - doit �tre pr�sente dans la classe concern�e
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre � membre
	*****************************/
	CMatrice<Type> operator-(CMatrice<Type> & MATMatrice);

	/*****************************
	Methode : Surcharge operateur * par constante
	******************************
	Entr�e : Type & MATMatrice
	Necessit� : Pr�condition : N�cessite la pr�sence de la surcharge de l'op�rateur * pour une matrice contenant des objets
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre � membre
	*****************************/
	CMatrice<Type> operator*(Type & qMATparam);

	/*****************************
	Methode : Surcharge operateur *
	******************************
	Entr�e : CMatrice<Type> & MATMatrice
	Necessit� : Pr�-condition : Si la matrice contient des pointeurs sur des objets, la surchage de l'op�rateur * doit �tre pr�sente dans la classe concern�e
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre � membre
	*****************************/
	CMatrice<Type> operator*(CMatrice<Type> & MATMatrice);

	/*****************************
	Methode : Surcharge operateur / par constante
	******************************
	Entr�e : Type & MATMatrice
	Necessit� : Pr�condition : N�cessite la pr�sence de la surcharge de l'op�rateur / pour une matrice contenant des objets
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre � membre
	*****************************/
	CMatrice<Type> operator/(Type & qMATparam);

	/*****************************
	Methode : Surcharge operateur =
	******************************
	Entr�e : CMatrice<Type> & MATMatrice
	Necessit� : Pr�-condition : La lib�ration des pointeurs avant l'affectation est � la charge de l'utilisateur
	Sortie : CMatrice<Type>
	Entraine : retourne une nouvelle matrice en surchageant l'operateur en question membre � membre
	*****************************/
	CMatrice<Type> & operator=(CMatrice<Type> & MATMatrice);

	/*****************************
	Methode : Surcharge de l'op�rateur de diff�rence entre deux matrices
	******************************
	Entr�e : CMatrice<Type> & MATMatrice
	Necessit� : n�ant
	Sortie : CMatrice<Type>
	Entraine : Recherche de diff�rence entre les deux matrices
	*****************************/
	bool operator!=(CMatrice<Type> & MATMatrice);
};

/*****************************
Methode : Surcharge operateur * avec deux arguments
******************************
Entr�e : Type qMATparam, CMatrice<Type> & MATparam
Necessit� : n�ant
Sortie : CMatrice<Type>
Entraine : Surchage de l'operateur * (pour avoir la commutativit�)
*****************************/
template<class Type>
CMatrice<Type> operator*(Type qMATparam, CMatrice<Type> & MATMatrice);

#include "CMatrice.cpp"

#endif
