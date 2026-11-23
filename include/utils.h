#pragma once
#include "struct.h"
#include<iostream>
#include<string>
/**
 * 统一格式打印order book的函数
 */
void print_book(ORDER_BOOK book);
bool cmp_decending(PRICE_LEVEL* a, PRICE_LEVEL* b);
bool cmp_ascending(PRICE_LEVEL* a, PRICE_LEVEL* b);