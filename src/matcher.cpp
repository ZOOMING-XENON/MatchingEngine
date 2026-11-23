#include "matcher.h"
void match(ORDER_BOOK& Ask,ORDER_BOOK& Bid){
    // 按照book里面的价格维护一个best_bid和best_ask，
    // 如果当前best_bid>=best_ask 则进行撮合直到best_bid<best_ask
    
    // -----------------------step1 找到best bid --------------------------
    Price best_bid;
    bool find = false;
    for(PRICE_LEVEL* pl : Bid.price_level){
        if(!(pl->order_list.empty())){
            //证明真的有这个价格的order
            best_bid = pl->price;
            find = true;
            break;
        }
    }
    if(find){
        std::cout<<"successfully find the best bid price:"<<best_bid<<std::endl;
    }else{
        std::cout<<"nothing to match"<<std::endl;
        return;
    }

    // 找到best ask
    Price best_ask;
    for(PRICE_LEVEL* pl : Ask.price_level){
        if(!(pl->order_list.empty())){
            //证明真的有这个价格的order
            best_ask = pl->price;
            find = true;
            break;
        }
    }
    if(find){
        std::cout<<"successfully find the best ask price:"<<best_ask<<std::endl;
    }else{
        std::cout<<"nothing to match"<<std::endl;
        return;
    // -----------------------step2 撮合 --------------------------
   if(best_ask>best_bid) return; //说明不用撮合
   // 首先需要找到



}


























}
