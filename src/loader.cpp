#include "../include/loader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

/**
 * 表格格式OrderId,Price,Quantity,Direction
 */
void load(std::string file_path,ORDER_BOOK& book){ // file_path = data.csv
    std::ifstream file(file_path);
    std::string line;
    if(!file.is_open()){
        std::cerr<<"cannot open file:"<<file_path<<std::endl;
        return;
    }
    while(std::getline(file,line)){
        std::cout<<line<<std::endl;//每次读一行
        //strip一下
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string word;
        while(std::getline(ss,word,',')){
            row.push_back(word);
        }
        
        ORDER* new_order = new ORDER; //这种new都是在堆上面分配的
        new_order->order_id = row[0];//string
        new_order->price =static_cast<Price>(std::llround(std::stod(row[1]) * 100));//100.01要转化为10001,csv里面读出来全是string  // 需要 #include <cmath>
        new_order->quantity = static_cast<Quantity>(std::stoi(row[2]));
        new_order->direction = row[3]=="Ask" ?  DIRECTION::Ask : DIRECTION::Bid;
        PRICE_LEVEL* new_level = new PRICE_LEVEL;
        new_level->price = new_order->price;
        new_level->order_list.push_back(new_order);
        book.price_level.push_back(new_level);

        
    }
    return;

}