// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.

#ifndef NOVELRT_AUDIOSERVICE_H
#define NOVELRT_AUDIOSERVICE_H

#ifndef NOVELRT_H
#error Please do not include this directly. Use the centralised header (NovelRT.h) instead!
#endif

//TODO: This won't exist after Kenny's rewrite, not too bothered about this class.
namespace NovelRT::Audio {
  class AudioService {
  private:
    const int _bufferSize = 2048;
    const int _noBuffer = 0;
    const ALfloat _pitch = 1.0f;
    
    LoggingService _logger;
    ALint _musicLoopAmount;
    ALuint _musicSource;
    ALint _musicSourceState;
    ALint _soundLoopAmount;
    ALuint _soundSource;
    ALint _soundSourceState;
    SoundBank _sounds;
    MusicBank _music;
    std::string _deviceName;
    Utilities::Lazy<std::unique_ptr<ALCdevice, void(*)(ALCdevice*)>> _device;
    Utilities::Lazy<std::unique_ptr<ALCcontext, void(*)(ALCcontext*)>> _context;

    ALuint readFile(std::string input);
    std::string getALError();

  public:
    bool isInitialised;

    AudioService();
    ~AudioService();

    bool initializeAudio();
    std::vector<ALuint>::iterator load(std::string input, bool isMusic);
    void unload(ALuint handle, bool isMusic);
    void playSound(std::vector<ALuint>::iterator handle, int loops);
    void stopSound();
    void setSoundVolume(float val);
    void setSoundPosition(float posX, float posY);
    void resumeMusic();
    void playMusic(std::vector<ALuint>::iterator handle, int loops);
    void pauseMusic();
    void stopMusic();
    void setMusicVolume(float value);
    void checkSources();
  };
}

#endif
