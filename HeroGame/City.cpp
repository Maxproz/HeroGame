#include "City.h"

#include "Quest.h"
#include <iostream>
#include <string>
#include "Player.h"

std::string City::ReadAvailableQuestsDescription() const
{
	return AvailableQuests.begin()->GetQuestDescription();


}

void City::DisplayCityInfoPrompt() const
{

	if (!CityInfoPrompt.empty())
	{
		for (int i = 0; i < CityInfoPrompt.size(); ++i)
		{
			std::cout << CityInfoPrompt[i] << std::endl;
		}
	}
	else
	{

	}

}


void City::TakeInputFromMainSquare()
{

	if (PlayerInCity->GetPlayerLocation() == Locations::ARGONIA_MAIN_SQUARE)
	{
		int PlayerCityAction{ 0 };
		std::cin >> PlayerCityAction;

		switch (PlayerCityAction)
		{
		case 1:
		{
			PlayerInCity->UpdatePlayerLocation(Locations::ARGONIA_TAVERN);
			IsPlayerInASubZone = true;


			break;
		}
		case 2:
		{
			PlayerInCity->UpdatePlayerLocation(Locations::ARGONIA_QUEST_BOARD);
			IsPlayerInASubZone = true;

			std::cout << "Would you like to take a new quest?" << std::endl;
			std::cout << ReadAvailableQuestsDescription() << std::endl;

			std::cout << "Would you like to take this quest?" << std::endl;
			std::cout << "Press 1 to accept the quest Press 2 to leave" << std::endl;
			int ShouldTakeQuest{ 0 };
			std::cin >> ShouldTakeQuest;
			switch (ShouldTakeQuest)
			{
				case 1:
				{
					PlayerInCity->AcceptQuest(*AvailableQuests.begin());
					break;
				}
				case 2:
				{

					break;
				}
			}

			break;
		}
		case 3:
		{
			PlayerInCity->UpdatePlayerLocation(Locations::ARGONIA_SEWERS);
			IsPlayerInASubZone = true;



			break;
		}
		case 4:
		{
			// do nothing
			break;
		}
		case 5:
		{
			PlayerInCity->UpdatePlayerLocation(Locations::ARGONIA_OUTSIDE_FOREST);
			IsPlayerInASubZone = false;

			// not sure if I  want to do this from here or call from the client 
			//ExitCity(PlayerInCity);


			break;
		}


		break;
		}
	}
	else // else if different city?
	{

	}




}

void City::SetVisitingPlayer(Player* InPlayer)
{
	PlayerInCity = InPlayer;
}
