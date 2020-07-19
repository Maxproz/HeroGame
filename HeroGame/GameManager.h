#pragma once



#include <iostream>
#include <string>
#include "Player.h"
#include <limits> // for waitforkeypress func


#include "plog/Log.h"

#include "City.h"

class GameManager
{
	// class to control the UI changes when the player selects an option to go to a different area.
	// Maybe it will do other things too.

public:
	static void DisplayWelcomeMessage()
	{
		LOGD << "DisplayWelcomeMessage() called"; // LOGD is defined by the plog library
		// Welcome Message
		std::cout << "Placeholder welcome message" << std::endl;
	}

	static std::string GetMainCharacterNameFromUser()
	{
		std::cout << "Enter a name for your character." << std::endl;
		std::string MainCharacterName{ "" };
		std::cin >> MainCharacterName;
		return MainCharacterName;
	}

	static void DisplayACharacterBasicInfo(Player* InCharacter)
	{
		LOGD << "DisplayACharacterBasicInfo() called";
		if (InCharacter)
		{
			std::cout << "Your name is " << InCharacter->GetName() << " your age is " << InCharacter->GetAge() << " your starting damage is " << InCharacter->GetDamage() << std::endl;
		}
		else
		{
			std::cout << "InCharacter is nullptr" << std::endl;
		}
	}

	static void DisplayGameIntroStory()
	{
		LOGD << "DisplayGameIntroStory() called";

		std::cout << "The story so far." << std::endl;
		std::cout << "Assassins ambush your family in the middle of the night." << std::endl;
		std::cout << "You were barely able to escape your familys estate and you made it to the nearby capital of Argonia after walking for a couple days." << std::endl;


		
	}


	static void WaitForKeyPress()
	{
		LOGD << "WaitForKeyPress() called";

		std::cout << "Press ENTER to continue...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	

	static void ClearConsole()
	{
		LOGD << "ClearConsole() called";
#if defined _WIN32
		system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
#elif defined (__APPLE__)
		system("clear");
#endif
	}

	static void UpdatePlayerNewLocationPrompt(Player* MainPlayer)
	{
		switch (MainPlayer->GetPlayerLocation())
		{
			case Locations::ARGONIA_TAVERN:
			{
				std::cout << "Welcome to the argonia Tavern we currently have one quest" << std::endl;
				PrintQuestDetails(MainPlayer);

				std::cout << "Would you like to accept this quest?" << std::endl;
				std::cout << "Press 1 to accept the quest or 2 to leave the Tavern" << std::endl;

				int PlayerChoice = GetPlayerChoiceInput();

				const int AcceptQuest = 1;
				const int LeaveTavern = 2;
				if (PlayerChoice == AcceptQuest)
				{
					MainPlayer->AcceptQuest(MainPlayer->GetTavernWeAreIn()->GetQuest());
					
					std::cout << "You now have one quest to ";
					MainPlayer->ListActiveQuest();
					std::cout << std::endl;

					std::cout << "There is nothing else to do here for now, You decide to leave the tavern" << std::endl;
					MainPlayer->ExitTavern(MainPlayer->GetTavernWeAreIn());
				}
				else if (PlayerChoice == LeaveTavern)
				{
					MainPlayer->ExitTavern(MainPlayer->GetTavernWeAreIn());
					// the rest of the code is handling the rest of the updates for leaving. 
					// we should be back in the main square after this.
				}
				else
				{
					// code should never hit for now
				}

				break;

			}
			case Locations::ARGONIA_SEWERS:
			{
				
				std::cout << "You have entered the argonia sewers" << std::endl;
				
				std::cout << "Would you like to keep exploring?" << std::endl;
				std::cout << "Press 1 to keep exploring or 2 to leave the Sewers" << std::endl;

				int PlayerChoice = GetPlayerChoiceInput();

				const int KeepExploring = 1;
				const int LeaveSewers = 2;
				while (PlayerChoice == KeepExploring)
				{
					ExplorationResult Result = MainPlayer->KeepExploringSewers();
					if (Result == ExplorationResult::ER_MONSTER)
					{
						// need to fight
						std::cout << "You encountred a giant rat." << std::endl;

					}
					else if (Result == ExplorationResult::ER_NOTHING)
					{
						std::cout << "You explored for a while but didn't find anything" << std::endl;
					}
					else
					{
						//code doesnt reach here for now
					}

					std::cout << "Would you like to keep exploring?" << std::endl;
					std::cout << "Press 1 to keep exploring or 2 to leave the Sewers" << std::endl;
					PlayerChoice = GetPlayerChoiceInput();

				}

				break;
			}
			case Locations::OUTSIDE_ARGONIA_FOREST:
			{
				std::cout << "Placeholder code for leaving argonia and entering the forest outside of it" << std::endl;
				break;
			}

			// all other cases break
			break;
		}


		// TODO: Future locations prompts?
	}


	static void PrintQuestDetails(Player* MainPlayer)
	{
		std::cout << "The quest is "; 
		std::cout << MainPlayer->GetTavernWeAreIn()->GetAvailableQuestDescription() << std::endl;
	}

	static int GetPlayerChoiceInput()
	{
		int PlayerChoice{ 0 };
		std::cin >> PlayerChoice;
		return PlayerChoice;
	}
};

