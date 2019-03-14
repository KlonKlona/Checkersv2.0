#include <iostream>
#include <cstdio>
#include "chequer.h"
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <ctime>

using namespace sf;

void check_queen_move(char **board, Move play, int bsize, bool WhiteTurn) {
if(play.queen == true) {
    int count = 0;
    int x = play.end.first;
    int y = play.end.second;
    if(board[x][y] == 'W') {
        while(play.end.first - play.start.first == -1 && play.end.second - play.start.second == -1 && count < 10) {
                    count ++;
            if (x > 0 && y > 0 && board[x - 1][y - 1] == '-') {
                do_move(board, Move(x, y, x-1, y-1, false, true, false));
                x--;
                y--;

            }
            if (x > 1 && y > 1 && board[x - 1][y - 1] == 'b' && board[x - 2][y - 2] == '-') {
                    do_move(board, Move(x, y, x-2, y-2, false, true, false));
                x -= 2;
                y -= 2;
                }
            if (x > 1 && y > 1 && board[x - 1][y - 1] == 'B' && board[x - 2][y - 2] == '-') {
                    do_move(board, Move(x, y, x-2, y-2, true, true, true));
                x -= 2;
                y -= 2;
                }
        }
        while(play.end.first - play.start.first == -1 && play.end.second - play.start.second == 1 && count < 10) {
                    count ++;
            if (x > 0 && y < bsize - 1 && board[x - 1][y + 1] == '-') {
                    do_move(board, Move(x, y, x-1, y+1, false, true, false));
                x--;
                y++;
            }
            if (x > 0 && y < bsize - 1 && board[x - 1][y + 1] == 'b' && board[x - 2][y + 2] == '-') {
                    do_move(board, Move(x, y, x-2, y+2, true, true, false));
                x -= 2;
                y += 2;
            }
            if (x > 0 && y < bsize - 1 && board[x - 1][y + 1] == 'B' && board[x - 2][y + 2] == '-') {
                    do_move(board, Move(x, y, x-2, y+2, true, true, true));
                x -= 2;
                y += 2;
            }
        }
        while(play.end.first - play.start.first == 1 && play.end.second - play.start.second == -1 && count < 10) {
                    count ++;
            if (x < bsize - 1 && y > 0 && board[x + 1][y - 1] == '-') {
                    do_move(board, Move(x, y, x+1, y-1, false, true, false));
                x++;
                y--;
            }
            if (x < bsize - 1 && y > 1 && board[x + 1][y - 1] == 'b' && board[x + 2][y - 2] == '-') {
                    do_move(board, Move(x, y, x+2, y-2, true, true, false));
                x += 2;
                y -= 2;
            }
            if (x < bsize - 1 && y > 1 && board[x + 1][y - 1] == 'B' && board[x + 2][y - 2] == '-') {
                    do_move(board, Move(x, y, x+2, y-2, true, true, true));
                x += 2;
                y -= 2;
            }
        }
        while(play.end.first - play.start.first == 1 && play.end.second - play.start.second == 1 && count < 10) {
                    count ++;
            if (x < bsize - 1 && y < bsize - 1 && board[x + 1][y + 1] == '-') {
                    do_move(board, Move(x, y, x+1, y+1, false, true, false));
                x++;
                y++;
            }
            if (x < bsize - 2 && y < bsize - 2 && board[x + 1][y + 1] == 'b' && board[x + 2][y + 2] == '-') {
                    do_move(board, Move(x, y, x+2, y+2, true, true, false));
                x += 2;
                y += 2;
            }
            if (x < bsize - 2 && y < bsize - 2 && board[x + 1][y + 1] == 'B' && board[x + 2][y + 2] == '-') {
                    do_move(board, Move(x, y, x+2, y+2, true, true, true));
                x += 2;
                y += 2;
            }
        }
    }
    if(board[x][y] == 'B') {
        while(play.end.first - play.start.first == -1 && play.end.second - play.start.second == -1 && count < 10) {
                    count ++;
            if (x > 0 && y > 0 && board[x - 1][y - 1] == '-') {
                    do_move(board, Move(x, y, x-1, y-1, false, true, false));
                x--;
                y--;
            }
            if (x > 1 && y > 1 && board[x - 1][y - 1] == 'w' && board[x - 2][y - 2] == '-') {
                    do_move(board, Move(x, y, x-2, y-2, false, true, false));
                x -= 2;
                y -= 2;
                }
            if (x > 1 && y > 1 && board[x - 1][y - 1] == 'W' && board[x - 2][y - 2] == '-') {
                    do_move(board, Move(x, y, x-2, y-2, true, true, true));
                x -= 2;
                y -= 2;
                }
        }
        while(play.end.first - play.start.first == -1 && play.end.second - play.start.second == 1 && count < 10) {
                    count ++;
            if (x > 0 && y < bsize - 1 && board[x - 1][y + 1] == '-') {
                    do_move(board, Move(x, y, x-1, y+1, false, true, false));
                x--;
                y++;
            }
            if (x > 0 && y < bsize - 1 && board[x - 1][y + 1] == 'w' && board[x - 2][y + 2] == '-') {
                    do_move(board, Move(x, y, x-2, y+2, true, true, false));
                x -= 2;
                y += 2;
            }
            if (x > 0 && y < bsize - 1 && board[x - 1][y + 1] == 'W' && board[x - 2][y + 2] == '-') {
                    do_move(board, Move(x, y, x-2, y+2, true, true, true));
                x -= 2;
                y += 2;
            }
        }
        while(play.end.first - play.start.first == 1 && play.end.second - play.start.second == -1 && count < 10) {
                    count ++;
            if (x < bsize - 1 && y > 0 && board[x + 1][y - 1] == '-') {
                    do_move(board, Move(x, y, x+1, y-1, false, true, false));
                x++;
                y--;
            }
            if (x < bsize - 1 && y > 1 && board[x + 1][y - 1] == 'w' && board[x + 2][y - 2] == '-') {
                    do_move(board, Move(x, y, x+2, y-2, true, true, false));
                x += 2;
                y -= 2;
            }
            if (x < bsize - 1 && y > 1 && board[x + 1][y - 1] == 'W' && board[x + 2][y - 2] == '-') {
                    do_move(board, Move(x, y, x+2, y-2, true, true, true));
                x += 2;
                y -= 2;
            }
        }
        while(play.end.first - play.start.first == 1 && play.end.second - play.start.second == 1 && count < 10) {
                    count ++;
            if (x < bsize - 1 && y < bsize - 1 && board[x + 1][y + 1] == '-') {
                    do_move(board, Move(x, y, x+1, y+1, false, true, false));
                x++;
                y++;
            }
            if (x < bsize - 2 && y < bsize - 2 && board[x + 1][y + 1] == 'w' && board[x + 2][y + 2] == '-') {
                    do_move(board, Move(x, y, x+2, y+2, true, true, false));
                x += 2;
                y += 2;
            }
            if (x < bsize - 2 && y < bsize - 2 && board[x + 1][y + 1] == 'W' && board[x + 2][y + 2] == '-') {
                    do_move(board, Move(x, y, x+2, y+2, true, true, true));
                x += 2;
                y += 2;
            }
        }
    }
}
}

void first_move(char **board, bool whiteTurn) {
    srand( time( NULL ) );
    std::vector<Move> moves;
    if (whiteTurn == true) {
        moves.push_back(Move(2, 1, 3, 0, false, false, false));
        moves.push_back(Move(2, 1, 3, 2, false, false, false));
        moves.push_back(Move(2, 3, 3, 2, false, false, false));
        moves.push_back(Move(2, 3, 3, 4, false, false, false));
        moves.push_back(Move(2, 5, 3, 3, false, false, false));
        moves.push_back(Move(2, 5, 3, 6, false, false, false));
        moves.push_back(Move(2, 7, 3, 6, false, false, false));
    }
    else {
        moves.push_back(Move(5, 0, 4, 1, false, false, false));
        moves.push_back(Move(5, 2, 4, 1, false, false, false));
        moves.push_back(Move(5, 2, 4, 3, false, false, false));
        moves.push_back(Move(5, 4, 4, 3, false, false, false));
        moves.push_back(Move(5, 4, 4, 5, false, false, false));
        moves.push_back(Move(5, 6, 4, 5, false, false, false));
        moves.push_back(Move(5, 6, 4, 7, false, false, false));
    }
    int i = std::rand() % 8;
    do_move(board, moves[i]);
}

void printBoard(char **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Move::show_move() {
    std::cout << "[ " << this->start.first << " , " << this->start.second << " ]" << std::endl;
    std::cout << "[ " << this->end.first << " , " << this->end.second << " ]" << std::endl;
    std::cout << "letalny: " << this->lethal << std::endl;
    std::cout << "wykonany przez damke: " << this->queen << std::endl;
    std::cout << "letalny dla damki: " << this->queen_lethal << std::endl;
}

void newGame(char **board, int bsize)
{
    for(int i = 0 ; i < bsize ; i++)
        for(int j = 0 ; j < bsize ; j++)
        {
            board[i][j] = '-';
            if((i == 0 || i == 2) && j % 2 == 1) board[i][j] = 'w';
            if(i == 1 && j % 2 == 0 ) board[i][j] = 'w';
            if((i == bsize - 3 || i == bsize - 1) && j % 2 == 0) board[i][j] = 'b';
            if(i == bsize - 2 && j % 2 == 1) board[i][j] = 'b';
        }
    return;
}

void copy_board(char **source, char **dest, int bsize) {
    for(int i = 0 ; i < bsize ; i++)
        for(int j = 0 ; j < bsize ; j++) {
            dest[i][j] = source[i][j];
        }
}

char** initBoard(int bsize)
{
    char **board = new char*[bsize];
    for(int i = 0; i < bsize ; i++)
        board[i] = new char[bsize];
    return board;
}

void do_move (char **board, Move play)
{
    char temp = board[play.start.first][play.start.second];
    board[play.start.first][play.start.second] = board[play.end.first][play.end.second];
    board[play.end.first][play.end.second] = temp;
    if(play.lethal)
    {
        if(play.end.first - play.start.first > 0 && play.end.second - play.start.second > 0)
            board[(play.end.first - 1)][(play.end.second - 1)] = '-';
        if(play.end.first - play.start.first > 0 && play.end.second - play.start.second < 0)
            board[(play.end.first - 1)][(play.end.second + 1)] = '-';
        if(play.end.first - play.start.first < 0 && play.end.second - play.start.second > 0)
            board[(play.end.first + 1)][(play.end.second - 1)] = '-';
        if(play.end.first - play.start.first < 0 && play.end.second - play.start.second < 0)
            board[(play.end.first + 1)][(play.end.second + 1)] = '-';
    }
}

void undo_move(char **board, Move play)
{
    board[play.start.first][play.start.second] = board[play.end.first][play.end.second];
    board[play.end.first][play.end.second] = '-';
    if (play.lethal)
    {
        if(play.queen == false && play.queen_lethal == false) {
            if (board[play.start.first][play.start.second] == 'b')
                board[(play.end.first + play.start.first) / 2][(play.end.second + play.start.second) / 2] = 'w';
            if (board[play.start.first][play.start.second] == 'w')
                board[(play.end.first + play.start.first) / 2][(play.end.second + play.start.second) / 2] = 'b';
        }
        if(play.queen == true && play.queen_lethal == false) {
            if (board[play.start.first][play.start.second] == 'B') {
                if(play.end.first - play.start.first > 0 && play.end.second - play.start.second > 0)
                    board[(play.end.first - 1)][(play.end.second - 1)] = 'w';
                if(play.end.first - play.start.first > 0 && play.end.second - play.start.second < 0)
                    board[(play.end.first - 1)][(play.end.second + 1)] = 'w';
                if(play.end.first - play.start.first < 0 && play.end.second - play.start.second > 0)
                    board[(play.end.first + 1)][(play.end.second - 1)] = 'w';
                if(play.end.first - play.start.first < 0 && play.end.second - play.start.second < 0)
                    board[(play.end.first + 1)][(play.end.second + 1)] = 'w';
            }
            if (board[play.start.first][play.start.second] == 'W') {
                if(play.end.first - play.start.first > 0 && play.end.second - play.start.second > 0)
                    board[(play.end.first - 1)][(play.end.second - 1)] = 'b';
                if(play.end.first - play.start.first > 0 && play.end.second - play.start.second < 0)
                    board[(play.end.first - 1)][(play.end.second + 1)] = 'b';
                if(play.end.first - play.start.first < 0 && play.end.second - play.start.second > 0)
                    board[(play.end.first + 1)][(play.end.second - 1)] = 'b';
                if(play.end.first - play.start.first < 0 && play.end.second - play.start.second < 0)
                    board[(play.end.first + 1)][(play.end.second + 1)] = 'b';
            }
        }
        if(play.queen == true && play.queen_lethal == true) {
            if (board[play.start.first][play.start.second] == 'B') {
                if(play.end.first - play.start.first > 0 && play.end.second - play.start.second > 0)
                    board[(play.end.first - 1)][(play.end.second - 1)] = 'W';
                if(play.end.first - play.start.first > 0 && play.end.second - play.start.second < 0)
                    board[(play.end.first - 1)][(play.end.second + 1)] = 'W';
                if(play.end.first - play.start.first < 0 && play.end.second - play.start.second > 0)
                    board[(play.end.first + 1)][(play.end.second - 1)] = 'W';
                if(play.end.first - play.start.first < 0 && play.end.second - play.start.second < 0)
                    board[(play.end.first + 1)][(play.end.second + 1)] = 'W';
            }
            if (board[play.start.first][play.start.second] == 'W') {
                if(play.end.first - play.start.first > 0 && play.end.second - play.start.second > 0)
                    board[(play.end.first - 1)][(play.end.second - 1)] = 'B';
                if(play.end.first - play.start.first > 0 && play.end.second - play.start.second < 0)
                    board[(play.end.first - 1)][(play.end.second + 1)] = 'B';
                if(play.end.first - play.start.first < 0 && play.end.second - play.start.second > 0)
                    board[(play.end.first + 1)][(play.end.second - 1)] = 'B';
                if(play.end.first - play.start.first < 0 && play.end.second - play.start.second < 0)
                    board[(play.end.first + 1)][(play.end.second + 1)] = 'B';
            }
        }
    }
}

void check_for_queens(char **board, int bsize) {
  for(int i = 0 ; i < bsize ; i++) {
    for(int j = 0 ; j < bsize ; j++) {
        if(i==0 && board[i][j] == 'b') board[i][j] = 'B';
        if(i==bsize - 1 && board[i][j] == 'w') board[i][j] = 'W';
    }
  }
}

vector<Move> findMoves(char **board, int bsize, bool whiteTurn)
{
    vector<Move> moves;
    //first jump (if possible)
    for (int x = 0; x < bsize; x++)
    {
        for (int y = 0; y < bsize; y++)
        {
            if (!whiteTurn && board[x][y] == 'B')
            {
                for ( int i = 1 ; i < bsize - 1 ; i++) {
                    if (x - i > 0 && y - i > 0) {
                    if (x > 1 && y > 1 && board[x - i][y - i] == 'w' && board[x - i - 1][y - i - 1] == '-')
                        moves.push_back(Move(x, y, x - i - 1, y - i - 1, true, true, false));
                        continue;
                    }
                    if (x - i > 0 && y + i < 7) {
                    if (x > 1 && y < bsize - 2 && board[x - i][y + i] == 'w' && board[x - i - 1][y + i + 1] == '-')
                        moves.push_back(Move(x, y, x - i - 1, y + i + 1, true, true, false));
                        continue;
                    }
                    if (x + i < 7 && y - i > 0) {
                    if (x < bsize - 2 && y > 1 && board[x + i][y - i] == 'w' && board[x + i + 1][y - i - 1] == '-')
                        moves.push_back(Move(x, y, x + i + 1, y - i - 1, true, true, false));
                        continue;
                    }
                    if (x + i < 7 && y + i < 7) {
                    if (x < bsize - 2 && y < bsize - 2 && board[x + i][y + i] == 'w' && board[x + i + 1][y + i + 1] == '-')
                        moves.push_back(Move(x, y, x + i + 1, y + i + 1, true, true, false));
                        continue;
                    }
                    if (x - i > 0 && y - i > 0) {
                    if (x > 1 && y > 1 && board[x - i][y - i] == 'W' && board[x - i - 1][y - i - 1] == '-')
                        moves.push_back(Move(x, y, x - i - 1, y - i - 1, true, true, true));
                        continue;
                    }
                    if (x - i > 0 && y + i < 7) {
                    if (x > 1 && y < bsize - 2 && board[x - i][y + i] == 'W' && board[x - i - 1][y + i + 1] == '-')
                        moves.push_back(Move(x, y, x - i - 1, y + i + 1, true, true, true));
                        continue;
                    }
                    if (x + i < 7 && y - i > 0) {
                    if (x < bsize - 2 && y > 1 && board[x + i][y - i] == 'W' && board[x + i + 1][y - i - 1] == '-')
                        moves.push_back(Move(x, y, x + i + 1, y - i - 1, true, true, true));
                        continue;
                    }
                    if (x + i < 7 && y + i < 7) {
                    if (x < bsize - 2 && y < bsize - 2 && board[x + i][y + i] == 'W' && board[x + i + 1][y + i + 1] == '-')
                        moves.push_back(Move(x, y, x + i + 1, y + i + 1, true, true, true));
                        continue;
                    }
                }
            }
            if (whiteTurn && board[x][y] == 'W')
            {
                for ( int i = 1 ; i < bsize - 1 ; i++) {
                    if (x - i > 0 && y - i > 0) {
                    if (x > 1 && y > 1 && board[x - i][y - i] == 'b' && board[x - i - 1][y - i - 1] == '-')
                        moves.push_back(Move(x, y, x - i - 1, y - i - 1, true, true, false));
                        continue;
                    }
                    if (x - i > 0 && y + i < 7) {
                    if (x > 1 && y < bsize - 2 && board[x - i][y + i] == 'b' && board[x - i - 1][y + i + 1] == '-')
                        moves.push_back(Move(x, y, x - i - 1, y + i + 1, true, true, false));
                        continue;
                    }
                    if (x + i < 7 && y - i > 0) {
                    if (x < bsize - 2 && y > 1 && board[x + i][y - i] == 'b' && board[x + i + 1][y - i - 1] == '-')
                        moves.push_back(Move(x, y, x + i + 1, y - i - 1, true, true, false));
                        continue;
                    }
                    if (x + i < 7 && y + i < 7) {
                    if (x < bsize - 2 && y < bsize - 2 && board[x + i][y + i] == 'b' && board[x + i + 1][y + i + 1] == '-')
                        moves.push_back(Move(x, y, x + i + 1, y + i + 1, true, true, false));
                        continue;
                    }
                    if (x - i > 0 && y - i > 0) {
                    if (x > 1 && y > 1 && board[x - i][y - i] == 'B' && board[x - i - 1][y - i - 1] == '-')
                        moves.push_back(Move(x, y, x - i - 1, y - i - 1, true, true, true));
                        continue;
                    }
                    if (x - i > 0 && y + i < 7) {
                    if (x > 1 && y < bsize - 2 && board[x - i][y + i] == 'B' && board[x - i - 1][y + i + 1] == '-')
                        moves.push_back(Move(x, y, x - i - 1, y + i + 1, true, true, true));
                        continue;
                    }
                    if (x + i < 7 && y - i > 0) {
                    if (x < bsize - 2 && y > 1 && board[x + i][y - i] == 'B' && board[x + i + 1][y - i - 1] == '-')
                        moves.push_back(Move(x, y, x + i + 1, y - i - 1, true, true, true));
                        continue;
                    }
                    if (x + i < 7 && y + i < 7) {
                    if (x < bsize - 2 && y < bsize - 2 && board[x + i][y + i] == 'B' && board[x + i + 1][y + i + 1] == '-')
                        moves.push_back(Move(x, y, x + i + 1, y + i + 1, true, true, true));
                        continue;
                    }
                }
            }
            if (!whiteTurn && board[x][y] == 'b')
            {
                if (x > 1 && y > 1 && board[x - 1][y - 1] == 'w' && board[x - 2][y - 2] == '-')
                    moves.push_back(Move(x, y, x - 2, y - 2, true, false, false));
                if (x > 1 && y < bsize - 2 && board[x - 1][y + 1] == 'w' && board[x - 2][y + 2] == '-')
                    moves.push_back(Move(x, y, x - 2, y + 2, true, false, false));
                if (x < bsize - 2 && y > 1 && board[x + 1][y - 1] == 'w' && board[x + 2][y - 2] == '-')
                    moves.push_back(Move(x, y, x + 2, y - 2, true, false, false));
                if (x < bsize - 2 && y < bsize - 2 && board[x + 1][y + 1] == 'w' && board[x + 2][y + 2] == '-')
                    moves.push_back(Move(x, y, x + 2, y + 2, true, false, false));
                if (x > 1 && y > 1 && board[x - 1][y - 1] == 'W' && board[x - 2][y - 2] == '-')
                    moves.push_back(Move(x, y, x - 2, y - 2, true, false, true));
                if (x > 1 && y < bsize - 2 && board[x - 1][y + 1] == 'W' && board[x - 2][y + 2] == '-')
                    moves.push_back(Move(x, y, x - 2, y + 2, true, false, true));
                if (x < bsize - 2 && y > 1 && board[x + 1][y - 1] == 'W' && board[x + 2][y - 2] == '-')
                    moves.push_back(Move(x, y, x + 2, y - 2, true, false, true));
                if (x < bsize - 2 && y < bsize - 2 && board[x + 1][y + 1] == 'W' && board[x + 2][y + 2] == '-')
                    moves.push_back(Move(x, y, x + 2, y + 2, true, false, true));
            }
            if (whiteTurn && board[x][y] == 'w')
            {
                if (x > 1 && y > 1 && board[x - 1][y - 1] == 'b' && board[x - 2][y - 2] == '-')
                    moves.push_back(Move(x, y, x - 2, y - 2, true, false, false));
                if (x > 1 && y < bsize - 2 && board[x - 1][y + 1] == 'b' && board[x - 2][y + 2] == '-')
                    moves.push_back(Move(x, y, x - 2, y + 2, true, false, false));
                if (x < bsize - 2 && y > 1 && board[x + 1][y - 1] == 'b' && board[x + 2][y - 2] == '-')
                    moves.push_back(Move(x, y, x + 2, y - 2, true, false, false));
                if (x < bsize - 2 && y < bsize - 2 && board[x + 1][y + 1] == 'b' && board[x + 2][y + 2] == '-')
                    moves.push_back(Move(x, y, x + 2, y + 2, true, false, false));
                if (x > 1 && y > 1 && board[x - 1][y - 1] == 'B' && board[x - 2][y - 2] == '-')
                    moves.push_back(Move(x, y, x - 2, y - 2, true, false, true));
                if (x > 1 && y < bsize - 2 && board[x - 1][y + 1] == 'B' && board[x - 2][y + 2] == '-')
                    moves.push_back(Move(x, y, x - 2, y + 2, true, false, true));
                if (x < bsize - 2 && y > 1 && board[x + 1][y - 1] == 'B' && board[x + 2][y - 2] == '-')
                    moves.push_back(Move(x, y, x + 2, y - 2, true, false, true));
                if (x < bsize - 2 && y < bsize - 2 && board[x + 1][y + 1] == 'B' && board[x + 2][y + 2] == '-')
                    moves.push_back(Move(x, y, x + 2, y + 2, true, false, true));
            }
        }
    }
    //then move
    for (int x = 0; x < bsize; x++)
    {
        for (int y = 0; y < bsize; y++)
        {
            if (!whiteTurn && board[x][y] == 'b')
            {
                if (x > 0 && y > 0 && board[x - 1][y - 1] == '-')
                    moves.push_back(Move(x, y, x - 1, y - 1, false, false, false));
                if (x > 0 && y < bsize - 1 && board[x - 1][y + 1] == '-')
                    moves.push_back(Move(x, y, x - 1, y + 1, false, false, false));
            }
            if (!whiteTurn && board[x][y] == 'B')
            {
                for ( int i = 1 ; i < bsize - 1 ; i++ ) {
                    if (x - i > -1 && y - i > -1) {
                    if (x > 0 && y > 0 && board[x - i][y - i] == '-')
                        moves.push_back(Move(x, y, x - i, y - i, false, true, false));
                    }
                    if (x - i > -1 && y + i < 8) {
                    if (x > 0 && y < bsize - 1 && board[x - i][y + i] == '-')
                        moves.push_back(Move(x, y, x - i, y + i, false, true, false));
                    }
                    if (x + i < 8 && y - i > -1) {
                    if (x < bsize - 1 && y > 0 && board[x + i][y - i] == '-')
                        moves.push_back(Move(x, y, x + i, y - i, false, true, false));
                    }
                    if (x + i < 8 && y + i < 8) {
                    if (x < bsize - 1 && y < bsize - 1 && board[x + i][y + i] == '-')
                        moves.push_back(Move(x, y, x + i, y + i, false, true, false));
                    }
                }
            }
            if (whiteTurn && board[x][y] == 'w')
            {
                if (x < bsize - 1 && y > 0 && board[x + 1][y - 1] == '-')
                    moves.push_back(Move(x, y, x + 1, y - 1, false, false, false));
                if (x < bsize - 1 && y < bsize - 1 && board[x + 1][y + 1] == '-')
                    moves.push_back(Move(x, y, x + 1, y + 1, false, false, false));
            }
            if (whiteTurn && board[x][y] == 'W')
            {
                for ( int i = 1 ; i < bsize - 1 ; i++ ) {
                    if (x - i > -1 && y - i > -1) {
                    if (x > 0 && y > 0 && board[x - i][y - i] == '-')
                        moves.push_back(Move(x, y, x - i, y - i, false, true, false));
                    }
                    if (x - i > -1 && y + i < 8) {
                    if (x > 0 && y < bsize - 1 && board[x - i][y + i] == '-')
                        moves.push_back(Move(x, y, x - i, y + i, false, true, false));
                    }
                    if (x + i < 8 && y - i > -1) {
                    if (x < bsize - 1 && y > 0 && board[x + i][y - i] == '-')
                        moves.push_back(Move(x, y, x + i, y - i, false, true, false));
                    }
                    if (x + i < 8 && y + i < 8) {
                    if (x < bsize - 1 && y < bsize - 1 && board[x + i][y + i] == '-')
                        moves.push_back(Move(x, y, x + i, y + i, false, true, false));
                    }
                }
            }
        }
    }
    //std::random_shuffle( moves.begin(), moves.end() );
    return moves;
}

int getScore(char **board, int bsize, bool whiteTurn)
{
    int whiteNum = 0, blackNum = 0;

    for (int i = 0; i < bsize; i++)
    {
        for (int j = 0; j < bsize; j++)
        {
            if (board[i][j] == 'b') blackNum++;
            if (board[i][j] == 'w') whiteNum++;
            if (board[i][j] == 'B') blackNum += 3;
            if (board[i][j] == 'W') whiteNum += 3;
        }
    }

    if (whiteTurn)
        return whiteNum - blackNum;
    else
        return blackNum - whiteNum;
}
