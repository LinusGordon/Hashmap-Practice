/*
 *   Linus Gordon
 *   February 3, 2016
 *   Annkissam Internship Question
 *
 *   The purpose of this program is to sort words and their frequencies from
 *   a paragraph given as input.
 *
 *   Note: I removed all words that contain a non-alphabetical character, unless
 *         there was punctuation at the end. In that case I removed
 *         the punctuation and kept the word.
 *
 *   Please compile using C++11 to support string.pop_back()
 */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

 // HashTable used to sort words and their frequencies
typedef map<string, int> HashTable;

// Counts the words and their frequencies
void countWords(istream& paragraph, HashTable& words)
{
        string cur;
        bool valid;
        while(paragraph >> cur) {
                valid = false;
                // Search through every letter in the current word
                for(size_t i = 0; i < cur.length(); i++) {
                        // Flag words containing non-alphabetical symbols
                        if(isalpha(cur[i])) {
                                valid = true;
                        } else if(i == (cur.length() - 1) && ispunct(cur[i])) {
                                valid = true;
                                cur.pop_back(); // Remove punctuation at end
                        } else {
                                valid = false;
                                break;
                        }
                }
                if(valid == true) // only insert valid words into HashTable
                        ++words[cur];
        }
}

int main(int argc, char **argv)
{
        (void)argc;
        ifstream paragraph(argv[1]);

        HashTable table;
        countWords(paragraph, table);

        cout << "[";
        for(HashTable::iterator i = table.begin(); i != table.end(); ++i) {
                if(i != table.begin()) {
                                cout << ", ";
                }
                cout << "['" << i->first << "', " << i->second << "]";
        }
        cout << "]" << endl;

        return 0;
}

