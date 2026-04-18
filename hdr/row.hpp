/**
 * @file row.hpp
 * @author Isaiah Preston
 * @brief One row class for each screen row in play class
 * @date 2026-04-04
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include "../hdr/slowObstacle.hpp"
#include "../hdr/mediumObstacle.hpp"
#include "../hdr/fastObstacle.hpp"

class Row {
public:
    Row();
    ~Row() {};

    void update();
    void render(sf::RenderWindow& window);

    void setRow(int row);
    obsType randomObsType();
    bool eachCheckIfInCharColumn();
    void reset();

private:
    int mRowVal;
    obsType mObsType;
    slowObstacle mSlowObs;
    mediumObstacle mMedObs;
    fastObstacle mFastObs;
};