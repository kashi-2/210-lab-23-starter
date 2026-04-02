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

void add_goat(list<Goat> &trip, string names[], string colors[]) {

    int randName = rand() % SZ_NAMES;
    int randColor = rand() % SZ_COLORS;
    int randAge = rand() % (MAX_AGE + 1);

    Goat g(names[randName], randAge, colors[randColor]);

    trip.push_back(g);

    cout << "Goat added: "
         << g.get_name() << " ("
         << g.get_age() << ", "
         << g.get_color() << ")\n";
} 

void display_trip(list<Goat> trip) {

    if (trip.empty()) {
        cout << "No goats in the trip.\n";
        return;
    }

    int index = 1;

    for (auto g : trip) {
        cout << "    [" << index << "] "
             << g.get_name() << " ("
             << g.get_age() << ", "
             << g.get_color() << ")\n";
        index++;
    }
}

int select_goat(list<Goat> trip) {

    display_trip(trip);

    int choice;

    cout << "Select goat --> ";
    cin >> choice;

    while (choice < 1 || choice > trip.size()) {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }

    return choice;
}

void delete_goat(list<Goat> &trip) {

    if (trip.empty()) {
        cout << "No goats to delete.\n";
        return;
    }

    int choice = select_goat(trip);

    auto it = trip.begin();

    for (int i = 1; i < choice; i++)
        it++;

    cout << "Deleting: " << it->get_name() << endl;

    trip.erase(it);
}