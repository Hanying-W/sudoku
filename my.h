#pragma once
//初始化页面
int iniface();
//选择不同的读取数独方式
void choose_enter(int k);
//从键盘读入数独
void choose_keyboard();
//从文件读入数独
void choose_file();
//按行进行检查是否有重复
bool check_row(int i, int j, int t);
//按列进行检查是否有重复
bool check_column(int i, int j, int t);
//按宫进行检查是否有重复
bool check_grids(int i, int j, int t);
//破解方法一
void dfs(int i, int j);
//输出最终的结果
void print();