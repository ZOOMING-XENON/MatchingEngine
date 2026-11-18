#pragma once
#include<string>
#include<vector>
#include<iostream>
#include "struct.h"
/**
   * @brief 从 CSV 文件加载订单到订单簿
   * @param file_path 文件路径，必须是标准逗号分隔的 .csv（如 data.csv）
   * @param book 要写入的订单簿
   * @note 文件建议保存为 UTF-8 无 BOM
   */
void load(std::string file_path,ORDER_BOOK& book);