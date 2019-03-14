#pragma once
#include "game_check.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>

class Move
{
public:
    pair<int, int> start;
    pair<int, int> end;
    bool lethal;
    bool queen;
    bool queen_lethal;

    Move(int x, int y, int x1, int y1, bool kill, bool q, bool q_l)
    {
        start.first = x; start.second = y;
        end.first = x1; end.second = y1;
        lethal = kill;
        queen = q;
        queen_lethal = q_l;
    }

    void show_move();

    Move& operator= (const Move& move) {
        if (this == &move) return *this;
        this->start.first = move.start.first;
        this->start.second = move.start.second;
        this->end.first = move.end.first;
        this->end.second = move.end.second;
        this->lethal = move.lethal;
        this->queen = move.queen;
        this->queen_lethal = move.queen_lethal;
        return *this;
    }

    bool operator==(const Move &move) {
        if( this->start.first == move.start.first ) {
            //std::cout << "1 zgadza sie" << std::endl;
            if( this->start.second == move.start.second )
                //std::cout << "2 zgadza sie" << std::endl;
                if( this->end.first == move.end.first ) {
                    //std::cout << "3 zgadza sie" << std::endl;
                    if( this->end.second == move.end.second) {
                        //std::cout << "4 zgadza sie" << std::endl;
                        if( this->lethal == move.lethal) {
                            //std::cout << "5 zgadza sie" << std::endl;
                            if( this->queen == move.queen) {
                                //std::cout << "6 zgadza sie" << std::endl;
                                return ( this->queen_lethal == move.queen_lethal);
                            }
                        }
                    }
                }
            }

        return false;
    }
};
    void first_move(char **board, bool whiteTurn);
    void check_queen_move(char **board, Move play, int bsize, bool WhiteTurn);
    void copy_board(char **source, char **dest, int bsize);
    void newGame(char **board, int bsize);
    char **initBoard(int bsize);
    void display_board(char **board);
    void display_board_graphics(char **board);
    void do_move (char **board, Move play);
    void undo_move(char **board, Move play);
    int getScore(char **board, int bsize, bool whiteTurn);
    vector<Move> findMoves(char **board, int bsize, bool whiteTurn);
    int alphabeta(char **board, int bsize, bool whiteTurn, int depth, int alpha, int beta);
    void game(char **board, int bsize, bool &whiteTurn);
    void check_for_queens(char **board, int bsize);
    void printBoard(char **board, int size);

