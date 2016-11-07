#include "Mapping.h"
#include "Image.h"
#include <iostream>

using namespace std;

Mapping::Mapping()
{
}


//#include <iostream>
//#include "Image.hpp"
//#include "PPMLoader.hpp"
//
//using namespace rw::sensor;
//using namespace rw::loaders;
//
//int main(int argc, char** argv) {
//	std::string filename(argv[1]);
//
//	std::cout << "loading image..." << std::endl;
//	Image* img = PPMLoader::load(filename);
void Mapping::diagram()
{
	std::cout << "test test";
	// do stuff here
	int channel = 0; // allways 0 on grayscale image

	std::cout << "inverting image..." << std::endl;
	// change all 0 pixels to 255 and all 255 pixels to 0
	/*for (int x = 0; x<map->getWidth(); x++) {
		for (int y = 0; y<map->getHeight(); y++) {
			int val = map->getPixelValuei(x, y, channel);
			if (val == 0) {
				map->setPixel8U(x, y, 255);
			}
			else if (val == 255) {
				map->setPixel8U(x, y, 0);
			}
		}
	}*/

	//std::cout << "Test off getWidth()" << ;
	//map->getWidth();
	std::cout << "saving image..." << std::endl;
	// save image
	//map->saveAsPGM("testout.pgm");

	// cleanup
	delete map;
}


Mapping::~Mapping()
{
}

int Mapping::test()
{
	std::cout << "TESTETESTEST";
	return 0;
}
