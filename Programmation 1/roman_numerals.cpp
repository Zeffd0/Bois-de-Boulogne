//Convert input from 1 to 4999 into roman numerals
#include <iostream>

using namespace std;

int main()
{

	int fourDigitsNumber = 0;
	int thousands = 0;
	int hundreds = 0;
	int tens = 0;

	cout << "Enter a value from 1 to 4999 : ";
	cin >> fourDigitsNumber;

	thousands = fourDigitsNumber / 1000;
	fourDigitsNumber %= 1000;

	hundreds = fourDigitsNumber / 100;
	fourDigitsNumber %= 100;

	tens = fourDigitsNumber / 10;
	fourDigitsNumber %= 10;

	switch (thousands)
	{
		case 1:		cout << "M";		break;
		case 2:		cout << "MM";		break;
		case 3:		cout << "MMM";		break;
		case 4:		cout << "MMMM";		break;
	}

	switch (hundreds)
	{
		case 1:		cout << "C";		break;
		case 2:		cout << "CC";		break;
		case 3:		cout << "CCC";		break;
		case 4:		cout << "CD";		break;
		case 5:		cout << "D";		break;
		case 6:		cout << "DC";		break;
		case 7:		cout << "DCC";		break;
		case 8:		cout << "DCCC";		break;
		case 9:		cout << "CM";		break;
	}

	switch (tens)
	{
		case 1:		cout << "X";		break;
		case 2:		cout << "XX";		break;
		case 3:		cout << "XXX";		break;
		case 4:		cout << "XL";		break;
		case 5:		cout << "L";		break;
		case 6:		cout << "LX";		break;
		case 7:		cout << "LXX";		break;
		case 8:		cout << "LXXX";		break;
		case 9:		cout << "XC";		break;
	}

	switch (fourDigitsNumber)
	{
		case 1:		cout << "I";		break;
		case 2:		cout << "II";		break;
		case 3:		cout << "III";		break;
		case 4:		cout << "IV";		break;
		case 5:		cout << "V";		break;
		case 6:		cout << "VI";		break;
		case 7:		cout << "VII";		break;
		case 8:		cout << "VIII";		break;
		case 9:		cout << "IX";		break;
	}
}
