#pragma once

#include <vector>
#include <iostream>
#include "functions.hpp"

class Square{
    usint number;
    usint Rn,Ln,Un,Sn; //right neighbor, left neighbor etc// 0==the hole // 10==the border

    public:
    Square();
    Square(usint nr) {number=nr;}
    usint getNumber() {return number;}
    void setNumber(usint nr) {number=nr;}
    void setNeighbors(usint r=0,usint l=0, usint u=0, usint s=0){ Rn=r; Ln=l; Un=u; Sn=s;}
    usint getRightNeighbor(){ return Rn;}
    usint getLeftNeighbor(){ return Ln;}
    usint getUpperNeighbor(){ return Un;}
    usint getSubNeighbor() {return Sn;}
};