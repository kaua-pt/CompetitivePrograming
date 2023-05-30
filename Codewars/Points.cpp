#include <string>
#include <array>

int points(const std::array<std::string, 10> games)
{
    int points = 0;
    for (std::string game : games)
    {
        if (game[0] > game[2])
            points += 3;
        if (game[0] == game[2])
            points += 1;
    }
    return points;
}