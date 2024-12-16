#include <components/audio_component.h>

AudioComponent::AudioComponent(int inputChannels, int outputChannels) {
	setAudioChannels(inputChannels, outputChannels);
}

AudioComponent::~AudioComponent() {
	shutdownAudio();
}

void AudioComponent::prepareToPlay(int samplesExpected, double sampleRate) {
	juce::ignoreUnused(samplesExpected, sampleRate);
}

void AudioComponent::releaseResources() {

}

void AudioComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo &info) {
	juce::ignoreUnused(info);
}
