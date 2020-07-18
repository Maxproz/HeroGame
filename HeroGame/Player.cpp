#include "Player.h"

#include "Quest.h"

#include <iostream>
#include <string>
#include "City.h"



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



