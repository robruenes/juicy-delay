#include "Parameters.h"

const juce::ParameterID gainParamID{"gain", 1};

using ParameterLayout = juce::AudioProcessorValueTreeState::ParameterLayout;
using juce::AudioParameterFloat;
using juce::AudioProcessorValueTreeState;
using juce::Decibels;

namespace {

template <typename T>
static T& getParamRef(AudioProcessorValueTreeState& apvts,
                      juce::ParameterID id) {
  return *(dynamic_cast<T*>(apvts.getParameter(id.getParamID())));
}

}  // namespace

Parameters::Parameters(AudioProcessorValueTreeState& apvts)
    : gain_(0.0f),
      gainParam_(getParamRef<AudioParameterFloat>(apvts, gainParamID)) {}

void Parameters::prepareToPlay(double sampleRate) noexcept {
  gainSmoother_.reset(sampleRate, /*rampLengthInSeconds=*/0.02);
}

void Parameters::update() noexcept {
  gainSmoother_.setTargetValue(Decibels::decibelsToGain(gainParam_.get()));
}

void Parameters::reset() noexcept {
  gain_ = 0.0f;
  gainSmoother_.setCurrentAndTargetValue(
      Decibels::decibelsToGain(gainParam_.get()));
}

void Parameters::smoothen() noexcept { gain_ = gainSmoother_.getNextValue(); }

float Parameters::getGain() { return gain_; }

ParameterLayout Parameters::createParameterLayout() {
  ParameterLayout layout;
  layout.add(std::make_unique<AudioParameterFloat>(
      gainParamID, "Output Gain", juce::NormalisableRange<float>{-12.0f, 12.0f},
      /*default=*/0.0f));
  return layout;
}
