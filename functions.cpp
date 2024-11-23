#include "functions.hpp"

usint getRandom(usint lowerBound, usint UpperBound){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<usint> dist(lowerBound,UpperBound);

    return dist(gen);
}