#pragma once
//��ʼ��ҳ��
int iniface();
//ѡ��ͬ�Ķ�ȡ������ʽ
void choose_enter(int k);
//�Ӽ��̶�������
void choose_keyboard();
//���ļ���������
void choose_file();
//���н��м���Ƿ����ظ�
bool check_row(int i, int j, int t);
//���н��м���Ƿ����ظ�
bool check_column(int i, int j, int t);
//�������м���Ƿ����ظ�
bool check_grids(int i, int j, int t);
//�ƽⷽ��һ
void dfs(int i, int j);
//������յĽ��
void print();