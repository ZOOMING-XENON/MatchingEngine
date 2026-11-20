#include <iostream>
#include <cstdint>
#include <vector>

#include "loader.h"
//我们记录的价格单位是0.01元，例如100.01元，记录为10001


//存放全局数据
ORDER_BOOK ASK;
ORDER_BOOK BID;


int main(){
    load("data/test.csv", ASK,DIRECTION::Ask);
    return 0;
}
   