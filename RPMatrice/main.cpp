#include "CMatrice.cpp"
#include "CException.h"
#include "CParse.h"

void main()
{
	unsigned int z = 0;

	// Test constructeur par d�faut
	CMatrice<int> * a = new CMatrice<int>();

	// Test constructeur de recopie
	CMatrice<int> * b = new CMatrice<int>(* a);

	// Test destructeur par d�faut
	delete(a);

	// Test m�thode MATAfficherMatrice
	CMatrice<int> c = CMatrice<int>(2, 2);
	c.MATModifierElement(1,1, 1);
	c.MATModifierElement(1,2, 2);
	c.MATModifierElement(2,1, 3);
	c.MATModifierElement(2,2, 4);
	c.MATAfficherMatrice();

	// Test de modification et de lecture des �lements de la matrice
	CMatrice<int> d = CMatrice<int>(2,2);
	d.MATModifierElement(2,2, 1);
}