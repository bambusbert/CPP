#include <iostream>

// cout anschauen wie das geht und syntax
int main (int argc, char **argv)
{
    int i = 0;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    while (argv[++i])
    {
        j = -1;
        while (argv[i][++j])
            std::cout << static_cast<char>(std::toupper(static_cast<int>(argv[i][j])));
    }
    std::cout << std::endl;
    return 0;
}
