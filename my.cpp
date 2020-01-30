#include "my.h"
#include "iostream"
using namespace std;
//设置数独地图
int map[10][10];
//标记当前位置能不能修改
bool sign[10][10];
//尝试次数
int cnt = 0;
//初始化页面
int iniface() 
{
	int k;
	printf("请在下面几个选项中选择你输入的方式：\n");
	printf("一次仅能解一个数独，有多组数独的请以文件的方式读入\n");
	printf("1、在下面直接输入要解的数独，以0表示空格\n");
	printf("2、从文件中读入要解的数独\n");
	printf("请输入您的选择：");
	//cin >> k;
	//return k;
	return 2;
}
//选择不同的读取数独方式
void choose_enter(int k)
{
	if (k == 1)
		choose_keyboard();
	else if (k == 2)
		choose_file();
}
//从键盘读入数独
void choose_keyboard()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			//标记当前位置不能修改
			if (map[i][j])
				sign[i][j] = true;
		}
	}
}
//从文件读入数独
void choose_file()
{
	//打开文件
	freopen("in.txt", "r", stdin);
	//读取文件信息
	choose_keyboard();
	//关闭文件
	fclose(stdin);

}
//按行进行检查是否有重复
bool check_row(int i, int j, int t)
{
	for (int k = 0; k < 9; k++) {
		if (t == map[i][k])
			return false;
	}
	return true;
}
//按列进行检查是否有重复
bool check_column(int i, int j, int t)
{
	for (int k = 0; k < 9; k++) {
		if (map[k][j] == t)
			return false;
	}
	return true;
}
//按宫进行检查是否有重复
bool check_grids(int i, int j, int t)
{
	//映射当前位置在3*3矩阵中的位置
	const int t_i = i % 3;
	const int t_j = j % 3;
	//左上角的横坐标
	const int x_1 = i - t_i;
	//左上角的纵坐标
	const int y_1 = j - t_j;
	//右下角的横坐标
	int x_2;
	if (t_i == 0)
		x_2 = i + 3;
	else if (t_i == 1)
		x_2 = i + 2;
	else if (t_i == 2)
		x_2 = i + 1;
	//右下角的纵坐标
	int y_2;
	if (t_j == 0)
		y_2 = j + 3;
	else if (t_j == 1)
		y_2 = j + 2;
	else if (t_j == 2)
		y_2 = j + 1;
	for (int x = x_1; x < x_2; x++) {
		for (int y = y_1; y < y_2; y++) {
			if (map[x][y] == t)
				return false;
		}
	}
	return true;
}
//破解方法一
void dfs(int i, int j)
{
	cnt++;
	//已经全部找到
	if (i == 9)
		print();
	//当前位置为题目所填
	else if (sign[i][j]) {
		//抵达行尾
		if (j == 8)
			dfs(i + 1, 0);
		//为抵达行尾
		else
			dfs(i, j + 1);
	}
	//可以填入数字
	else {
		for (int k = 9; k > 0; k--) {
			//当前数字可以填入当前位置
			if (check_row(i, j, k) && check_column(i, j, k) && check_grids(i, j, k)) {
				map[i][j] = k;
				//抵达行尾
				if (j == 8)
					dfs(i + 1, 0);
				//为抵达行尾
				else
					dfs(i, j + 1);
				//当前选的数字不符合要求
				map[i][j] = 0;
			}
		}
	}
}
//输出最终结果
void print()
{
	//freopen("out.txt", "w+", stdout);
	printf("破解成功，所需的次数为：%d\n", cnt);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	//_sleep(500);
	//fclose(stdout);
}