//Built in code blocks as a project to use command line arguments
//Program uses a user's input base between 2 and 36
//the user's number in that input base
//converts it to the user's desired output base between 2 and 36
//Written by Joshua Corelli
//February 15th, 2020
//Language in C++

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;

//functions declared
char reVal(int num);
void strev(char *str);
void fromdeci (int argv2, int argv3, char *coefficients);
int val(char c);
int toDeci(char * argv[], int argv1);

int main (int argc, char *argv[])
{
    //local variables
    char coefficients [36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int argv1, argv2, argv3, in_deci;

    //turning the characters in argv that represent the input base
    //and output base into usable integers
    stringstream x(argv[1]);
    x>>argv1;
    stringstream y(argv[3]);
    y>>argv3;

    //checking if input base is already a decimal
    if (argv1 == 10)
    {
        //converting the decimal number in the input base to a usable integer number
        //This is in the if loop so it does not change the value of a character
        //with the possibility of it going to the else statement
        stringstream z(argv[2]);
        z>>argv2;

        //function to convert the decimal to the desired output base
        fromdeci (argv2, argv3, coefficients);
    }
    else
    {
        //function to convert the input base to its equivalent decimal value (Base 10)
        in_deci = toDeci(argv, argv1);

        //sends the decimal value to the fromdeci function to be converted into the desired base output
        fromdeci (in_deci, argv3, coefficients);
    }

    return 0;
}

//function definition to turn remainder values back into characters '0' - 'Z'
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

//function definition to flip the remainder values that represent the output base
//The remainder values read backwards equals the output value in the output base
void strev(char *str)
{
    int length = strlen(str);
    int i = 0;
    char tempVal = {'0'};
    for (i = 0; i < length/2; i++)
    {

        //reads sting from the end to beginning
        tempVal = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = tempVal;
    }
    //print output number that is now in desired output base
    cout<<str<<endl;
}

//function definition to convert the decimal to the desired output base
void fromdeci (int argv2, int argv3, char *coefficients)
{
    int i = 0;

    //once at 0 that means the decimal value has been
    //divided by the desired base number until it cannot be
    //divided any more and the remainder will begin to repeat
    while (argv2 > 0)
    {
        //gets remainder of anything from (argv3 - 1) to 0 <-- range
        int remainder = argv2 % argv3;

        //store the character results received from the reVal function
        coefficients[i++] = reVal(remainder);

        //divide the decimal number (base 10) in order to not
        //repeat the remainder cycle on the same number before
        argv2 = argv2 / argv3;
    }

    //once the while statement ends i should read a NULL character
    //which is the end of a string (knows when the string ends)
    coefficients[i] = '\0';

    // Reverse the result found from the remainder function
    strev(coefficients);

    return;
}

//function definition to convert the character's held at argv[2]
//into there represented integer values
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

//function to convert argv[2] into a decimal number (Base 10)
//by using the base it is in and multiplying the digits that make
//up the decimal number by the base it is in
//Ex.) 301 in base 4 would be 1(10^0)+0(10^1)+3(10^2)
int toDeci(char * argv[], int argv1)
{
    //measures how long the number in the input base is
    int length = strlen(argv[2]);

    int power = 1; //the digit in the ones position of the number is always
                   //multiplied by one first
    int num = 0;

    int i = 0;

    //Ex.) 301 in base 4 would be 1(10^0)+0(10^1)+3(10^2)
    //converts the input base into decimal
    for (i = length - 1; i >= 0; i--)
    {
        //num holds the decimal value(base 10)
        num = num + val((argv[2])[i]) * power;
        power = power * argv1;
    }

    return num;
}
