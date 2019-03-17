///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"

CompositeTransform::CompositeTransform(const CompositeTransform & mdd) :AbsTransform(mdd){}

// Cloner la transformation composite et ses commandes enfant
CompositeTransform * CompositeTransform::clone(void) const
{
	////creer un nouv objet 
	//CompositeTransform *compositeTransform;// = new CompositeTransform;
	////clonage avec le constructeur copie du nouveau objet
	//CompositeTransform CompositeTransform = *compositeTransform;//=*compositeTransform;
	////retour du nouveau objet
	////compositeTransform->m_transforms = CompositeTransform.m_transforms;
	//compositeTransform->m_transforms = CompositeTransform.m_transforms ;
	//return compositeTransform ;
	////return nullptr;
	CompositeTransform* compositeTransform = new CompositeTransform;
	// CompositeTransform = *compositeTransform;

	for (auto i=0; m_transforms.size();i++)
		compositeTransform->addChild(m_transforms.[i]->clone());

	return compositeTransform;
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	for (auto i =0 ;i< m_transforms.size();i++)
		m_transforms[i]->transform(c, outFile);

}

void CompositeTransform::addChild(const AbsTransform& t)
{ 
	//std::unique_ptr<AbsTransform> value = std::unique_ptr<AbsTransform>(t.clone());
	m_transforms.push_back(std::unique_ptr<AbsTransform>(t.clone()));
	
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	m_transforms.pop_back();
}
