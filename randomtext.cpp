#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random string of given length using printable ASCII characters
string random_string(int length)
{
    static const char printable_chars[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "jklmnopqrstuvwxyz"
        "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
        //without abcdefghi

    string result(length, ' ');

    srand(time(nullptr)); // seed the random number generator

    for (int i = 0; i < length; i++) {
        result[i] = printable_chars[rand() % (sizeof(printable_chars) - 1)];
    }

    return result;
}

int main()
{
    int length = 10000;

    string randomStr = random_string(length);
    char c = 'a';
    for(int index = 9000; index < 9005; index++)
    {
        randomStr[index] = c;
        ++c;
    }
    c = 'a';
    for(int index = 9005; index < 9015; index++)
    {
        randomStr[index] = c;
        ++c;
    }


    cout << randomStr << endl;

    return 0;
}
