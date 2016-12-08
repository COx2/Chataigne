/*
  ==============================================================================

    TriggerLayer.cpp
    Created: 17 Nov 2016 7:59:54pm
    Author:  Ben Kuper

  ==============================================================================
*/

#include "TriggerLayer.h"
#include "TriggerLayerPanel.h"
#include "TriggerLayerTimeline.h"

TriggerLayer::TriggerLayer() :
	SequenceLayer("New Trigger Layer")
  {
  }

  TriggerLayer::~TriggerLayer()
  {
  }

  void TriggerLayer::init()
  {
  }

  void TriggerLayer::loadJSONDataInternal(var data)
  {
  }

  SequenceLayerPanel * TriggerLayer::getPanel()
  {
	  return new TriggerLayerPanel(this);
  }

  SequenceLayerTimeline * TriggerLayer::getTimelineUI()
  {
	  return new TriggerLayerTimeline(this);
  }
