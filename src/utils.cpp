#include "utils.h"
void print_book(ORDER_BOOK book){
    for(PRICE_LEVEL* p :book.price_level){
        std::cout<<"Level Price is:"<<p->price<<std::endl;
        for(ORDER* o:p->order_list){
            std::string direction_string = o->direction==DIRECTION::Ask? "Ask":"Bid";
            std::cout<<o->order_id<<" "<<o->price<<" "<<o->quantity<<" "<<direction_string<<std::endl;
        }
        std::cout<<std::string(30,'-')<<std::endl;
    }
}
bool cmp_decending(PRICE_LEVEL* a, PRICE_LEVEL* b){
    return a->price>b->price;
}
bool cmp_ascending(PRICE_LEVEL* a, PRICE_LEVEL* b){
    return a->price<b->price;
}