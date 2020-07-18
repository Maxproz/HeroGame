#include "Quest.h"




void SubjugationQuest::ProgressQuest()
{
	KillProgress = KillProgress + 1;
	UpdateQuest();
}

bool SubjugationQuest::UpdateQuest()
{
	if (KillProgress == KillsToComplete)
	{
		IsQuestComplete = true;
		return true;
	}
	else
	{
		return false;
	}
}
