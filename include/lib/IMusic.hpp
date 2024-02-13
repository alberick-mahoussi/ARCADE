/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** IMusic
*/


#ifndef IMUSIC_HPP_
#define IMUSIC_HPP_

#include <string>

class IMusic {
    public:
        virtual void playMusic(const std::string &path, bool loop, float volume) = 0;
        virtual void clearMusic() = 0;
        virtual ~IMusic() = default;
};

#endif /* !IMUSIC_HPP_ */