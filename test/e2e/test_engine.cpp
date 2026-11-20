#ifndef CASE_DIR
#error "CASE_DIR not defined, please configure via CMake"
#endif // 利用CMake里面定义的宏
#include "loader.h" //这里面就包括了struct.h
#include<iostream>
#include<filesystem>
namespace fs = std::filesystem;

int main(){
    ORDER_BOOK Ask,Bid;
    fs::path path = fs::path(CASE_DIR) / "01_simple_match" / "test.csv";
    // 填充Ask订单簿
    load(path,Ask,DIRECTION::Ask);//这里填写相对路径是对于运行位置而言而不是该文件位置。例如运行位置在build文件夹中，则这里是build/case/...找不到
    // 填充Bid订单簿
    load(path,Bid,DIRECTION::Bid);
    print_book(Ask);
    print_book(Bid);
   


}