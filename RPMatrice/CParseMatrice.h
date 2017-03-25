#ifndef C_PARSEMATRICE_H
#define C_PARSEMATRICE_H

class CParseMatrice
{
private:
	// Attributs
	static unsigned int uiPAMNbLignes;
	static unsigned int uiPAMNbColonnes;
	

	// Accesseurs
	static inline unsigned int PAMLireNbLignes();
	static inline void PAMAssignerNbLignes(char * sChaine);
	static inline unsigned int PAMLireNbColonnes();
	static inline void PAMAssignerNbColonnes(char * sChaine);

	// Methodes
	static char * PAMLireType();
	
public:
	void PAMTraiterFichier(char * sChemin);
};

#endif