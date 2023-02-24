/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h> //This gives definition of class
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BasicGainAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    BasicGainAudioProcessorEditor (BasicGainAudioProcessor&);
    ~BasicGainAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BasicGainAudioProcessor& audioProcessor;
    
    juce::Slider mGainSlider;
    juce::Slider mPanSlider;
    
    void sliderValueChanged(juce::Slider*slider) override;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicGainAudioProcessorEditor)
};
