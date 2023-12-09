#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    int k;
    int A;
    int B;
    vector<int> arr;
    int tmp;

    cin >> n >> k >> A >> B;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    int sum = 0;
    int result = 0;

    for (int i = 0; i <= n - k; i++)
    {
        for (int x = 0; x <= k - 1; x++)
        {
            sum = sum + arr[i+x];
        }
        // cout << i << " " << sum << endl;
        if (sum >= A && sum <= B)
        {
            result++;
            // cout << i << endl;
        }
        sum = 0;
    }
    cout << result << "\n";
}