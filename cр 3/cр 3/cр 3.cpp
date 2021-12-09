#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct exam
{
    int studentID;
    double avMark;
    string nameOfExam;
    int mark;
};

exam* resizeArray(int& oldSize, int newSize, exam* st)
{
    if (oldSize == newSize)
    {
        return st;
    }
    exam* newArray = new exam[newSize];
    oldSize = newSize < oldSize ? newSize : oldSize;
    for (int i = 0; i < oldSize; i++)
        newArray[i] = st[i];
    oldSize = newSize;
    delete[] st;
    return newArray;
}

exam* structureFromFile(string fileName, int& size)
{
    ifstream file("sw.txt");
    if (!file.is_open())
    {
        return nullptr;
    }
    size <= 0 ? size - 1 : size = size;
    exam* st = new exam[size];
    int numberOfLines = 0;
    while (!file.eof())
    {
        if (numberOfLines == size)
        {
            st = resizeArray(size, size + 1, st);
        }
        file >> st[numberOfLines].studentID;
        file >> st[numberOfLines].avMark;
        file >> st[numberOfLines].nameOfExam;
        file >> st[numberOfLines].mark;
        numberOfLines++;
    }
    file.close();
    return st;
}

void writeStuctureInFile1(string fileName, exam* st, int size, int openMode)
{
    ofstream file(fileName, openMode);
    if (!file.is_open())
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        file << st[i].studentID << " " << st[i].avMark << " " << st[i].nameOfExam << " " << st[i].mark << endl;
    }
    file.close();
}

void writeStuctureInFile2(string fileName, exam* st, int size, int openMode)
{
    exam *replace;
    ofstream file(fileName, openMode);
    if (!file.is_open())
    {
        return;
    }
    file << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        file << st[i].studentID << " " << st[i].avMark << " " << st[i].nameOfExam << " " << st[i].mark << endl;
    }
    file.close();
}

void writeStuctureInFile3(string fileName, exam* st, int size, int openMode)
{
    exam* sort;
    ofstream file(fileName, openMode);
    if (!file.is_open()) 
    {
        return;
    }
    else
    {
        cout << "File is open!" << endl;
    }
    file << endl;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 1; j < size - i - 1; j++)
        {
            if (st[j].avMark < st[j + 1].avMark)
            {
                exam temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }
    file << "The array is sorted in descending order(avMark VVV)." << endl;
    for (int i = 0; i < size; i++)
    {
        file << st[i].studentID << " " << st[i].avMark << " " << st[i].nameOfExam << " " << st[i].mark << endl;
    }
    file.close();
}

int sizeOfFile(string fileName)
{
    fstream file(fileName);
    file.seekg(0, std::ios::end);
    int size = file.tellg();
    file.close();
    return size;
}

void main()
{
    int size = 1;
    exam* exam = structureFromFile("sw.txt", size);
    writeStuctureInFile1("text.txt", exam, size, ios_base::out);
    writeStuctureInFile2("text.txt", exam, size, ios_base::app);
    writeStuctureInFile3("text.txt", exam, size, ios_base::app);
    int fileSize = sizeOfFile("sw.txt");
    cout << "size of the file: " << fileSize<<endl;
    cout << "programm completed!";
}
