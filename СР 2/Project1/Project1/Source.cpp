#include <iostream>
#include <ctime>

using namespace std;

void arrayCreation(int array[], int& size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % 41 - 20;
        cout << "������: " << "a[" << i + 1 << "] = " << array[i] << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int arsize, num;
    cout << "������� ������ �������: ";
    cin >> arsize;
    int* ar = new int[arsize];
    arrayCreation(ar, arsize);
    cout << endl;
    cout << "������� ����� ";
    cin >> num;
    cout << "������� ������� �������� �������, ������� ���������� �����: ";
    for (int i = 0; i < arsize; i++)
    {
        if (ar[i] == num)
        {
            cout << i;
            break;
        }
    }
    delete[] ar;
}
