#include <iostream>
#include <ctime>

using namespace std;

void arrayCreation(int a[], int& size)
{
    for (int i = 0; i < size; ++i)
    {
        a[i] = rand() % 41 - 20;
        cout << "a[" << i + 1 << "] = " << a[i] << endl;
    }
}

int main ()
{
    setlocale (LC_ALL, "rus");
    srand (time(0));
    int arsize;
    cout << "������� ������ �������: "; 
    cin >> arsize;
    int* ar = new int[arsize];
    arrayCreation(ar, arsize);
    cout << endl;
    cout << "�����, ������� ������ �������� ���� ����������: ";
    for (int i = 2; i < arsize; i++)
    {
        if (ar[i] < (ar[i - 2] - ar[i - 1]))
            cout << ar[i] << ", ";
    }
    delete[] ar;
}
