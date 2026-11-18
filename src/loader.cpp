#include "../include/loader.h"
#include <string>
#include <fstream>

void load(std::string file_path,ORDER_BOOK& book){ // file_path = data.csv
    std::ifstream file(file_path);
    std::string s;
    if(!file.is_open()){
        std::cerr<<"cannot open file:"<<file_path<<std::endl;
        return;
    }
    while(std::getline(file,s)){
        std::cout<<s<<std::endl;
    }
    return;

}