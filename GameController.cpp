#include "GameController.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Start()
{
	PrintWelcome();
	int select = Menu();
	while (select)
	{
		if (select == 1)
		{
			NewGame();
			select = 0;
		}
		else if (select == 2)
		{
			if (LoadGame())
			{
				select = 0;
			}
			else
			{
				select = Menu();
			}
		}
		else if (select == 3)
		{
			ShowStudentInfo();
			select = Menu();
		}
		else if (select == 4)
		{
			Quit();
			select = 0;
		}
	}
}



void Game::PrintWelcome()
{
	std::cout << "Welcome to Qwirkle!\n---------------------\n" << std::endl;
}


std::string Game::UserPrompt()
{
	std::cout << "> ";
	std::string str;
	std::getline(std::cin, str);
	std::cout << std::endl;
	return str;
}


void Game::PrintInvalid()
{
	std::cout << "Invalid Input" << std::endl;
}


int Game::Menu()
{
	std::cout << "Menu\n----\n1. New Game\n2. Load Game\n3. Show student information\n4. Quit\n" << std::endl;
	int select = 0;
	while (!select)
	{
		std::string num = UserPrompt();
		select = atoi(num.c_str());
		if (select < 1 || select>4)
		{
			PrintInvalid();
			select = 0;
		}
	}
	return select;
}


void Game::NewGame()
{
	std::cout << "Starting a New Game\n" << std::endl;
	for (int i = 0; i < 2; i++)
	{
		Player player; player.score = 0;
		bool legal = false;
		while (!legal)
		{
			legal = true;
			std::cout << "Enter a name for player " << i + 1 << " (uppercase characters only)" << std::endl;
			player.name = UserPrompt();
			if (player.name.empty()) legal = false;
			else
			{
				for (auto c : player.name)
				{
					if (c<'A' || c>'Z')
						legal = false;
				}
			}
			if (!legal) PrintInvalid();
		}
		m_players.push_back(player);
	}

	}



bool Game::LoadGame()
{
	std::cout << "Enter the filename from which load a game" << std::endl;
	std::string file = UserPrompt();

	file.erase(0, file.find_first_not_of(" "));
	file.erase(file.find_last_not_of(" ") + 1);
	std::ifstream is;
	is.open(file);
	if (!is)
	{
		std::cout << "Can not load the game!\n" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Qwirkle game successfully loaded\n" << std::endl;
		return true;
	}
}


void Game::ShowStudentInfo()
{
	struct Student
	{
		std::string m_name, m_studentID, m_email;
		Student(std::string Name, std::string StudentID, std::string Email) { m_name = Name; m_studentID = StudentID; m_email = Email; }
		void Print() { std::cout << "Name:" << m_name << "\nStudent ID:" << m_studentID << "\nEmail:" << m_email << std::endl; }
	};

	std::vector<Student> students;
	students.push_back(Student("Oscar", "3562697", "s3562697@student.rmit.edu.au"));
	students.push_back(Student("Jack", "3661033", "s3661033@student.rmit.edu.au"));
	students.push_back(Student("Cryil", "3579811", "s3579811@student.rmit.edu.au"));
	students.push_back(Student("Jason", "3566690", "s3566690@student.rmit.edu.au"));

	std::cout << "----------------------------------" << std::endl;
	for (size_t i = 0; i < students.size(); i++)
	{
		students[i].Print();
		if (i + 1 < students.size()) std::cout << std::endl;
	}
	std::cout << "----------------------------------\n" << std::endl;
}


void Game::Quit()
{
	std::cout << "Goodbye" << std::endl;
}
