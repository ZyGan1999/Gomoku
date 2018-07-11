#pragma once
class PiecePosition//表示一个棋子的位置
{
public:
	PiecePosition(int x, int y) { xx = x; yy = y; }
	PiecePosition(const PiecePosition & ps);//复制构造
	int getX() { return xx; }
	int getY() { return yy; }
	void setX(int x) { xx = x; }
	void setY(int y) { yy = y; }
	~PiecePosition();
private:
	int xx; int yy;
};

