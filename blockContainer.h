#ifndef BLOCKCONTAINER_H_INCLUDED
#define BLOCKCONTAINER_H_INCLUDED

#include "block.h"

class ContainerOfBlocks : public sf::Drawable {
 public:
  ContainerOfBlocks();
  ContainerOfBlocks(const sf::Vector2f pos, char **board, int WB);
  ~ContainerOfBlocks();
  std::vector<Block> blockContainer;
  std::vector<Block> &getContainer();
  void drawContainer(sf::RenderWindow &window);
  void setBoard(char **board, int WB);

 private:
  virtual void draw(sf::RenderTarget &renderTarget, sf::RenderStates renderStates) const;
};

#endif
