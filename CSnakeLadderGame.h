#pragma once
#include <queue>
#include <vector>
class CDice; 
class CPlayer;
class IJumper;
//This Class purpose has the main logic how game behaves
class CSnakeLadderGame
{
private:
	int	m_boardSize;
	int m_numOfPlayers;
	CDice *m_objDice;
	std::queue<CPlayer*> m_quePlayers;
	std::vector<IJumper*> m_vecSnakesNLadders;
	void InitializeGame();
	void DeinitGame();
public:
	CSnakeLadderGame();
	~CSnakeLadderGame();
	void StartGame();
};

