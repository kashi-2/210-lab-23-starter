// COMSC-210 | Lab 23 | Akashdeep Singh

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Goat.h"

using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {

    srand(time(0));

    list<Goat> trip;

    // read names
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int nameCount = 0;

    while (fin >> names[nameCount])
        nameCount++;

    fin.close();

    // read colors
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    int colorCount = 0;

    while (fin1 >> colors[colorCount])
        colorCount++;

    fin1.close();

    int choice;

    do {
        choice = main_menu();

        if (choice == 1)
            add_goat(trip, names, colors);

        else if (choice == 2)
            delete_goat(trip);

        else if (choice == 3)
            display_trip(trip);

    } while (choice != 4);

    cout << "Goodbye!\n";

    return 0;
} 

    int main_menu() {

    int choice;

    cout << "\n*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Quit\n";
    cout << "Choice --> ";

    cin >> choice;

    while (choice < 1 || choice > 4) {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }

    return choice;
}