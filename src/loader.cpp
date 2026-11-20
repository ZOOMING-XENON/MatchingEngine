#include "loader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <filesystem>
namespace fs = std::filesystem;
/**
 * 表格格式OrderId,Price,Quantity,Direction
 * 而且我觉得我们可以直接load进不同的book中，这样子不用在match的时候再拆开来
 */
void load(const fs::path& file_path,ORDER_BOOK& book,DIRECTION target_direction){ // file_path = data.csv
    std::ifstream file(file_path);
    std::string line;
    if(!file.is_open()){
        std::cerr<<"cannot open file:"<<file_path<<std::endl;
        return;
    }
    std::getline(file,line);// 跳过表头，防止其被读取参与后续的字符变换操作
    std::cout<<"table head:"<<std::endl<<line<<std::endl;
    std::cout<<std::string(30, '-')<<std::endl;//分割符
    while(std::getline(file,line)){
        std::stringstream ss(line);// 转换为输入输出字符流，以便二次读取
        std::vector<std::string> row;
        std::string word;
        while(std::getline(ss,word,',')){
            row.push_back(word);
            std::cout<<word<<" ";
        }
        std::cout<<std::endl<<std::string(30, '-')<<std::endl;//分割符
        
        //根据target_direction录入book
        std::string target_direction_string = target_direction==DIRECTION::Ask? "Ask" : "Bid";
        if(row[3]==target_direction_string){
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
    }
    return;

}