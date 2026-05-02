/**
 * @file row.hpp
 * @author Isaiah Preston
 * @brief One row class for each screen row in play class
 * @date 2026-04-04
 */

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include "../hdr/slowObstacle.hpp"
#include "../hdr/mediumObstacle.hpp"
#include "../hdr/fastObstacle.hpp"
#include "../hdr/bubbleObstacle.hpp"

// #include "../hdr/play.hpp"

class Row {
public:
    Row();
    ~Row() {};

    void update(double dt);
    void render(sf::RenderWindow& window);
    
    void setBubExists(bool doesIt);
    obsType getObsType();

    void setRow(int row);
    obsType randomObsType(double dt);
    bool eachCheckIfInCharColumn();
    void reset();

private:
    int mRowVal = -1;
    obsType mObsType;
    slowObstacle mSlowObs;
    mediumObstacle mMedObs;
    fastObstacle mFastObs;
    bubbleObstacle mBubObs;

    // bool mBubExists = false;
};
