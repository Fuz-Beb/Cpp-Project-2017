#include "CParse.h"
#include "CException.h"
#include "CMatrice.h"

/*****************************
Methode : Lire nombre de lignes
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : retourne nombre de lignes
*****************************/
unsigned int CParse::PARLireNbLignes()
{
	return uiPARNbLignes;
}

/*****************************
Methode : Ecrire nombre de lignes
******************************
Entrée : unsigned int uiNbLignes
Necessité : néant
Sortie : néant
Entraine : modification nombre de lignes
*****************************/
void CParse::PAREcrireNbLigne(unsigned int uiNbLignes)
{
	uiPARNbLignes = uiNbLignes;
}

/*****************************
Methode : Lire nombre de colonnes
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : retourne nombre de colonnes
*****************************/
unsigned int CParse::PARLireNbColonnes()
{
	return uiPARNbColonnes;
}
 
/*****************************
Methode : Ecrire nombre de colonnes
******************************
Entrée : unsigned int uiNbColonnes
Necessité : néant
Sortie : néant
Entraine : modification nombre de colonnes
*****************************/
void CParse::PAREcrireNbColonnes(unsigned int uiNbColonnes)
{
	uiPARNbColonnes = uiNbColonnes;
}

/*****************************
Methode : Traiter fichier
******************************
Entrée : 
Necessité : néant
Sortie : néant
Entraine : 
*****************************/
void CParse::PARTraiterFichier(char * psChemin)
{/*
	string sContenu[4];
	string sBuffer;
	char * sBufferDouble;
	unsigned int uiBoucle = 0, uiBoucleBuffer = 0, uiCompteurLigne = 0, uiCompteurColonne = 0, uiBoucleBufferDouble = 0, uiMaxColonne;
	ifstream fichier("test.txt", ios::in); // Ouvrir le fichier en lecture

	if(!fichier)// Si ouverture a reussi
		throw CException(ECHECFICHIER, "Echec d'ouverture du fichier");

	while(getline(fichier, sContenu[uiBoucle])) {
		uiBoucle++;
		toLower(sContenu[0]);
	}

	if(sContenu[0] != "double")
		throw CException(MAUVAISTYPE, "La matrice lue n'est pas de type double");

	if(atoi(sContenu[1].c_str()) < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

	uiPARNbLignes = atoi(sContenu[1].c_str());

	if(atoi(sContenu[2].c_str()) < 1)
		throw CException(ERREURTAILLE, "Erreur de la taille");

	uiPARNbColonnes = atoi(sContenu[1].c_str());

	CMatrice<double> pMATMatrice = CMatrice<double>(uiPARNbLignes, uiPARNbColonnes);


	while(getline(fichier, sBuffer)) { // Parcourir les lignes jusqu'à la fin
		
		uiMaxColonne = uiPARNbColonnes; // Remise du compteur de colonne à la taille annoncée

		while(uiBoucleBuffer < uiMaxColonne) { // Parcourir les colonnes de la ligne actuel
			
			if(sBuffer[uiBoucleBuffer] != ' ') { // Verifier si espace
				//sBufferDouble[uiBoucleBufferDouble] = sBuffer[uiBoucleBuffer]; // A FREE ET A STRDUP
				
				if(sBufferDouble != NULL)
					//sBufferDouble = // Verifier si il y a quelques choses dans le buffer, si oui alors concatenate et agrandir buffer
				
				sBufferDouble = strdup((const char*)sBuffer[uiBoucleBuffer]); // A FREE ET A STRDUP
				uiBoucleBufferDouble++;

				if(sBuffer[uiBoucleBuffer + 1] == ' ' || sBuffer[uiBoucleBuffer + 1] == '\0' || sBuffer[uiBoucleBuffer + 1] == '\n' || sBuffer[uiBoucleBuffer + 1] == '\t')
					pMATMatrice.MATModifierElement(uiCompteurLigne, uiCompteurColonne, stof(sBufferDouble));
					free(sBufferDouble);
			}

			else
				uiMaxColonne++;

			// Ligne ajouter element matrice

			uiBoucleBuffer++;
		}

		uiCompteurLigne++;
	}


	fichier.close();*/
}

void toLower(basic_string<char>& sChaine) {
   for (basic_string<char>::iterator p = sChaine.begin();
        p != sChaine.end(); ++p) {
      *p = tolower(*p);
   }
}

void toLower(basic_string<wchar_t>& sChaine) {
   for (basic_string<wchar_t>::iterator p = sChaine.begin();
        p != sChaine.end(); ++p) {
      *p = towlower(*p);
   }
}

/*
void string_to_float(string & chaine, float* tab)
{
	int cc=nbre_colonne((char*)chaine.c_str());
	tab=new float [cc];

	for(int j=0;j<cc;j++) {
		string X;
		X=chaine.substr(j*8+j,8);
		tab[j]=atof(X.c_str());
		printf("tab[%d]= %f",j,tab[j]) ;
	}
}
*/
