#include <iostream>
#include "Image.h"
#include "PPMLoader.h"
#include "Robot.h"
#include "Transform.h"
#include "Mapping.h"
//#include <cmath>

#define PI 3.14159265358979323846 

using namespace rw::sensor;
using namespace rw::loaders;
using namespace std;


int main(int argc, char** argv) {
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::string filename(argv[1]);
	std::cout << filename << std::endl;


	std::cout << "loading image..." << std::endl;
	Image* img = PPMLoader::load(filename);

	// initiate
	//Robot wall_e(img);
	//Transform H4(200, 500, 3);
	
	Mapping fireObj(img);
	fireObj.Brushfire();

	std::cout << "saving image brushfire..." << std::endl;
	fireObj.getBrushfireMap()->saveAsPGM("brushfire.pgm");
	fireObj.getBrushfireMapWObj()->saveAsPGM("brushfireWObj.pgm");
	fireObj.getBrushfireMapInc()->saveAsPGM("brushfireInc.pgm");
	img->saveAsPGM("original.pgm");

	Mapping voronoiObj(img);
	voronoiObj.Voronoi();
	


	// printing image
	//std::cout << "saving image..." << std::endl;
	//img->saveAsPGM("testout.pgm");
	
	// cleanup
	delete img;
	system("pause");
	
	return 0;
}