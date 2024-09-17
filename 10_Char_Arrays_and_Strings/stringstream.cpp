// Stringstream is a stream class to operate on strings. It basically implements input/output operations on memory (string) based streams. stringstream can be helpful in different type of parsing. The following operators/functions are commonly used here.

// 1. Extraction Operator (>>) : This operator is used to read from the string stream. It can be used to read the contents of the stream as if it were a standard input/output stream.

// 2. Insertion Operator (<<) : This operator is used to write to the string stream. It can be used to write the contents of the stream as if it were a standard output stream.

// 3. str() : This function is used to get the contents of the stream as a string object.

// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;


int main() {
    string s = {"My name is ayush"};
    
    stringstream ss1(s);
    
    string token = "";
    
    while(ss1 >> token){
        cout<<token<<endl;
    }

    return 0;
}