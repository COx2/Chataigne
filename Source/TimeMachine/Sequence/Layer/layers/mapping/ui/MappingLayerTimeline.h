/*
  ==============================================================================

    MappingLayerTimeline.h
    Created: 20 Nov 2016 3:08:35pm
    Author:  Ben Kuper

  ==============================================================================
*/

#ifndef MAPPINGLAYERTIMELINE_H_INCLUDED
#define MAPPINGLAYERTIMELINE_H_INCLUDED

#include "../../../ui/SequenceLayerTimeline.h"
#include "../MappingLayer.h"
#include "../timecolor/ui/TimeColorManagerUI.h"

class MappingLayerTimeline :
	public SequenceLayerTimeline
{
public:
	MappingLayerTimeline(MappingLayer * layer);
	~MappingLayerTimeline();

	MappingLayer * mappingLayer;

	OwnedArray<AutomationUI> automationsUI;
	ScopedPointer<TimeColorManagerUI> colorManagerUI;

	void setupUIForLayerMode();

	void updateContent() override;
	void resized() override;

	void controllableFeedbackUpdateInternal(Controllable * c) override;
	void inspectableSelectionChanged(Inspectable * i) override;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MappingLayerTimeline)

};


#endif  // MAPPINGLAYERTIMELINE_H_INCLUDED
