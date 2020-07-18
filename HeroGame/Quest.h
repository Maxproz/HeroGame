
#pragma once


#include <vector>

class Quest
{
public:
	enum class QuestType;
private:
	QuestType QuestObjective{ QuestType::QT_UNASSIGNED };

	bool IsQuestAssigned{ false };
	std::string QuestDescription{ "" };



public:
	Quest(const QuestType& CurrentQuestObjective, const bool& QuestStatus, const std::string& CurrentQuestDescription)
		: QuestObjective{ CurrentQuestObjective }, IsQuestAssigned{ QuestStatus }, QuestDescription{ CurrentQuestDescription }
	{

	}


	enum class QuestType
	{
		QT_SUBJUGATION,
		QT_GATHERING,
		QT_ESCORT,
		QT_SPECIAL,
		QT_UNASSIGNED
	};

	std::string GetQuestDescription() const { return QuestDescription; }
	void ChangeQuestStatus(const bool& IsAssigned) { IsQuestAssigned = IsAssigned; }


};

class SubjugationQuest : public Quest
{
private:
	unsigned int KillProgress{ 0 };
	unsigned int KillsToComplete{ 0 };
	bool IsQuestComplete{ false };
public:
	SubjugationQuest(const bool& QuestStatus, const std::string& CurrentQuestDescription,  const unsigned int& KillsToFinishQuest)
		: Quest{ QuestType::QT_SUBJUGATION, QuestStatus, CurrentQuestDescription }, KillsToComplete{ KillsToFinishQuest }
	{
		
	}

	void ProgressQuest();
	bool UpdateQuest();
	bool GetQuestCompletionStatus() const { return IsQuestComplete; } // for the tavern/quest guild to check quest status
};
