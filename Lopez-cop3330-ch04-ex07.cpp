/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Julio Lopez
 */
#include "std_lib_facilities.h"

vector < string > nums;

int get_number() {
    const int c = nums.size();
    string s;
    int r = c;
    if (cin >> r)
        return r;
    cin.clear();
    cin >> s;
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] == s)
            return i;
    error("Error in string: ", s);
    return 0;
}

void initialize_numbers() {
    nums.push_back("zero");
    nums.push_back("one");
    nums.push_back("two");
    nums.push_back("three");
    nums.push_back("four");
    nums.push_back("five");
    nums.push_back("six");
    nums.push_back("seven");
    nums.push_back("eight");
    nums.push_back("nine");
    nums.push_back("ten");
}

int main() {
    initialize_numbers();
    cout << "Enter your desired equation for two integers seperated by a space: ";
    int first = get_number();
    char inputOperator = 0;
    cin >> inputOperator;
    int second = get_number();
    string outputOperator;
    double tot;
    switch (inputOperator) {
    case '+':
        outputOperator = "The sum of ";
        tot = first + second;
        break;
    case '-':
        outputOperator = "The difference between ";
        tot = first - second;
        break;
    case '*':
        outputOperator = "The product of ";
        tot = first * second;
        break;
    case '/':
        outputOperator = "The ratio of ";
        if (second == 0)
            error("divide by 0 error");
        tot = first / second;
        break;
    default:
        error("Operator error");
    }
    cout << outputOperator << first << " and " << second << " is " << tot << '\n';
}