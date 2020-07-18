#include "City.h"

#include "Quest.h"
#include <iostream>
#include <string>
#include "Player.h"

std::string Tavern::GetAvailableQuestDescription() const
{
	if (AvailableQuest)
		return AvailableQuest->GetQuestDescription();
	else
	{
		std::cout << "Available Quest is nullptr";
		throw std::exception("GetAvailableQuestDescription has a nullptr");
	}
}





void City::SetVisitingPlayer(Player* InPlayer)
{
	PlayerInCity = InPlayer;
}
