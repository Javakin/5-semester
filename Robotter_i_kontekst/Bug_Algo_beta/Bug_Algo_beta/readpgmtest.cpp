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
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::string filename("Bane2.pgm");
	std::cout << filename << std::endl;


	std::cout << "loading image..." << std::endl;
	Image* img = PPMLoader::load(filename);
	

	// initiate
	Robot wall_e(img);
	Transform H4(100, 150, 3);

	wall_e.goTo(H4);
	wall_e.getRobotPath();

	/*
	point p1 = { 10,10 };
	point p2 = { 190,190 };

	Mapping fireObj(img);
	fireObj.brushfire();
	fireObj.Voronoi();
	fireObj.dijkstra(p1, p2);


	fireObj.getBrushfireMap()->saveAsPGM("brushfire.pgm");
	fireObj.getBrushfireMapWObj()->saveAsPGM("brushfireWObj.pgm");
	fireObj.getBrushfireMapInc()->saveAsPGM("brushfireInc.pgm");
	fireObj.getPathMap()->saveAsPGM("pathMap.pgm");
	fireObj.getVoronoiMap()->saveAsPGM("voronoidPoints.pgm");
	

	img->saveAsPGM("original.pgm");	
	*/

	
	// cleanup
	delete img;
	system("pause");
	
	return 0;
}