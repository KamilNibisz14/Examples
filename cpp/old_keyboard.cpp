// Program sprawdza czy podany wyraz może być zapisany za pomocą starej klawiatury telefonu, gdzie np. (2 = a, 2 = c)

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool check(const std::string& number, const std::string& str)
{
    std::string z;
    for (int j = 0; j < str.size(); ++j)
    {
        int w = str[j] - 97;
        if (w > 17)
            w--;
        if (w > 23)
            w--;
        w /= 3;
        w += 2;
        z.push_back(w + 48);
    }
    return number.find(z) != std::string::npos;
}

int main()
{
    std::string phoneNumber;
    int numberOW;
    std::ifstream plik;
    plik.open("file.txt");
    plik >> phoneNumber >> numberOW;
    
    for (int i = 0; i < numberOW; ++i) 
    {
        std::string str;
        plik >> str;
        if (check(phoneNumber, str))
        {
            std::cout << str << std::endl;
        }

    }

    return 0;
}
