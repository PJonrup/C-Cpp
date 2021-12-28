#include <iostream>
#include <fstream>  // Why is this needed if we include it in using?
#include <string>   // same here?
#include <iomanip>

using std::string, std::ifstream, std::cout, std::cin, std::endl, std::fixed, std::setprecision;

/*

- Count the number of words.
- Calculate the average length of all the words.
- print the shortest and the longest word in the file.
- if the file is empty, print an error.

Format:
There are 4711 words in the file.
The shortest word was "I" with 1 character(s).
The longest word was "halfpennyworths" with 15 character(s).
The average length was 5.50 character(s).

*/

int main () {

    string filename{"test.txt"}, temp{}, sWord{}, lWord{};
    int wCount{}, totWordLength{};
    float aLength{};

    ifstream s(filename, s.binary);

    if(!s.is_open()) {
        cout << "error: nothing to read in file." << endl;
    } else {
        
        cout << "Starting to read word by word..." << endl;

        while (s >> temp) {
            
            if (temp.length() < sWord.length() || sWord.length() == 0) {
                sWord = temp;
            } else if (temp.length() > lWord.length()) {
                lWord = temp;
            }

            totWordLength += temp.length();
            wCount++;
        }

        aLength = totWordLength / wCount;

        cout << "There are " << wCount << " word in the file." << endl;
        cout << "The shortest word was \"" << sWord << "\" with " << sWord.length() << " character(s)." << endl;
        cout << "The longest word was \"" << lWord << "\" with " << lWord.length() << " character(s)." << endl;
        cout << fixed << setprecision(2);
        cout << "The average word length was " << aLength << " character(s)." << endl;
    }

    

    /*
    if (s) {
        
        s.seekg(0, s.end);
        int length = s.tellg();
        s.seekg(0, s.beg);

        char * buffer = new char [length];

        cout << "reading " << length << " characters..." << endl;
        s.read(buffer, length);

        if (s) {
            cout << "all characters read successfully" << endl;
        } else {
            cout << "error: only " << s.gcount() << " could be read" << endl;
        }

        s.close();

        delete[] buffer;

    } else {
        cout << "error: could not read file";
    }
    */

    return 0;
}