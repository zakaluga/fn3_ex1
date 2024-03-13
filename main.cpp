#include <iostream>

struct Sizes {
    int a, b, c;
    // Sizes() {a = 100; b = 100; c = 100;};
    Sizes(int a, int b, int c) { this->a = a; this->b = b; this->c = c; }
};

struct Position {
    int x, y;
    Position(int x, int y) { this->x = x; this->y = y; }
};

class FurnetureProperties {
    enum Material {
        Wood, Steel, Plastic, Mixed
    };
    Sizes sizes;
    Material material;
    Position position;
public:
    FurnetureProperties(Material& mat, const Sizes& s, Position& pos) :sizes(s), material(mat), position(pos) {

    };
    void Move(int x, int y) {
        this->position.x = x;
        this->position.y = y;
    };
};

class Chair {
public:
    FurnetureProperties properties;
    Chair(const FurnetureProperties& prop) :properties(prop) {

    };
};

int main(int argc, char* argv[])
{
    int count;
    std::cout << "¬ведите количество стульев:";
    std::cin >> count;
    for (int i = 0; i < count; i++) {

    }
}