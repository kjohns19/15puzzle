#include <puzzle_display.hpp>
#include <SFML/Graphics.hpp>

PuzzleDisplay::PuzzleDisplay(
        const Puzzle& puzzle,
        const std::string& filename,
        int cellWidth, int cellHeight)
: d_puzzle(&puzzle)
, d_cellWidth(cellWidth)
, d_cellHeight(cellHeight)
{
    d_texture.loadFromFile(filename);
}

void PuzzleDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    int rows = d_puzzle->rows();
    int columns = d_puzzle->columns();
    sf::Vector2u imageSize = d_texture.getSize();
    int cellWidth = imageSize.x/columns;
    int cellHeight = imageSize.y/rows;

    sf::Sprite sprite(d_texture);
    sprite.setScale(1.0f*d_cellWidth/cellWidth, 1.0f*d_cellHeight/cellHeight);

    bool solved = d_puzzle->solved();

    for(int row = 0; row < rows; row++)
        for(int col = 0; col < columns; col++)
        {
            int x = col*d_cellWidth;
            int y = row*d_cellHeight;
            auto value = d_puzzle->get(row, col);
            int cellX = value.second*cellWidth;
            int cellY = value.first*cellHeight;

            if (solved || !(value.first == rows-1 && value.second == columns-1))
            {
                sprite.setTextureRect({cellX, cellY, cellWidth, cellHeight});
                sprite.setPosition({1.0f*x, 1.0f*y});
                target.draw(sprite, states);
            }
        }
}
