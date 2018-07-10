#pragma once
#include "CheckerState.h"
class CheckerNode
{
public:
	CheckerNode();
	CheckerNode(CheckerState st);
	CheckerNode(const CheckerNode & ck);
	CheckerNode createChdByPutPiece(PiecePosition p,bool isblack);//ͨ����(x,y)���괦���������ӽڵ�
	CheckerState & getState() {
		return _state;
	}
	~CheckerNode();
private:
	CheckerState _state;

};

