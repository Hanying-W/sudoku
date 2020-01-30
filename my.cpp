#include "my.h"
#include "iostream"
using namespace std;
//����������ͼ
int map[10][10];
//��ǵ�ǰλ���ܲ����޸�
bool sign[10][10];
//���Դ���
int cnt = 0;
//��ʼ��ҳ��
int iniface() 
{
	int k;
	printf("�������漸��ѡ����ѡ��������ķ�ʽ��\n");
	printf("һ�ν��ܽ�һ���������ж��������������ļ��ķ�ʽ����\n");
	printf("1��������ֱ������Ҫ�����������0��ʾ�ո�\n");
	printf("2�����ļ��ж���Ҫ�������\n");
	printf("����������ѡ��");
	//cin >> k;
	//return k;
	return 2;
}
//ѡ��ͬ�Ķ�ȡ������ʽ
void choose_enter(int k)
{
	if (k == 1)
		choose_keyboard();
	else if (k == 2)
		choose_file();
}
//�Ӽ��̶�������
void choose_keyboard()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			//��ǵ�ǰλ�ò����޸�
			if (map[i][j])
				sign[i][j] = true;
		}
	}
}
//���ļ���������
void choose_file()
{
	//���ļ�
	freopen("in.txt", "r", stdin);
	//��ȡ�ļ���Ϣ
	choose_keyboard();
	//�ر��ļ�
	fclose(stdin);

}
//���н��м���Ƿ����ظ�
bool check_row(int i, int j, int t)
{
	for (int k = 0; k < 9; k++) {
		if (t == map[i][k])
			return false;
	}
	return true;
}
//���н��м���Ƿ����ظ�
bool check_column(int i, int j, int t)
{
	for (int k = 0; k < 9; k++) {
		if (map[k][j] == t)
			return false;
	}
	return true;
}
//�������м���Ƿ����ظ�
bool check_grids(int i, int j, int t)
{
	//ӳ�䵱ǰλ����3*3�����е�λ��
	const int t_i = i % 3;
	const int t_j = j % 3;
	//���Ͻǵĺ�����
	const int x_1 = i - t_i;
	//���Ͻǵ�������
	const int y_1 = j - t_j;
	//���½ǵĺ�����
	int x_2;
	if (t_i == 0)
		x_2 = i + 3;
	else if (t_i == 1)
		x_2 = i + 2;
	else if (t_i == 2)
		x_2 = i + 1;
	//���½ǵ�������
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
//�ƽⷽ��һ
void dfs(int i, int j)
{
	cnt++;
	//�Ѿ�ȫ���ҵ�
	if (i == 9)
		print();
	//��ǰλ��Ϊ��Ŀ����
	else if (sign[i][j]) {
		//�ִ���β
		if (j == 8)
			dfs(i + 1, 0);
		//Ϊ�ִ���β
		else
			dfs(i, j + 1);
	}
	//������������
	else {
		for (int k = 9; k > 0; k--) {
			//��ǰ���ֿ������뵱ǰλ��
			if (check_row(i, j, k) && check_column(i, j, k) && check_grids(i, j, k)) {
				map[i][j] = k;
				//�ִ���β
				if (j == 8)
					dfs(i + 1, 0);
				//Ϊ�ִ���β
				else
					dfs(i, j + 1);
				//��ǰѡ�����ֲ�����Ҫ��
				map[i][j] = 0;
			}
		}
	}
}
//������ս��
void print()
{
	//freopen("out.txt", "w+", stdout);
	printf("�ƽ�ɹ�������Ĵ���Ϊ��%d\n", cnt);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	//_sleep(500);
	//fclose(stdout);
}