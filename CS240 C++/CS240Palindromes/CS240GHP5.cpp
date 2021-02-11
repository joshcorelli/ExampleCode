    //Asks the user for the name of a file
    //Opens and read the users file
    //Reports if the words a palindrome and prints the word
    //Outputs the number of palindromes found and
    //the total number of words in the file
    //Written by Joshua Corelli
    //April 2 2020
    //Language: C++ (g++ target)
    //Made in CodeBlocks

    #include <iostream>
    #include <fstream>
    #include <cstring>
    #include <cassert>
    #include <stack>
    #include <queue>
    #include <cstdlib>

    using namespace std;

    int main(void)
    {
        //creating a stack and queue to use characters
        stack <char> s;
        queue <char> q;

        //local variables declared
        int palcounter = 0, wordcounter = 0, i = 0;
	    string userFile, line;
	    ifstream fileIn;
        bool palindrome = true;
        char Schar, Qchar, word [150];

        //Asking user to enter a file name
	    cout << endl << "Enter the name of your file: ";

        //Reading the users file name
	    cin >> userFile;

        //Opening the file and what it contains
	    fileIn.open (userFile.data());

        //Testing to see if the file opened
        assert (fileIn.is_open());

        //getting words from a file line by line
        while ( fileIn >> line )
        {
            //turning the word from the file into
            //a character array the size of the word
            //not including the null character

            if (line.length() > 150)
            {
                cerr << "*** A word in your file is bigger than 150 characters ***\n";
                exit(1);
            }

            line.copy (word, 150);

            //putting the letters of the word onto the stack
            //and queue until the end of the word is reached
            for (i = 0; i < line.length(); i++)
            {
                s.push (word[i]);
                q.push(word[i]);
            }

            //checking to see if the word was a palindrome
            //until a letter in the queue is not the same
            //as a letter in the stack then immediately
            //ending the check
            while (!q.empty() && palindrome)
            {
                //getting the last letter of the word
                Schar = s.top();

                //getting rid of the last letter in the stack
                //and ran until stack is empty
                s.pop();

                //getting the first letter of the word
                Qchar = q.front();

                //compares the last letter of the word
                //to the first letter of the word
                if (Schar != Qchar)
                {
                    palindrome = false;
                }

                //getting rid of the first letter in the queue
                //and ran until queue is empty
                q.pop( );

            }

            //checking to see if the word was a palindrome
            //to count and output the word
            if (palindrome)
            {
                cout << word << endl;
                palcounter++;
            }

            //Emptying stack and queue for next word
            while (!q.empty() || !s.empty())
            {
                s.pop();
                q.pop();
            }

            //clearing out the character array so that it can
            //get the next word without any left behing characters
            memset(word, 0, sizeof(word));

            //reseting the palindrome
            palindrome = true;

            //counting the number of words processed
            wordcounter++;

        }

        //outputting the number of palindromes and words
        cout << "The number of words that are palindromes are " << palcounter << endl;

        cout << "The total number of words processed are " << wordcounter << endl;

        return 0;
    }
