/**
 * @file play.cpp
 * @author Isaiah
 * @brief 
 * @date 2026-04-04
 */

#include "../hdr/play.hpp"

Play::Play(sf::RenderWindow& playWindow) {
    for(int i = 0; i < 5; i++)
        mRow[i].setRow(i);
}

