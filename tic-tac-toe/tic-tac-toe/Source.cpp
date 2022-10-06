#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<char>CELLS;

void show_cells(int n) {
	cout << "Cells numbers: \n";
	for (int i = 0; i < n * n; i++) {
		if (i < 9) { //чтобы поле ровно выводилось
			if ((i + 1) % n == 0) {//проверка конца строки
				cout << "-" << i + 1 << " -" << endl;
				continue;
			}
			cout << "-" << i + 1 << " -" << "|";
		}
		else {
			if ((i + 1) % n == 0) {//проверка конца строки
				cout << "-" << i + 1 << "-" << endl;
				continue;
			}
			cout << "-" << i + 1 << "-" << "|";
		}
	}
	cout <<endl<<"current situation (--- empty): \n" << endl;
	for (int i = 0; i < n * n; i++) {
		if ((i + 1) % n == 0) {//проверка конца строки
			cout << "-" << CELLS[i] << "-" << endl;
			continue;
		}
		cout << "-" <<CELLS[i]<< "-" << "|";
	}
}

struct Tree {
	int WLN = 0; //none win loose / (0, 1, 2)
	vector<Tree> branches;//у каждого есть по несколько разветвлений, нужно будет установить ресайз для них через подсчёт возможных ходов
	int turn = 0;// чей ход 0-компьютера, 1-игрока
	vector<char>cells;
};

int main() {
	int n = 0;
	cout << "Insert size of field(3-5): ";
	cin >> n;
	CELLS.resize(n*n);
	for (int i = 0; i < CELLS.size(); i++) {
		CELLS[i] ='-';
	}
	show_cells(n);
}