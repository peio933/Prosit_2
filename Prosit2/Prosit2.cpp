// Including necessary libraries
#include "Liberary1.h"
#include "Liberary2.h"

// Main function
int main()
{
	// Set the locale for character handling to French
	setlocale(LC_CTYPE, "fra");

	// Output program title
	cout << "Crypter / Décrypter de fichier" << endl;

	// Create instances of Crypt and File classes
	Crypt crypt;
	File fileTool;

	// Declare variables
	string text;
	string txtACoder;
	string txtDecode;
	int decalage;
	char key;
	int mode = -1;
	int size;

	// Main program loop
	while (mode != 4)
	{
		// Display encryption modes menu
		cout << " Mode de cryptage :\n 1 - Cesar\n 2 - XOR\n 3 - Cesar + XOR\n 4 - Quitter" << endl;
		cin >> mode;

		// Check if the selected mode is valid
		if (mode > 0 && mode < 4)
		{
			// Declare and initialize modeCode variable
			int modeCode = -1;

			// Prompt user to choose encryption or decryption
			while (modeCode < 1 or modeCode > 2)
			{
				cout << " Que souhaitez-vous ? :\n 1 - Crypter\n 2 - Décrypter" << endl;
				cin >> modeCode;
			}

			// Prompt user for the file path
			cout << "Entrez le chemin d'accès du fichier à crypter :" << endl;
			cin >> text;

			// Prompt user for input mode: message or file
			int inputMode = 0;
			cout << "Voulez-vous crypter à partir:\n1. Message saisi\n2. Fichier" << endl;
			cin >> inputMode;

			// If input mode is message, prompt user for the text to be encrypted
			if (inputMode == 1)
			{
				cout << "Entrez le texte à crypter :";
				cin >> txtACoder;
			}

			// Handle Caesar encryption
			if (mode == 1 or mode == 3)
			{
				// Prompt user for the shift value (decalage)
				cout << "Entrez le décalage :";
				cin >> decalage;

				// Adjust decalage for decryption
				if (modeCode == 2)
				{
					decalage = -decalage;
				}

				// Perform Caesar encryption and write to file
				if (mode == 1)
				{
					if (inputMode == 1)
					{
						txtDecode = crypt.cesar(txtACoder, decalage);
					}
					else
					{
						txtDecode = crypt.cesar(fileTool.readFile(text + ".txt"), decalage);
					}
					fileTool.writeFile(text + ".txt", txtDecode);
				}
			}

			// Handle XOR encryption
			if (mode == 2 or mode == 3)
			{
				// Prompt user for encryption key
				cout << " Entrez la clé de chiffrement : ";
				cin >> key;

				// Prompt user for file size if decrypting with XOR
				if (modeCode == 2)
				{
					cout << " Entrez la taille du fichier:";
					cin >> size;
				}
				else
				{
					size = sizeof(txtACoder);
				}

				// Perform XOR encryption and write to file
				if (mode == 2)
				{
					if (inputMode == 1)
					{
						txtDecode = crypt.XOR(txtACoder, key);
					}
					else
					{
						txtDecode = crypt.XOR(fileTool.readFileBin(text + ".bin", size), key);
					}
					cout << txtDecode << endl;

					// Write the result to the appropriate file type (binary or text)
					if (modeCode == 1)
					{
						fileTool.writeFileBin(text + ".bin", txtDecode, size);
					}
					else
					{
						fileTool.writeFile(text + ".txt", txtDecode);
					}
				}
			}

			// Handle Cesar + XOR encryption
			if (mode == 3)
			{
				if (inputMode == 1)
				{
					txtDecode = crypt.cesarXXOR(txtACoder, decalage, key, modeCode);
				}
				else
				{
					txtDecode = crypt.cesarXXOR(fileTool.readFileBin(text + ".bin", size), decalage, key, modeCode);
				}

				// Write the result to the appropriate file type (binary or text)
				if (modeCode == 1)
				{
					fileTool.writeFileBin(text + ".bin", txtDecode, size);
				}
				else
				{
					cout << "Texte décodé: " << txtDecode << endl;
					fileTool.writeFile(text + ".txt", txtDecode);
				}
			}

			// Output success message
			cout << "Fichier " << text << " crypté avec succès !" << endl;
		}
	}

	// End of the program
	return 0;
}



