#include <iostream>

//[0,0][0,1][0,2]
//[1,0][1,1][1,2]
//[2,0][2,1][2,2]

constexpr int wins[8][3][2] = {
    //Horisontals
    {{0,0},{0,1},{0,2}},
    {{1,0},{1,1},{1,2}},
    {{2,0},{2,1},{2,2}},
    // Verticals
    {{0,0},{1,0},{2,0}},
    {{0,1},{1,1},{2,1}},
    {{0,2},{1,2},{2,2}},
    //Diagonals
    {{0,0},{1,1},{2,2}},
    {{0,2},{1,1},{2,0}}
};

void printField(char field[3][3]) {
    std::cout << "  1  2  3" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1;
        for (int j = 0; j < 3; j++) {
            std::cout << "[" << field[i][j] << "]";
        }
        std::cout << std::endl;
    }
}
bool winCheck(char field[3][3], char player) {

    for (int i = 0; i < 8; i++) {
        if (field[wins[i][0][0]][wins[i][0][1]] == player &&
            field[wins[i][1][0]][wins[i][1][1]] == player &&
            field[wins[i][2][0]][wins[i][2][1]] == player)
        {
            return true;
        }

    }

    return false;
}

int main()
{

    char field[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char player;

    for (int turn = 1; turn < 10; turn++) {

        player = (turn % 2 != 0) ? 'X' : 'O';

        printField(field);

        int i, j;

        std::cout << "Choose row and column for " << player << ": ";

        while (!(std::cin >> i >> j) || i < 1 || i > 3 || j < 1 || j > 3)
        {
            std::cout << "Wrong input. Enter numbers 1-3: ";

            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        i--, j--;

        if (field[i][j] == ' ') {
            field[i][j] = player;
        }
        else {
            std::cout << "This cell is already taken" << std::endl;
            turn--;
            continue;
        }

        if (winCheck(field, player)) {
            printField(field);
            std::cout << player << " Win!" << std::endl;
            break;
        }

        if (turn == 9) {
            printField(field);
            std::cout << "Draw!" << std::endl;
        }
    }

    return 0;
}

