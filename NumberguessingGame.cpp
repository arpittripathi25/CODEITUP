#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int secret, guess;
    int tries = 0;

    
    secret = rand() % 100 + 1;   

    cout << "Number Guessing Game" << endl;
    cout << "Guess the number between 1 and 100" << endl;
    guess = -1; 

    while (guess != secret) {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess > secret) {
            cout << "Too High!" << endl;
        } 
        else if (guess < secret) {
            cout << "Too Low!" << endl;
        } 
        else {
            cout << "Correct! You found it in " << tries << " tries." << endl;
        }
    }

    return 0;
}
