#pragma once

#include <iostream>
#include "Hash.h"
#include "List.h"
#include <string>

#define TABLE_SIZE		13

using namespace std;


int main()
{
	Hash kage;
	List aList(TABLE_SIZE);

	string astring = "test";
	kage.getHash(astring, TABLE_SIZE);

	



	return 0;
}