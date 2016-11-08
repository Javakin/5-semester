/*Original from Steen-Bjørn, Current Project*/

#include <iostream>
#include "Image.h"
#include "PPMLoader.h"
#include "Dijkstra.h"

#define PI 3.14159265358979323846 

using namespace rw::sensor;
using namespace rw::loaders;
using namespace std;


int main(int argc, char** argv) {
	std::string filename(argv[1]);

	Image* img = PPMLoader::load(filename);
	Dijkstra pathPlanning(img);

	pathPlanning.algorithm();

	// printing image
	std::cout << "saving image..." << std::endl;
	img->saveAsPGM("testout.pgm");

	// cleanup
	delete img;
	return 0;
}