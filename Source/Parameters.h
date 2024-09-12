#pragma once

#include <JuceHeader.h>

class Parameters {
 public:
  Parameters(juce::AudioProcessorValueTreeState& apvts);

  static juce::AudioProcessorValueTreeState::ParameterLayout
  createParameterLayout();

  void prepareToPlay(double sampleRate) noexcept;
  void update() noexcept;
  void reset() noexcept;
  void smoothen() noexcept;

  float getGain();

 private:
  float gain_;
  juce::AudioParameterFloat& gainParam_;
  juce::LinearSmoothedValue<float> gainSmoother_;
};
