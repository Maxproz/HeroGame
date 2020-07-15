#include "Player.h"

#include "Quest.h"

#include <iostream>
#include <string>
#include "City.h"



void Player::AcceptQuest(Quest& AcceptedQuest)
{
	AcceptedQuest.ChangeQuestStatus(Quest::QuestStatus::QS_ACTIVE);
	ActiveQuests.push_back(AcceptedQuest);
}

void Player::ListActiveQuests() const
{
	for (int i = 0; i < ActiveQuests.size(); ++i)
	{
		std::cout << ActiveQuests.begin()->GetQuestDescription();
	}
}

void Player::UpdatePlayerLocation(const Locations& NewLocation)
{
	PlayerLocation = NewLocation;
}


void Player::EnterCity(City* CityPlayerEnters)
{
	CityPlayerEnters->SetVisitingPlayer(this);
}

void Player::ExitCity(City* CityPlayerLeaves)
{
	CityPlayerLeaves->SetVisitingPlayer(nullptr);
}
