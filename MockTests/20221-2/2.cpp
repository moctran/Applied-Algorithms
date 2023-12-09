#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> arr;

void insert(int x)
{
    arr.push_back(x);
}

int deleteMax(void)
{
    int max = *max_element(arr.begin(), arr.end());
    vector<int> :: iterator it;
    it = find(arr.begin(), arr.end(), max);
    arr.erase(it);
    return max;
}

int main(void)
{
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    string command;
    while (command != "*")
    {
        cin >> command;

        if (command == "delete-max")
            cout << deleteMax() << endl;
        
        else if (command == "insert")
        {
            int cmd;
            cin >> cmd;
            insert(cmd);
        }
    }

    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
}