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
	int xx = 0;
	int yy = 0;
	int xxx = 0;
	int yyy = img->getHeight();
	int xxxx = img->getHeight();
	int yyyy = img->getHeight();
	int xxxxx = img->getHeight();
	int yyyyy = 0;

	int testIfblack = 0;
	vector<vector<int>> testvec(rows,vector<int> (cols, val));
	int channel = 0; // allways 0 on grayscale image

	for (unsigned int x = 0; x<img->getWidth(); ++x) {
		for (unsigned int y = 0; y<img->getHeight(); ++y) {
			int val = img->getPixelValuei(x, y, channel);
			
			testvec[x][y] = val;
			//cout << " Testvec val at " << x << ", " << y << ": " <<testvec[x][y] << endl;

			if (x < img->getWidth()-1 && x > 1 && y < img->getHeight()-1 && y > 1)
			{
				if (testvec[x][y] != testvec[x - 1 ][y] && testvec[x][y] != testvec[x + 1 ][y] && testvec[x - 1][y] != 254 && testvec[x + 1][y] != 254)
				{
					testvec[x][y] = 254;
				}
				else if (testvec[x][y] != testvec[x][y - 1] && testvec[x][y] != testvec[x][y + 1] && testvec[x][y - 1] != 254 && testvec[x][y + 1] != 254)
				{
					testvec[x][y] = 254;
				}
			}
		}
	}
	for (int i = 0; i < img->getWidth()-1; i++)
	{
			if (testvec[xx + 1][yy + 1] != 254 && testvec[xx + 1][yy] && testvec[xx][yy + 1])
			{
				++xx;
				++yy;
				testvec[xx][yy] = 254;
			}

			if (testvec[xxx + 1][yyy - 1] != 254 && testvec[xxx + 1][yyy - 2] != 254 && testvec[xxx][yyy - 1] != 254)
			{
				++xxx;
				--yyy;
				testvec[xxx][yyy] = 254;
			}
			
			if (testvec[xxxx - 1][yyyy - 1] != 254 && testvec[xxxx - 1][yyyy - 2] != 254 && testvec[xxxx - 2][yyyy - 1] != 254)
			{
				--xxxx;
				--yyyy;
				testvec[xxxx][yyyy] = 254;
			}
			/*&& testvec[xxxxx - 1][yyyyy - 2] != 254 && testvec[xxxxx - 2][yyyyy - 1] != 254*/
			if (testvec[xxxxx - 1][yyyyy + 1] != 254 && testvec[xxxxx - 1][yyyyy] != 254 /*&& testvec[xxxxx][yyyyy + 1] != 254*/)
			{
				--xxxxx;
				++yyyyy;
				testvec[xxxxx][yyyyy] = 254;
			}
	}
	testvec[xxx + 1][yyy - 1] = 254;
	for (unsigned int x = 0; x < img->getWidth(); ++x) {
		for (unsigned int y = 0; y < img->getHeight(); ++y) {
			if (testvec[x][y] == 254) {
				img->setPixel8U(x, y, 0);
			}
		}
	}

	//for (int i = 1; i < 10; i++)
	//{
	//	++xx;
	//	++yy;
	//	testvec[xx][yy] = 254;
	//}
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