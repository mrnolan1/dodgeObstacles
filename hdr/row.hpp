/**
 * @file row.hpp
 * @author Isaiah Preston
 * @brief 
 * @date 2026-04-04
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../hdr/obstacle.hpp"

enum obsType {slowObs, medObs, fastObs};

class Row {
public:
    Row();
    ~Row() {};
    void setRow(int row);
    obsType getObsType();
    void setObsType(obsType curObsType);
private:
    int mRowVal;
    obsType mObsType;
};