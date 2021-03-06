/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
// This is a handy slider subclass that controls an AudioProcessorParameter
// (may move this class into the library itself at some point in the future..)
//class JuceDemoPluginAudioProcessorEditor::ParameterSlider   : public Slider,
//                                                              private Timer
//{
//public:
//    ParameterSlider (AudioProcessorParameter& p)
//        : Slider (p.getName (256)), param (p)
//    {
//        setRange (0.0, 1.0, 0.0);
//        startTimerHz (30);
//        updateSliderPos();
//    }
//
//    void valueChanged() override
//    {
//        if (isMouseButtonDown())
//            param.setValueNotifyingHost ((float) Slider::getValue());
//        else
//            param.setValue ((float) Slider::getValue());
//    }
//
//    void timerCallback() override       { updateSliderPos(); }
//
//    void startedDragging() override     { param.beginChangeGesture(); }
//    void stoppedDragging() override     { param.endChangeGesture();   }
//
//    double getValueFromText (const String& text) override   { return param.getValueForText (text); }
//    String getTextFromValue (double value) override         { return param.getText ((float) value, 1024); }
//
//    void updateSliderPos()
//    {
//        const float newValue = param.getValue();
//
//        if (newValue != (float) Slider::getValue() && ! isMouseButtonDown())
//            Slider::setValue (newValue);
//    }
//
//    AudioProcessorParameter& param;
//
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ParameterSlider)
//};

//==============================================================================
JuceDemoPluginAudioProcessorEditor::JuceDemoPluginAudioProcessorEditor (JuceDemoPluginAudioProcessor& owner)
    : AudioProcessorEditor (owner),
    keyboardComponent (owner.keyboardState, MidiKeyboardComponent::horizontalKeyboard),
    //lastMidiInputIndex (0),
    assignCC(128),
    attackCC(128),
    decayCC(128),
    sustainCC(128),
    releaseCC(128),
    cutoffCC(128),
    QCC(128),
    vibratoRateCC(128),
    vibratoPhaseCC(128),
    vibratoStrengthCC(128),
    tremeloRateCC(128),
    tremeloPhaseCC(128),
    tremeloStrengthCC(128)
 //   midiCollector(owner.midiCollector)

//    modWheel(0),
//    learning(false)
{
    // add some sliders..
    // MIDI Inputs
//    addAndMakeVisible (midiInputListLabel);
//    midiInputListLabel.setText ("MIDI Input:", dontSendNotification);
//    midiInputListLabel.attachToComponent (&midiInputList, true);
//    
//    // menu listing all the available MIDI inputs
//    addAndMakeVisible (midiInputList);
//    midiInputList.setTextWhenNoChoicesAvailable ("No MIDI Inputs Enabled");
//    const StringArray midiInputs (MidiInput::getDevices());
//    midiInputList.addItemList (midiInputs, 1);
//    midiInputList.setSelectedId(0); // default
//    midiInputList.addListener (this);
    
    // by default we use the first MIDI input
//    setMidiInput(0);
    
//    audioDeviceManager.initialise(getProcessor().getTotalNumInputChannels(), getProcessor().getTotalNumOutputChannels(), nullptr, true, String(), nullptr);
    
 //   audioDeviceManager.addMidiInputCallback(String(), &owner.midiCollector);
//
//    audioDeviceManager
    
//    midiInput.
    // The MIDI keyboard
    addAndMakeVisible(keyboardComponent);
//    midiCollector = getProcessor().midiCollector;
    
    //Faust voice controls:
    
    //att, del (typo for decay), sus, rel
    addAndMakeVisible(attackSlider);
    attackSlider.setRange(0.01, 2, 0.001);
    attackSlider.setValue(0.1);
    attackSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    attackSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    attackSlider.addListener(this);
    
    addAndMakeVisible(decaySlider);
    decaySlider.setRange(0.01, 2, 0.001);
    decaySlider.setValue(0.1);
    decaySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    decaySlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    decaySlider.addListener(this);
    
    addAndMakeVisible(sustainSlider);
    sustainSlider.setRange(0, 100, 0.1);
    sustainSlider.setValue(75);
    sustainSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    sustainSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    sustainSlider.addListener(this);
    
    addAndMakeVisible(releaseSlider);
    releaseSlider.setRange(0, 4, 0.001);
    releaseSlider.setValue(0.2);
    releaseSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    releaseSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    releaseSlider.addListener(this);
    
    addAndMakeVisible(attackLabel);
    attackLabel.setText("Attack", dontSendNotification);
    attackLabel.attachToComponent(&attackSlider, true);
    
    addAndMakeVisible(decayLabel);
    decayLabel.setText("Decay", dontSendNotification);
    decayLabel.attachToComponent(&decaySlider, true);
    
    addAndMakeVisible(sustainLabel);
    sustainLabel.setText("Sustain", dontSendNotification);
    sustainLabel.attachToComponent(&sustainSlider, true);
    
    addAndMakeVisible(releaseLabel);
    releaseLabel.setText("Release", dontSendNotification);
    releaseLabel.attachToComponent(&releaseSlider, true);
    
    
    //Filter cutoff, Q
    addAndMakeVisible(cutoffSlider);
    cutoffSlider.setRange(1, 9, 0.001);
    cutoffSlider.setValue(9);
    cutoffSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    cutoffSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    cutoffSlider.addListener(this);
    
    addAndMakeVisible(cutoffLabel);
    cutoffLabel.setText("Cutoff", dontSendNotification);
    cutoffLabel.attachToComponent(&cutoffSlider, true);
    
    addAndMakeVisible(QSlider);
    QSlider.setRange(1, 20, 0.001);
    QSlider.setValue(7);
    QSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    QSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    QSlider.addListener(this);
    
    addAndMakeVisible(QLabel);
    QLabel.setText("Q", dontSendNotification);
    QLabel.attachToComponent(&QSlider, true);
    
    
    //vibrato: vibrate, vibstr, vibOn
    addAndMakeVisible(vibratoRateSlider);
    vibratoRateSlider.setRange(2, 12, 0.001);
    vibratoRateSlider.setValue(6);
    vibratoRateSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    vibratoRateSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    vibratoRateSlider.addListener(this);
    
    addAndMakeVisible(vibratoRateLabel);
    vibratoRateLabel.setText("Rate", dontSendNotification);
    vibratoRateLabel.attachToComponent(&vibratoRateSlider, true);
    
    addAndMakeVisible(vibratoPhaseSlider);
    vibratoPhaseSlider.setRange(0, 1, 0.0001);
    vibratoPhaseSlider.setValue(0);
    vibratoPhaseSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    vibratoPhaseSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    vibratoPhaseSlider.addListener(this);
    
    addAndMakeVisible(vibratoPhaseLabel);
    vibratoPhaseLabel.setText("Phase", dontSendNotification);
    vibratoPhaseLabel.attachToComponent(&vibratoPhaseSlider, true);
    
    addAndMakeVisible(vibratoStrengthSlider);
    vibratoStrengthSlider.setRange(0, 1, 0.001);
    vibratoStrengthSlider.setValue(0.5);
    vibratoStrengthSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoStrengthSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    vibratoStrengthSlider.addListener(this);
    
    addAndMakeVisible(vibratoStrengthLabel);
    vibratoStrengthLabel.setText("Strength", dontSendNotification);
    vibratoStrengthLabel.attachToComponent(&vibratoStrengthSlider, true);
    
    //Tremelo: tremrate, tremstr, tremOn
    addAndMakeVisible(tremeloRateSlider);
    tremeloRateSlider.setRange(2, 12, 0.001);
    tremeloRateSlider.setValue(6);
    tremeloRateSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    tremeloRateSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    tremeloRateSlider.addListener(this);
    
    addAndMakeVisible(tremeloRateLabel);
    tremeloRateLabel.setText("Rate", dontSendNotification);
    tremeloRateLabel.attachToComponent(&tremeloRateSlider, true);
    
    addAndMakeVisible(tremeloPhaseSlider);
    tremeloPhaseSlider.setRange(0, 1, 0.0001);
    tremeloPhaseSlider.setValue(0);
    tremeloPhaseSlider.setSliderStyle(juce::Slider::LinearHorizontal);
    tremeloPhaseSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    tremeloPhaseSlider.addListener(this);
    
    addAndMakeVisible(tremeloPhaseLabel);
    tremeloPhaseLabel.setText("Phase", dontSendNotification);
    tremeloPhaseLabel.attachToComponent(&tremeloPhaseSlider, true);
    
    
    
    addAndMakeVisible(tremeloStrengthSlider);
    tremeloStrengthSlider.setRange(0, 1, 0.001);
    tremeloStrengthSlider.setValue(0.5);
    tremeloStrengthSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    tremeloStrengthSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 0, 0);
    tremeloStrengthSlider.addListener(this);
    
    addAndMakeVisible(tremeloStrengthLabel);
    tremeloStrengthLabel.setText("Strength", dontSendNotification);
    tremeloStrengthLabel.attachToComponent(&tremeloStrengthSlider, true);
    
    addAndMakeVisible(vibratoOffButton);
    vibratoOffButton.setRadioGroupId(1);
    vibratoOffButton.setToggleState(true, dontSendNotification);
    vibratoOffButton.addListener(this);
    
    addAndMakeVisible(vibratoOffLabel);
    vibratoOffLabel.setText("Off", dontSendNotification);
    vibratoOffLabel.attachToComponent(&vibratoOffButton, true);
    
    addAndMakeVisible(vibratoLabel);
    vibratoLabel.setText("Vibrato", dontSendNotification);
    
    addAndMakeVisible(tremeloOffButton);
    tremeloOffButton.setRadioGroupId(2);
    tremeloOffButton.setToggleState(true, dontSendNotification);
    tremeloOffButton.addListener(this);
    
    addAndMakeVisible(tremeloOffLabel);
    tremeloOffLabel.setText("Off", dontSendNotification);
    tremeloOffLabel.attachToComponent(&tremeloOffButton, true);
    
    addAndMakeVisible(tremeloLabel);
    tremeloLabel.setText("Tremolo", dontSendNotification);
    
    addAndMakeVisible(vibratoOnButton);
    vibratoOnButton.setRadioGroupId(1);
    vibratoOnButton.addListener(this);
    
    addAndMakeVisible(vibratoOnLabel);
    vibratoOnLabel.setText("On", dontSendNotification);
    vibratoOnLabel.attachToComponent(&vibratoOnButton, true);
    
    addAndMakeVisible(tremeloOnButton);
    tremeloOnButton.setRadioGroupId(2);
    tremeloOnButton.addListener(this);
    
    addAndMakeVisible(tremeloOnLabel);
    tremeloOnLabel.setText("On", dontSendNotification);
    tremeloOnLabel.attachToComponent(&tremeloOnButton, true);
    
    
    addAndMakeVisible(vibratoMWOnButton);
    vibratoMWOnButton.setRadioGroupId(1);
    vibratoMWOnButton.addListener(this);
    
    addAndMakeVisible(vibratoMWOnLabel);
    vibratoMWOnLabel.setText("to CC1", dontSendNotification);
    vibratoMWOnLabel.attachToComponent(&vibratoMWOnButton, true);
    
    addAndMakeVisible(tremeloMWOnButton);
    tremeloMWOnButton.setRadioGroupId(2);
    tremeloMWOnButton.addListener(this);
    
    addAndMakeVisible(tremeloMWOnLabel);
    tremeloMWOnLabel.setText("to CC1", dontSendNotification);
    tremeloMWOnLabel.attachToComponent(&tremeloMWOnButton, true);
    
    addAndMakeVisible(learnButton);
    learnButton.addListener(this);
    
    addAndMakeVisible(learnButtonLabel);
    learnButtonLabel.setText("MIDI CC Learn", dontSendNotification);
    learnButtonLabel.attachToComponent(&learnButton, true);
    
    // set resize limits for this plug-in
    setResizeLimits (500, 400, 1000, 800);
    
    // set our component's initial size to be the last one that was stored in the filter's settings
    setSize (owner.lastUIWidth,
             owner.lastUIHeight);

    // start a timer which will keep our timecode display updated
//    startTimerHz (30);
}

JuceDemoPluginAudioProcessorEditor::~JuceDemoPluginAudioProcessorEditor()
{
}

//==============================================================================
void JuceDemoPluginAudioProcessorEditor::paint (Graphics& g)
{
    g.setGradientFill (ColourGradient (Colours::white, 0, 0,
                                       Colours::lightgrey, 0, (float) getHeight(), false));
    g.fillAll();
}

//void JuceDemoPluginAudioProcessorEditor::MidiInputCallback

void JuceDemoPluginAudioProcessorEditor::resized()
{
    // This lays out our child components...
//    midiInputList.setBounds(labelWidth, 0, getWidth() - labelWidth, 20);
    attackSlider.setBounds(labelWidth, 2*spacing, knobDiameter, knobDiameter);
    decaySlider.setBounds(labelWidth + (getWidth() - labelWidth-knobDiameter-spacing)/3, 2*spacing, knobDiameter, knobDiameter);
    sustainSlider.setBounds(labelWidth + 2*(getWidth() - labelWidth-knobDiameter-spacing)/3, 2*spacing, knobDiameter, knobDiameter);
    releaseSlider.setBounds(labelWidth + 3*(getWidth() - labelWidth-knobDiameter-spacing)/3, 2*spacing, knobDiameter, knobDiameter);
    cutoffSlider.setBounds(labelWidth, 3*spacing + knobDiameter, (getWidth() - labelWidth-knobDiameter-spacing-2*spacing),knobDiameter);
    QSlider.setBounds(labelWidth + 3*(getWidth() - labelWidth-knobDiameter-spacing)/3, 3*spacing + knobDiameter, knobDiameter, knobDiameter);
    vibratoLabel.setBounds(labelWidth + knobDiameter + spacing-35, 4*spacing + 2*knobDiameter-spacing-2, knobDiameter*2, knobDiameter-30);
    vibratoOffButton.setBounds(labelWidth, 4*spacing + 2*knobDiameter-spacing, knobDiameter, knobDiameter-30);
    vibratoOnButton.setBounds(labelWidth, 4*spacing + 2*knobDiameter+5, knobDiameter, knobDiameter-30);
    vibratoMWOnButton.setBounds(labelWidth, 4*spacing + 2*knobDiameter+spacing+10, knobDiameter, knobDiameter-30);
    vibratoRateSlider.setBounds(labelWidth + knobDiameter + spacing, 4*spacing + 2*knobDiameter+5, (getWidth() - labelWidth-knobDiameter-spacing-2*spacing)-2*knobDiameter, knobDiameter-30);
    vibratoPhaseSlider.setBounds(labelWidth + knobDiameter + spacing, 4*spacing + 2*knobDiameter+spacing+10, (getWidth() - labelWidth-knobDiameter-spacing-2*spacing)-2*knobDiameter, knobDiameter-30);
    vibratoStrengthSlider.setBounds(labelWidth + 3*(getWidth() - labelWidth-knobDiameter-spacing)/3, 4*spacing + 2*knobDiameter+2, knobDiameter, knobDiameter);
    tremeloLabel.setBounds(labelWidth + knobDiameter + spacing-35, 5*spacing + 3*knobDiameter-spacing, knobDiameter*2, knobDiameter-30);
    tremeloOffButton.setBounds(labelWidth, 5*spacing + 3*knobDiameter-spacing+2, knobDiameter, knobDiameter-30);
    tremeloOnButton.setBounds(labelWidth, 5*spacing + 3*knobDiameter+7, knobDiameter, knobDiameter-30);
    tremeloMWOnButton.setBounds(labelWidth, 5*spacing + 3*knobDiameter+spacing+12, knobDiameter, knobDiameter-30);
    tremeloRateSlider.setBounds(labelWidth + knobDiameter + spacing, 5*spacing + 3*knobDiameter+7, (getWidth() - labelWidth-knobDiameter-spacing-2*spacing)-2*knobDiameter, knobDiameter-30);
    tremeloPhaseSlider.setBounds(labelWidth + knobDiameter + spacing, 5*spacing + 3*knobDiameter+spacing+12, (getWidth() - labelWidth-knobDiameter-spacing-2*spacing)-2*knobDiameter, knobDiameter-30);
    tremeloStrengthSlider.setBounds(labelWidth + 3*(getWidth() - labelWidth-knobDiameter-spacing)/3, 5*spacing + 3*knobDiameter+4, knobDiameter, knobDiameter);
    learnButton.setBounds(labelWidth + knobDiameter + spacing, 6*spacing + 4*knobDiameter, knobDiameter, knobDiameter-30);
    keyboardComponent.setBounds (0, getHeight()-80, getWidth(), 80);

    
    
//    Rectangle<int> r (getLocalBounds().reduced (8));
//
//    timecodeDisplayLabel.setBounds (r.removeFromTop (26));
//    midiKeyboard.setBounds (r.removeFromBottom (70));
//
//    r.removeFromTop (30);
//    Rectangle<int> sliderArea (r.removeFromTop (50));
//    gainSlider->setBounds (sliderArea.removeFromLeft (jmin (180, sliderArea.getWidth() / 2)));
//    delaySlider->setBounds (sliderArea.removeFromLeft (jmin (180, sliderArea.getWidth())));

    getProcessor().lastUIWidth = getWidth();
    getProcessor().lastUIHeight = getHeight();
}

void JuceDemoPluginAudioProcessorEditor::sliderValueChanged (Slider* slider)  {
    int nVoices = getProcessor().synth.getNumVoices();
    if(slider == &attackSlider) {
        if(learning) {
//                            for(int i = 0; i < getProcessor().synth.getNumVoices(); ++i)
//                                getProcessor().synth.getVoice(i)->faustParameterChanged("attackCC",assignCC);
            getProcessor().attackCC = getProcessor().assignCC;
            DBG("Main attackCC = " <<attackCC);
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i){
                getProcessor().synth.getVoice(i)->faustParameterChanged("attack",attackSlider.getValue());
            
        }
       // }
    }
    if(slider == &decaySlider) {
        if(learning) {
            getProcessor().decayCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("decay",decaySlider.getValue());
//        if(learning) {
//            decayCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &sustainSlider) {
        if(learning) {
            getProcessor().sustainCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("sustain",sustainSlider.getValue());
//        if(learning) {
//            sustainCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &releaseSlider) {
        if(learning) {
            getProcessor().releaseCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("release",releaseSlider.getValue());
//        if(learning) {
//            releaseCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &cutoffSlider) {
        if(learning) {
            getProcessor().cutoffCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("cutoff",cutoffSlider.getValue());
//        if(learning) {
//            cutoffCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &QSlider) {
        if(learning) {
            getProcessor().QCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("Q",QSlider.getValue());
//        if(learning) {
//            QCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &vibratoRateSlider) {
        if(learning) {
            getProcessor().vibratoRateCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("vibRate",vibratoRateSlider.getValue());
//        if(learning) {
//            vibratoRateCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &vibratoStrengthSlider) {
        if(learning) {
            getProcessor().vibratoStrengthCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("vibStr",vibratoStrengthSlider.getValue());
//        if(learning) {
//            vibratoStrengthCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &vibratoPhaseSlider) {
        if(learning) {
            getProcessor().vibratoPhaseCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
            for(int i = 0; i < nVoices; ++i)
                getProcessor().synth.getVoice(i)->faustParameterChanged("vibPhase",vibratoPhaseSlider.getValue());
        //        if(learning) {
        //            vibratoStrengthCC = assignCC;
        //            learnButton.setToggleState(false, dontSendNotification);
        //        }
    }
    if(slider == &tremeloRateSlider) {
        if(learning) {
            getProcessor().tremeloRateCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("tremRate",tremeloRateSlider.getValue());
//        if(learning) {
//            tremeloRateCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &tremeloStrengthSlider) {
        if(learning) {
            getProcessor().tremeloStrengthCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
        for(int i = 0; i < nVoices; ++i)
            getProcessor().synth.getVoice(i)->faustParameterChanged("tremStr",tremeloStrengthSlider.getValue());
//        if(learning) {
//            tremeloStrengthCC = assignCC;
//            learnButton.setToggleState(false, dontSendNotification);
//        }
    }
    if(slider == &tremeloPhaseSlider) {
        if(learning) {
            getProcessor().tremeloPhaseCC = getProcessor().assignCC;
            learnButton.setToggleState(false, sendNotification);
        } else
            for(int i = 0; i < nVoices; ++i)
                getProcessor().synth.getVoice(i)->faustParameterChanged("tremPhase",tremeloPhaseSlider.getValue());
        //        if(learning) {
        //            tremeloStrengthCC = assignCC;
        //            learnButton.setToggleState(false, dontSendNotification);
        //        }
    }
}


void JuceDemoPluginAudioProcessorEditor::buttonClicked (Button* button) {
    int nVoices = getProcessor().synth.getNumVoices();
    if(button == &learnButton) {
        learning = (int)learnButton.getToggleState();
        DBG("Learning = " << learning);
        getProcessor().learning = learning;
//        for(int i = 0; i < getProcessor().synth.getNumVoices(); ++i) {
//            getProcessor().synth.getVoice(i)->faustParameterChanged("midiLearn", (int) learning);
//        }
        assignCC = 128;
    }
    if(button == &tremeloOnButton) {
        for(int i = 0; i < nVoices; ++i) {
            getProcessor().synth.getVoice(i)->faustParameterChanged("tremOn", 1);
            getProcessor().synth.getVoice(i)->faustParameterChanged("tremMWOn", (float) tremeloMWOnButton.getToggleState());
        }
    }
    if(button == &vibratoOnButton) {
        for(int i = 0; i < nVoices; ++i) {
            getProcessor().synth.getVoice(i)->faustParameterChanged("vibOn", 1);
            getProcessor().synth.getVoice(i)->faustParameterChanged("vibMWOn", (float) vibratoMWOnButton.getToggleState());
        }
    }
    if(button == &tremeloOffButton) {
        for(int i = 0; i < nVoices; ++i) {
            getProcessor().synth.getVoice(i)->faustParameterChanged("tremOn", 0);
            getProcessor().synth.getVoice(i)->faustParameterChanged("tremMWOn", (float) tremeloMWOnButton.getToggleState());
        }
    }
    if(button == &vibratoOffButton) {
        for(int i = 0; i < nVoices; ++i) {
            getProcessor().synth.getVoice(i)->faustParameterChanged("vibOn", 0);
            getProcessor().synth.getVoice(i)->faustParameterChanged("vibMWOn", (float) vibratoMWOnButton.getToggleState());
        }
    }
    if(button == &tremeloMWOnButton) {
        for(int i = 0; i < nVoices; ++i) {
            getProcessor().synth.getVoice(i)->faustParameterChanged("tremMWOn", (float) tremeloMWOnButton.getToggleState());
            getProcessor().synth.getVoice(i)->faustParameterChanged("tremOn", 0);
        }
    }
    if(button == &vibratoMWOnButton) {
        for(int i = 0; i < nVoices; ++i) {
            getProcessor().synth.getVoice(i)->faustParameterChanged("vibMWOn", (float) vibratoMWOnButton.getToggleState());
            getProcessor().synth.getVoice(i)->faustParameterChanged("vibOn", 0);
        }
    }
    
}

//void MidiMessageCollector::handleIncomingMidiMessage(MidiInput* input, const MidiMessage& message) override {
//    handleIncomingMidiMessage(input, message);
//}

//void JuceDemoPluginAudioProcessorEditor:: handleIncomingMidiMessage (MidiInput*, const MidiMessage& message) {
//    DBG("Editor midiMessage handler called");
//    if(message.isController()){
//        int nVoices = getProcessor().synth.getNumVoices();
//        if(message.getControllerNumber() == 1) {
//            modWheel = message.getControllerValue()/127;
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("modWheel", modWheel);
//            }
//        }
//        if(message.getControllerNumber() > 1 && learnButton.getToggleState()) {
//            assignCC = message.getControllerNumber();
//            DBG("AssignCC = " << assignCC);
//            
//        }
//        if(message.getControllerNumber() == attackCC){
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("attack", (float)message.getControllerValue()/127*1.99+0.01);
//            }
//            //attackSlider.setValue((float)message.getControllerValue()/127*1.99+0.01, dontSendNotification);
//        }
//        if(message.getControllerNumber() == decayCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("decay", (float)message.getControllerValue()/127*1.99+0.01);
//            }
//        }
//        if(message.getControllerNumber() == sustainCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("sustain", (float)message.getControllerValue()/127*100);
//            }
//        }
//        if(message.getControllerNumber() == releaseCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("release", (float)message.getControllerValue()/127*3.999+0.001);
//            }
//        }
//        if(message.getControllerNumber() == cutoffCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("cutoff", (float)message.getControllerValue()/127*7980+20);
//            }
//        }
//        if(message.getControllerNumber() == QCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("Q", (float)message.getControllerValue()/127*19+1);
//            }
//        }
//        if(message.getControllerNumber() == vibratoRateCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("vibRate", (float)message.getControllerValue()/127*10+2);
//            }
//        }
//        if(message.getControllerNumber() == vibratoPhaseCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("vibPhase", (float)message.getControllerValue()/127);
//            }
//        }
//        if(message.getControllerNumber() == vibratoStrengthCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("vibStr", (float)message.getControllerValue()/127);
//            }
//        }
//        if(message.getControllerNumber() == tremeloRateCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("tremRate", (float)message.getControllerValue()/127*10+2);
//            }
//        }
//        if(message.getControllerNumber() == tremeloPhaseCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("tremPhase", (float)message.getControllerValue()/127);
//            }
//        }
//        if(message.getControllerNumber() == tremeloStrengthCC) {
//            for (int i = 0; i < nVoices; ++i) {
//                getProcessor().synth.getVoice(i)->faustParameterChanged("tremStr", (float)message.getControllerValue()/127);
//            }
//        }
//    }
//}


//==============================================================================
//void JuceDemoPluginAudioProcessorEditor::timerCallback()
//{
// //   updateTimecodeDisplay (getProcessor().lastPosInfo);
//}

//==============================================================================
// quick-and-dirty function to format a timecode string
static String timeToTimecodeString (double seconds)
{
    const int millisecs = roundToInt (seconds * 1000.0);
    const int absMillisecs = std::abs (millisecs);

    return String::formatted ("%02d:%02d:%02d.%03d",
                              millisecs / 360000,
                              (absMillisecs / 60000) % 60,
                              (absMillisecs / 1000) % 60,
                              absMillisecs % 1000);
}

// quick-and-dirty function to format a bars/beats string
static String quarterNotePositionToBarsBeatsString (double quarterNotes, int numerator, int denominator)
{
    if (numerator == 0 || denominator == 0)
        return "1|1|000";

    const int quarterNotesPerBar = (numerator * 4 / denominator);
    const double beats  = (fmod (quarterNotes, quarterNotesPerBar) / quarterNotesPerBar) * numerator;

    const int bar    = ((int) quarterNotes) / quarterNotesPerBar + 1;
    const int beat   = ((int) beats) + 1;
    const int ticks  = ((int) (fmod (beats, 1.0) * 960.0 + 0.5));

    return String::formatted ("%d|%d|%03d", bar, beat, ticks);
}

// Updates the text in our position label.
//void JuceDemoPluginAudioProcessorEditor::updateTimecodeDisplay (AudioPlayHead::CurrentPositionInfo pos)
//{
//    MemoryOutputStream displayText;
//
//    displayText << "[" << SystemStats::getJUCEVersion() << "]   "
//                << String (pos.bpm, 2) << " bpm, "
//                << pos.timeSigNumerator << '/' << pos.timeSigDenominator
//                << "  -  " << timeToTimecodeString (pos.timeInSeconds)
//                << "  -  " << quarterNotePositionToBarsBeatsString (pos.ppqPosition,
//                                                                    pos.timeSigNumerator,
//                                                                    pos.timeSigDenominator);
//
//    if (pos.isRecording)
//        displayText << "  (recording)";
//    else if (pos.isPlaying)
//        displayText << "  (playing)";
//
////    timecodeDisplayLabel.setText (displayText.toString(), dontSendNotification);
//}
