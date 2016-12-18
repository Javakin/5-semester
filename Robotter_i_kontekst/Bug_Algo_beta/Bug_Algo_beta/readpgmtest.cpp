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
	std::cout << filename << std::endl;

	std::cout << "loading image..." << std::endl;
	Image* img = PPMLoader::load(filename);
	Mapping brusfireMapping(img);


	SeekAndDeliver port3(img, &brusfireMapping);
	
	// setup SensorClass
	std::string filename2("targets.pgm");
	std::cout << filename << std::endl;

	std::cout << "loading image..." << std::endl;
	Image* img2 = PPMLoader::load(filename2);

	SensorClass task1(img,img2);

	task1.sensoring({ 25,15 });
	

	// call relevant funcioctions
	port3.coverragePlaning();
	

	// dump image output
	port3.saveAllAsPGM();
		
	
	// cleanup
	delete img;
	//system("pause");
	
	return 0;
}