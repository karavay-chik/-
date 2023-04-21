#pragma once
#include"AdjancentMatrixGraph.h"
#include <iostream>
using namespace std;

struct item {
	int value;
	int priority;
};
class Heap {
	item* arr;
	int  size;
	void shift_up(int pos); // ������� ������� �����
	void shift_down(int pos); // ������� ������� ����
public:
	Heap(int n);
	~Heap();
	void push(int value, int priority); // ���������� �������� � ������� ������ � ��� �����������
	void pop(); // ���������� �������� �� �������
	int top(); // �������� ������� �� ������� � ��������� ����������� (��� ��� ����������)
	void clear(); // ������� �������
	void printAsArray();// ������ ������� � ���� �������
	void coutTree(int pos, int level);
	void printAsTree(); // ������ ������� � ���� ������
	int primMST(AdjancentMatrixGraph* g);
};