#pragma once

#include <juce_audio_utils/juce_audio_utils.h>

class AudioComponent : public juce::AudioAppComponent {
public:
	AudioComponent(int inputChannels=2, int outputChannels=0);
	~AudioComponent();

	void prepareToPlay(int samplesExpected, double sampleRate) override;
	void releaseResources() override;
	void getNextAudioBlock(const juce::AudioSourceChannelInfo &info) override;

private:
	//juce::ReaderSource reader_source;

};
