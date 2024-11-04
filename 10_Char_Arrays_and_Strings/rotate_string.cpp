// How can we roate a string by a given number of characters?
// STL provides a function rotate() that can be used to rotate a string by a given number of characters. The function is defined in the <algorithm> header file. The function takes three arguments: the beginning of the range, the middle of the range, and the end of the range. The middle of the range is the point around which the string is rotated. The function rotates the elements in the range [first, last) such that the element at the middle of the range becomes the first element of the range. The function returns an iterator pointing to the first element of the range after the rotation. The function has the following prototype:

// template <class ForwardIterator>
// ForwardIterator rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last);
// Here's an example that demonstrates how to use the rotate() function to rotate a string by a given number of characters:

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str = "geeksforgeeks";
    int k = 5;

    // Rotate the string by k characters
    rotate(str.begin(), str.begin() + k, str.end());

    cout << str << endl; // Output: forgeeksggeeks
    return 0;
}
