#include <iostream>
#include "Image.h"
#include "PPMLoader.h"
#include "Robot.h"
#include "Transform.h"

#define PI 3.14159265358979323846 

using namespace rw::sensor;
using namespace rw::loaders;
using namespace std;


int main(int argc, char** argv) {
	std::string filename(argv[1]);
	std::cout << filename << std::endl;

	double trig = cos(0);
	trig = cos(1);


	std::cout << "loading image..." << std::endl;
	Image* img = PPMLoader::load(filename);

	// initiate robot
	Robot wall_e(img);
	Robot test;

	// initiate transform matrixes 
	double dir = -90 * PI / 180;

	Transform H1(100, 0, 0);
	Transform H2(0, 200, 0);
	Transform H3(0, 0, dir);
	Transform H4(200, 500, 60 * PI / 180);

	H1.printTransform("H1");
	H2.printTransform("H2");
	H3.printTransform("H3");


	// matrix multipluer
	H1.mult(H2).mult(H3).printTransform("H3 * H2 * H1");
	H3.mult(H2).mult(H1).printTransform("H1 * H2 * H3");

	// make a move
	wall_e.goTo(H1);
	

	// printing image
	std::cout << "saving image..." << std::endl;
	img->saveAsPGM("testout.pgm");
	
	// cleanup
	delete img;
	H1.remove();
	H2.remove();
	H3.remove();
	H4.remove();

	system("pause");
	
	return 0;
}