#include <iostream>
#include "Image.h"
#include "PPMLoader.h"
#include "Robot.h"
#include "Transform.h"

#define PI 3.14159265358979323846 

using namespace rw::sensor;
using namespace rw::loaders;


int main(int argc, char** argv) {
	std::string filename(argv[1]);
	std::cout << filename << std::endl;


	std::cout << "loading image..." << std::endl;
	Image* img = PPMLoader::load(filename);

	// initiate robot
	Robot wall_e(img);

	// initiate transform matrixes 
	Transform H1(100, 0, 0);
	Transform H2(0, 200, 0);
	Transform H3(0, 0, 30 * PI / 180);
	
	//Transform H4():
	Transform Ha(200, 0, 0);
	Transform Hb(500, 0, 0);
	Transform Hc(0, 0, 60 * PI / 180);

	// make a move
	wall_e.move(Ha);
	wall_e.move(Hb);
	wall_e.move(Hc);

	// printing image
	std::cout << "saving image..." << std::endl;
	img->saveAsPGM("testout.pgm");
	
	// cleanup
	delete img;

	system("pause");
	
	return 0;
}