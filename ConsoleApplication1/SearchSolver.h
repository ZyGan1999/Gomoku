#pragma once
#include "CheckerNode.h"
#include <stack>
using namespace std;
class SearchSolver
{
public:
	SearchSolver();
	~SearchSolver();
	void init(int checkerX, int checkerY, int numToWin, bool isBlack);
	PiecePosition putPiece(int depth);
	long long CalcNodeScore(CheckerNode & node);
	long long Max(CheckerNode & node, int depth, long long alpha);
	long long Min(CheckerNode & node, int depth, long long beta);
	long long CalcNumOfContinuePiece(vector<int>& vec);
	void setCurNode(CheckerNode node) {
		curNode = node;
	}
private:
	CheckerNode curNode;
	PiecePosition bestPosition;
	
	bool isMax;
	int depth;
};
