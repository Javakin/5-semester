#pragma once

#include "Image.h"


class Mapping
{
public:
	Mapping();

	void diagram();

	~Mapping();
	int test();
private:
	rw::sensor::Image* map;
	
};

