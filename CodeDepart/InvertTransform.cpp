///////////////////////////////////////////////////////////
//  InvertTransform.cpp
//  Implementation of the Class InvertTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "InvertTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"
#include <vector>

// Methode pour appliquer une transformation d'inversion à un Chunk
void InvertTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{ 
	//comme c'est un operateur constant ne px pas modifier --> faire une copie 
   	int sizeChunk = c->size();
	char* tmpChunk = c->get();//copie de notre chunk 
	
	//vecteur vide
	std::vector<AbsAudioFile> temp;

	temp.begin;
	temp.end;
	//swap();

	outFile.addChunk();
}
