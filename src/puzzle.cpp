#include <puzzle.hpp>

Puzzle::Puzzle(int rows, int columns)
: d_data(rows*columns)
, d_rows(rows)
, d_columns(columns)
{
    reset();
}

void Puzzle::scramble()
{
    kj::Random<int> random;
    scramble(random);
}
void Puzzle::scramble(kj::Random<int>& random)
{
    for(int i = 0; i < 1000; i++)
        randomMove(random);
    for(int i = 0; i < d_rows; i++)
        up();
    for(int i = 0; i < d_columns; i++)
        left();
}

void Puzzle::randomMove()
{
    kj::Random<int> random;
    randomMove(random);
}
void Puzzle::randomMove(kj::Random<int>& random)
{
    bool good = false;
    while(!good)
    {
        int rand = random(0, 4);
        if (rand == 0)
            good = up();
        else if (rand == 1)
            good = down();
        else if (rand == 2)
            good = left();
        else if (rand == 3)
            good = right();
    }
}
void Puzzle::reset()
{
    int value = 0;
    for(int row = 0; row < d_rows; row++)
        for(int col = 0; col < d_columns; col++)
            ref(row, col) = ++value;
    d_emptyRow = d_rows-1;
    d_emptyColumn = d_columns-1;
}

bool Puzzle::solved() const
{
    int value = 0;
    for(int row = 0; row < d_rows; row++)
        for(int col = 0; col < d_columns; col++)
            if (ref(row, col) != ++value)
                return false;
    return true;
}

bool Puzzle::up()
{
    return move(1, 0);
}
bool Puzzle::down()
{
    return move(-1, 0);
}
bool Puzzle::left()
{
    return move(0, 1);
}
bool Puzzle::right()
{
    return move(0, -1);
}

std::pair<int, int> Puzzle::get(int row, int column) const
{
    int value = ref(row, column)-1;
    return { value / d_columns, value % d_columns };
}

bool Puzzle::move(int rowDir, int colDir)
{
    int newRow = d_emptyRow+rowDir;
    int newCol = d_emptyColumn+colDir;
    if (newRow < 0 || newRow > d_rows-1 || newCol < 0 || newCol > d_columns-1)
        return false;
    std::swap(ref(d_emptyRow, d_emptyColumn), ref(newRow, newCol));
    d_emptyRow = newRow;
    d_emptyColumn = newCol;
    return true;
}

int& Puzzle::ref(int row, int column)
{
    return d_data.at(row*d_columns + column);
}

const int& Puzzle::ref(int row, int column) const
{
    return d_data.at(row*d_columns + column);
}
