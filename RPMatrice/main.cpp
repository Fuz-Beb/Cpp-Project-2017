#include "CMatrice.cpp"
#include "CException.h"
#include "CParse.h"

void main()
{
	// Constructeur par d�faut :
	CMatrice<int> * a = new CMatrice<int>();

	// Constructeur de recopie :
	CMatrice<int> * b = new CMatrice<int>(* a);

	// Destructeur :
	delete(a);
}