#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "chequer.h"
#include "block.h"
#include "blockContainer.h"
#include "Menu.h"

using namespace std;
using namespace sf;

Move *bestMove = new Move(0, 0, 0, 0, false, false, false);

int negamax(char **board, int bsize, int depth, int a, int b, bool whiteTurn)
{
    char **temp = initBoard(8);
    copy_board(board, temp, 8);
    if (depth == 0) {
        return getScore(temp, bsize, whiteTurn);
    }
    std::vector<Move> possibleMoves;
    possibleMoves = findMoves(temp, bsize, whiteTurn);
    for (const Move &move : possibleMoves) {
        do_move(temp, move);
        a = std::max(a, -negamax(temp, bsize, depth - 1, -b, -a, !whiteTurn));
        //undo_move(temp, move);
        if (b <= a)
            return b; // β cutoff.
    }
    return a;
}

int alphabeta(char **board, int bsize, bool whiteTurn, int depth, int alpha, int beta)
{
    std::vector<Move> possibleMoves;
    possibleMoves = findMoves(board, bsize, whiteTurn);

    int a = -std::numeric_limits<int>::max();
    int b = std::numeric_limits<int>::max();
    for (const Move &move : possibleMoves) {
        int v = negamax(board, bsize, depth, a, b, whiteTurn);
        if (v > a) {
            a = v;
            *bestMove = move;
        }
    }
   /* if (depth == 0) return getScore(board, bsize, whiteTurn);
    char **temp = initBoard(8);
    copy_board(board, temp, 8);
    vector<Move> movelist = findMoves(temp, bsize, whiteTurn);
    for (const Move &move : movelist)
    {
        do_move(temp, move);
        int tmp = -alphabeta(temp, bsize, !whiteTurn, depth - 1, -beta, -alpha);
        undo_move(temp, move);
        if (tmp > alpha)
        {
            if( depth == 3 )
                bestMove = move;
            alpha = tmp;
        }
        if(beta <= alpha)
            return beta;
    }
    return alpha;*/
}

int main()
{
    int timer = 0;
    char **board;
    board = initBoard(8);
    newGame(board, 8);
    int bsize = 8;
    bool whiteTurn = false;
    bool play = false;
    bool first = true;
    int a = -std::numeric_limits<int>::max();
    int b = std::numeric_limits<int>::max();
    sf::Texture BlackCheckerTex;
    BlackCheckerTex.loadFromFile("czarny.png");
    sf::Sprite BlackCheckerSprite;
    BlackCheckerSprite.setTexture(BlackCheckerTex);

    sf::Texture WhiteCheckerTex;
    WhiteCheckerTex.loadFromFile("bialy.png");
    sf::Sprite WhiteCheckerSprite;
    WhiteCheckerSprite.setTexture(WhiteCheckerTex);

    sf::Texture BlackQueenTex;
    BlackQueenTex.loadFromFile("czarna.png");
    sf::Sprite BlackQueenSprite;
    BlackQueenSprite.setTexture(BlackQueenTex);

    sf::Texture WhiteQueenTex;
    WhiteQueenTex.loadFromFile("biala.png");
    sf::Sprite WhiteQueenSprite;
    WhiteQueenSprite.setTexture(WhiteQueenTex);

    sf::RenderWindow oknoAplikacji( VideoMode( 800, 800, 32 ), "Checkers Game v1.0" );

    Menu menu(oknoAplikacji.getSize().x, oknoAplikacji.getSize().y);

    sf::Texture tekstura;
    tekstura.loadFromFile( "board.jpg" );

    sf::Sprite obrazek;
    obrazek.setTexture( tekstura );
    obrazek.setScale( 1, 1 );

    sf::Texture menu_back_tex;
    menu_back_tex.loadFromFile( "menu.jpg" );
    sf::Vector2u TextureSize;
    sf::Vector2u WindowSize;
    TextureSize = menu_back_tex.getSize();
    WindowSize = oknoAplikacji.getSize();

    sf::Sprite menu_back;
    menu_back.setTexture( menu_back_tex );
    menu_back.setScale( (float) WindowSize.x / TextureSize.x, (float) WindowSize.y / TextureSize.y );

    sf::Vector2f ButtonPosition = menu.getPosition(0);
    std::cout << ButtonPosition.x << " " << ButtonPosition.y << std::endl;

    Move PreviousMove(0, 0, 0, 0, false, false, false);

    while( oknoAplikacji.isOpen() )
    {
        sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            switch(zdarzenie.type) {
            case sf::Event::KeyReleased:
                switch(zdarzenie.key.code) {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(menu.GetPressedItem()) {
                    case 0:
                        std::cout << "Play button has been pressed" << std::endl;
                        play = true;
                        break;
                    case 1:
                        std::cout << "Options button has been pressed" << std::endl;
                        break;
                    case 2:
                        oknoAplikacji.close();
                        break;
                    }
                    break;
                }
                break;
                case::Event::MouseMoved:
                    menu.CheckMouse(oknoAplikacji);
                    break;
                case sf::Event::MouseButtonPressed:
                    int menubutton;
                    menubutton = menu.CheckPress(oknoAplikacji);
                    switch(menubutton) {
                    case 0:
                        play = true;
                        std::cout << "Clicked Play!" << std::endl;
                        break;
                    case 1:
                        std::cout << "Clicked Options!" << std::endl;
                        break;
                    case 2:
                        std::cout << "Clicked Exit!" << std::endl;
                        oknoAplikacji.close();
                        break;
                    }
                    break;
            }


            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                 oknoAplikacji.close();
        }
        if(play == false) {
        oknoAplikacji.clear();

        oknoAplikacji.draw(menu_back);
        menu.draw(oknoAplikacji);

        oknoAplikacji.display();

        }
        if(play == true) {
        timer++;
        sf::sleep(sf::milliseconds(700));
        bestMove->show_move();
        ContainerOfBlocks WtestBlocks(sf::Vector2f(0.0f, 0.0f), board, 0);
        ContainerOfBlocks BtestBlocks(sf::Vector2f(0.0f, 0.0f), board, 1);
        if (*bestMove == PreviousMove && timer > 15) {
            std::cout << "cos sie zapetlilo" << std::endl;
            *bestMove = Move(0, 0, 0, 0, false, false, false);
            //alphabeta(board, bsize, whiteTurn, 5, a, b);
        }
        if(!(*bestMove == PreviousMove) && timer > 15 ) {
            std::cout << "wszystko ok" << std::endl;
        }
        PreviousMove = *bestMove;
        if (timer > 10) {
            if(first == true) {
                first_move(board, whiteTurn);
                whiteTurn = !whiteTurn;
                first = false;
                WtestBlocks.setBoard(board, 0);
                BtestBlocks.setBoard(board, 1);
            }
            else {
            alphabeta(board, bsize, whiteTurn, 5, a, b);
            do_move(board, *bestMove);
            WtestBlocks.setBoard(board, 0);
            BtestBlocks.setBoard(board, 1);
            check_for_queens(board, 8);
            if(bestMove->lethal) {
               alphabeta(board, bsize, whiteTurn, 5, a, b);
                if(!bestMove->lethal) {
                      whiteTurn = !whiteTurn;
                }
            }
            else {
                whiteTurn = !whiteTurn;
            }
        }
        }
        oknoAplikacji.clear( sf::Color::Black );
        oknoAplikacji.draw( obrazek );

        vector<Block> & WBlocks = WtestBlocks.getContainer();
        vector<Block> & BBlocks = BtestBlocks.getContainer();

        for (int i = 0; i < BBlocks.size(); i++) {
            if(BBlocks[i].queen == false) {
            BlackCheckerSprite.setPosition(BBlocks[i].getPosition());
            oknoAplikacji.draw(BlackCheckerSprite);
            //std::cout << i << "Black Checker printed" << std::endl;
            }
            else {
            BlackQueenSprite.setPosition(BBlocks[i].getPosition());
            oknoAplikacji.draw(BlackQueenSprite);
            //std::cout << i << "Black Queen printed" << std::endl;
            }
        }
        for (int i = 0; i < WBlocks.size(); i++) {
            if(WBlocks[i].queen == false) {
            WhiteCheckerSprite.setPosition(WBlocks[i].getPosition());
            oknoAplikacji.draw(WhiteCheckerSprite);
            //std::cout << i << "White Checker printed" << std::endl;
            }
            else {
            WhiteQueenSprite.setPosition(WBlocks[i].getPosition());
            oknoAplikacji.draw(WhiteQueenSprite);
            //std::cout << i << "White Queen printed" << std::endl;
            }
        }

        oknoAplikacji.display();
        if(WBlocks.size() < 2 && BBlocks.size() > WBlocks.size()) {
            oknoAplikacji.close();
        }
        if(BBlocks.size() < 2 && BBlocks.size() < WBlocks.size()) {
            oknoAplikacji.close();
        }
}
}
   return 0;
}
