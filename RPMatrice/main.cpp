#include "CMatrice.cpp"
#include "CException.h"
#include "CParse.h"

void main()
{
	// Test constructeur par défaut
	CMatrice<int> * a = new CMatrice<int>();

	// Test constructeur de recopie
	CMatrice<int> * b = new CMatrice<int>(* a);

	// Test destructeur par défaut
	delete(a);

}