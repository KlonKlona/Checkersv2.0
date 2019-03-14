#include "blockContainer.h"

ContainerOfBlocks::ContainerOfBlocks() {
}

ContainerOfBlocks::ContainerOfBlocks(const sf::Vector2f pos, char **board, int WB) {
    for( int i = 0 ; i < 8 ; i++ )
        for(int j = 0 ; j < 8 ; j++)
        {
            float x = pos.x;
            float y = pos.y;
                if(board[i][j] == 'w' && WB == 0){
                    blockContainer.push_back(Block(y + j*100.f,x + i*100.0f, false, false));
                }
                if(board[i][j] == 'b' && WB == 1){
                    blockContainer.push_back(Block(y + j*100.f,x + i*100.0f, true, false));
                }
                if(board[i][j] == 'W' && WB == 0){
                    blockContainer.push_back(Block(y + j*100.f,x + i*100.0f, false, true));
                }
                if(board[i][j] == 'B' && WB == 1){
                    blockContainer.push_back(Block(y + j*100.f,x + i*100.0f, true, true));
                }
        }
}

void ContainerOfBlocks::setBoard (char **board, int WB) {
    blockContainer.clear();
    for( int i = 0 ; i < 8 ; i++ )
        for( int j = 0 ; j < 8 ; j++ )
        {
            float x = 0;
            float y = 0;
                if(board[i][j] == 'w' && WB == 0){
                    blockContainer.push_back(Block(y + j*100.f,x + i*100.0f, false, false));
                }
                if(board[i][j] == 'b' && WB == 1){
                    blockContainer.push_back(Block(y + j*100.f,x + i*100.0f, true, false));
                }
                if(board[i][j] == 'W' && WB == 0){
                    blockContainer.push_back(Block(y + j*100.f,x + i*100.0f, false, true));
                }
                if(board[i][j] == 'B' && WB == 1){
                    blockContainer.push_back(Block(y + j*100.f,x + i*100.0f, true, true));
                }
        }
}

ContainerOfBlocks::~ContainerOfBlocks() {
}

std::vector<Block> &ContainerOfBlocks::getContainer() {
  return blockContainer;
}

void ContainerOfBlocks::drawContainer(sf::RenderWindow &window) {
  for (std::size_t i = 0; i < blockContainer.size(); ++i) {
    window.draw(blockContainer[i]);
  }
}

void ContainerOfBlocks::draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const {
  for (std::size_t i = 0; i < blockContainer.size(); ++i) {
    renderTarget.draw(blockContainer[i]);
  }
}
