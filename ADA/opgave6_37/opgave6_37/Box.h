#pragma once
class Box
{
public:
	Box();
	Box(int aMaxWeight);

	bool addWeight(int itemWeight);
	int getCurrentWeight();
	int getMaxWeight();
	~Box();

private: 
	int currentWeight;
	int maxWeight;
};

