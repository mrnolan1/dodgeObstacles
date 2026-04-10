/**
 * @file row.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @date 2026-04-04
 */

#include "../hdr/row.hpp"

Row::Row() {
    mObsType = noObs;
}

void Row::setRow(int row) {
    mRowVal = row;
    mSlowObs.setRow(row);
    mMedObs.setRow(row);
    mFastObs.setRow(row);
}

void Row::update() {
    switch(mObsType) {
        case noObs: {
            mObsType = randomObstype();
        }
        case slowObs: {
            mObsType = mSlowObs.update();
            break;
        }
        case medObs: {
            mObsType = mMedObs.update();
            break;
        }
        case fastObs: {
            mObsType = mFastObs.update();
            break;
        }
    }
}

obsType Row::randomObsType() {
    mObsType = curObsType;
}