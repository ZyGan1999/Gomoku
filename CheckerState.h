#pragma once
#include "PiecePosition.h"
#include <vector>
#include <iostream>
using namespace std;
class CheckerState
{
public:
	CheckerState();
	CheckerState(const CheckerState & st);
	~CheckerState();
	void putPiece(PiecePosition p,bool isBlack);
	bool canPutPiece(int x, int y);//(x,y)�����ܷ�������
	bool isNeighborPiece(int x, int y);//(x,y)��Χ�Ƿ�������(�ж����Ϊ2)
	bool shouldPutPiece(int x, int y) {
		return canPutPiece(x, y) && isNeighborPiece(x, y);
	}
	vector<vector<int>> getChecker();
	void printPieces() const {
		for (int i = 0; i < 19; i++) {
			for (int j = 0; j < 19; j++) {
				if (_pieces[i][j] == -1) cout << _pieces[i][j];
				else cout << ' ' << _pieces[i][j];
			}
			cout << endl;
		}
	}

private:
	int _pieces[19][19];//1�� -1��
};
