// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <cstdlib>

struct Player
{
    std::size_t x{};
    std::size_t y{};
    std::size_t treasure_count{}; // treasure count
};

#endif
