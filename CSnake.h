#pragma once
#include "IJumper.h"

class CSnake: public IJumper
{
private:
	int m_startingPos;
	int m_endPos;

public:
	CSnake(int startingPos, int endingPos);
	void setPosition(int startingPos, int endingPos);
	int getStartingPostion();
	int getEndingPosition();
};

