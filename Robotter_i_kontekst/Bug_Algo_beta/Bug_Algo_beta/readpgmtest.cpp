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
	std::string filename(argv[1]);
	std::cout << filename << std::endl;


	std::cout << "loading image..." << std::endl;
	Image* img = PPMLoader::load(filename);

	// initiate
	//Robot wall_e(img);
	//Transform H4(200, 500, 3);
	
	/*Mapping invert;
	invert.diagram();*/
	// This part is going inside "Mapping.cpp"

	cout << "Width of image: " << img->getWidth() << endl;
	cout << "Height of image: " << img->getHeight() << endl;
	int rows = img->getHeight();
	int cols = img->getWidth();
	int val = 1;
	int x = 0;
	int y = 0;
	vector<vector<int>> testvec(rows,vector<int> (cols, val));
	int channel = 0; // allways 0 on grayscale image

	for (unsigned int x = 0; x<img->getWidth(); ++x) {
		for (unsigned int y = 0; y<img->getHeight(); ++y) {
			int val = img->getPixelValuei(x, y, channel);
			
			testvec[x][y] = val;
			cout << " Testvec val at " << x << ", " << y << ": " <<testvec[x][y];

			if (x < img->getWidth() && x > 0 && y < img->getHeight() && y > 0)
			{
				if (testvec[x - 1][y] != testvec[x][y])
				{
					testvec[x][y] = 255;
				}
				else if (testvec[x - 1][y - 1] != testvec[x][y])
				{
					testvec[x][y] = 255;
				}
				else if (testvec[x - 1][y + 1] != testvec[x][y])
				{
					testvec[x][y] = 255;
				}
				else if (testvec[x + 1][y] != testvec[x][y])
				{
					testvec[x][y] = 255;
				}
				else if (testvec[x + 1][y - 1] != testvec[x][y])
				{
					testvec[x][y] = 255;
				}
				else if (testvec[x + 1][y + 1] != testvec[x][y])
				{
					testvec[x][y] = 255;
				}
				else if (testvec[x][y - 1] != testvec[x][y])
				{
					testvec[x][y] = 255;
				}
				else if (testvec[x][y + 1] != testvec[x][y])
				{
					testvec[x][y] = 255;
				}
				
			}
			/*
			if (val <= 127) {
				img->setPixel8U(x, y, 255);
			}
			else if (val > 127) {
				img->setPixel8U(x, y, 0);
			}*/
		}
	}
	/*for (auto i : testvec)
		cout << "Test vec val: " << i << " " << endl;*/
	/*for (auto i = testvec.begin(); i < testvec.end(); ++i)
	{
		cout << "Test vec val: " << testvec[i] << " i: " << i << endl;
	}*/

	std::cout << "saving image..." << std::endl;
	// save image
	img->saveAsPGM("testout.pgm");

	

	/*Mapping testtt;
	testtt.test();*/

	//std::cout << "Test off getWidth(): " << img->getWidth() << std::endl;

	// printing image
	//std::cout << "saving image..." << std::endl;
	//img->saveAsPGM("testout.pgm");
	


	// cleanup
	delete img;
	system("pause");
	
	return 0;
}