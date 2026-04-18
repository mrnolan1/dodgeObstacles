/**
 * @file row.cpp
 * @author Isaiah Preston
 * @brief One row class for each screen row in play class
 * @date 2026-04-04
 */

#include "../hdr/row.hpp"

/**
 * @brief Construct a new Row::Row object
 *          Set current obsType to noObs
 */
Row::Row() {
    mObsType = noObs;
}

/**
 * @brief Handle updating the "active" obstacle of this row
 *          If none, randomly chose if a new obs is created
 */
void Row::update(double dt) {
    switch(mObsType) {
        case noObs: {
            mObsType = randomObsType();
            break;
        }
        case slowObs: {
            mObsType = mSlowObs.update(dt);
            break;
        }
        case medObs: {
            mObsType = mMedObs.update(dt);
            break;
        }
        case fastObs: {
            mObsType = mFastObs.update(dt);
            break;
        }
    }
}

/**
 * @brief Render each obstacle of each speed for each row
 * 
 * @param window 
 */
void Row::render(sf::RenderWindow& window) {
    mSlowObs.render(window);
    mMedObs.render(window);
    mFastObs.render(window);
}

/**
 * @brief Given a row, set all row values to this row
 * 
 * @param row 
 */
void Row::setRow(int row) {
    mRowVal = row;
    mSlowObs.setRow(row);
    mMedObs.setRow(row);
    mFastObs.setRow(row);
}

/**
 * @brief Randomly generate whether an obstacle (of any three types) is created
 * 
 * @return obsType 
 */
obsType Row::randomObsType() {
    static std::random_device rd;  
    static std::mt19937 gen(rd()); 

    std::uniform_int_distribution<> dist(1, 10000);
    int num = dist(gen);
    
    if(num == 1)
        return slowObs;
    else if(num == 2)
        return medObs;
    else if(num == 3)
        return fastObs;
    else
        return noObs;
}

/**
 * @brief Call individual obstacle checks to determine if each obs is "on" character
 * 
 * @return true 
 * @return false 
 */
bool Row::eachCheckIfInCharColumn() {
    if(mSlowObs.checkIfInCharColumn() || 
        mMedObs.checkIfInCharColumn() ||
        mFastObs.checkIfInCharColumn()) 
            return true;
    else   
            return false;
}

/**
 * @brief Reset obstacle positions when a new game is started
 */
void Row::reset() {
    mSlowObs.reset();
    mMedObs.reset();
    mFastObs.reset();
}