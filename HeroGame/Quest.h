
#pragma once


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
