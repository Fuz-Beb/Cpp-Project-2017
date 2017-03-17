#include "CMatrice.cpp"
#include "CException.h"
#include "CParse.h"

void main()
{
	unsigned int z = 0;

	// Test constructeur par défaut
	CMatrice<int> * a = new CMatrice<int>();

	// Test constructeur de recopie
	CMatrice<int> * b = new CMatrice<int>(* a);

	// Test destructeur par défaut
	delete(a);

	// Test de modification et de lecture des élements de la matrice
	CMatrice<int> c = CMatrice<int>(2,2);
	c.MATModifierElement(1,1, 1);
	z = c.MATLireElement(1,1);
	printf("- %d -", z);
	
	c.MATModifierElement(1, 2, 6);
	z = c.MATLireElement(1,2);
	printf(" - %d - ", z);

	c.MATModifierElement(2, 1, 7);
	z = c.MATLireElement(2,1);
	printf(" - %d - ", z);

	c.MATModifierElement(2, 2, 10);
	z = c.MATLireElement(2,2);
	printf(" - %d - ", z);
}