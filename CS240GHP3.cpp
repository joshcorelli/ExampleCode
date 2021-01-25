    //Asks the user for a file
    //opens and read the users file
    //reports the number of words starting with the letter d
    //Written by Joshua Corelli
    //January 3/2/2020
    //Language: C++ (g++ target)

    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cassert>

    using namespace std;

    int main (void)
    {
    //local varibles declared
	int i = 0, counter = 0;
	string userFile, word;
	ifstream fileIn;

    //Asking user to enter a file name
	cout<<endl<<"Enter the name of your file: ";

    //Reading the users file name
	cin>>userFile;

    //Opening the file and what it contains
	fileIn.open (userFile.data());

    //Testing to see if the file opened
    assert (fileIn.is_open());

    //Taking the each word from the file one by one
    while (fileIn >> word)
    {
        //Checking to see if the word starts with the letter 'd' or 'D'
        if (word[i] == 'd' || word[i] == 'D')
        {
            //If the word starts with the letter 'd' or 'D'
            //go back to the top of the while loop and get the next word
            continue;
        }

        //if the word does not start with the letter 'd' or 'D' increment the counter
        else
        {
            //counting number of word that do not start with 'd' or 'D'
            counter++;
        }
    }

    //Print out the number of words that do not start with the letter 'd' or 'D"
    cout<<"The number of words that don't start with the letter D or d is "<<counter<<endl<<endl;

    //close the file
    fileIn.close();

	return 0;
    }
