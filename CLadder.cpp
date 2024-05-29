#include "CLadder.h"
#include <iostream>

CLadder::CLadder(int startingPos, int endingPos)
{
	if (startingPos > endingPos)
	{
		std::cerr << "For Ladder starting position should be lesser than ending position.\n";
		this->m_startingPos = -1;
		this->m_endingPos = -1;
		return;
	}
	this->m_startingPos = startingPos;
	this->m_endingPos = endingPos;
}

void CLadder::setPosition(int startingPos, int endingPos)
{
	if (startingPos > endingPos)
	{
		std::cerr << "For Ladder starting position should be lesser than ending position.\n";
		return;
	}
	this->m_startingPos = startingPos;
	this->m_endingPos = endingPos;
}
int CLadder::getStartingPostion()
{
	return this->m_startingPos;
}
int CLadder::getEndingPosition()
{
	return this->m_endingPos;
}