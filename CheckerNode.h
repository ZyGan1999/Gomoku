#pragma once
#include "CheckerState.h"
class CheckerNode
{
public:
	CheckerNode();
	CheckerNode(CheckerState st);
	CheckerNode(const CheckerNode & ck);
	CheckerNode createChdByPutPiece(PiecePosition p,bool isblack);//通过在(x,y)坐标处下子生成子节点
	CheckerState & getState() {
		return _state;
	}
	~CheckerNode();
private:
	CheckerState _state;

};

