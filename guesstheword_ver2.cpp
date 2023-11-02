// NB:
// Cara menghapus semua history output sebelum menjalankan program selanjutnya

#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <windows.h>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"

using namespace std;

int main()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 eng(seed);
    uniform_int_distribution<> distr(0,3);

    string kata[] = {
        "lion",
        "elephant",
        "eagle",
        "snake"
    };

    string cluesLion[] = {
        "This thing is an animal",
        "This animal is a carnivore",
        "This animal is the king of the jungle"
    };

    string cluesElephant[] = {
        "This thing is an animal",
        "This animal is big",
        "This animal has trunk like arm",

    };

    string cluesEagle[] = {
        "This thing is an animal",
        "This animal can fly high",
        "This animal have sharp eyesight"
    };

    string cluesSnake[] = {
        "This thing is an animal",
        "This animal can slither",
        "This animal have venomous bite"
    };

    int randomIndex = distr(eng);
    string kataBenar = kata[randomIndex];
    string *cluesTrue;

    if (kataBenar == "lion"){
        cluesTrue = cluesLion;
    }
    else if (kataBenar == "elephant"){
        cluesTrue = cluesElephant;
    }
    else if (kataBenar == "eagle"){
        cluesTrue = cluesEagle;
    }
    else if (kataBenar == "snake"){
        cluesTrue = cluesSnake;
    }

    bool gameOn = true;

    while(gameOn){
        char lanjut;
        char lanjut2;
        string Nama;
        string jawabanBenar;
        int panjangBatas = 30;

        cout << WHITE << "Welcome to Word Utopia \nPress 0 to continue: ";
        cin >> lanjut;
        for (int d = 0; d < panjangBatas; ++d){
            cout << "=";
        }
        cout << endl;
        if(lanjut == '0'){
            cout << "What should i call you: ";
            cin >> Nama;
            for (int d = 0; d < panjangBatas; ++d){
                cout << "=";
            }
            cout << endl;
        
            cout << "Heyy " << Nama <<", would you like to play a game that can help you with critical thinking skills \nPress 0 to continue: ";
            cin >> lanjut2;
            for (int d = 0; d < panjangBatas; ++d){
                cout << "=";
            }
            cout << endl;
            
            if(lanjut2 == '0'){
                cout << "Okay then, lets get into the game. Enjoyy" << endl;
                for (int d = 0; d < panjangBatas; ++d){
                    cout << "=";
                }
                cout << endl;
                for(int i=0; i<3; i++){
                    cout << cluesTrue[i] << endl; 
                    cout << "Guess the word based on the clue given: ";
                    cin >> jawabanBenar;

                    if(jawabanBenar == kataBenar){
                        cout << GREEN << "Congratulation!, You're correct!" << endl;
                        break;
                    }
                    else if(i == 2){
                        cout << "Ooopss sorry, looks like you already use all of your chances \nThe answer is " << kataBenar;
                    }
                    else{
                        cout << RED << "Try again losers" << endl;
                        for (int d = 0; d < panjangBatas; ++d){
                            cout << "=";
                        }
                        cout << endl;
                    }
                }
               
            }
            else{
                cout << "Game over. DOn't talk to me again";
            }
        }
        else{
            cout << "Game over. Don't talk to me again";
        }     
        gameOn = !gameOn;
    }
    return 0;
}