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




#include "Player.h"
#include "City.h"
#include "Quest.h"
#include "GameManager.h"


int main()
{

	// Initial Makings of a game manager class?
	GameManager::DisplayWelcomeMessage();
	std::string MainCharacterName = GameManager::GetMainCharacterNameFromUser();

	const unsigned int MainCharacterAge{ 14 }; // 14 for now for story reasons, maybe change later.

	// Create the Main Character 
	const unsigned int StartingCharacterDamage{ 1 };
	Player* MainCharacter = new Player(MainCharacterAge, MainCharacterName, StartingCharacterDamage); // Initial damage is 1 for now.

	GameManager::DisplayACharacterBasicInfo(MainCharacter);
	GameManager::DisplayGameIntroStory();

	// Create a starting quest for the player to take.
	Quest* ArgnoiaRatKillQuest = new Quest(Quest::QuestType::QT_SUBJUGATION, Quest::QuestStatus::QS_INACTIVE, "Kill 5 sewer rats");
	City* Argonia = new City(4, ArgnoiaRatKillQuest);
	// TODO: how is the quest supposed to know the player is in the sewers killing rats?
	MainCharacter->EnterCity(Argonia);


	// So far the player enters the city, has his current location updated to argonia main square, and a reference to the player is also added to the city
	// Right now argonia is created with a pre-built quest that is currently not being used.

	// Next I need to figure out how to flush the UI since all the tutorial stuff is done. (how will i  do it with a press any key to continue which flushes the UI)
	// Then I need some sort of strategy to program that will advance the game and also not be too confusing.




}

