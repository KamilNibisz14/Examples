#include <iostream>
#include <vector>

char symbol[4] = { 'J', 'D', 'K', 'A' };

struct card
{
    int number;
    char color;
};

bool war(const std::vector<card>& computer, const std::vector<card>& player, int l)
{
    while (true)
    {
        if (computer[0].number < 11)
            std::cout << "Computer card       " << computer[l].number << computer[l].color << "          " << computer.size() << std::endl;
        else
            std::cout << "Computer card       " << symbol[(computer[l].number % 11)] << computer[l].color << "          " << computer.size() << std::endl;
        std::cout << std::endl;
        std::cout << "               War!!!" << std::endl;
        std::cout << std::endl;
        if (player[0].number < 11)
            std::cout << "Your Card           " << player[l].number << player[l].color << "          " << player.size() << std::endl;
        else
            std::cout << "Your Card           " << symbol[(player[l].number % 11)] << player[l].color << "          " << player.size() << std::endl;
        if (computer[l].number < player[l].number)
            return true;
        else if (computer[l].number > player[l].number)
            return true;
        else
            l += 2;
        getchar();

    }
}

int main()
{
    srand(time(NULL));
    card cards[52];
    for (int i = 0; i < 52; ++i)
    {
        cards[i].number = i % 13 + 2;
        if (i < 13)
            cards[i].color = 3;
        else if (i < 26)
            cards[i].color = 4;
        else if (i < 39)
            cards[i].color = 5;
        else if (i > 38)
            cards[i].color = 6;
    }

    for (int i = 0; i < 1000; ++i)
    {
        int r1 = rand() % 52;
        int r2 = rand() % 52;
        std::swap(cards[r1].number, cards[r2].number);
        std::swap(cards[r1].color, cards[r2].color);
    }

    std::vector<card> computer;
    std::vector<card> player;
    for (int i = 0; i < 52; i += 2)
    {
        computer.push_back(cards[i]);
        player.push_back(cards[i + 1]);
    }

    while (true)
    {
        bool w;
        if (computer[0].number < 11) {
            std::cout << "Computer card       " << computer[0].number << computer[0].color << "          " << computer.size() << std::endl;
        } else {
            std::cout << "Computer card       " << symbol[(computer[0].number % 11)] << computer[0].color << "          " << computer.size() << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        if (player[0].number < 11) {
            std::cout << "Your Card           " << player[0].number << player[0].color << "          " << player.size() << std::endl;
        } else {
            std::cout << "Your Card           " << symbol[(player[0].number % 11)] << computer[0].color << "          " << player.size() << std::endl;
        }

        getchar();
        system("cls");
        
        if (computer[0].number < player[0].number)
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "              Player WIN" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            player.push_back(player[0]);
            player.push_back(computer[0]);
            computer.erase(computer.begin());
            player.erase(player.begin());
        }
        else if (computer[0].number > player[0].number)
        {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "              Computer WIN" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
            computer.push_back(computer[0]);
            computer.push_back(player[0]);
            computer.erase(computer.begin());
            player.erase(player.begin());
        }
        else if (computer[0].number == player[0].number)
        {
            int l = 2;
            w = war(computer, player, l);
            if (w == true)
            {
                for (int i = 0; i < l + 1; ++i)
                {
                    player.push_back(player[i]);
                    player.push_back(computer[i]);
                }
                for (int i = 0; i < l + 1; ++i)
                {
                    computer.erase(computer.begin());
                    player.erase(player.begin());
                }
            }
            else
            {
                if (w == true)
                {
                    for (int i = 0; i < l + 1; ++i)
                    {
                        computer.push_back(computer[i]);
                        computer.push_back(player[i]);
                    }
                    for (int i = 0; i < l + 1; ++i)
                    {
                        computer.erase(computer.begin());
                        player.erase(player.begin());
                    }
                }
            }
        }

        getchar();
        system("cls");

        if (computer.size() == 0)
        {
            std::cout << "          Player win the game!!!" << std::endl;
            return 0;
        }
        if (player.size() == 0)
        {
            std::cout << "          Computer win the game!!!" << std::endl;
            return 0;
        }

    }

    return 0;
}