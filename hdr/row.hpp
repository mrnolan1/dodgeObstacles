/**
 * @file row.hpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-04-04
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../hdr/obstacle.hpp"

class Row {
public:
    Row();
    ~Row() {};

    void update();
    void render();

    void setRow(int row);
    obsType randomObsType();

private:
    int mRowVal;
    obsType mObsType;
};