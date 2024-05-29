#pragma once
class CDice
{
private:
	int numOfDice;
public:
	CDice(int count);
	int rollDice();
	void setNumOfDice(int count);
};

