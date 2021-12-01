#include <cstdio>
#include <iostream>

char symbol[4] = { 'J', 'D', 'K', 'A' };
int cards[24];
int moves[24];
int& hand = cards[23];

void printCard(int card)
{
    if (card < 100)
    {
        char color = card / 6 + 3;
        int tmp = card % 6;
        if (tmp < 2)
            printf("%c%d", color, tmp + 9);
        else
            printf("%c%c", color, symbol[tmp - 2]);
    }
    else
    {
        printf("XXX");
    }
}

void printCards()
{
    for (int i = 0; i < 6; ++i)
    {
        printCard(cards[i]); printf("\t");
        printCard(cards[6 + i]); printf("\t");
        printCard(cards[12 + i]); printf("\t");

        if (i < 5)
            printCard(cards[18 + i]); printf("\n");
    }

    printf("\nHand: ");
    printCard(hand);
    printf("\n");
}

bool isOK()
{
    for (int i = 0; i < 23; ++i)
    {
        if (cards[i] != i) {
            return false;
        }
    }

    return true;
}

int main()
{
    srand(time(NULL));
    int tmp, position;
    int count;
    int counter = 0;
    do
    {
        count = 0;

        for (int i = 0; i < 24; ++i)
        {
            cards[i] = i + 100;
            moves[i] = 0;
        }

        for (int i = 0; i < 23; ++i)
        {
            position = rand() % (24 - i) + i;
            tmp = cards[i];
            cards[i] = cards[position];
            cards[position] = tmp;
        }

        hand %= 100;

        while (hand != 23)
        {
            moves[count++] = hand;
            tmp = cards[hand];
            cards[hand] = hand;
            hand = tmp % 100;
        }

        moves[count++] = hand;

        for (int i = 0; i < 23; ++i) {
            cards[i] %= 100;
        }

        counter++;
    } while (!isOK());

    printf("Wygrana partia udala sie po %d probach\n\nAby przejsc do przebiegu parti prosze nacisnac dowolny przycisk na klawiaturze\n", counter);

    getchar();

    for (int i = 0; i < 24; ++i) {
        cards[i] = i + 100;
    }

    for (int i = 0; i < count; ++i)
    {
        system("cls");
        hand = moves[i];
        printCards();
        cards[hand] = hand;
        getchar();
    }

    for (int i = 0; i < 24; ++i) {
        cards[i] %= 100;
    }

    system("cls");
    printCards();

    return 0;
}
