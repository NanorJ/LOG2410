///////////////////////////////////////////////////////////
//  CompositeTransform.cpp
//  Implementation of the Class CompositeTransform
//  Created on:      13-mar.-2017
//  Original author: francois
///////////////////////////////////////////////////////////

#include "CompositeTransform.h"
#include "AbsAudioFile.h"
#include "ChunkIterator.h"


CompositeTransform::CompositeTransform(const CompositeTransform & mdd) {
//:AbsTransform(mdd)
	for (auto it=mdd.begin(); it!=mdd.end(); it++) {
		addChild(*it);
	}
}

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
	//CompositeTransform* compositeTransform = new CompositeTransform;
	// CompositeTransform = *compositeTransform;

	//for (auto i=0; m_transforms.size(1);i++)
		//compositeTransform->addChild(m_transforms.[i]->clone());

	return (new CompositeTransform(*this));
}

// Executer les transformations enfant
void CompositeTransform::transform(const Chunk_iterator& c, AbsAudioFile& outFile) const
{
	for (int i =0 ;i< m_transforms.size();i++)
		m_transforms[i].get()->transform(c, outFile);

}

void CompositeTransform::addChild(const AbsTransform& t)
{ 
//std::unique_ptr<AbsTransform> value = std::unique_ptr<AbsTransform>(t.clone());
	m_transforms.push_back((TransformPtr)t.clone());//changed the type
	
}

void CompositeTransform::removeChild(TransformIterator_const transfIt)
{
	//erase instead of pop
	m_transforms.erase(transfIt);
}
