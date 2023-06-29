#include <iostream>

using namespace std;

int trailingZeroes(int n)
{
	int trailing_zeroes = 0;
	int temp = n;
	int unit_place = temp % 10;
	temp /= 10;
	while (unit_place == 0 && temp != 0)
	{
		trailing_zeroes++;
		unit_place = temp % 10;
		temp /= 10;
	}
	int even = n / 2;
	int fives = n / 5;
	int tens = n / 10;
	int only_fives = fives - tens;
	int even_without_tens = even - tens;
	int selected;
	cout << even_without_tens << " " << only_fives << " " << tens << endl;
	selected = min(even_without_tens, only_fives);
	return tens + selected;
}

int main(){
	int n = 30;
	cout << trailingZeroes(n) << endl;
}