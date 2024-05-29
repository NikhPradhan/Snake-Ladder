#include "CDice.h"
#include <random>
#include <iostream>
CDice::CDice(int count) 
{
	if (count <= 0)
		std::cerr << "Num of Dice count should be greater than 0\n";

	this->numOfDice = count;
}
int CDice::rollDice()
{
	return (rand() % (numOfDice * 6)) + 1;
}
void CDice::setNumOfDice(int count)
{
	this->numOfDice = count;
}