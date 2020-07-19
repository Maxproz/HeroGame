#pragma once


#include <vector>
#include "Locations.h"

class Quest;
class City;
class Tavern;
class Sewers;


enum class ExplorationResult
{
	ER_NOTHING,
	ER_MONSTER,
	ER_CHEST
};

class Player
{
private:
	unsigned int Age{ 0 };
	std::string Name{ "" };
	unsigned int Damage{ 0 };
	Quest* ActiveQuest = nullptr;
	Locations PlayerLocation{ Locations::ARGONIA_MAIN_SQUARE }; // Player starts the game here
	Tavern* TavernWeAreVisiting{ nullptr };
	Sewers* SewersWeAreVisiting{ nullptr };

public:
	Player(unsigned int m_Age, std::string m_Name, unsigned int m_Damage)
		: Age{ m_Age }, Name{ m_Name }, Damage{ m_Damage }
	{

	}

	std::string GetName() const { return Name; }
	unsigned int GetAge() const { return Age; }
	unsigned int GetDamage() const { return Damage; }

	void AcceptQuest(Quest* AcceptedQuest);
	void ListActiveQuest() const;

	void UpdatePlayerLocation(const Locations& NewLocation);
	Locations GetPlayerLocation() const { return PlayerLocation; }

	void EnterCity(City* CityPlayerEnters);
	void ExitCity(City* CityPlayerLeaves);


	void EnterTavern(Tavern* InTavern);
	void ExitTavern(Tavern* OutTavern);

	void EnterSewers(Sewers* InSewers);
	void ExitSewers(Sewers* OutSewers);
	Tavern* GetTavernWeAreIn();
	Sewers* GetSewersWeAreIn();

	ExplorationResult KeepExploringSewers();

};