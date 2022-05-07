#include <iostream>
#include <fstream>
#include <random>
#include <filesystem>
#include <cassert>
#include <algorithm>
#include <string>

#include <stdlib.h>
#include <windows.h>
#include <shlwapi.h>
#include <vector>

using namespace std;

string ExePath()
{
    return ("C://Users//egrvr//Documents//proga//c_inf//data_base//");
}

int search(vector<string> arr)
{
    string el;
    cin >> el;
    auto it = find(arr.begin(), arr.end(), el);

    if (it != arr.end())
    {
        cout << "Element Found" << endl;
        return distance(arr.begin(), it);
    }
    else
    {
        cout << "Element Not Found" << endl;
        return -1;
    }
}

void display(vector<string> s1, vector<string> s2, vector<string> s3, int index)
{
if (index != -1)
    cout << "\nname - "<< s1[index]<< "; number - "<< s2[index]<< "; email - "<< s3[index]<< '\n';
}

void input(vector<string> s1, vector<string> s2, vector<string> s3, int len)
{

    cout << "\n0 - exit \n1 - search by name \n2 - search by phone \n3 - search by email \n";

    int input_n;

    while (true)
    {
        cin >> input_n;

        switch (input_n)
        {
        case (0):
        {
            return;
            exit;
            break;
        }
        case (1):
        {
            display(s1,s2,s3,search(s1));
            break;
        }
        case (2):
        {
            display(s1,s2,s3,search(s2));
            break;
        }
        case (3):
        {
            display(s1,s2,s3,search(s3));
            break;
        }
        }
    }
}

//   input(link_table, SizeOf, array2d, count, names);

vector<string> readData(string name)
{
    string filename(ExePath() + name + ".txt");
    string line;

    ifstream input_file(filename);

    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    }
    string word;
    vector<string> array_to_write;

    while (input_file >> word)
    {
        array_to_write.push_back(word);
    }

    input_file.close();
    return array_to_write;
}

void Start_Session()
{
    string name = "sprav";
    // cin >> name;
    auto data = readData(name);

    vector<string> s1;
    vector<string> s2;
    vector<string> s3;

    for (int i = 0; i < data.size() / 3; i++)
    {
        s1.push_back(data[i * 3 + 0]);
        s2.push_back(data[i * 3 + 1]);
        s3.push_back(data[i * 3 + 2]);
    }
    data.clear();
    int size = s1.size();
    input(s1, s2, s3, size);
}

int main(int args, char **argv)
{

    Start_Session();
    std::cout << '\n'
              << "End" << '\n';
    //system("pause");
    return 0;
}