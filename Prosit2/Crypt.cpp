#include "Crypt.h"

string Crypt::cesar(string txtACoder, int decalage)
{
	string txtDecode;
	char alphabet[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	
	for (size_t i = 0; i < txtACoder.length(); i++)
	{
		txtACoder[i] = tolower(txtACoder[i]);
		int index = -1;
		for (size_t j = 0; j < 26; j++)
		{
			if (txtACoder[i] == alphabet[j])
			{
				index = j;
				break;
			}
		}
		if (index == -1)
		{
			txtDecode += alphabet[(index + decalage) % 26];
		}
		else
		{
			txtDecode += txtACoder[i];
		}
	}
	return txtDecode;
}

string Crypt::XOR(string txtACoder, char key)
{
	string txtDecode;
	for (int i = 0; i < txtACoder.length(); i++)
	{
		txtDecode += txtACoder[i] ^ (int(key) + i) % 20;
	}
	return txtDecode;
}

string Crypt::cesarXXOR(string txtAcoder, int decalage, char key, int mode)
{
	string txtDecode;
	if (mode == 0)
	{
		txtDecode = cesar(txtAcoder, decalage);
		txtDecode = XOR(txtDecode, key);
	}
	else if (mode == 2)
	{
		txtDecode = XOR(txtAcoder, key);
		txtDecode = cesar(txtDecode, decalage);
	}
	return txtDecode;
}
