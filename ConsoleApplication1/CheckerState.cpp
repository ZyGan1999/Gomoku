#include "CheckerState.h"
#include <algorithm>
#include <vector>
using namespace std;

CheckerState::CheckerState()
{
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			_pieces[i][j] = 0;
		}
	}
}

CheckerState::CheckerState(const CheckerState & st)
{
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			_pieces[i][j] = st._pieces[i][j];
		}
	}
}


CheckerState::~CheckerState()
{
}

void CheckerState::putPiece(PiecePosition p, bool isBlack)
{
	_pieces[p.getX()][p.getY()] = isBlack ? 1 : -1;
}

bool CheckerState::canPutPiece(int x, int y)
{
	return _pieces[x][y] == 0;
}
bool CheckerState::isNeighborPiece(int x, int y)
{
	int x_inf = std::max(x - 1, 0);
	int y_inf = std::max(y - 1, 0);
	int x_sup = std::min(x + 1, 18);
	int y_sup = std::min(y + 1, 18);
	for (int i = x_inf; i <= x_sup; i++) {
		for (int j = y_inf; j <= y_sup; j++) {
			if (i == x && j == y) continue;
			if (_pieces[i][j] != 0) return true;
		}
	}
	return false;
}
vector<vector<int>> CheckerState::getChecker()
{
	vector<vector<int>> judges;
	for (int i = 0; i < 19; i++) {
		vector<int> curRow;
		vector<int> curLine;
		curRow.push_back(3);
		curLine.push_back(3);
		for (int j = 0; j < 19; j++) {
			int x1 = _pieces[i][j];
			int x2 = _pieces[j][i];
			curRow.push_back(x1);
			curLine.push_back(x2);
		}
		curRow.push_back(3);
		curLine.push_back(3);
		judges.push_back(curRow);
		judges.push_back(curLine);
	}
	for (int i = 0; i < 19; ++i)
	{
		int x, y;
		vector<int> n;
		n.push_back(3);
		for (x = i, y = 0; x < 19 && y < 19; ++x, ++y) {
			n.push_back(_pieces[y][x]);
		}
		n.push_back(3);
		judges.push_back(n);
	}
	for (int j = 1; j < 19; ++j)
	{
		int x, y;
		vector<int> n;
		n.push_back(3);
		for (x = 0, y = j; y<19 && x<19; ++x, ++y)
			n.push_back(_pieces[y][x]);
		n.push_back(3);
		judges.push_back(n);
	}
	//上半反斜线们
	for (int i = 0; i<19; ++i)
	{
		vector<int> n;
		int x, y;
		n.push_back(3);
		for (y = i, x = 0; y >= 0 && x<19; --y, ++x)
			n.push_back(_pieces[y][x]);
		n.push_back(3);
		judges.push_back(n);
	}
	//下半反斜线们
	for (int j = 1; j<19; ++j)
	{
		vector<int> n;
		int x, y;
		n.push_back(3);
		for (y = j, x = 18; y<19 && x >= 0; ++y, --x)
			n.push_back(_pieces[x][y]);
		n.push_back(3);
		judges.push_back(n);
	}

	return judges;
}
