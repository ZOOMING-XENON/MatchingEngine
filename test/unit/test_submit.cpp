#ifndef CASE_DIR_UNIT
#error "CASE_DIR_UNIT not defined, please configure via CMake"
#endif // 利用CMake里面定义的宏
#include "loader.h" //这里面就包括了struct.h
#include<iostream>
#include<filesystem>
#include "matcher.h"
#include "submit.h"
namespace fs = std::filesystem;

int main(){
    ORDER_BOOK Ask,Bid;
    fs::path path = fs::path(CASE_DIR_UNIT)/ "test_submit.csv";
    //测试ask单主动去打bid

    //情况1：只打掉1单
    load(path,Bid,DIRECTION::Bid);
    std::cout<<std::string(15,'-')<<"Bid Map"<<std::string(15,'-')<<std::endl;
    print_book(Bid);
    ORDER new_ask;
    new_ask.order_id="12";
    new_ask.direction=DIRECTION::Ask;
    new_ask.price=Price(9900);
    new_ask.quantity = Quantity(10);
    submit(new_ask,Ask,Bid);
    std::cout<<std::endl;
    std::cout<<"after submit"<<std::endl<<std::endl;
    print_book(Bid);
    std::cout<<std::endl;


    //情况2：连续扫空
    new_ask.order_id="13";
    new_ask.direction=DIRECTION::Ask;
    new_ask.price=Price(9900);
    new_ask.quantity = Quantity(200);
    submit(new_ask,Ask,Bid);
    std::cout<<std::endl;
    std::cout<<"after submit"<<std::endl;
    std::cout<<std::endl;
    print_book(Bid);

   


}