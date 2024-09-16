#include <iostream>
#include<cstdlib>
time_t current_time = time(NULL);
using namespace std;

int removeStones(int &pile, int take) {
    pile -= take;
    return pile;
}

int main() {
    int pile = 20, take = 0;
    bool playerTurn = true;

    while (pile > 0){
        if (playerTurn) {
            take = 0;
            while (take < 1 || take > 3 || take > pile) {
                cout << "There are " << pile << " stones in the pile. Would you like to take one, two, or three stones: ";
                cin >> take;
                if (take < 1 || take > 3 || take > pile) {
                    cout << "Invalid response. Try again." << endl;
                }
            }
            removeStones(pile, take);
            playerTurn = false;
        } else {
            if (pile == 1 || pile == 2) {
                take = 1;
            } else if (pile == 3) {
                take = 2;
            } else if (pile == 4) {
                take = 3;
            } else {
                take = 1 + (rand() % 3);
            }
            cout << "There were " << pile << " stones. Computer took " << take << " stones." << endl;
            removeStones(pile, take);
            playerTurn = true;
        }
    }
    if (playerTurn) {
        cout << "Congratulations! You have won!" << endl;
    } else {
        cout << "Sorry, you have lost. Try again next time." << endl;
    }
}
