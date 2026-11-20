#include "matcher.h"
bool cmp_decending(PRICE_LEVEL* a, PRICE_LEVEL* b){
    return a->price>b->price;
}
void match(ORDER_BOOK& Ask,ORDER_BOOK& Bid){
    // 按照book里面的价格维护一个best_bid和best_ask，
    // 如果当前best_bid>=best_ask 则进行撮合直到best_bid<best_ask
    // 先进行排序，根据price_level的price进行排序
    std::sort(Ask.price_level.begin(),Ask.price_level.end(),cmp_decending);

     
}