#include <iostream>
#include <vector>

void permutation(std::vector<char> vec, int poz = 0)
{
    if (poz == vec.size())
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            std::cout << vec[i];
        }
        std::cout << std::endl;
    }
    else 
    {
        for (int i = poz; i < vec.size(); i++) 
        {
            std::swap(vec[i], vec[poz]);
            permutation(vec, poz + 1);
            std::swap(vec[i], vec[poz]);
        }
    }
}

int main()
{
    int number;
    std::vector<int> letters;
    std::cin >> number;
    for (int i = 0; i < number; ++i)
    {
        int z;
        std::cin >> z;
        letters.push_back(z);
    }
    for (int i = 0; i < letters.size(); ++i)
    {
        std::vector<char> vec;
        if (letters[i] == 1)
        {
            std::cout << "a" << std::endl;
        }
        else
        {
            for (int j = 0; j < letters[i]; ++j)
            {
                vec.push_back((char)97 + j);
            }
            permutation(vec);
        }
    }

    return 0;
}