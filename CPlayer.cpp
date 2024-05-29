#include "CPlayer.h"
#include <string>

CPlayer::CPlayer(int inId, std::string inName)
{
	this->id = inId;
	this->name = inName;
	this->m_currPos = 0;
}
void CPlayer::setName(std::string& iName)
{
	this->name = iName;
}

std::string CPlayer::getName()
{
	return this->name;
}
void CPlayer::setID(int inId)
{
	this->id = inId;
}
int CPlayer::getID()
{
	return this->id;
}

void CPlayer::setCurrPosition(int currPos)
{
	this->m_currPos = currPos;
}
int CPlayer::getCurrPosition()
{
	return this->m_currPos;
}