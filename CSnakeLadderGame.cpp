#include "CSnakeLadderGame.h"
#include "CPlayer.h"
#include "CDice.h"
#include "CSnake.h"
#include "CLadder.h"

#define DEFAULT_BOARD_SIZE 100
CSnakeLadderGame::CSnakeLadderGame()
{
	m_boardSize = 0;
	m_numOfPlayers = 0;
	m_objDice = NULL;
}

CSnakeLadderGame::~CSnakeLadderGame()
{
	
}
void CSnakeLadderGame::DeinitGame()
{
	//Deinit Dice
	delete m_objDice;

	//Deinit Players
	while (!m_quePlayers.empty())
	{
		//Deleting all the dynamically allocated player object
		CPlayer* player = m_quePlayers.front();
		m_quePlayers.pop();
		delete player;
		player = NULL; //avoiding dangling pointer
	}

	//Deinit Snake and ladders
	for (IJumper* ptrJumper : m_vecSnakesNLadders)
	{
		delete ptrJumper;
		ptrJumper = NULL;//avoiding dangling pointer
	}
}
void CSnakeLadderGame::InitializeGame()
{
	//Initializing board
	if (m_boardSize == 0)
		m_boardSize = DEFAULT_BOARD_SIZE;

	//Initializing Dice
	int inputVal = 1;
	std::cout << "Enter number of dice:\n";
	std::cin>>inputVal;
	m_objDice = new CDice(inputVal);
	
	//Initializing Players
	inputVal = 1;
	std::cout << "Enter number of players:\n";
	std::cin >> inputVal;
	m_numOfPlayers = inputVal;
	for (int i = 0; i < m_numOfPlayers; i++)
	{
		std::string playerName;
		std::cout << "Enter Player" << i << " name:\n";
		std::cin >> playerName;
		CPlayer* player = new CPlayer(i + 1, playerName);
		m_quePlayers.push(player);
	}
	
	m_vecSnakesNLadders.push_back(new CSnake(30, 10));
	m_vecSnakesNLadders.push_back(new CSnake(40, 7));
	m_vecSnakesNLadders.push_back(new CSnake(50, 32));
	m_vecSnakesNLadders.push_back(new CSnake(98, 20));


	m_vecSnakesNLadders.push_back(new CLadder(3, 29));
	m_vecSnakesNLadders.push_back(new CLadder(42, 52));
	m_vecSnakesNLadders.push_back(new CLadder(33, 47));
	m_vecSnakesNLadders.push_back(new CLadder(21, 72));
	m_vecSnakesNLadders.push_back(new CLadder(53, 90));
	//Initializing Ladders
	//int numOfLadders = 3;
	//std::cout << "Enter number of Ladders:\n";
	//std::cin >> numOfLadders;
	/*
	for (int i = 0; i < numOfLadders; i++)
	{
		int bottomPos = 0;
		int topPos = 0;
		std::cout << "Enter ladder" << i << " bottom postion:\n";
		std::cin >> bottomPos;
		std::cout << "Enter ladder" << i << " top postion:\n";
		std::cin >> topPos;
		if (bottomPos >= topPos)
		{
			std::cerr << "Ladder top position should be greater than bottom position.\nEnter again\n";
			--i; // reseting the loop to renter postion for the same ladder 
			continue;
		}
		IJumper* ladder = new CLadder(bottomPos, topPos);
		m_vecSnakesNLadders.push_back(ladder);
	}
	*/

}

void CSnakeLadderGame::StartGame()
{
	InitializeGame();
	std::queue<CPlayer*> queWinners;
	while (m_quePlayers.size() > 1)
	{
		CPlayer* ptrCurPlayer = m_quePlayers.front();
		m_quePlayers.pop();
		int currPlayerPos = 0;
		if (m_objDice != NULL)
		{
			currPlayerPos = ptrCurPlayer->getCurrPosition();
			std::string playerName = ptrCurPlayer->getName();
			int diceVal = m_objDice->rollDice();
			std::cout <<"\n"<< playerName << " Current position: " << currPlayerPos << "\nRolled dice: " << diceVal << ".\n";
			currPlayerPos += diceVal;
			if (currPlayerPos == m_boardSize)
			{
				//Won the Game
				//Setting up to new position
				std::cout << playerName << " New postion: " << currPlayerPos << "\n\n";
				std::cout <<"\t"<< playerName << " Won\n\n";
				queWinners.push(ptrCurPlayer);
			}
			else if (currPlayerPos > m_boardSize)
			{
				//As the position will be beyond board size
				std::cout << "\t" << playerName << " Position will be greated than finish point, try again.\n\n";
				//putting players at the end of queue for its turn
				m_quePlayers.push(ptrCurPlayer);
			}
			else
			{
				//Setting up to new position
				ptrCurPlayer->setCurrPosition(currPlayerPos);
				std::cout << playerName << " New postion: " << ptrCurPlayer->getCurrPosition()<<"\n\n";
				for (IJumper* ptrIJumper : m_vecSnakesNLadders)
				{
					if (ptrIJumper == NULL)
					{
						continue;
					}
					
					if (ptrIJumper->getStartingPostion() == currPlayerPos)
					{
						if (ptrIJumper->getStartingPostion() > ptrIJumper->getEndingPosition())
						{
							//Snake
							currPlayerPos = ptrIJumper->getEndingPosition();
							ptrCurPlayer->setCurrPosition(currPlayerPos);
							std::cout << "\t" << playerName << " Bitten by snake,and moved to position: " << currPlayerPos << "\n\n";
						}
						else
						{
							//Ladder
							currPlayerPos = ptrIJumper->getEndingPosition();
							ptrCurPlayer->setCurrPosition(currPlayerPos);
							std::cout << "\t" << playerName << " Got Ladder,and moved to position: " << currPlayerPos << "\n\n";

						}
					}
					
				}
				//putting players at the end of queue for its turn
				m_quePlayers.push(ptrCurPlayer);
			}
		}
	}
	std::cout << "Winners are: \n";
	for (int i = 0; !queWinners.empty();i++)
	{
		CPlayer *ptr = queWinners.front();
		queWinners.pop();
		std::cout<<ptr->getName()<<" Won"<<i+1<<std::endl;
		delete ptr;
	}
	DeinitGame();
	
}