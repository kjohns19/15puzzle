#ifndef INCLUDED_PUZZLE
#define INCLUDED_PUZZLE

#include <kj/random.hpp>
#include <vector>

class Puzzle
{
public:
    Puzzle(int rows, int columns);

    void scramble();
    void scramble(kj::Random<int>& random);
    void randomMove();
    void randomMove(kj::Random<int>& random);
    void reset();

    bool solved() const;

    bool up();
    bool down();
    bool left();
    bool right();

    std::pair<int, int> get(int row, int column) const;

    int rows() const { return d_rows; }
    int columns() const { return d_columns; }
private:
    bool move(int rowDir, int colDir);

    int& ref(int row, int column);
    const int& ref(int row, int column) const;

    std::vector<int> d_data;
    int d_rows;
    int d_columns;
    int d_emptyRow;
    int d_emptyColumn;
};

#endif //INCLUDED_PUZZLE
