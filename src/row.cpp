/**
 * @file row.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @date 2026-04-04
 */

#include "../hdr/row.hpp"

Row::Row() {
    mObsType = slowObs;
}

void Row::setRow(int row) {
    mRowVal = row;
}

obsType Row::getObsType() {
    return mObsType;
}

void Row::setObsType(obsType curObsType) {
    mObsType = curObsType;
}