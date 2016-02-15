#include <puzzle.hpp>
#include <puzzle_display.hpp>
#include <kj/random.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
    int width = 800;
    int height = 800;
    sf::RenderWindow window(sf::VideoMode(width, height), "15 Puzzle");

    int rows = 4;
    int columns = 4;
    std::string filename = "puzzle.png";

    if (argc >= 3)
    {
        rows = atoi(argv[1]);
        columns = atoi(argv[2]);
    }
    if (argc >= 4)
        filename = argv[3];

    Puzzle puzzle(rows, columns);
    kj::Random<int> random;

    PuzzleDisplay display(puzzle, filename, width/columns, height/rows);

    int scrambleTime = 0;
    int scrambleMax = 8000;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                    puzzle.up();
                if (event.key.code == sf::Keyboard::Down)
                    puzzle.down();
                if (event.key.code == sf::Keyboard::Left)
                    puzzle.left();
                if (event.key.code == sf::Keyboard::Right)
                    puzzle.right();
            }
        }

        if (scrambleTime < scrambleMax)
        {
            if (scrambleTime % 8 == 0)
            puzzle.randomMove(random);
            scrambleTime++;
        }

        window.clear();
        window.draw(display);
        window.display();
    }

    return 0;
}
