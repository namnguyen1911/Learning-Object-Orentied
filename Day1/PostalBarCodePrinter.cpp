#include <iostream>
#include <string>
using namespace std;

string getZip()
{
    string input;
    cout << "Enter 5-digit-zipcode: ";
    cin >> input;
    return input;
}

void printDigit(int d)
{
    switch(d)
    {
        case 1: cout << "...||"; break;
        case 2: cout << "..|.|"; break;
        case 3: cout << "..||."; break;
        case 4: cout << ".|..|"; break;
        case 5: cout << ".|.|."; break;
        case 6: cout << ".||.."; break;
        case 7: cout << "|...|"; break;
        case 8: cout << "|..|."; break;
        case 9: cout << "|.|.."; break;
        case 0: cout << "||..."; break;
        default: cout << "Invalid digit";
    }
}

int calcCheckDigit(int sum)
{
    int roundOfSum = sum;
    while(!(roundOfSum % 10 == 0))
    {
        roundOfSum++;
    }
    return roundOfSum - sum;
}

void printBarCode(string zip)
{
    int sum = 0;

    cout << "|";
    for(int i = 0; i < zip.size(); i++)
    {
        int temp = zip[i] - '0';
        sum += temp;
        printDigit(temp);
    }
    printDigit(calcCheckDigit(sum));
    cout << "|";
}

int main()
{
    string zipcode;
    
    zipcode = getZip();
    printBarCode(zipcode);

    return 0;
}