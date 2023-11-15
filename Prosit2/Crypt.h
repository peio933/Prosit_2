#include "Liberary1.h"

class Crypt
{
public:
	string cesar(string txtACoder, int decalage);
	string XOR(string txtACoder, char key);
	string cesarXXOR(string txtAcoder, int decalage, char key, int mode);
};