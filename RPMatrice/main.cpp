#include "CMatrice.cpp"
#include "CException.h"
#include "CParse.h"

void main()
{
	// Test constructeur par d�faut
	CMatrice<int> * a = new CMatrice<int>();

	// Test constructeur de recopie
	CMatrice<int> * b = new CMatrice<int>(* a);

	// Test destructeur par d�faut
	delete(a);

	// Test m�thode MATAfficherMatrice
	CMatrice<int> c = CMatrice<int>();

	c.MATAfficherMatrice();

}