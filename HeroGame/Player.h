#pragma once


#include <vector>
#include "Locations.h"

class Quest;
class City;

class Player
{
private:
	unsigned int Age{ 0 };
	std::string Name{ "" };
	unsigned int Damage{ 0 };
	std::vector<Quest> ActiveQuests;
	Locations PlayerLocation{ Locations::ARGONIA_MAIN_SQUARE }; // Player starts the game here

public:
	Player(unsigned int m_Age, std::string m_Name, unsigned int m_Damage)
		: Age{ m_Age }, Name{ m_Name }, Damage{ m_Damage }
	{

	}

	std::string GetName() const { return Name; }
	unsigned int GetAge() const { return Age; }
	unsigned int GetDamage() const { return Damage; }

	void AcceptQuest(Quest& AcceptedQuest);
	void ListActiveQuests() const;

	void UpdatePlayerLocation(const Locations& NewLocation);
	Locations GetPlayerLocation() const { return PlayerLocation; }

	void EnterCity(City* CityPlayerEnters);
	void ExitCity(City* CityPlayerLeaves);
};