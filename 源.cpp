#include "my.h"
#include "graphics.h"
#include "cstdio"
int main() {
	//freopen("out.txt", "w", stdout);
	//��ȡ�û�ѡ������ķ�ʽ
	//int k = iniface();
	//�����û������뷽ʽȥѡ��ͬ�����뷽ʽ�Ľӿ�
	choose_enter(2);
	//�ƽⷽ��һ
	dfs(0, 0);
	//fclose(stdout);
	return 0;
}