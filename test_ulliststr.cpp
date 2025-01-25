#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iostream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr dat;

    cout << "Is empty: " << dat.empty() << endl;  // Should be 1 aka true
    cout << "Size: " << dat.size() << endl;       // Should be 0

    dat.push_back(to_string(7));
    dat.push_front(to_string(8));
    dat.push_back(to_string(9));
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
    // prints: 8 7 9
    cout << "Amount of Strings: " << dat.size() << endl;  

    cout << "Front: " << dat.front() << endl;
    cout << "Back: " << dat.back() << endl;

    cout << "Remove all using pop_back:" << endl;
    while (!dat.empty()) {
        cout << "Remove: " << dat.back() << endl; // Print the current back element
        dat.pop_back(); // Remove the back element
    }
    cout << "Updated size: " << dat.size() << endl;

    cout << "Adding with push_front:" << endl;
    for (size_t i = 0; i < 8; i++) {
        dat.push_front(to_string(i)); // Add element to the front
    }

    // Print the list in the correct order
    for (size_t i = 0; i < dat.size(); i++) {
        cout << dat.get(i) << " ";
    }
    cout << endl;
    cout << "Amount of Strings: " << dat.size() << endl; 

    cout << "Remove all using pop_front:" << endl;

    while (!dat.empty()) {
        cout << "Remove: " << dat.front() << endl; // Print the current front element
        dat.pop_front(); // Remove the front element
    }

    cout << "Deleteing an empty list using pop_front:" << endl;
    dat.pop_front(); // Will delete the node
    cout << "Will display if there is no segfault" << endl;
}
