#include "block.h"


Block::Block(float startX, float startY,bool c, bool _q)
{
  position.x = startX;
  position.y = startY;
  block.setPosition(position);
  queen = _q;
  WB = c;
}

Block::~Block() {
}

void Block::draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const {
  renderTarget.draw(block);
}

void move_block(Block& block, Move play) {
  block.position.x = play.end.first*100.0f;
  block.position.y = play.end.second*100.0f;
}

