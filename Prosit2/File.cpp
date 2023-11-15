#include "Liberary1.h"
#include "Liberary2.h"

void File::writeFile(string text, string txt)
{
	ofstream File;
	File.open(text);
	File << txt;
	File.close();
	
}

string File::readFile(string text)
{
	ifstream File;
	File.open(text);
	string readed;
	string line;
	if (File.is_open())
	{
		while (getline(File, line))
		{
			readed += line;
		}
	}
	return readed;
}

void File::writeFileBin(string text, string txt, int size)
{
	int i;
	const char* c = &txt[0];
	const char* d = &text[0];
	FILE* file = fopen(d, "w+b");
	for (i = 0; i < size; i++)
	{
		fprintf(file, "%c", c[i]);
		
	}
	fclose(file);
}

string File::readFileBin(string text, const int size)
{
	int i;
	string s;
	string s1;
	const char* d = &text[0];
	i = 0;
	FILE* file = fopen(d, "r+b");
	fseek(file, i, SEEK_SET);
	for (i = 0; i < size; i++)
	{
		s = (char)fgetc(file);
		s1.append(s);
	}
	fclose(file);
	return s1;
}
