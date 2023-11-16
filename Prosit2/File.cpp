// Including necessary libraries
#include "Liberary1.h"
#include "Liberary2.h"

// Definition of the File class methods

// Read the contents of a file and return them as a string
string File::readFile(string text)
{
	// Initializing variables
	ifstream File;
	File.open(text);
	string readed;
	string line;

	// Check if the file is open
	if (File.is_open())
	{
		// Read each line from the file and append it to the readed string
		while (getline(File, line))
		{
			readed += line;
		}
	}

	// Return the contents of the file as a string
	return readed;
}

// Write a binary file with the given text and size
void File::writeFileBin(string text, string txt, int size)
{
	// Initializing variables
	int i;
	const char* c = &txt[0];
	const char* d = &text[0];

	// Open the file in write binary mode
	FILE* file = fopen(d, "w+b");

	// Write each character from the text to the file
	for (i = 0; i < size; i++)
	{
		fprintf(file, "%c", c[i]);
	}

	// Close the file
	fclose(file);
}

// Read a binary file and return its contents as a string
string File::readFileBin(string text, const int size)
{
	// Initializing variables
	int i;
	string s;
	string s1;
	const char* d = &text[0];
	i = 0;

	// Open the file in read binary mode
	FILE* file = fopen(d, "r+b");
	fseek(file, i, SEEK_SET);

	// Read each character from the file and append it to the string
	for (i = 0; i < size; i++)
	{
		s = (char)fgetc(file);
		s1.append(s);
	}

	// Close the file
	fclose(file);

	// Return the contents of the file as a string
	return s1;
}

// Write a text file with the given text
void File::writeFile(string text, string txt)
{
	// Initializing variable
	ofstream File;

	// Open the file in write mode
	File.open(text);

	// Write the text to the file
	File << txt;

	// Close the file
	File.close();
}

