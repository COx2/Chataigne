/*
  ==============================================================================

    ScriptFilter.h
    Created: 21 Feb 2017 6:59:12pm
    Author:  Ben

  ==============================================================================
*/

#ifndef SCRIPTFILTER_H_INCLUDED
#define SCRIPTFILTER_H_INCLUDED

#include "../MappingFilter.h"

class ScriptFilter :
	public MappingFilter
{
public:
	ScriptFilter(var params);
	~ScriptFilter();

	static String scriptTemplate;
	Script script;

	void processInternal() override;

	var getJSONData() override;
	void loadJSONDataInternal(var data) override;

	static ScriptFilter * create(var params) { return new ScriptFilter(params); }
	virtual String getTypeString() const override { return "Script"; }

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ScriptFilter)
};



#endif  // SCRIPTFILTER_H_INCLUDED
