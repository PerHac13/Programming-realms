#include <bits/stdc++.h>

using namespace std;

// Max sum sub array of size =k & sum<X
int maxSubarraySum(int arr[], int n, int k, int x)
{

    int sum = 0, ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum < x)
        ans = sum;
    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];
        if (sum < x)
            ans = max(ans, sum);
    }
    return ans;
}

// Smallest Subarray with sum > x
int minSubarraySize(int arr[], int n, int k, int x)
{
    int sum = 0, minLength = n + 1;
    int s = 0, e = 0;
    while (e < n)
    {
        while (sum <= x && e < n)
        {
            sum += arr[e++];
        }
        while (sum > x && s < n)
        {
            if (e - s < minLength)
            {
                minLength = e - s;
                sum -= arr[s++];
            }
        }
    }
    return minLength;
}

// Form Number Divisible by 3
void computeNumberFromSubarray(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    bool found = 0;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = 1;
    }

    for (int j = k; j < arr.size(); j++)
    {
        if (found)
            break;
        sum = sum + arr[j] - arr[j - k];
        if (sum % 3 == 0)
        {
            ans = make_pair(j - k + 1, j);
            found = 1;
        }
    }
    if (!found)
        ans = make_pair(-1, 0);
    if (ans.first == -1)
        cout << "No such array" << endl;
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}

// Subarray of size K with palindromic concatenation
bool isPalindrome(int n)
{
    int tmp = n, num = 0;
    while (tmp > 0)
    {
        num = num * 10 + tmp % 10;
        tmp /= 10;
    }
    if (num == n)
        return 1;
    return 0;
}

int findPalindromicSubarray(vector<int> arr, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        num = num * 10 + arr[i];
    }
    if (isPalindrome(num))
        return 0;

    for (int j = k; j / arr.size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];
        if (isPalindrome(num))
        {
            return j - k + 1;
        }
    }
    return -1;
}

int main()
{

    return 0;
}