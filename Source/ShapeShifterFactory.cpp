/*
  ==============================================================================

    ShapeShifterFactory.cpp
    Created: 18 May 2016 11:45:57am
    Author:  bkupe

  ==============================================================================
*/

#include "ShapeShifterFactory.h"

#include "Inspector.h"
#include "CustomLoggerUI.h"
#include "MainComponent.h"
#include "ModuleManagerUI.h"
#include "SequenceManagerUI.h"
#include "StateManagerUI.h"
#include "StateMachineView.h"
#include "TimeMachineView.h"
#include "Outliner.h"

ShapeShifterContent * ShapeShifterFactory::createContentForIndex(PanelName pn)
{
	String contentName = globalPanelNames[(int)pn];

	switch (pn)
	{
	case ModulesPanel:
		return new ModuleManagerUI(ModuleManager::getInstance());
		break;

	case StateMachinePanel:
		return new StateMachineView(StateManager::getInstance());
		break;

	case TimeMachinePanel:
		return new TimeMachineView(SequenceManager::getInstance());
		break;

	case StatesPanel:
		return new StateManagerUI(StateManager::getInstance());
		break;

	case SequencesPanel:
		return new SequenceManagerUI(SequenceManager::getInstance());
		break;


	case InspectorPanel:
		return new InspectorViewport(contentName, Inspector::getInstance());
		break;

	case LoggerPanel:
		return new CustomLoggerUI(contentName, CustomLogger::getInstance());
		break;

	case OutlinerPanel:
		return new Outliner("Outliner");


	default:
		DBG("Panel not handled : " << contentName << ", index in names = " << globalPanelNames.strings.indexOf(contentName));
	}
	return nullptr;
}

ShapeShifterContent * ShapeShifterFactory::createContentForName(String name)
{
	return createContentForIndex((PanelName)globalPanelNames.strings.indexOf(name));
}
