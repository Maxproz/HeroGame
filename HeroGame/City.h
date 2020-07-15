#pragma once


#include <vector>
class Quest;
class Player;

class City
{
private:
	unsigned int NumberOfPeople{ 0 };
	std::vector<Quest> AvailableQuests;
	std::vector<std::string> CityInfoPrompt;
	
	Player* PlayerInCity;
	bool IsPlayerInASubZone{ false };

protected:


public:
	City() = delete;

	City(unsigned int NumOfPeople, std::vector<Quest> QuestsForPlayers)
		: NumberOfPeople{ NumOfPeople }, AvailableQuests{ QuestsForPlayers }
	{

	}

	City(unsigned int NumOfPeople, std::vector<Quest> QuestsForPlayers, std::vector<std::string> CityInfo)
		: NumberOfPeople{ NumOfPeople }, AvailableQuests{ QuestsForPlayers }, CityInfoPrompt{ CityInfo }

	{

	}

	// TODO: how will I handle reading past an array of size 1 
	// TODO: how will I handle a null pointer
	std::string ReadAvailableQuestsDescription() const;
	void DisplayCityInfoPrompt() const;
	void TakeInputFromMainSquare();
	void SetVisitingPlayer(Player* InPlayer);
};

