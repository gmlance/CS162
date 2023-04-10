#include "zoo.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

// constructor
Zoo::Zoo() {
    // starting balance of $100,000
    balance = 100000;
    feed_price = 80;
    month = -1;

    user_quit = false;

    // no animals to start
    n_sealions = n_bears = n_tigers = 0;

    // allocate empty arrays?
    sealion_exhibit = new Sealion[n_sealions];
    bear_exhibit = new Bear[n_bears];
    tiger_exhibit = new Tiger[n_tigers];
}

// destructor
Zoo::~Zoo() {
    delete[] sealion_exhibit;
    delete[] bear_exhibit;
    delete[] tiger_exhibit;
}

// helper functions
bool Zoo::game_over() {
    return (balance < 0.0) || user_quit;
}

// if (CONDITION) {
//     return true;
// } else {
//     return false;
// }

// return CONDITION;

void Zoo::play_turn() {
    age_game();

    // count decimals and not all the digits
    cout << fixed;
    cout << "Month: " << month << endl;
    // only display 2 decimal places
    cout << "Starting Balance: $" << setprecision(2) << balance << endl;

    special_event();
    display_ages();

    collect_revenue();

    cout << endl;
    cout << "Current Balance: $" << setprecision(2) << balance << endl;
    buy_animals();

    cout << endl;
    feed_animals();

    cout << "Ending Balance: $" << setprecision(2) << balance
         << endl << endl << endl;
}

void Zoo::display_ages() {
    int counts[] = {0, 0, 0};
    for (int i = 0; i < n_sealions; i++) {
        counts[sealion_exhibit[i].determine_age_code()]++;
    }
    for (int i = 0; i < n_bears; i++) {
        counts[bear_exhibit[i].determine_age_code()]++;
    }
    for (int i = 0; i < n_tigers; i++) {
        counts[tiger_exhibit[i].determine_age_code()]++;
    }

    cout << "Babies: " << counts[0] << ", "
         << "Adolescents: " << counts[1] << ", "
         << "Adults: " << counts[2] << endl;
}

// play_turn helpers
void Zoo::age_game() {
    // advance time
    month++;

    // age all sealions
    for (int i = 0; i < n_sealions; i++) {
        sealion_exhibit[i].increment_age();
    }

    // age all bears
    for (int i = 0; i < n_bears; i++) {
        bear_exhibit[i].increment_age();
    }

    // age all tigers
    for (int i = 0; i < n_tigers; i++) {
        tiger_exhibit[i].increment_age();
    }
}

void Zoo::special_event() {
    int special = rand() % 4;

    // 0: sickness
    // 1: birth
    // 2: attendance boom
    // 4: nothing

    if (special == 0) {
        // sick
        int n_total = n_tigers + n_bears + n_sealions;
        // check to see if there are animals
        if (n_total == 0) {
            cout << "No special event this month." << endl;
            return;
        }
        int index_sick = rand() % n_total;
        if (index_sick < n_tigers) {
            cout << "One of your Tigers got sick!" << endl;
            // can they afford to pay for it?
            double cost = Tiger().get_animal_price() / 2.0;
            if (balance > cost) {
                cout << "You spent $" << cost << " to make it better." << endl;
                // pay for it
                balance -= cost;
            } else {
                cout << "It died, because you could not afford care." << endl;
                // animal dies (remove from array)
                for (int i = index_sick; i < (n_tigers - 1); i++) {
                    tiger_exhibit[i] = tiger_exhibit[i + 1];
                }
                n_tigers--;
                // shrink?
                Tiger* tiger_temp = new Tiger[n_tigers];
                for (int i = 0; i < n_tigers; i++) {
                    tiger_temp[i] = tiger_exhibit[i];
                }

                Tiger* old_pointer = tiger_exhibit;
                tiger_exhibit = tiger_temp;
                delete[] old_pointer;
            }
        } else if (index_sick < (n_tigers + n_bears)) {
            index_sick -= n_tigers;
            cout << "One of your Bears got sick!" << endl;
            double cost = Bear().get_animal_price() / 2.0;
            if (balance > cost) {
                cout << "You spent $" << cost << " to make it better." << endl;
                balance -= cost;
            } else {
                cout << "It died, because you could not afford care." << endl;
                for (int i = index_sick; i < (n_bears - 1); i++) {
                    bear_exhibit[i] = bear_exhibit[i + 1];
                }
                n_bears--;
                Bear* bear_temp = new Bear[n_bears];
                for (int i = 0; i < n_bears; i++) {
                    bear_temp[i] = bear_exhibit[i];
                }
                Bear* old_pointer = bear_exhibit;
                bear_exhibit = bear_temp;
                delete[] old_pointer;
            }
        } else {
            index_sick -= (n_tigers + n_bears);
            cout << "One of your Sealions got sick!" << endl;
            double cost = Sealion().get_animal_price() / 2.0;
            if (balance > cost) {
                cout << "You spent $" << cost << " to make it better." << endl;
                balance -= cost;
            } else {
                cout << "It died, because you could not afford care." << endl;
                for (int i = index_sick; i < (n_sealions - 1); i++) {
                    sealion_exhibit[i] = sealion_exhibit[i + 1];
                }
                n_sealions--;
                Sealion* sealion_temp = new Sealion[n_sealions];
                for (int i = 0; i < n_sealions; i++) {
                    sealion_temp[i] = sealion_exhibit[i];
                }
                Sealion* old_pointer = sealion_exhibit;
                sealion_exhibit = sealion_temp;
                delete[] sealion_exhibit;
            }
        }
    } else if (special == 1) {
        // birth
        int n_adults = 0;
        for (int i = 0; i < n_sealions; i++) {
            n_adults += (sealion_exhibit[i].determine_age_code() == ADULT);
        }
        for (int i = 0; i < n_bears; i++) {
            n_adults += (bear_exhibit[i].determine_age_code() == ADULT);
        }
        for (int i = 0; i < n_tigers; i++) {
            n_adults += (tiger_exhibit[i].determine_age_code() == ADULT);
        }

        // if no adults, return
        if (n_adults == 0) {
            return;
        }

        int index_birth = rand() % n_adults;
        int my_index = -1;

        for (int i = 0; i < n_sealions; i++) {
            my_index += (sealion_exhibit[i].determine_age_code() == ADULT);
            if (my_index == index_birth) {
                // this animal will give birth
                cout << "One of your Sealions has given birth!" << endl;
                // find new_n_sealions
                int new_n_sealions = n_sealions + 1;
                // temporary new array with added animals
                Sealion* sealion_temp = new Sealion[new_n_sealions];
                // fill in that sealion_temp array with old animals
                for (int i = 0; i < n_sealions; i++) {
                    sealion_temp[i] = sealion_exhibit[i];
                }
                // add new animals as well
                for (int i = n_sealions; i < new_n_sealions; i++) {
                    sealion_temp[i] = Sealion(0);
                }
                // sealion_exhibit is now the sealion_temp array
                Sealion* old_pointer = sealion_exhibit;
                sealion_exhibit = sealion_temp;
                delete[] old_pointer;

                n_sealions = new_n_sealions;
                return;
            }
        }
        for (int i = 0; i < n_bears; i++) {
            my_index += (bear_exhibit[i].determine_age_code() == ADULT);
            if (my_index == index_birth) {
                cout << "One of your Bears has given birth!" << endl;
                int new_n_bears = n_bears + 1;
                Bear* bear_temp = new Bear[new_n_bears];
                for (int i = 0; i < n_bears; i++) {
                    bear_temp[i] = bear_exhibit[i];
                }
                for (int i = n_bears; i < new_n_bears; i++) {
                    bear_temp[i] = Bear(0);
                }
                Bear* old_pointer = bear_exhibit;
                bear_exhibit = bear_temp;
                delete[] old_pointer;

                n_bears = new_n_bears;
                return;
            }
        }
        for (int i = 0; i < n_tigers; i++) {
            my_index += (tiger_exhibit[i].determine_age_code() == ADULT);
            if (my_index == index_birth) {
                cout << "One of your Tigers has given birth!" << endl;
                int new_n_tigers = n_tigers + 1;
                Tiger* tiger_temp = new Tiger[new_n_tigers];
                for (int i = 0; i < n_tigers; i++) {
                    tiger_temp[i] = tiger_exhibit[i];
                }
                for (int i = n_tigers; i < new_n_tigers; i++) {
                    tiger_temp[i] = Tiger(0);
                }
                Tiger* old_pointer = tiger_exhibit;
                tiger_exhibit = tiger_temp;
                delete[] old_pointer;

                n_tigers = new_n_tigers;
                return;
            }
        }
    } else if (special == 2) {
        cout << "Your zoo had an attendance boost!" << endl;

        // return if no sealions
        if (n_sealions == 0) {
            return;
        }

        // attendance boom
        double revenue = 0.0;
        for (int i = 0; i < n_sealions; i++) {
            revenue += (150.0 + (rand() % 250));
        }

        cout << "The Sealion exhibit made an extra $" << revenue << '.' << endl;
        balance += revenue;
    }
    // nothing
}

void Zoo::collect_revenue() {
    double revenue = 0.0;
    for (int i = 0; i < n_sealions; i++) {
        revenue += sealion_exhibit[i].compute_revenue();
    }
    for (int i = 0; i < n_bears; i++) {
        revenue += bear_exhibit[i].compute_revenue();
    }
    for (int i = 0; i < n_tigers; i++) {
        revenue += tiger_exhibit[i].compute_revenue();
    }

    cout << "Your zoo collected an income of $"
         << setprecision(2) << revenue << endl;
    balance += revenue;
}

void Zoo::buy_animals() {
    // print menu
    cout << "Would you like to buy any animals? (y/N/quit)" << endl << "> "; 
    
    // get input
    string input;
    cin >> input;
    
    // case-insensitive
    for (char & c : input) {
        c = toupper(c);
    }

    // if user wants to exit
    if (input == "QUIT") {
        user_quit = true;
    }

    // process input
    while (input == "Y" || input == "YES") {
        // find out which animal to buy
        string valid = "1234";
        string animal = "0";
        while (valid.find(animal) == string::npos) {
            // print menu
            cout << "1. Buy Tigers"  << endl
                << "2. Buy Bears" << endl
                << "3. Buy Sealions" << endl 
                << "4. Quit" << endl << "> "; 

            // get input
            cin >> animal;
        }

        string animals[] = {"Tiger", "Bear", "Sealion"};

        // if they want to quit, break
        if (animal == "4") {
            break;
        }
    
        // find out how many to buy
        valid = "123";
        string number = "0";
        while (valid.find(number) == string::npos) {
            // print menu
            cout << "1. Buy 1 " << animals[stoi(animal) - 1] << endl
                << "2. Buy 2 " << animals[stoi(animal) - 1] << 's' << endl
                << "3. Quit" << endl << "> "; 

            // get input
            cin >> number;
        }

        // if they quit, ask about the animals again
        if (number == "3") {
            continue;
        }

        // otherwise, have an animal and a number
        if (animal == "1") {
            // find new_n_tigers
            int new_n_tigers = n_tigers + stoi(number);
            // check to see if we can buy it
            double cost = stoi(number) * Tiger().get_animal_price();
            if (cost > balance) {
                cout << "You do not have enough money to buy "
                     << number << ' ' << animals[stoi(animal) - 1] << 's' << endl;
                continue;
            } else {
                // display the cost
                cout << "You paid $" << setprecision(2) << cost << " for "
                     << number << ' ' << animals[stoi(animal) - 1] << 's' << endl;
                balance -= cost;
            }
            // temporary new array with added animals
            Tiger* tiger_temp = new Tiger[new_n_tigers];
            // fill in that tiger_temp array with old animals
            for (int i = 0; i < n_tigers; i++) {
               tiger_temp[i] = tiger_exhibit[i];
            }
            // add new animals as well
            for (int i = n_tigers; i < new_n_tigers; i++) {
                tiger_temp[i] = Tiger(48);
            }
            // tiger_exhibit is now the tiger_temp array
            Tiger* old_pointer = tiger_exhibit;
            tiger_exhibit = tiger_temp;
            delete[] old_pointer;

            n_tigers = new_n_tigers;
            return;
        } else if (animal == "2") {
            int new_n_bears = n_bears + stoi(number);
            double cost = stoi(number) * Bear().get_animal_price();
            if (cost > balance) {
                cout << "You do not have enough money to buy "
                     << number << ' ' << animals[stoi(animal) - 1] << 's' << endl;
                continue;
            } else {
                // display the cost
                cout << "You paid $" << setprecision(2) << cost << " for "
                     << number << ' ' << animals[stoi(animal) - 1] << 's' << endl;
                balance -= cost;
            }
            Bear* bear_temp = new Bear[new_n_bears];
            for (int i = 0; i < n_bears; i++) {
               bear_temp[i] = bear_exhibit[i];
            }
            for (int i = n_bears; i < new_n_bears; i++) {
                bear_temp[i] = Bear(48);
            }
            Bear* old_pointer = bear_exhibit;
            bear_exhibit = bear_temp;
            delete[] old_pointer;
    
            n_bears = new_n_bears;
            return;
        } else if (animal == "3") {
            int new_n_sealions = n_sealions + stoi(number);
            double cost = stoi(number) * Sealion().get_animal_price();
            if (cost > balance) {
                cout << "You do not have enough money to buy "
                     << number << ' ' << animals[stoi(animal) - 1] << 's' << endl;
                continue;
            } else {
                // display the cost
                cout << "You paid $" << setprecision(2) << cost << " for "
                     << number << ' ' << animals[stoi(animal) - 1] << 's' << endl;
                balance -= cost;
            }
            Sealion* sealion_temp = new Sealion[new_n_sealions];
            for (int i = 0; i < n_sealions; i++) {
               sealion_temp[i] = sealion_exhibit[i];
            }
            for (int i = n_sealions; i < new_n_sealions; i++) {
                sealion_temp[i] = Sealion(48);
            }
            Sealion* old_pointer = sealion_exhibit;
            sealion_exhibit = sealion_temp;
            delete[] old_pointer;
    
            n_sealions = new_n_sealions;
            return;
        }
    }
}

void Zoo::feed_animals() {
    cout << setprecision(2) << "Feed Price: $" << feed_price << endl;

    // feed all animals
    for (int i = 0; i < n_sealions; i++) {
        balance -= feed_price * sealion_exhibit[i].get_food_multiplier();
    }
    for (int i = 0; i < n_bears; i++) {
        balance -= feed_price * bear_exhibit[i].get_food_multiplier();
    }
    for (int i = 0; i < n_tigers; i++) {
        balance -= feed_price * tiger_exhibit[i].get_food_multiplier();
    }

    // change feed price
    // random number between 0.8 and 1.2
    double change = (float)(80 + (rand() % 40)) / 100.0;
    cout << "Feed Price % Change: " << change << endl;
    feed_price *= change;
}
