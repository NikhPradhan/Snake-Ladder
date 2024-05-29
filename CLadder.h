#pragma once
#include "IJumper.h"
class CLadder : public IJumper
{
private:
	int m_startingPos;
	int m_endingPos;

public:
	CLadder(int startingPos, int endingPos);
	void setPosition(int startingPos, int endingPos);
	int getStartingPostion();
	int getEndingPosition();

};

