#include "CheckerNode.h"

CheckerNode::CheckerNode():_state()
{
}

CheckerNode::CheckerNode(CheckerState st) :_state(st){}

CheckerNode::CheckerNode(const CheckerNode & ck):_state(ck._state){}

CheckerNode CheckerNode::createChdByPutPiece(PiecePosition p, bool isblack)
{
	CheckerNode child = (*this);
	child._state.putPiece(p, isblack);
	return child;
}


CheckerNode::~CheckerNode(){}
