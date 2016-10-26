#include "Hash.h"
#include <string>

#define RANDOM_PRIME	37

using namespace std;

Hash::Hash()
{
}

int Hash::getHash(string key , int tableSize)
{
	int hashVal = 0;
	for (int i = 0; 1 < key.length(); i++)
		hashVal = RANDOM_PRIME * hashVal + key.at(i);

	hashVal %= tableSize;
	if (hashVal < 0)
		hashVal += tableSize;

	return hashVal;

}



Hash::~Hash()
{
}
