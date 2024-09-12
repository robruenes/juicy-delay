#pragma once

#include <JuceHeader.h>

class Parameters {
 public:
  Parameters(juce::AudioProcessorValueTreeState& apvts);

  static juce::AudioProcessorValueTreeState::ParameterLayout
  createParameterLayout();

  void update() noexcept;

  float getGain();

 private:
  float gain_;
  juce::AudioParameterFloat& gainParam_;
};
