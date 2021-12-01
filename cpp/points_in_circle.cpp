#include <iostream>

struct circle
{
    int r, x, y;
};

struct point
{
    int x, y;
};

void is_in_circle(const point& point, const circle& circle)
{
    double dx = point.x - circle.x;
    double dy = point.y - circle.y;
    if (dx * dx + dy * dy < circle.r * circle.r) {
        std::cout << "In circle" << std::endl;
    }
    else if (dx * dx + dy * dy == circle.r * circle.r) {
        std::cout << "on Edge" << std::endl;
    }
    else {
        std::cout << "Out of circle" << std::endl;
    }
}


int main()
{
    ::circle circle;
    std::cout << "Enter the data of the district (x y r) " << std::endl;
    std::cin >> circle.x >> circle.y >> circle.r;

    int numbers;
    std::cout << "Enter the number of points and then their coordinates" << std::endl;
    std::cin >> numbers;

    for (int i = 0; i < numbers; ++i)
    {
        point point;
        std::cin >> point.x >> point.y;
        is_in_circle(point, circle);
    }

    return 0;
}