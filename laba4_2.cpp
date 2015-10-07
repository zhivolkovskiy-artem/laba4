#include <iostream>
#define MAXSIZE 100

using namespace std;

int calculator(char *str)
{
	int size = strlen(str), sum = 0, i = 0;
	while (i < size)
	{
		int j = i;
		char *number = new char[MAXSIZE];
		while (isdigit(str[j]))
		{
			j++;
		}
		for (int k = 0; k < j - i; k++)
		{
			number[k] = str[i + k];
		}
		if (str[i - 1] == '-') sum -= atoi(number);
		else sum += atoi(number);
		i += j - i + 1;
		delete [] number;
	}
	
	return sum;
}

int main()
{
	
	return 0;
}