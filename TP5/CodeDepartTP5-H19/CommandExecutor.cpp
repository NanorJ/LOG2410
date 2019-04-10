#include "CommandExecutor.h"

CommandExecutor & CommandExecutor::getInstance(void)
{
	static CommandExecutor m_instance;
	return m_instance;
}

void CommandExecutor::addCommand(const std::shared_ptr<AbsCommand>& c)
{
	// Ajouter la commande a la liste des commandes
	m_commandList.push_back(c);
	// A COMPLETER...
}

void CommandExecutor::executeAllCommands(AbsAudioFile& f)
{
	// Executer toutes les commandes dans la liste de commandes
	for (auto it = m_commandList.begin(); it != m_commandList.end(); it++)
		(it->get())->execute(f);
	// A COMPLETER...
}

void CommandExecutor::clearAllCommands(void)
{
	// Vider la liste des commandes
	m_commandList.clear();
	// A COMPLETER...
}
