#include "Header.h"

Heap::Heap(int n)
{
	size = 0;
	item* arr = new item[n];
}

Heap::~Heap()
{
	clear();
}

void Heap::push(int value, int priority)
{
	item c;
	c.value = value;
	c.priority = priority;
	arr[size] = c;
	shift_up(size);
	size++;
}

void Heap::pop()
{
	if (size != 0) {
		arr[0] = arr[size--];
		shift_down(0);
	}
}

int Heap::top()
{
	return arr[0].value;
}

void Heap::clear()
{
	delete arr;
}

void Heap::printAsArray()
{
	int i = 0;
	while (i < size)
		cout << arr[i].value << ' ';
	cout << endl;
}

void Heap::coutTree(int pos, int level) {
	if (pos < size) {
		int ch1 = pos * 2 + 1;
		int ch2 = pos * 2 + 2;
		coutTree(ch2, level + 1);
		for (int i = 0; i < level; i++) cout << '\t';
		cout << arr[pos].value << endl;
		coutTree(ch1, level + 1);
	}
}

void Heap::printAsTree() {
	coutTree(0, 0);
}

int Heap::primMST(AdjancentMatrixGraph* g)
{
	int sum = 0;
	int n = g->getSize();//кол-во вершин
	int inf = -1000000000;//ребро между вершинами отсутствует
	vector<bool> used(n); //массив вершин включенных в остов
	vector<int> min_e(n, inf);//хранит вес наименьшего ребра из вершины i
	min_e[0] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
		if (min_e[v] == inf) 
			exit(0);

		used[v] = true;
		sum += min_e[v];

		for (int i = 0; i < n; i++)
			if (g[v][i] < min_e[i])
				min_e[i] = g[v][i];
	}
	return sum;
}

void Heap::shift_up(int pos)
{
	int t;
	t = pos / 2;
	if (t != 0) {
		if (arr[pos].priority > arr[t].priority) {
			swap(arr[t], arr[pos]);
			shift_up(t);
		}
	}
}

void Heap::shift_down(int pos)
{
	int t;
	t = pos * 2;
	if (t < size) {
		if (t + 1 <= size && arr[t + 1].priority > arr[t].priority)
			t++;
		if (arr[pos].priority < arr[t].priority) {
			swap(arr[t], arr[pos]);
			shift_down(t);
		}
	}
}
