#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "������� ����� �����:" << endl;
	cin >> n;
	while (n)
	{
		cout << n % 10 << endl;
		n /= 10;
	}
	return 0;
}
 