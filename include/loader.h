#pragma once
#include<string>
#include<vector>
#include<iostream>
#include "struct.h"
#include "utils.h"
#include <filesystem>

namespace fs = std::filesystem;
/**
   * @brief 从 CSV 文件加载订单到订单簿
   * @param file_path 文件路径,格式应该为filesystem::path类型，必须是标准逗号分隔的 .csv（如 data.csv）
   * @param book 要写入的订单簿
   * @note 文件建议保存为 UTF-8 无 BOM
   */
void load(const fs::path& file_path,ORDER_BOOK& book,DIRECTION target_direction);