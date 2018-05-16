/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.
	4
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FirstPluginEverAudioProcessorEditor::FirstPluginEverAudioProcessorEditor (FirstPluginEverAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{	
	
    setSize (200, 400);
	gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
	gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);	
	gainSlider.setRange(-48.0, 0.0);
	gainSlider.setValue(-1.0);
	gainSlider.addListener(this);
	addAndMakeVisible(gainSlider);
}

FirstPluginEverAudioProcessorEditor::~FirstPluginEverAudioProcessorEditor()
{
}

//==============================================================================
void FirstPluginEverAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void FirstPluginEverAudioProcessorEditor::resized()
{
	gainSlider.setBounds(getLocalBounds());
}

void FirstPluginEverAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
	if (slider == &gainSlider) {
		processor.rawVolume = pow(10, gainSlider.getValue() / 20);
	}
}
