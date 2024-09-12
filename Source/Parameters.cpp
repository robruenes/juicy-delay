#include "Parameters.h"

const juce::ParameterID gainParamID{"gain", 1};

using ParameterLayout = juce::AudioProcessorValueTreeState::ParameterLayout;
using juce::AudioParameterFloat;
using juce::AudioProcessorValueTreeState;

namespace {

AudioParameterFloat& TreeStateAndIDToFloatRef(
    AudioProcessorValueTreeState& apvts, juce::ParameterID id) {
  return *(
      dynamic_cast<AudioParameterFloat*>(apvts.getParameter(id.getParamID())));
}

}  // namespace

Parameters::Parameters(AudioProcessorValueTreeState& apvts)
    : gain_(0.0f), gainParam_(TreeStateAndIDToFloatRef(apvts, gainParamID)) {}

void Parameters::update() noexcept {
  gain_ = juce::Decibels::decibelsToGain(gainParam_.get());
}

float Parameters::getGain() {
  return gain_;
}

ParameterLayout Parameters::createParameterLayout() {
  ParameterLayout layout;
  layout.add(std::make_unique<AudioParameterFloat>(
      gainParamID, "Output Gain", juce::NormalisableRange<float>{-12.0f, 12.0f},
      /*default=*/0.0f));
  return layout;
}
