#include "Parameters.h"

const juce::ParameterID gainParamID{"gain", 1};

using ParameterLayout = juce::AudioProcessorValueTreeState::ParameterLayout;

Parameters::Parameters(juce::AudioProcessorValueTreeState& apvts)
    : gainParam_(*(dynamic_cast<juce::AudioParameterFloat*>(
          apvts.getParameter(gainParamID.getParamID())))) {}

void Parameters::setGain(float gain) { gainParam_ = gain; }

float Parameters::getGain() { return gainParam_.get(); }

ParameterLayout Parameters::createParameterLayout() {
  ParameterLayout layout;
  layout.add(std::make_unique<juce::AudioParameterFloat>(
      gainParamID, "Output Gain", juce::NormalisableRange<float>{-12.0f, 12.0f},
      /*default=*/0.0f));
  return layout;
}
