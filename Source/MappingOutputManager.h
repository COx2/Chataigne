/*
  ==============================================================================

    MappingOutputManager.h
    Created: 28 Oct 2016 8:11:54pm
    Author:  bkupe

  ==============================================================================
*/

#ifndef MAPPINGOUTPUTMANAGER_H_INCLUDED
#define MAPPINGOUTPUTMANAGER_H_INCLUDED


#include "BaseManager.h"
#include "MappingOutput.h"

class MappingOutputManager :
	public BaseManager<MappingOutput>
{
public:
	MappingOutputManager();
	~MappingOutputManager();

	void setValue(var value);

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MappingOutputManager)

};




#endif  // MAPPINGOUTPUTMANAGER_H_INCLUDED
