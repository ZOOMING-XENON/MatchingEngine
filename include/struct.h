#pragma once
#include<cstdint>
#include<vector>
#include<string>
// 发现从软件构造上来讲，结构体会放在.h文件里面存储，这样主文件include一下就可以识别
// 但是一般不把结构体放在.cpp中，因为有的函数需要使用结构体输入输出，在.h中必然需要重新定义一遍，这样会造成重复定义
using Price = std::int64_t;
using Quantity = std::int64_t;
enum class DIRECTION{Ask,Bid};
struct ORDER{
    std::string order_id;
    Price price;
    Quantity quantity;
    DIRECTION direction = DIRECTION::Ask;
};
struct PRICE_LEVEL{
    Price price;
    std::vector<ORDER*> order_list;

};
struct ORDER_BOOK{
    std::vector<PRICE_LEVEL*> price_level;
};
