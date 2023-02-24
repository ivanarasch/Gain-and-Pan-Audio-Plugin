/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicGainAudioProcessorEditor::BasicGainAudioProcessorEditor (BasicGainAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 400);
    
    mGainSlider.setRange(0.0f, 1.0f); //you want to go from 0 gain to 1 gain
    mGainSlider.setValue(1.0f); //setting initial value at unity gain
    
    addAndMakeVisible(&mGainSlider); // this passes the adress of our slider to this function
    mGainSlider.addListener(this);
    
    mPanSlider.setRange(0.0f,1.0f);
    mPanSlider.setValue(1.0f);
    
    addAndMakeVisible(&mPanSlider); // this passes the adress of our slider to this function
    mPanSlider.addListener(this);
}

BasicGainAudioProcessorEditor::~BasicGainAudioProcessorEditor()
{
    mGainSlider.removeListener(this); //'this' is a pointer it represents this instance of audio and it passed the ID number to this function
    mPanSlider.removeListener(this);
}



//==============================================================================
void BasicGainAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)//function definitions dont end w semicolon
{
    //get  the value of the slider and assign  the result to the processor's mGainSliderValue member variable
    audioProcessor.mGainSliderValue=mGainSlider.getValue();
    audioProcessor.mPanSliderValue=mPanSlider.getValue();
    
}


void BasicGainAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    g.fillAll(juce::Colours::hotpink);
    g.setColour (juce::Colours::blue);
    g.setFont (15.0f);
    g.drawFittedText ("Hola Mundo!", getLocalBounds(), juce::Justification::centred, 1);
}

void BasicGainAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mGainSlider.setBounds(50,50,300,50);
    mPanSlider.setBounds(25,25,200,25);
}
