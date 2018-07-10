//by liang_jk
#include<boardwindow.h>

/*
 * You need to complete this function.
 *
 * The first parameter you've got describes a board,
 * you can use "at(x,y)" to know whether there is a stone at (x,y) and what color it is.
 *
 * You can use "board_size" as a const number. Actually it has been defined as 19.
 *
 * If it returns 0, it means there is a stone belongs to you.
 * If it returns 1, it means there is a stone belongs to the player.
 * If it returns -1, it means there is no stone.
 * If it returns -2, it means the position is invalid.
 *
 * After you decide where to put your stone, please use "make_move" function.
 * Use it like this "Game->make_move(x,y)" if you decide to put your stone at (x,y).
 *
 * The coordinates begin from 0.
 * Make sure the coordinate you give is valid, or the application will crash!!!
 *
 * Here is a example for you with a random algorithm.
*/

// Include headers you need here.
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "SearchSolver.h"

void solve(const Board& board,BoardWindow*Game)
{
	SearchSolver s;
	CheckerNode n;
	for(int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
		{
			int k = board.at(i, j);
			if (k == -1) continue;
			n = n.createChdByPutPiece(PiecePosition(i, j), (k == 0));
		}
	s.setCurNode(n);
	auto p = s.putPiece(2);
    //Remember to recall "make_move" function.
    Game->make_move(p.getX(), p.getY());
}
