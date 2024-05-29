
#include "CSnake.h"
#include <iostream>

CSnake::CSnake(int startingPos, int endingPos)
{
	if (startingPos < endingPos)
	{
		std::cerr << "For snake starting position should be greater than ending position \n";
		this->m_startingPos = -1;
		this->m_endPos = -1;
		return;
	}
	this->m_startingPos = startingPos;
	this->m_endPos = endingPos;
}

void CSnake::setPosition(int startingPos, int endingPos)
{
	if (startingPos < endingPos)
	{
		std::cerr << "For snake starting position should be greater than ending position \n";
		return;
	}
	this->m_startingPos = startingPos;
	this->m_endPos = endingPos;
}
int CSnake::getStartingPostion()
{
	return this->m_startingPos;
}
int CSnake::getEndingPosition()
{
	return this->m_endPos;
}