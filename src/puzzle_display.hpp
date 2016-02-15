#ifndef INCLUDED_PUZZLE_DISPLAY
#define INCLUDED_PUZZLE_DISPLAY

#include <puzzle.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace sf {

class RenderTarget;
class RenderStates;

}

class PuzzleDisplay : public sf::Drawable
{
public:
    PuzzleDisplay(
            const Puzzle& puzzle,
            const std::string& filename,
            int cellWidth, int cellHeight);

    const Puzzle& puzzle() const { return *d_puzzle; }
    void puzzle(const Puzzle& puzzle) { d_puzzle = &puzzle; }
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    const Puzzle* d_puzzle;
    sf::Texture d_texture;
    int d_cellWidth;
    int d_cellHeight;
};

#endif //INCLUDED_PUZZLE_DISPLAY
