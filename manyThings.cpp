#include <iostream>
using namespace std;

/***Function Definitions ******/
int passCopy(int num){
    num = 42;
    cout << "PassCopy: " << num << endl;
    return num;
}
void passReference(int &num){
 	num++;
    cout << "PassReference: " << num << endl;
}
bool isEven(int num){
    if (num % 2 == 0) {
        return true;
    } else{
        return false;
    }
}

int main(){
    int num = 2;
	cout << "Original Value: " << num << endl;
 	//test Code here
    cout << isEven(num) << endl;
    passCopy(num);
    cout << "Num after passCopy: " << num << endl;
    cout << "Returned from passCopy: " << passCopy(num) << endl;
    passReference(num);
    cout << "Num after passReference: " << num << endl;
    cout << isEven(num) << endl;
}
