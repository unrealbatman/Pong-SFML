#include "../../header/Sound/SoundService.h"
#include <iostream>

namespace Sound
{
    sf::Music SoundService::backgroundMusic;
    sf::SoundBuffer SoundService::bufferButtonClick;
    sf::SoundBuffer SoundService::bufferFlagSound;
    sf::SoundBuffer SoundService::bufferExplosion;
    sf::SoundBuffer SoundService::bufferGameWon;
    sf::Sound SoundService::soundEffect;
    float SoundService::backgroundMusicVolume = 50.0f; // Default volume

    void SoundService::Initialize()
    {
        // Update the paths based on the directory structure
        LoadBackgroundMusicFromFile("assets/sounds/background_music.mp3");
        LoadSoundFromFile("assets/sounds/button_click_sound.wav",
            "assets/sounds/flag_sound.wav",
            "assets/sounds/explosion_sound.wav",
            "assets/sounds/game_won_sound.wav");
    }

    void SoundService::LoadBackgroundMusicFromFile(const std::string& path)
    {
        if (!backgroundMusic.openFromFile(path))
            std::cerr << "Error loading background music file: " << path << std::endl;
    }

    void SoundService::LoadSoundFromFile(const std::string& button_click_path, const std::string& flag_sound_path,
        const std::string& explosion_sound_path, const std::string& game_won_sound_path)
    {
        if (!bufferButtonClick.loadFromFile(button_click_path))
            std::cerr << "Error loading sound file: " << button_click_path << std::endl;
        if (!bufferFlagSound.loadFromFile(flag_sound_path))
            std::cerr << "Error loading sound file: " << flag_sound_path << std::endl;
        if (!bufferExplosion.loadFromFile(explosion_sound_path))
            std::cerr << "Error loading sound file: " << explosion_sound_path << std::endl;
        if (!bufferGameWon.loadFromFile(game_won_sound_path))
            std::cerr << "Error loading sound file: " << game_won_sound_path << std::endl;
    }

    void SoundService::PlaySound(SoundType soundType)
    {
        switch (soundType)
        {
        case SoundType::BUTTON_CLICK:
            soundEffect.setBuffer(bufferButtonClick);
            break;
        case SoundType::FLAG:
            soundEffect.setBuffer(bufferFlagSound);
            break;
        case SoundType::EXPLOSION:
            soundEffect.setBuffer(bufferExplosion);
            break;
        case SoundType::GAME_WON:
            soundEffect.setBuffer(bufferGameWon);
            break;
        default:
            std::cerr << "Invalid sound type" << std::endl;
            return;
        }

        soundEffect.play();
    }

    void SoundService::PlayBackgroundMusic()
    {
        backgroundMusic.setLoop(true);
        backgroundMusic.setVolume(backgroundMusicVolume);
        backgroundMusic.play();
    }
}