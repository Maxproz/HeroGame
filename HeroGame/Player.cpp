#include "Player.h"

#include "Quest.h"

#include <iostream>
#include <string>
#include "City.h"

// for KeepexploringRandom generation
#include <cstdlib>
#include <ctime>

void Player::AcceptQuest(Quest* AcceptedQuest)
{
	AcceptedQuest->ChangeQuestStatus(true);
	ActiveQuest = AcceptedQuest;

}

void Player::ListActiveQuest() const
{

	if (ActiveQuest)
	{
		std::cout << ActiveQuest->GetQuestDescription();
	}
	else
	{
		std::cout << "Error: ActiveQuest is nullptr" << std::endl;
	}


}

void Player::UpdatePlayerLocation(const Locations& NewLocation)
{
	PlayerLocation = NewLocation;
}


void Player::EnterCity(City* CityPlayerEnters)
{
	UpdatePlayerLocation(Locations::ARGONIA_MAIN_SQUARE);
	CityPlayerEnters->SetVisitingPlayer(this);
}

void Player::ExitCity(City* CityPlayerLeaves)
{
	UpdatePlayerLocation(Locations::OUTSIDE_ARGONIA_FOREST);
	CityPlayerLeaves->SetVisitingPlayer(nullptr);
}

void Player::EnterTavern(Tavern* InTavern)
{
	TavernWeAreVisiting = InTavern;
	InTavern->PlayerEnters();
	UpdatePlayerLocation(Locations::ARGONIA_TAVERN);
}

void Player::ExitTavern(Tavern* OutTavern)
{
	TavernWeAreVisiting = nullptr;
	OutTavern->PlayerExits();
	UpdatePlayerLocation(Locations::ARGONIA_MAIN_SQUARE);
}

void Player::EnterSewers(Sewers* InSewers)
{
	SewersWeAreVisiting = InSewers;
	InSewers->PlayerEnters();
	UpdatePlayerLocation(Locations::ARGONIA_SEWERS);
}

void Player::ExitSewers(Sewers* OutSewers)
{
	SewersWeAreVisiting = nullptr;
	OutSewers->PlayerExits();
	UpdatePlayerLocation(Locations::ARGONIA_MAIN_SQUARE);
}

Tavern* Player::GetTavernWeAreIn()
{
	if (TavernWeAreVisiting)
	{
		return TavernWeAreVisiting;
	}
	else
	{
		throw std::exception("nullptr inside GetTavernWeAreIn()");
	}
}

Sewers* Player::GetSewersWeAreIn()
{
	if (SewersWeAreVisiting)
	{
		return SewersWeAreVisiting;
	}
	else
	{
		throw std::exception("nullptr inside GetSewersWeAreIn()");
	}
}

ExplorationResult Player::KeepExploringSewers()
{
	srand((unsigned)time(0));
	int RandomNumber;
	RandomNumber = (rand() % 10) + 1;

	if (RandomNumber > 5)
	{
		// Monster appears, need to fight
		return ExplorationResult::ER_MONSTER;
	}
	else if (RandomNumber <= 5)
	{
		// you fight nothing
		return ExplorationResult::ER_NOTHING;
	}
	else
	{
		// treasure chest code for later in case I need to split 3 way rand
		
	}

}




