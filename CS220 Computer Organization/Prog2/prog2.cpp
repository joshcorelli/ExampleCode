//Built in Ubuntu to take a 10 bit pattern
//Interprets it as a unsigned, signed magnitude, 1's and 2's complement
//Uses a single command line argument, the name of an input file
//Written by Joshua Corelli
//February 16th, 2020
//Language in C++

#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>

using namespace std;


//functions declared
int to_deci (char *filesline);

void unsigned_num (char *filesline);

int char_int(char c);

int ones_comp (char *filesline);

int twos_comp (char *filesline);


int main(int argc, char *argv[])
{
    //local variables
	int binnum = 0, num = 0;

	char filesline [11];

	string line;

    //reading the contents of the file into file
	ifstream file(argv[1]);

    //Getting a single line from a file and storing
    //the file line into line
	while (getline(file, line))
	{
        //copying the contents of the line into a
        //a usable character array filesline
		line.copy( filesline, 11);

        //function call
		unsigned_num ( filesline);

	}

    //closing the file
	file.close();

	return 0;
}

//converting a binary number (Base 2) into its decimal value
int to_deci (char *filesline)
{
    //finding how big the filesline array is (should be 11)
    int length = strlen(filesline);

    //the digit in the ones position of the number is always
    //multiplied by one first
    int power = 1;

    int num = 0;

    int i = 0;

        //Ex.) 1010101011 in would be 1(2^0)+0(2^1)+1(2^2)...+1(2^10)
        //converts the input base 2 into decimal
        for (i = length - 1; i >= 0; i--)
        {
            //num holds the decimal value(base 10)
            num = num + char_int((filesline)[i]) * power;
            power = power * 2;
        }

    return num;

}

//checking to see if the binary number is positive or negative
void unsigned_num (char *filesline)
{
    int posNum = 0, negNum = 0, signmag = 0;
    int twos = 0;

    //if the first binary digit is zero it is a positive number
    //so no need to send the number to other functions
    if (filesline[0] == '0')
    {
        posNum = to_deci (filesline);
        cout << posNum << " " << '+' << posNum 
        << " " << '+' << posNum
        <<" " << '+' << posNum;
        cout << endl;
    }

    //if the first binary digit is one it is a negative number
    //therefore singed magnitude, one's compliment, and two's compliment
    //must be calculated
    else if (filesline[0] == '1')
    {
        //convert the binary number to its decimal value
        negNum = to_deci (filesline);

        //output the unsigned value of the binary number
        cout << negNum;

        //change the first digit of the binary number to zero
        //to allow the number to be calculated in signed magnitude
        filesline[0] = '0';

        //calc the signed magnitude decimal value
        signmag = to_deci (filesline);

        cout << " " << '-' << signmag;

        //change the first digit of the binary number back to a one
        //to cacl one's comp and two's comp on the original binary number
        filesline[0] = '1';

        //calcualte ones comp, but return two's comp decimal because
        //it is calculated with one's comp value and one's comp is
        //outputed to the screen in its function definition
        twos = ones_comp (filesline);

        //output two's comp decimal value
        cout << " " << '-' << twos << endl;
    }

    return;
}

//turns the binary digit into a integer value
int char_int(char c)
{
    if (c >= '0' && c <= '9')
    {
	    return (int)c - '0';
    }
}

//function to calc one's comp value
int ones_comp (char *filesline)
{
    //find the length of the binary number (again should be 11)
    int length = strlen(filesline);

    int i = 0, ones = 0, twos = 0;

    //flip all digits in the binary number
    //1 goes to 0 and 0 goes to 1
    for (i = 0; i <= length - 1; i++)
    {
        if (filesline[i] == '0')
        {
            filesline[i] = '1';
        }
        else
        {
            filesline[i] = '0';
        }
    }

    //cacl one's comp decimal value
    ones = to_deci (filesline);

    //use the binary number obtained by one's comp
    //and use it to calc two's comp value
    twos = twos_comp (filesline);

    //one's comp decimal value outputed
    cout << " " << '-' << ones;

    return twos;
}
 
//cacl two's comp value using one's comp binary number
//by adding 1 to the end of the binary number
int twos_comp (char *filesline)
{
    //cacl length of the binary number (should be 11)
    int length = strlen(filesline);

    int i = 0, twos = 0;

    //starts at the end of the binary number where the value,
    //0 * (2^1) or 1 * (2^1), would be
    for (i = length - 1; i >= 0; i--)
    {
        //change 1's to 0's until a 0 is found
        //once a 0 is found change it to a 1 and stop calculating
        if (filesline[i] == '1')
        {
            filesline[i] = '0';
        }

        else
        {
            filesline[i] = '1';

            break;
        }
    }

    //send the binary number obtained from 2's comp to be calc
    //as its decimal number value
    twos = to_deci (filesline);

    return twos; 

}
