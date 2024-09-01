#pragma once

#include <JuceHeader.h>

class Parameters {
 public:
  Parameters(juce::AudioProcessorValueTreeState& apvts);

  static juce::AudioProcessorValueTreeState::ParameterLayout
  createParameterLayout();

  void setGain(float gainInDb);
  float getGain();

 private:
  juce::AudioParameterFloat& gainParam_;
};
