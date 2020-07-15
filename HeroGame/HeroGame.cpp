// HeroGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> // To read cin into std::string




class Weapon
{
private:
	unsigned int Damage{ 0 };
	std::string Name{ "" };
public:
	Weapon(unsigned int m_Damage, std::string m_Name)
		: Damage(m_Damage), Name(m_Name)
	{

	}

	virtual void WeaponSwing() = 0;
	std::string GetName() const { return Name; }
	unsigned int GetDamage() const { return Damage; }
};

//class Axe : Weapon
//{
//private:
//
//public:
//
//
//};

//ew



// Room for Axe, mace, classes etc that inherit from weapon and implement GetName as their class name.
// Seems kind of useless now, but later it might be useful for something.

#include <vector>



//class GameManager
//{
//	// class to control the UI changes when the player selects an option to go to a different area.
//private:
//	enum class PlayerArea
//	{
//		PA_ARGONIA,
//		PA_ARGONIA_SEWERS,
//		PA_ARGONIA_QUEST_BOARD,
//		PA_ARGONIA_TAVERN
//	};
//
//	// Player starts in the argonia city center
//	PlayerArea PlayerCurrentArea{ PlayerArea::PA_ARGONIA }; 
//public:
//
//};

#include "Player.h"
#include "City.h"
#include "Quest.h"

int main()
{

	// Initial Makings of a game manager class?
	// Welcome Message
	std::cout << "Placeholder welcome message" << std::endl;


	std::cout << "Enter a name for your character." << std::endl;

	std::string MainCharacterName{ "" };
	std::cin >> MainCharacterName;

	//std::cout << "Enter an Age for your character." << std::endl;
	unsigned int MainCharacterAge{ 14 };
	//std::cin >> MainCharacterAge;

	// Create the Main Character 
	unsigned int StartingCharacterDamage{ 1 };
	Player MainCharacter(MainCharacterAge, MainCharacterName, StartingCharacterDamage); // Initial damage is 1 for now.


	std::cout << "Your name is " << MainCharacter.GetName() << " your age is " << MainCharacter.GetAge() << " your starting damage is " << MainCharacter.GetDamage();


	std::cout << "The story so far." << std::endl;
	std::cout << "Assassins ambush your family in the middle of the night." << std::endl;
	std::cout << "You were barely able to escape your familys estate and you made it to the nearby capital of Argonia after walking for a couple days." << std::endl;

	Quest ArgnoiaRatKillQuest(Quest::QuestType::QT_SUBJUGATION, Quest::QuestStatus::QS_INACTIVE, "Kill 5 sewer rats");
	std::vector<Quest> ArgoniaQuests{ ArgnoiaRatKillQuest };
	std::vector<std::string> ArgoniaInfo{ "Press 1 To Travel to the Tavern", "Press 2 to Travel to the Quest Board", "Press 3 to Travel to the Sewers",  "Press 5 to leave the city." };

	City Argonia(4, ArgoniaQuests, ArgoniaInfo);
	MainCharacter.EnterCity(&Argonia);

	Argonia.DisplayCityInfoPrompt();
	Argonia.TakeInputFromMainSquare();

	std::cout << "You have accepted the quest, Press 2 to go back to the previous menu" << std::endl; // TODO maybe: or press 1 to get another quest?

	// TODO: Learn how to flush/clear the console so its less confusing about whats going on.

	// We need a way to get players off of a sub menu if they are on one and back into the main square.
	int PlayerInput{ 0 };
	std::cin >> PlayerInput;
	if (PlayerInput == 1)
	{
		// do nothing for now

	}
	else if (PlayerInput == 2)
	{
		MainCharacter.UpdatePlayerLocation(Locations::ARGONIA_MAIN_SQUARE);

	}

	Argonia.TakeInputFromMainSquare();


	// hmmm is this how I want to do this? its pretty constricted.


}

