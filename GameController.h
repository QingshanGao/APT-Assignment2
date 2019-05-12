
#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include <string>
#include "Player.h"
#include <vector>


class Game
{
private:
	//Print welcome message
	void PrintWelcome();
	//Print invalid message
	void PrintInvalid();
	//Prompt user to input
	std::string UserPrompt();
	//print menu
	int Menu();
	//start a new game with input player name
	void NewGame();
	//load file from director
	bool LoadGame();
	//vector to store player name
	std::vector<Player> m_players;
	//Show up author information
	void ShowStudentInfo();
	//print Goodbye and quit game
	void Quit();
public:
	Game();
	~Game();
	void Start();
};

#endif
