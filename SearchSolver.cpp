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
	if (depth <= 0) return CalcNodeScore(node);//递归边界
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (node.getState().shouldPutPiece(i, j)) {//可下子并且周围有其他子
				CheckerNode child = node.createChdByPutPiece(PiecePosition(i, j), true);//下黑棋生成子节点
				long long val = Min(child, depth - 1, ret);//进入Min层继续递归
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
	if (depth <= 0) return CalcNodeScore(node);//递归边界
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (node.getState().shouldPutPiece(i, j)) {//可下子并且周围有其他子
				CheckerNode child = node.createChdByPutPiece(PiecePosition(i, j), false);//下白棋生成子节点
				long long val = Max(child, depth - 1, ret);//进入Max层继续递归
				if (val < ret) ret = val;
				if (val < beta) return beta;//beta剪枝
			}
		}
	}
	return ret;
}

long long SearchSolver::CalcNumOfContinuePiece(vector<int>& vec)
{
	long long rtn = 0;
	for (auto i = vec.begin(); i != vec.end(); ++i) {
		if ((*i) == 0 || (*i) == 3) continue;//注：棋盘边界为3
		long long piecetype = (*i);
		auto j = i + 1;
		while (j != vec.end() && (*j) == piecetype) ++j;
		long long continum = j - i;
		int freeNum = 0;
		if (*(i - 1) == 0) ++freeNum;
		if ((*j) == 0) ++freeNum;
		if (piecetype == -1) piecetype *= 2;
		if (continum == 5) rtn += piecetype * 2147483647;//五连 评估为无穷大
		else if (continum == 4 && freeNum == 2) rtn += piecetype * 500000;//活四 评估为500000分
		else if (continum == 4 && freeNum == 1) rtn += piecetype * 1000;//半死四 1000分
		else if (continum == 3 && freeNum == 2) rtn += piecetype * 1500;//活三 1500分
		else if (continum == 3 && freeNum == 1) rtn += piecetype * 100;//半死三 100分
		else if (continum == 2 && freeNum == 2) rtn += piecetype * 200;//活二 200分
		else if (continum == 2 && freeNum == 1) rtn += piecetype * 50;//半死二 50分
		else if (continum == 1 && freeNum == 2) rtn += piecetype * 10;//活一 10分
		else if(continum == 1 && freeNum == 1) rtn += piecetype;//半活一 1分
		i = j - 1;
	}
	return rtn;
}
