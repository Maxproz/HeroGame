#pragma once



#include <iostream>
#include <string>
#include "Player.h"

class GameManager
{
	// class to control the UI changes when the player selects an option to go to a different area.
	// Maybe it will do other things too.

public:
	static void DisplayWelcomeMessage()
	{
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
		std::cout << "The story so far." << std::endl;
		std::cout << "Assassins ambush your family in the middle of the night." << std::endl;
		std::cout << "You were barely able to escape your familys estate and you made it to the nearby capital of Argonia after walking for a couple days." << std::endl;


		// TODO: How to flush UI after player reads this?
	}

};

