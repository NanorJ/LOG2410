#include "ChecksumCommand.h"
#include "AbsAudioFile.h"

void ChecksumCommand::execute(AbsAudioFile & f)
{
	// Declencher l'execution de la commande
	f.accept(m_visitor);
	// A COMPLETER...
}
