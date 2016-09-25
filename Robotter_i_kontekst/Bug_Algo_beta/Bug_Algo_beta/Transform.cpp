#include "Transform.h"




int main(int argc, char** argv)
{
	std::cout << "Hello" << std::endl;

	Transform transform1(1, 0, 0);
	Transform transform2(0, 0, 45 * PI / 180.0);
	Transform transform3(1, 0, 0);
	Transform transform4(0, 0, 45 * PI / 180.0);

	std::cout << "Transform1:";
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			std::cout << transform1(i, j) << "  ";
		}
		std::cout << std::endl;
	}


	Point p(0, 0);
	Point p2 = transform1.mult(transform2.mult(transform3.mult(transform4.mult(p))));
	std::cout << "Transformed Point " << p2(0) << ", " << p2(1) << ", " << p2(2) << std::endl;
	return 0;
}