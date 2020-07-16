#pragma once


#include <vector>
class Quest;
class Player;

class City
{
private:
	unsigned int NumberOfPeople{ 0 };
	Quest* AvailableQuest{ nullptr };
	Player* PlayerInCity;
	bool IsPlayerInASubZone{ false };

protected:


public:
	City() = delete;


	// TODO: Make a constructor that takes no quests and assigns availablequest to nullptr and gives a no quest available to the player if they try to take one.
	City(unsigned int NumOfPeople, Quest* QuestForPlayers)
		: NumberOfPeople{ NumOfPeople }, AvailableQuest{ QuestForPlayers }
	{

	}



	void SetVisitingPlayer(Player* InPlayer);
	std::string GetAvailableQuestDescription() const;

};

