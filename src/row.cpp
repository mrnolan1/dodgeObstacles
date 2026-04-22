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
            mObsType = randomObsType(dt);
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
    std::cout << "Start render\n";
    mSlowObs.render(window);
    std::cout << "Render between slow and med\n";
    mMedObs.render(window);
    std::cout << "Render between med and fast\n";
    mFastObs.render(window);
    std::cout << "End render\n";
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
obsType Row::randomObsType(double dt) {
    static std::random_device rd;                   // a seed source for the random number engine
    static std::mt19937 gen(rd());                  // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dist(1, 1/dt); // Use distrib to transform the random unsigned int
    
    if(dist(gen) == 1)
        return slowObs; 
    else if(dist(gen) == 2)
        return medObs;
    else if(dist(gen) == 3)
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