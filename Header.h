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
	void shift_up(int pos); // поднять элемент вверх
	void shift_down(int pos); // поднять элемент вниз
public:
	Heap(int n);
	~Heap();
	void push(int value, int priority); // добавление элемента в очередь вместе с его приоритетом
	void pop(); // извлечение элемента из очереди
	int top(); // получить элемент из очереди с наивысшим приоритетом (без его извлечения)
	void clear(); // очистка очереди
	void printAsArray();// печать очереди в виде массива
	void coutTree(int pos, int level);
	void printAsTree(); // печать очереди в виде дерева
	int primMST(AdjancentMatrixGraph* g);
};