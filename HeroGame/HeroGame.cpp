// HeroGame.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "Player.h"
#include "City.h"
#include "Quest.h"
#include "GameManager.h"


#include "plog/Log.h"


int main()
{
	plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger


	// Initial Makings of a game manager class?
	GameManager::DisplayWelcomeMessage();
	std::string MainCharacterName = GameManager::GetMainCharacterNameFromUser();

	const unsigned int MainCharacterAge{ 14 }; // 14 for now for story reasons, maybe change later.

	// Create the Main Character 
	const unsigned int StartingCharacterDamage{ 1 };
	Player* MainCharacter = new Player(MainCharacterAge, MainCharacterName, StartingCharacterDamage); // Initial damage is 1 for now.

	GameManager::DisplayACharacterBasicInfo(MainCharacter);
	GameManager::WaitForKeyPress(); // why do I have to do this twice.
	GameManager::WaitForKeyPress();
	GameManager::ClearConsole();

	GameManager::DisplayGameIntroStory();
	GameManager::WaitForKeyPress();
	GameManager::WaitForKeyPress();
	GameManager::ClearConsole();

	// Create a starting quest for the player to take.
	SubjugationQuest* ArgnoiaRatKillQuest = new SubjugationQuest(false, "Kill 5 sewer rats", 5);
	City* Argonia = new City(ArgnoiaRatKillQuest);
	// TODO: how is the quest supposed to know the player is in the sewers killing rats?
	MainCharacter->EnterCity(Argonia);


	// So far the player enters the city, has his current location updated to argonia main square, and a reference to the player is also added to the city
	// Right now argonia is created with a pre-built quest that is currently not being used.
	// Then I need some sort of strategy to program that will advance the game and also not be too confusing.

	// As of right now the player has a blank UI and is 'inside' of argonia (just entered)

	// TODO: Refactor this better
	std::cout << "Press 1 To enter the tavern." << std::endl;
	std::cout << "Press 2 To enter the sewers." << std::endl;
	std::cout << "Press 3 To leave the city." << std::endl;

	//GameManager::WaitForKeyPress();
	//GameManager::ClearConsole();

	// TODO: Refactor this better
	int PlayerAction{ 0 };
	std::cin >> PlayerAction;
	switch (PlayerAction)
	{
		case 1:
		{
			MainCharacter->EnterTavern(&(Argonia->GetTavern()));
			GameManager::UpdatePlayerNewLocationPrompt(MainCharacter);
			break;
		}
		case 2:
		{
			//MainCharacter->EnterSewers(&(Argonia->GetSewers()));
			GameManager::UpdatePlayerNewLocationPrompt(MainCharacter);
			break;
		}
		case 3:
		{
			//MainCharacter->LeaveCity(&(Argonia->LeaveCity()));
			GameManager::UpdatePlayerNewLocationPrompt(MainCharacter);
			break;
		}

		// When I Refactor this I can account for other options here
		break;
	}



}

