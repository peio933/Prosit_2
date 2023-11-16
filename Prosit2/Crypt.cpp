// Including necessary libraries
#include "Liberary1.h"
#include "Liberary2.h"

// Definition of the cesar function in the Crypt class
string Crypt::cesar(string txtACoder, int decalage)
{
	// Initializing variables
	string txtDecode;
	char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	// Loop through each character in the input string
	for (size_t i = 0; i < txtACoder.length(); i++)
	{
		// Convert the current character to lowercase
		txtACoder[i] = tolower(txtACoder[i]);
		int index = -1;

		// Check if the character is in the alphabet
		for (size_t j = 0; j < 26; j++)
		{
			if (txtACoder[i] == alphabet[j])
			{
				index = j;
				break;
			}
		}

		// If the character is in the alphabet, perform the Caesar cipher encryption
		if (index != -1)
		{
			txtDecode += alphabet[(index + decalage) % 26];
		}
		// If the character is not in the alphabet, keep it unchanged
		else
		{
			txtDecode += txtACoder[i];
		}
	}
	// Return the encrypted string
	return txtDecode;
}

// Definition of the XOR function in the Crypt class
string Crypt::XOR(string txtACoder, char key)
{
	// Initializing variables
	string txtDecode;

	// Loop through each character in the input string
	for (int i = 0; i < txtACoder.size(); i++)
	{
		// Perform XOR encryption using a key that changes with each character position
		txtDecode += txtACoder[i] ^ (int(key) + i) % 20;
	}
	// Return the encrypted string
	return txtDecode;
}

// Definition of the cesarXXOR function in the Crypt class
string Crypt::cesarXXOR(string txtAcoder, int decalage, char key, int mode)
{
	// Initializing variable
	string txtDecode;

	// Check the mode of operation
	if (mode == 1)
	{
		// Encrypt using Caesar cipher followed by XOR
		txtDecode = cesar(txtAcoder, decalage);
		txtDecode = XOR(txtDecode, key);
	}
	else if (mode == 2)
	{
		// Encrypt using XOR followed by Caesar cipher
		txtDecode = XOR(txtAcoder, key);
		txtDecode = cesar(txtDecode, decalage);
	}

	// Return the encrypted string
	return txtDecode;
}

