#pragma once
class PiecePosition
{
public:
	PiecePosition(int x, int y) { xx = x; yy = y; }
	PiecePosition(const PiecePosition & ps);
	int getX() { return xx; }
	int getY() { return yy; }
	void setX(int x) { xx = x; }
	void setY(int y) { yy = y; }
	~PiecePosition();
private:
	int xx; int yy;
};

