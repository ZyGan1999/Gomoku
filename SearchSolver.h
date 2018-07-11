#pragma once
#include "CheckerNode.h"
#include <stack>
using namespace std;
class SearchSolver
{
public:
	SearchSolver();
	~SearchSolver();
	void init(int checkerX, int checkerY, int numToWin, bool isBlack);//用规则参数初始化 棋盘长、宽、要求连子数、是否处在黑层
	PiecePosition putPiece(int depth);//用极大极小值搜索得出此步该在哪里下子
	long long CalcNodeScore(CheckerNode & node);//计算棋盘节点当前评估函数值
	long long Max(CheckerNode & node, int depth, long long alpha);//极大值搜索
	long long Min(CheckerNode & node, int depth, long long beta);//极小值搜索
	void setCurNode(CheckerNode node) {//设置初始的棋盘状态节点
		curNode = node;
	}
private:
	CheckerNode curNode;//当前棋盘状态节点 用作搜索的根节点
	PiecePosition bestPosition;//搜索得出的最好的下棋位置
	long long CalcNumOfContinuePiece(vector<int>& vec);//通过一个数组计算估价分数
	bool isMax;//是否处在Max层
	int depth;//搜索深度
};
