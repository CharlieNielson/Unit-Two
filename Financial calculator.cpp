#include <iostream>
using namespace std;

void getChoice(int &choice) {
    cout << "1. Calculate Years to Financial Goal" << endl;
    cout << "2. Calculate Amount based on Years" << endl;
    cout << "3. Quit" << endl;
    cin >> choice;
}
void enterValues(double &investment, double &rate){
    cout << "Enter Investment amount: ";
    cin >> investment;
    cout << "Enter Intrest rate: ";
    cin >> rate;
    rate /= 100;
}
int years(double investment, double rate, double goal){
    int years = 0;
    while(investment < goal){
        investment += investment * rate;
        years++;
    }
    return years;
}
int growth(double investment, double rate, double time){
    for(int i = 0; i < time; i++){
        investment += investment * rate;
    }
    return investment;
}

int main (){
    cout << "Financial Calculator Redux" << endl;

    int choice;
    double investment = 0, rate = 0;
    double goal;

    do {
        getChoice(choice);
        if(choice <= 2) {
            enterValues(investment, rate);
        }
        if (choice == 1) {
            cout << "Enter your Financial goal: ";
            cin >> goal;
            cout << "Years to goal: " << years(investment, rate, goal);
            cout << endl;
        } else if (choice == 2) {
            cout << "Enter Number of years in investment: ";
            int time;
            cin >> time;
            cout << "Investment after " << time << " years: " << growth(investment, rate, time);
            cout << endl;
        }

    }while(choice < 3);
    return 0;
}
