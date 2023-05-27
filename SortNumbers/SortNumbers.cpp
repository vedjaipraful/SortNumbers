// SortNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
enum SortOrder { ascend, descend };

// Check if the input is a number or a non-number
bool isNumber(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i]) == false) {
            return false;
        }
    }
    return true;
}

// prints an array
template <typename T>
void printArray(vector<T>& array, string operation) {
    cout << "The array elements " << operation << " are - " << endl;
    for (T& i : array) {
        cout << i << endl;
    }
}

template <typename T>
void sortArray(vector<T>& array, SortOrder val) {
    cout << "sort the array" << endl;
    if (val == SortOrder::ascend) {
        sort(array.begin(), array.end());
    }
    else if (val == SortOrder::descend) {
        sort(array.begin(), array.end(), greater<T>());
    }
}

int main()
{
    std::cout << "Hello World!\n";
    vector <int> array;
    cout << "Enter numbers to sort - " << endl;

    string line;
    vector<int> inputArray;

    while (getline(cin, line))
    {
        if (line.empty() || isNumber(line) == false) {
            break;
        }

        inputArray.push_back(stoi(line));
    }

    cout << "User has input " << inputArray.size() << " numbers" << endl;
    // if there are no elements, do not perform the below steps. Just leave
    if (inputArray.size() > 0) {
        // print the numbers
        printArray(inputArray, "before");

        // perform sort
        sortArray(inputArray, SortOrder::descend);

        // print the numbers
        printArray(inputArray, "after");

    }
    else {
        cout << "Nothing to sort" << endl;
    }

    return 0;
}
