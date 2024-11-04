// A trick for all permutations of a string
// If we concat the string with itself, all possible permutations of the string will be present in the new string.
// For example, consider the string "abc". If we concat the string with itself, we get "abcabc". Now, all possible permutations of the string "abc" are present in the new string "abcabc". The permutations are as follows:

// abc
// bca
// cab
// abc
// bca
// cab

#include <iostream>
#include <string>
using namespace std;

void printPermutations(string str) {
    // Concatenate the string with itself
    string s = str + str;

    // Print all possible permutations of the string
    for (int i = 0; i < str.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            cout << s[i + j];
        }
        cout << endl;
    }

    // finding permuation in string
    // if we concatinate or add the string to itself it will have all its permutations of that particular string
    // so we can find the string in the new string
    // if we find the string in the new string then it is a permutation of the string
    
    string goal = "abc";
    string s = "abcabc";
        if((s+s).find(goal) != string::npos){
            cout<<"Yes";
        }
}