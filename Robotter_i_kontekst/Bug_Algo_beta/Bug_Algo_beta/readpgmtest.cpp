#include <iostream>
#include "Image.h"
#include "PPMLoader.h"
#include "Robot.h"
#include "Transform.h"
#include "Mapping.h"
#include "SeekAndDeliver.h"
#include "SensorClass.h"
//#include <cmath>

#define PI 3.14159265358979323846 

using namespace rw::sensor;
using namespace rw::loaders;
using namespace std;


int main(int argc, char** argv) {
	// for detection of memory leaks 
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		
	// setup SeekAndDeliver
	std::string filename("Images/Bane5.pgm");
	std::string filename2("Images/targets.pgm");
	std::cout << filename << std::endl;

	std::cout << "loading image..." << std::endl;
	Image* img = PPMLoader::load(filename);
	Image* target = PPMLoader::load(filename2);
	Mapping brusfireMapping(img);
	SensorClass sensor(img, target);

	SeekAndDeliver port3(img, &brusfireMapping, &sensor);
	
	
	// call relevant funcioctions
	port3.coverragePlaning();
	
	// dump image output
	port3.saveAllAsPGM();
	
	
	// cleanup
	delete img;
	delete target;
	system("pause");
	
	return 0;
}