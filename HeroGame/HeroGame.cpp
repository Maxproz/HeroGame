// HeroGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> // To read cin into std::string




class Weapon
{
private:
	unsigned int Damage{ 0 };
	std::string Name{ "" };
public:
	Weapon(unsigned int m_Damage, std::string m_Name)
		: Damage(m_Damage), Name(m_Name)
	{

	}

	virtual void WeaponSwing() = 0;
	std::string GetName() const { return Name; }
	unsigned int GetDamage() const { return Damage; }
};

class Axe : Weapon
{
private:

public:


};

//ew

#include <vector>

class Quest
{
public:
	enum class QuestStatus;
	enum class QuestType;
private:



	QuestType QuestObjective{ QuestType::QT_UNASSIGNED };
	QuestStatus QuestState{ QuestStatus::QS_INACTIVE };
	std::string QuestDescription{ "" };

public:
	Quest(QuestType CurrentQuestObjective, QuestStatus CurrentQuestState, std::string CurrentQuestDescription)
		: QuestObjective{ CurrentQuestObjective }, QuestState{ CurrentQuestState }, QuestDescription{ CurrentQuestDescription }
	{

	}
	// Is this quest assigned to a player?
	enum class QuestStatus
	{
		QS_ACTIVE,
		QS_INACTIVE,
		QS_COMPLETE,
		QS_ABANDONED,
	};

	enum class QuestType
	{
		QT_SUBJUGATION,
		QT_GATHERING,
		QT_ESCORT,
		QT_SPECIAL,
		QT_UNASSIGNED
	};

	std::string GetQuestDescription() const { return QuestDescription; }
	void ChangeQuestStatus(QuestStatus NewStatus) { QuestState = NewStatus; }
};

// Room for Axe, mace, classes etc that inherit from weapon and implement GetName as their class name.
// Seems kind of useless now, but later it might be useful for something.

#include <vector>

class Player
{
private:
	unsigned int Age{0};
	std::string Name{ "" };
	unsigned int Damage{ 0 };
	std::vector<Quest> ActiveQuests;

public:
	Player(unsigned int m_Age, std::string m_Name, unsigned int m_Damage)
		: Age{ m_Age }, Name{ m_Name }, Damage{ m_Damage }
	{

	}

	std::string GetName() const { return Name; }
	unsigned int GetAge() const { return Age; }
	unsigned int GetDamage() const { return Damage; }

	void AcceptQuest(Quest& AcceptedQuest)
	{
		AcceptedQuest.ChangeQuestStatus(Quest::QuestStatus::QS_ACTIVE);
		ActiveQuests.push_back(AcceptedQuest);
	}

	void ListActiveQuests() const
	{
		for (int i = 0; i < ActiveQuests.size(); ++i)
		{
			std::cout << ActiveQuests.begin()->GetQuestDescription();
		}
	}

};



class City
{
private:
	unsigned int NumberOfPeople{ 0 };
	std::vector<Quest> AvailableQuests;
public:
	City() = delete;

	City(unsigned int NumOfPeople, std::vector<Quest> QuestsForPlayers)
		: NumberOfPeople{ NumOfPeople }, AvailableQuests{ QuestsForPlayers }
	{

	}

	// TODO: how will I handle reading past an array of size 1 
	// TODO: how will I handle a null pointer
	std::string ReadAvailableQuestsDescription() const
	{ 
		return AvailableQuests.begin()->GetQuestDescription();
	}

};


//class GameManager
//{
//	// class to control the UI changes when the player selects an option to go to a different area.
//private:
//	enum class PlayerArea
//	{
//		PA_ARGONIA,
//		PA_ARGONIA_SEWERS,
//		PA_ARGONIA_QUEST_BOARD,
//		PA_ARGONIA_TAVERN
//	};
//
//	// Player starts in the argonia city center
//	PlayerArea PlayerCurrentArea{ PlayerArea::PA_ARGONIA }; 
//public:
//
//};

int main()
{

	// Initial Makings of a game manager class?
	// Welcome Message
	std::cout << "Placeholder welcome message" << std::endl;


	std::cout << "Enter a name for your character." << std::endl;

	std::string MainCharacterName{ "" };
	std::cin >> MainCharacterName;

	//std::cout << "Enter an Age for your character." << std::endl;
	unsigned int MainCharacterAge{ 14 };
	//std::cin >> MainCharacterAge;

	// Create the Main Character 
	unsigned int StartingCharacterDamage{ 1 };
	Player MainCharacter(MainCharacterAge, MainCharacterName, StartingCharacterDamage); // Initial damage is 1 for now.


	std::cout << "Your name is " << MainCharacter.GetName() << " your age is " << MainCharacter.GetAge() << " your starting damage is " << MainCharacter.GetDamage();


	std::cout << "The story so far." << std::endl;
	std::cout << "Assassins ambush your family in the middle of the night." << std::endl;
	std::cout << "You were barely able to escape your familys estate and you made it to the nearby capital of Argonia after walking for a couple days." << std::endl;

	Quest ArgnoiaRatKillQuest(Quest::QuestType::QT_SUBJUGATION, Quest::QuestStatus::QS_INACTIVE, "Kill 5 sewer rats");
	std::vector<Quest> ArgoniaQuests{ ArgnoiaRatKillQuest };
	City Argonia(4, ArgoniaQuests);

	// Argonia town center action prompt
	std::cout << "Press 1 To Travel to the Tavern" << std::endl;
	std::cout << "Press 2 to Travel to the Quest Board" << std::endl;
	std::cout << "Press 3 to Travel to the Sewers" << std::endl;
	std::cout << "Press 5 to leave the city." << std::endl;

	int PlayerCityAction{ 0 };
	std::cin >> PlayerCityAction;
	switch (PlayerCityAction)
	{
		case 1: 
		{


			break;
		}
		case 2:
		{
			std::cout << "Would you like to take a new quest?" << std::endl;
			std::cout << Argonia.ReadAvailableQuestsDescription() << std::endl;

			std::cout << "Would you like to take this quest?" << std::endl;
			std::cout << "Press 1 to accept the quest Press 2 to leave" << std::endl;
			int ShouldTakeQuest{ 0 };
			std::cin >> ShouldTakeQuest;
			switch (ShouldTakeQuest)
			{
				case 1: 
				{
					MainCharacter.AcceptQuest(*ArgoniaQuests.begin());
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


			break;
		}
		case 4:
		{
			// do nothing
			break;
		}
		case 5:
		{

			break;
		}
		break;              //execution of subsequent statements is terminated
	}


	// Argonia town center action prompt
	std::cout << "Press 1 To Travel to the Tavern" << std::endl;
	//std::cout << "Press 2 to Travel to the Quest Board" << std::endl;
	std::cout << "Press 3 to Travel to the Sewers" << std::endl;
	std::cout << "Press 5 to leave the city." << std::endl;


	//MainCharacter.ListActiveQuests();


}

