#include <algorithm>

#include "FileStringFindReplace.h"
#include "ChunkIterator.h"
#include "MemAudioFile.h"

FileStringFindReplace::FileStringFindReplace(const std::vector<char>& sOrig, const std::vector<char> & sNew, const std::string & outFileName)
	: m_searchString(sOrig), m_replaceString(sNew), m_outFile(std::make_shared<MemAudioFile>(outFileName))
{
}

FileStringFindReplace::FileStringFindReplace(const std::vector<char>& sOrig, const std::vector<char> & sNew, const std::shared_ptr<AbsAudioFile>& outFile)
	: m_searchString(sOrig), m_replaceString(sNew), m_outFile(outFile)
{
}

FileStringFindReplace * FileStringFindReplace::clone(void)
{
	return new FileStringFindReplace(*this);
}

void FileStringFindReplace::visit(const AudioFile & f)
{
	// A COMPLETER:
	// Iterer sur chaque Chunk du fichier d'entree
	for (auto it = f.begin(); it != f.end(); it++) {
		//    - Construire un nouvel iterateur pointant a la fin du fichier de sortie
		Chunk_iterator endIt(*m_outFile,m_outFile->getNumberChunks());
	
		//    - Initialiser la memoire de l'iterateur avec le contenu du Chunk d'entree
		memcpy(endIt->get(),it->get(),endIt->size());
		//    - Remplacer les caracteres dans le Chunk de sortie avec findReplace

		findReplace(endIt->get(),endIt->get()+endIt->size());//marche pour les deux 
		//    - Ajouter le nouveau Chunk au fichier de sortie
		m_outFile->addChunk(endIt);
	}
	
}

void FileStringFindReplace::visit(const MemAudioFile & f)
{
	size_t chunkSize = f.getChunkSize();
	size_t nChunks = f.getNumberChunks();
	const char* buf = f.get() + f.getHeaderSize();
	// A COMPLETER:
	// Iterer sur chaque Chunk du fichier d'entree dans buf
	for (auto it = f.begin(); it != f.end(); it++) {


		//    - Construire un nouvel iterateur pointant a la fin du fichier de sortie
		//    - Initialiser la memoire de l'iterateur avec le contenu du Chunk d'entree
		Chunk_iterator endIt(*m_outFile, m_outFile->getNumberChunks());
		//    - Remplacer les caracteres dans le Chunk de sortie avec findReplace
		memcpy(endIt->get(), it->get(), endIt->size());
		findReplace(endIt->get(), endIt->get() + endIt->size());
		//    - Ajouter le nouveau Chunk au fichier de sortie
		m_outFile->addChunk(endIt);
		//    - Avancer dans buf
		buf = f.get();
	}
}

void FileStringFindReplace::findReplace(char * p_beg, char * p_end)
{
	auto it = std::search(p_beg, p_end, m_searchString.begin(), m_searchString.end());
	if (it != p_end)
	{
		for (size_t irepl = 0; irepl < m_replaceString.size(); ++irepl)
			*(it + irepl) = m_replaceString[irepl];
	}
}
