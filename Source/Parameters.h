#pragma once

#include <JuceHeader.h>

class Parameters {
 public:
  Parameters(juce::AudioProcessorValueTreeState& apvts);

  static juce::AudioProcessorValueTreeState::ParameterLayout
  createParameterLayout();

  void setGainInDb(float gainInDb);
  float getGainInDb();

 private:
  juce::AudioParameterFloat& gainParam_;
};
