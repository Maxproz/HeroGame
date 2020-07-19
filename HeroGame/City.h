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

class Sewers
{
private:
	bool IsPlayerVisiting{ false };
	int NumberOfGiantRats{ 5 };
	bool IsSewersCleared{ false };

public:
	void SetSewersCleared() { if (NumberOfGiantRats == 0) { IsSewersCleared = true; } }
	void AGiantRatIsKilled() { NumberOfGiantRats = NumberOfGiantRats - 1; }
	void PlayerEnters() { IsPlayerVisiting = true; }
	void PlayerExits() { IsPlayerVisiting = false; }
	bool IsPlayerVisitingHere() const { return IsPlayerVisiting; }

};

class City
{
private:
	
	Player* PlayerInCity;
	Tavern* CityTavern{ nullptr };
	Sewers* CitySewers{ nullptr };
public:
	City() = delete;


	// TODO: Make a constructor that takes no quests and assigns availablequest to nullptr and gives a no quest available to the player if they try to take one.
	City(Quest* QuestForPlayers)
		: CityTavern{ new Tavern{ QuestForPlayers } }
	{
		CitySewers = new Sewers();
	}


	void SetVisitingPlayer(Player* InPlayer);
	bool IsPlayerInTavern() const { return CityTavern->IsPlayerVisitingHere(); }
	Tavern* GetTavern() const { return CityTavern; }
	Sewers* GetSewers() const { return CitySewers; }
};

