#include "PiecePosition.h"


PiecePosition::PiecePosition(const PiecePosition & ps)
{
	this->xx = ps.xx;
	this->yy = ps.yy;
}

PiecePosition::~PiecePosition()
{
}
