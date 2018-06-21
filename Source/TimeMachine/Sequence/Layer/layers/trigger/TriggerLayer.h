/*
  ==============================================================================

    TriggerLayer.h
    Created: 17 Nov 2016 7:59:54pm
    Author:  Ben Kuper

  ==============================================================================
*/

#ifndef TRIGGERLAYER_H_INCLUDED
#define TRIGGERLAYER_H_INCLUDED

#include "../../SequenceLayer.h"
#include "TimeTriggerManager.h"

class TriggerLayer :
	public SequenceLayer
{
public :
	TriggerLayer(Sequence * _sequence, var params = var());
	~TriggerLayer();

	TimeTriggerManager ttm;
	
	Trigger * lockAll;
	Trigger * unlockAll;

	virtual bool paste() override;

	virtual void onContainerTriggerTriggered(Trigger *) override;

	var getJSONData() override;
	void loadJSONDataInternal(var data) override;

	static TriggerLayer * create(Sequence * sequence, var params) { return new TriggerLayer(sequence, params); }
	virtual String getTypeString() const override { return "Trigger"; }


	virtual SequenceLayerPanel * getPanel() override;
	virtual SequenceLayerTimeline * getTimelineUI() override;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TriggerLayer)
};



#endif  // TRIGGERLAYER_H_INCLUDED
