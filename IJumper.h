#pragma once
class IJumper
{


public:
	virtual void setPosition(int startingPos, int endingPos) = 0;
	virtual int getStartingPostion() = 0;
	virtual int getEndingPosition() = 0;
};

