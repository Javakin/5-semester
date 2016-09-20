#include "TextHandle.h"
#include <iostream>
#include <stack>          // std::stack
#include <string>		 // std::string

//using namespace std;

TextHandle::TextHandle()
{
}

bool TextHandle::balPar(std::string text)
{
	// create stack
	std::stack<int> first;

	// iterate through the string
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '(') 
			first.push(0);
		if (text[i] == ')')
		{
			if (first.empty())
				return false;
			first.pop();
		}
	}

	// check that the stak is empty
	if (first.empty())
		return true;
	return false;
}


TextHandle::~TextHandle()
{
}
