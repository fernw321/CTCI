// Write a program to print the last K lines of a text file
// *Implementing circular array method*

#include <iostream>
#include <fstream>

using namespace std;

void printLastKLines(char* fileName) {

    // Initialize variables and the files
    const int K = 4; // Prointing the last 4 letters
    string L[K];
    int size = 0; // Number of lines in the file
    ifstream file(fileName); // Read in the file

    // Iterate line by line through the file
    while (file.peek() != EOF) {
        // Push the values to the circular array
        getline(file, L[(size%K)]);
        // Keep count of the file line count
        size++;
    }

    const int START = K > size ? 0 : size%K;
    const int COUNT = min(size, K);

    for (int i = 0; i < COUNT; i++) {
        cout << L[(START+i)%K] << endl;
    }
}


int main() {

char* file = "example.txt";
printLastKLines(file);
return 0;

}
