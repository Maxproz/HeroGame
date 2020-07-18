#pragma once


#include <vector>
class Quest;
class Player;

class Tavern
{
private:
	bool IsPlayerVisiting{ false };
	Quest* AvailableQuest{ nullptr };
public:
	void PlayerEnters() { IsPlayerVisiting = true; }
	void PlayerExits() { IsPlayerVisiting = false; }
	bool IsPlayerVisitingHere() const { return IsPlayerVisiting; }
	std::string GetAvailableQuestDescription() const;
	Quest* GetQuest() const { return AvailableQuest; }

	Tavern(Quest* QuestForPlayers) : AvailableQuest{ QuestForPlayers }
	{

	}
};


class City
{
private:
	
	Player* PlayerInCity;
	Tavern CityTavern{ nullptr };

public:
	City() = delete;


	// TODO: Make a constructor that takes no quests and assigns availablequest to nullptr and gives a no quest available to the player if they try to take one.
	City(Quest* QuestForPlayers)
		: CityTavern{ QuestForPlayers }
	{

	}


	void SetVisitingPlayer(Player* InPlayer);
	bool IsPlayerInTavern() const { return CityTavern.IsPlayerVisitingHere(); }
	Tavern GetTavern() const { return CityTavern; }

};

