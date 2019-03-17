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
	char* tempChunk;
	tempChunk= c->get();//copie de notre chunk 
	
	//vecteur vide
	std::vector<char> temp;
	//resize notre temp 
	temp.resize(sizeChunk);

	//parcourir notre vecteur de chunk size
	for (int i = 0; i < sizeChunk; i++) {
		//inversion du chunk et remplir le temporaire
		temp[i] = tempChunk[sizeChunk - 1 - i];
	}
	//creation d'objet de chunk iterator (prend un audiofile et le size en paramètre)
	Chunk_iterator chunkIterator(outFile, outFile.getNumberChunks());
	//creation d'un chunk avec les données inversées du vecteur

	*chunkIterator = Chunk(temp.size(), temp.data());//c'est un get() de notre vecteur 
	//utilise chunk_iterator pour utiliser addchunk 
	//ajout du chunk dans le outfile
	outFile.addChunk(chunkIterator);
}
