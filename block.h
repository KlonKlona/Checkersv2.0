#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "chequer.h"

class Block : public sf::Drawable, public sf::Transformable {
 public:
  Block() = delete;
  Block(float startX, float startY, bool c, bool _q);
  virtual ~Block();
  void move_block(Block& block, Move play);
  sf::Vector2f position;
  sf::Sprite block;
  bool queen;
  bool WB;
  sf::Vector2f & getPosition(){ return position; }

 private:
  virtual void draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const;
  sf::Color colour;
};

#endif
