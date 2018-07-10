#include "SearchSolver.h"
#include <iostream>
#include <vector>
using namespace std;

SearchSolver::SearchSolver():bestPosition(-1,-1)
{
	init(19, 19, 5, true);
}


SearchSolver::~SearchSolver()
{
}

void SearchSolver::init(int checkerX, int checkerY, int numToWin, bool isBlack)
{
	CheckerNode n0;
	curNode = n0;
	this->isMax = isBlack;
}

PiecePosition SearchSolver::putPiece(int depth)
{
	//to do 最大最小值搜索
	vector<PiecePosition> _positions;
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (curNode.getState().shouldPutPiece(i, j)){
				_positions.push_back(PiecePosition(i, j));
			}
		}
	}
	long long MaxScore = -1000000000000;
	for (auto i = _positions.begin(); i != _positions.end(); ++i) {
		CheckerNode child = curNode.createChdByPutPiece((*i), true);
		long long curScore = Min(child, depth, MaxScore);
		if (curScore > MaxScore) {
			MaxScore = curScore;
			bestPosition = (*i);
		}
	}
	return bestPosition;
}

long long SearchSolver::CalcNodeScore(CheckerNode & node)
{
	long long ret = 0;
	vector<vector<int>> judges = node.getState().getChecker();
	for (auto i = judges.begin(); i != judges.end(); ++i) {
		ret += CalcNumOfContinuePiece(*i);
	}
	return ret;
}

long long SearchSolver::Max(CheckerNode & node, int depth, long long alpha)
{
	long long ret = -100000000000;
	if (depth <= 0) return CalcNodeScore(node);
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (node.getState().shouldPutPiece(i, j)) {
				CheckerNode child = node.createChdByPutPiece(PiecePosition(i, j), true);//下黑棋生成子节点
				long long val = Min(child, depth - 1, ret);
				if (val > ret) { ret = val; }
				//if (val > alpha) { alpha = val; }
			}
		}
	}
	return ret;
}

long long SearchSolver::Min(CheckerNode & node, int depth, long long beta)
{
	long long ret = 100000000000000;
	if (depth <= 0) return CalcNodeScore(node);
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (node.getState().shouldPutPiece(i, j)) {
				CheckerNode child = node.createChdByPutPiece(PiecePosition(i, j), false);//下白棋生成子节点
				long long val = Max(child, depth - 1, ret);
				if (val < ret) ret = val;
				if (val < beta) return beta;
			}
		}
	}
	return ret;
}

long long SearchSolver::CalcNumOfContinuePiece(vector<int>& vec)
{
	long long rtn = 0;
	for (auto i = vec.begin(); i != vec.end(); ++i) {
		if ((*i) == 0 || (*i) == 3) continue;
		long long piecetype = (*i);
		auto j = i + 1;
		while (j != vec.end() && (*j) == piecetype) ++j;
		long long continum = j - i;
		int freeNum = 0;
		if (*(i - 1) == 0) ++freeNum;
		if ((*j) == 0) ++freeNum;
		if (piecetype == -1) piecetype *= 2;
		if (continum == 5) rtn += piecetype * 2147483647;
		else if (continum == 4 && freeNum == 2) rtn += piecetype * 500000;
		else if (continum == 4 && freeNum == 1) rtn += piecetype * 1000;
		else if (continum == 3 && freeNum == 2) rtn += piecetype * 1500;
		else if (continum == 3 && freeNum == 1) rtn += piecetype * 100;
		else if (continum == 2 && freeNum == 2) rtn += piecetype * 200;
		else if (continum == 2 && freeNum == 1) rtn += piecetype * 50;
		else if (continum == 1 && freeNum == 2) rtn += piecetype * 10;
		else if(continum == 1 && freeNum == 1) rtn += piecetype;
		i = j - 1;
	}
	return rtn;
}
