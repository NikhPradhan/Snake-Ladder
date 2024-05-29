#pragma once
#include <iostream>


class CPlayer
{
private:
	int id;
	std::string name;
public:
	int m_currPos;

public:
	CPlayer(int inId = -1, std::string inName = "NULL");
	void setName(std::string &iName);
	std::string getName();
	void setID(int id);
	int getID();
	void setCurrPosition(int currPos);
	int getCurrPosition();
};

