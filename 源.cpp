#include "my.h"
#include "graphics.h"
#include "cstdio"
int main() {
	//freopen("out.txt", "w", stdout);
	//获取用户选择输入的方式
	//int k = iniface();
	//依据用户的输入方式去选择不同的输入方式的接口
	choose_enter(2);
	//破解方法一
	dfs(0, 0);
	//fclose(stdout);
	return 0;
}