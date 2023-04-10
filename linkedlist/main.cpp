#include <iostream>
#include "linked_list.h"

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

using uint = unsigned int;
using std::cin;
using std::cout;
using std::endl;

template <typename T>
void submain() {
    Linked_List<T> lst;
    char char_in;
    T val_in;

    char_in = 'Y';
    while (char_in == 'Y') {
        cout << "Please enter a number: ";
        cin >> val_in;

        lst.push_front(val_in);

        while (char_in == 'Y') {
            cout << "Do you want to enter another number? (Y/n): ";
            cin >> char_in;
            char_in = toupper(char_in);

            if (char_in == 'Y') {
                cout << "Please enter a number: ";
                cin >> val_in;
                lst.push_front(val_in);
            }
        }

        cout << "Sort ascending or descending? (a/d): ";
        cin >> char_in;
        char_in = toupper(char_in);
        
        if(char_in == 'A')  {
            lst.sort_ascending();
        } else if(char_in == 'D') {
            lst.sort_descending();
        }
        
        cout << "Your linked list is: ";
        lst.print();

        cout << "You have " << lst.count_primes() << " prime number(s) in your list." << endl;

        cout << "Do you want to do this again? (Y/n): ";
        cin >> char_in;
        char_in = toupper(char_in);

        lst.clear();
    }
}

int main() {
    char char_in;

    cout << "Would you like to use unsigned int mode? (Y/n): ";
    cin >> char_in;
    char_in = toupper(char_in);

    if (char_in == 'Y') {
        submain<unsigned int>();
    } else {
        submain<int>();
    }
}
