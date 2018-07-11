#pragma once
#include "CheckerNode.h"
#include <stack>
using namespace std;
class SearchSolver
{
public:
	SearchSolver();
	~SearchSolver();
	void init(int checkerX, int checkerY, int numToWin, bool isBlack);//�ù��������ʼ�� ���̳�����Ҫ�����������Ƿ��ںڲ�
	PiecePosition putPiece(int depth);//�ü���Сֵ�����ó��˲�������������
	long long CalcNodeScore(CheckerNode & node);//�������̽ڵ㵱ǰ��������ֵ
	long long Max(CheckerNode & node, int depth, long long alpha);//����ֵ����
	long long Min(CheckerNode & node, int depth, long long beta);//��Сֵ����
	void setCurNode(CheckerNode node) {//���ó�ʼ������״̬�ڵ�
		curNode = node;
	}
private:
	CheckerNode curNode;//��ǰ����״̬�ڵ� ���������ĸ��ڵ�
	PiecePosition bestPosition;//�����ó�����õ�����λ��
	long long CalcNumOfContinuePiece(vector<int>& vec);//ͨ��һ�����������۷���
	bool isMax;//�Ƿ���Max��
	int depth;//�������
};
