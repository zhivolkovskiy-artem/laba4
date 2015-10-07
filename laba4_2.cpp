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
		delete[] number;
	}

	return sum;
}

void assert(char* s, int myanswer)
{
	int ans = calculator(s);
	if (ans == myanswer)
		cout << "OK" << endl;
	else
		cout << "FAIL" << endl;
}
int main() {
	char s1[] = "-43+3-1-11";
	assert(s1, -52);
	char s2[] = "324+36-3583-6+13";
	assert(s2, -3216);
	char s3[] = "-50182-123+1+0-1230";
	assert(s3, -51534);
	char s4[] = "276+297";
	assert(s4, 573);
	char s5[] = "123+321";
	assert(s5, 444);
	return 0;
}
