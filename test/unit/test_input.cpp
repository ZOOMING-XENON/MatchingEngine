#include "loader.h"
#include<iostream>
#include<cassert>
int main(){
    ORDER_BOOK book1;
    load("../data/test.csv",book1,DIRECTION::Ask);
    return 0;
}
