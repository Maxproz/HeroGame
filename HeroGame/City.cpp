#include "City.h"

#include "Quest.h"
#include <iostream>
#include <string>
#include "Player.h"

std::string City::GetAvailableQuestDescription() const
{
	if (AvailableQuest)
		return AvailableQuest->GetQuestDescription();
	else
	{
		std::cout << "Available Quest is nullptr";
	}
}



void City::SetVisitingPlayer(Player* InPlayer)
{
	PlayerInCity = InPlayer;
}
