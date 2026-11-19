#include "loader.h" //这里面就包括了struct.h
#include<iostream>
int main(){
    ORDER_BOOK book1;
    load("./cases/01_simple_match/test.csv",book1);//这里填写相对路径是对于运行位置而言而不是该文件位置。例如运行位置在build文件夹中，则这里是build/case/...找不到
    
    std::cout<<"check:"<<std::endl;
    std::cout<<book1.price_level[0]->order_list[0]->order_id<<std::endl;
    std::cout<<book1.price_level[0]->order_list[0]->price<<std::endl;
    std::cout<<book1.price_level[0]->order_list[0]->quantity<<std::endl;
    //std::cout<<book1.price_level[0]->order_list[0]->direction<<std::endl;


}