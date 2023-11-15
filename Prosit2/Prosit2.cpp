#include "Liberary1.h"
#include "Liberary2.h"

int main()
{
	cout << "Crypter / Décrypter de fichier" << endl;

	Crypt crypt;
	File fileTool;
	string text;
	string txtACoder;
	string txtDecoder;
	int decalage;
	char key;
	int mode = -1;
	int size;

	while (mode != 4) 
	{
		cout << " Mode de cryptage :\n 1 - Cesar\n 2 - XOR\n 3 - Cesar + XOR\n 4 - Quitter" << endl;
		cin >> mode;

		if (mode > 0 && mode < 4)
		{
			int modeCode = -1;
			while (modeCode < 1 or modeCode > 2)
			{
				cout << " Que souhaitez-vous ? :\n 1 - Crypter\n 2 - Décrypter" << endl;
				cin >> modeCode;
			}

			cout << " Entrez le nom du fichier à crypter : " << endl;
			cin >> text;

			int inputMode = 0;
			cout << " Entrez le mode d'entrée :\n 1 - Texte\n 2 - Binaire" << endl;
			cin >> inputMode;

			if (inputMode == 1)
			{
				cout << " Entrez le texte à crypter : " << endl;
				cin >> txtACoder;
			}
			else if (inputMode == 2)
			{
				cout << " Entrez la taille du fichier à crypter : " << endl;
				cin >> size;
				cout << " Entrez le texte à crypter : " << endl;
				cin >> txtACoder;

			
		}

	}

}

