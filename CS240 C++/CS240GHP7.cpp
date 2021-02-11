//Creates a 15 element vector
//Fills it with ??
//Gets 10 words from user and fills the vector by hashing
//Displays the vector, both empty and filled positions
//Asks user for words to search for in the vector
//or ends the search with an N or n
//Displays if the users word was found or not found
//Written by Joshua Corelli
//April 4th, 2020
//Language: C++ (g++ target)
//Made in CodeBlocks

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Arrays max size
const int MAXARRAYSIZE = 15;
class Hash
{
    public:

    //Constructor function
    Hash() : word_array (MAXARRAYSIZE)
    {
        //Filling the array with ?? to indicate empty positions
        for (i = 0; i < 15; i++)
            word_array.at(i) = "??";
    }

    //Function to store the words from the user
    void store(char firstletter, char lastletter, string hashed)
    {
        i = 0;
        //Getting a number to store the word in positions 0-14 of the vector
        val = (firstletter + lastletter) % 15;

        //Checking to see if the position is empty
        if (word_array.at(val) == "??")
            //Placing word into vector
            word_array.at(val) = hashed;

        //Vector position is not empty
        else
        {
            //Terminating condition once an empty position is found
            while (i != 1)
            {
                //Checking to see if at the end of the vector
                if (val == 14)
                    //Looking at first position of the array
                    val = 0;
                else
                    //Getting next position in the array
                    val++;

                //Checking to see if the position is empty
                if (word_array.at(val) == "??")
                {
                    //Placing word into vector
                    word_array.at(val) = hashed;
                    //Ending the loop
                    i++;
                }
            }
        }
    }

    //Function to display the words in the vector
    void display()
    {
        //Added space for looks
        cout << endl;

        //Printing out the 15 positions
        for (i = 0; i < 15; i++)
        {

            //Seeing if the position is empty or has a word in it
            //and outputting it to the user
            if (word_array.at(i) == "??")
            {
                cout << "Position " << i + 1 << ": ??" << endl;
            }

            else
            {
                cout << "Position " << i + 1 << ": " << word_array.at(i) << endl;
            }

        }
    }

    //Function to see if the users word is in the vector
    void search (char firstletter, char lastletter, string hashed)
    {
        i = 0;
        counter = 0;
        //Getting a number to check if the word is in positions 0-14 of the vector
        val = (firstletter + lastletter) % 15;

        //Checking to see if position is empty
        //if so then the word was not in the vector
        if (word_array.at(val) == "??")
            cout << "The word " << hashed << " was not found in the vector" <<endl;

        //Position checked was not empty and has a word
        else
        {
            //Checking to see if position is the users word
            //if so then the word was in the vector
            if (word_array.at(val) == hashed)
                cout << "The word " << hashed << " was found at position " << val + 1 << endl;
            //The users word did not match the vectors word
            else
            {
                //Terminating condition once at an empty position is reached
                //and users word was not found
                while (i != 1)
                {
                    //Checking if at the end of the array
                    if (val == 14)
                    {
                        //Looking at the first position of the array
                        val = 0;
                    }
                    else
                        //Go to next position
                        val++;

                    //Checking to see if position is empty
                    //if so then the word was not in the vector
                    if (word_array.at(val) == "??")
                    {
                        cout << "The word " << hashed << " was not found in the vector" << endl;
                        i++;
                    }
                    //Checking to see if users word is at the position in the vector
                    if (word_array.at(val) == hashed)
                    {
                        cout << "The word " << hashed << " was found at position " << val + 1 << endl;
                        //Ending the loop
                        i++;
                    }
                }
            }
        }
    }

    private:

    //Local Variables only available to the hash class and inheritance classes if any
    vector <string> word_array;
    int i = 0, val, counter;
    char firstletter, lastletter;
    string hashed;
};


int main (void)
{
    //Local variables declared
    Hash words;
    char first_letter, last_letter;
    int i = 0, size;
    string word;

    //Asking user for 10 words
    cout << "Enter 10 words to be hashed and stored in a vector" << endl;

    //Reading users 10 words and sending them to be stored in the vector
    //Done so by hashing
    for (i = 0; i < 10; i++)
    {
        cout << "Word number " << i + 1 << ": ";
        cin >> word;

        first_letter = word.at(0);
        size = word.length();
        last_letter = word.at(size - 1);

        //Send the first letter and last letter of the users word
        //as well as the users word to be stored
        words.store(first_letter, last_letter, word);
    }

    //Display the vector of words and empty positions
    words.display();

    i = 0;
    word = 'Y';

    //Loop terminates once a user enters an N or n
    while ( i != 1)
    {
        cout << endl << "Enter a word to search for in the vector" << endl;
        cout << "Enter N or n to stop searching: ";

        //Read the users word or read N / n
        cin >> word;

        //Checking to see if user wanted to stop searching
        if ( word != "N" && word != "n")
        {
            first_letter = word.at(0);
            size = word.length();
            last_letter = word.at(size - 1);

            //Send the first letter and last letter of the users word
            //as well as the users word to be checked if it is in the vector
            words.search(first_letter, last_letter, word);
        }

        else
        {
            //End the loop since user entered an N or n
            i++;
        }
    }
        return 0;
}
