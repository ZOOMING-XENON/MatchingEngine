#include "submit.h"
#include "utils.h"
PRICE_LEVEL* find_tradable_level(const ORDER& order,ORDER_BOOK& book){
    if(order.direction ==DIRECTION::Ask){
        //进来的是卖单，要找高价买单
        //判定一下传进来的book对不对,对于ask单一定要返回bid订单簿里面的order
        if(book.direction!=DIRECTION::Bid){
            std::cerr<<"wrong input book for function: ORDER* find_tradable_order(Price order_price,ORDER_BOOK book, DIRECTION order_direction)"<<std::endl;
            return nullptr;
        } 
        if(book.price_level.empty()) return nullptr;
        Price best_bid = find_best(book);
        if(order.price>best_bid) return nullptr;//没有可以交易的
        return book.price_level.front();

    }
    if(order.direction ==DIRECTION::Bid){
        //进来的是买单，要找低价卖单
        if(book.direction!=DIRECTION::Ask){
            std::cerr<<"wrong input book for function: ORDER* find_tradable_order(Price order_price,ORDER_BOOK book, DIRECTION order_direction)"<<std::endl;
            return nullptr;
        } 
        if(book.price_level.empty()) return nullptr;
        Price best_ask = find_best(book);
        if(order.price<best_ask) return nullptr;//没有可以交易的
        return book.price_level.front();

    }
    return nullptr;
}
void submit(ORDER order,ORDER_BOOK& Ask,ORDER_BOOK& Bid){
    if(order.direction==DIRECTION::Ask){
        // 进来卖单，要check买的簿Bid
        Price order_price = order.price;
        PRICE_LEVEL* level = find_tradable_level(order,Bid);
        if(level==nullptr) return;
        if(level->order_list.front()->quantity > order.quantity){
            Quantity q = order.quantity;
            level->order_list.front()->quantity -= order.quantity;
            order.quantity = Quantity(0);
            std::cout<<"[order traded]:"<<std::endl;
            std::cout<<"sell order:"<<order.order_id<<std::endl;
            std::cout<<"buy order:"<<level->order_list.front()->order_id<<std::endl;
            std::cout<<"traded price:"<<level->order_list.front()->price<<std::endl;
            std::cout<<"traded quantity:"<<q<<std::endl;
        }else{
            // 说明这单ask会吃掉多个bid的order，甚至整个level
            while(order.quantity>0){
                PRICE_LEVEL* level = find_tradable_level(order,Bid);
                if(level!=nullptr){
                    if(level->order_list.front()->quantity > order.quantity){
                        Quantity q = order.quantity;
                        level->order_list.front()->quantity -= order.quantity;
                        order.quantity = 0;
                        std::cout<<"[big order traded]:"<<std::endl;
                        std::cout<<"sell order:"<<order.order_id<<std::endl;
                        std::cout<<"buy order:"<<level->order_list.front()->order_id<<std::endl;
                        std::cout<<"traded price:"<<level->order_list.front()->price<<std::endl;
                        std::cout<<"traded quantity:"<<q<<std::endl;
                    }else{
                        //这个时候 order里面的数量更多
                        Quantity q = level->order_list.front()->quantity;
                        order.quantity -= level->order_list.front()->quantity;
                        level->order_list.front()->quantity = 0;
                        //此时需要处理掉这个已经被吃完的tradable单的vector
                        std::cout<<"[big order traded]:"<<std::endl;
                        std::cout<<"sell order:"<<order.order_id<<std::endl;
                        std::cout<<"buy order:"<<level->order_list.front()->order_id<<std::endl;
                        std::cout<<"traded price:"<<level->order_list.front()->price<<std::endl;
                        std::cout<<"traded quantity:"<<q<<std::endl;
                        level->order_list.erase(level->order_list.begin());
                        //删掉level里面这个list
                        if(level->order_list.empty()){
                            // 还要释放掉这个level
                            Bid.price_level.erase(Bid.price_level.begin());
                        }
                    }

                }else{
                    break;
                }

            }
            std::cout<<"done!"<<std::endl;
            

        }

    }
}