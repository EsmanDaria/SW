#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, c, d, r1, r2, r3;
	cout << "����� ���������������" << endl;
	cin >> a;
	cout << "������ ���������������" << endl;
	cin >> b;
	cout << "������ ���������������" << endl;
	cin >> c;
	cout << "������� ���������" << endl;
	cin >> d;
	r1 = sqrt(a * a + b * b);
	r2 = sqrt(a * a + c * c);
	r3 = sqrt(b * b + c * c);
	if ((d > r1), (d > r2), (d > r3))
		cout << "�����" << endl;
	else cout << "�� �����" << endl;
	return 0;

}