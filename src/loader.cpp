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
    while(std::getline(file,line)){
        std::stringstream ss(line);// 转换为输入输出字符流，以便二次读取
        std::vector<std::string> row;
        std::string word;
        while(std::getline(ss,word,',')){
            row.push_back(word);
        }        
        //根据target_direction录入book
        std::string target_direction_string = target_direction==DIRECTION::Ask? "Ask" : "Bid";
        if(row[3]==target_direction_string){
            // 首先选择方向对的
            ORDER* new_order = new ORDER; //这种new都是在堆上面分配的
            new_order->order_id = row[0];//string
            new_order->price =static_cast<Price>(std::llround(std::stod(row[1]) * 100));//100.01要转化为10001,csv里面读出来全是string  // 需要 #include <cmath>
            new_order->quantity = static_cast<Quantity>(std::stoi(row[2]));
            new_order->direction = row[3]=="Ask" ?  DIRECTION::Ask : DIRECTION::Bid;
            // 其次要判断这个price是否在已有的pricelevel里面，
            //如果在的话则在已有的pricelevel结构体的order_list里面加，
            //如果不在则需要在ORDER_BOOK里面新增一个PRICE_LEVEL
            Price new_order_price = new_order->price;
            auto it = std::find_if(book.price_level.begin(),book.price_level.end(),[&](const PRICE_LEVEL* lv){return lv->price == new_order_price; });
            PRICE_LEVEL* new_level;

            if(it == book.price_level.end()){
                //说明没有这个pricelevel
                new_level = new PRICE_LEVEL;
                new_level->price = new_order->price;
                new_level->order_list.push_back(new_order);
                book.price_level.push_back(new_level);
                // 插入之后还要进行排序
                if(target_direction_string=="Ask"){
                    std::sort(book.price_level.begin(),book.price_level.end(),cmp_ascending);
                }else{
                    std::sort(book.price_level.begin(),book.price_level.end(),cmp_decending);

                }
                
            }else{
                //说明已经有这个pricelevel了，而且找到就是it
                new_level = *it;
                new_level->order_list.push_back(new_order);
            }
        }        
    }
    return;

}