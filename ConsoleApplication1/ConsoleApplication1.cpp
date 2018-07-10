
#include "SearchSolver.h"
using namespace std;
int main()
{
	SearchSolver s;
	CheckerNode n;
	n = n.createChdByPutPiece(PiecePosition(5, 5), false);
	n = n.createChdByPutPiece(PiecePosition(5, 6), false);
	n = n.createChdByPutPiece(PiecePosition(5, 7), false);
	n = n.createChdByPutPiece(PiecePosition(3, 4), true);
	n = n.createChdByPutPiece(PiecePosition(3, 5), true);
	n = n.createChdByPutPiece(PiecePosition(5, 4), true);
	s.CalcNodeScore(n);
	//vector<int> test({ 3, 0, 0, -1, -1, -1, 0, 3 });
	//s.CalcNumOfContinuePiece(test);
    return 0;
}

