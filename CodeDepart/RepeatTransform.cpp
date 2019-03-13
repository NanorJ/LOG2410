///////////////////////////////////////////////////////////
//  RepeatTransform.cpp
//  Implementation of the Class RepeatTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "RepeatTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

void RepeatTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
    //dupliquer des segments audio
	for (int i = 0; i < m_nRepetitions; i++) {
		//int size = outFile.getChunkSize;
		//int numberChunks = outFile.getNumberChunks;
		outFile.addChunk(c);
		//? is it enough????? 
	}
}

size_t RepeatTransform::getNRepetitions(void)
{
	return m_nRepetitions;
}

