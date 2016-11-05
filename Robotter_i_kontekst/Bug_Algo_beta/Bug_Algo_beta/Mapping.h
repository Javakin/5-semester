#pragma once

#include "Image.h"


class Mapping
{
public:
	Mapping();

	~Mapping();

private:
	rw::sensor::Image* map;
	
};

