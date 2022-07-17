#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
cout << " ========= Fishing game ===========\n\n";

string fish_name;
cout << "What kind of fish will you catch?";
cin >> fish_name;

ifstream file ("river.txt");

if (!file.is_open ()){
    cout << "Error open file for read";
}

ofstream in_file ("basket.txt",ios::app);

if (!in_file.is_open ()){
        cout << "Error open file for write";
}
string catchFish;

    while (!file.eof()){
        file >> catchFish;
        cout << "You catch " << catchFish << " fish!\n";
        if (fish_name == catchFish) {
            cout << "\nput the "<< catchFish <<" fish in the basket\n\n";
            in_file << catchFish << endl;
        }
    }

    file.close ();
    in_file.close();

    //считаем количество рыбы в корзине

    file.open ("basket.txt");
    vector <string> caught_fish ;
    if (!file.is_open()) {
        cout << "Error opening basket";
    }
    while (!file.eof ()){
        string temp;
        file >> temp;
        caught_fish.push_back (temp);
    }
    file.close ();

    // вывод содержимого корзины
    for (int i = 0; i < caught_fish.size() -1; i++){
        string fish;
        if (caught_fish [i] != "-" ) {
            fish = caught_fish[i];
            int fish_in_basket = 0;
            for (int j = 0; j < caught_fish.size(); j++) {
                if (caught_fish[j] == fish) {
                    caught_fish[j] = "-";
                    fish_in_basket++;
                }
            }
            cout << "\nYou have " << fish_in_basket << " " << fish << " in basket.\n";
        }
    }



}
