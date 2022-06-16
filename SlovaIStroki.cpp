#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main()   //Для работы необходимо создать txt файл в директории программы, Пример где должен быть файл: C:\Users\artem\source\repos\SlovaIStroki\SlovaIStroki
{
    ifstream File;
    string fileName;
    string word;
    int slova = 0;
    int stroki = 0;
    char* str = new char[1024];
    int q = 0;

    cout << "Vvedite nazvanie faila v deriktorii programmi: ";
    getline(cin, fileName);

    File.open(fileName.c_str());
    if (!File.is_open())
        perror("Error");
    else
    {
        cout << "Vvedite 1 dlya podscheta strok, 2 dlya podscheta slov: ";
        cin >> q;
        switch (q)
        {
        case 1:
        {
            while (!File.eof())
            {
                File.getline(str, 1024, '\n');
                stroki++;
            }
            cout << "Kolichestvo strok: " << stroki << '\n';
            File.close();
            cin.get();
            break;
        }
        case 2:
        {
            while (!File.eof())
            {
                File >> word;
                slova++;
            }
            cout << "Kolichestvo slov: " << slova << '\n';
            File.close();
            cin.get();
            break;
        }
        }
    }
}