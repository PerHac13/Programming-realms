#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets;

void generateSubset(vector<int> &subset, int i, vector<int> &nums)
{
    if (i == nums.size())
    {
        subsets.push_back(subset);
        return;
    }

    // ith element not in subset
    generateSubset(subset, i + 1, nums);

    // ith element in subset
    subset.push_back(nums[i]);
    generateSubset(subset, i + 1, nums);
    subset.pop_back();
}

int main()
{

    vector<int> a = {1, 2, 3, 4};
    vector<int> v;
    generateSubset(v, 0, a);
    for (auto subset : subsets)
    {
        for (auto &it : subset)
        {
            cout << it << ' ';
        }
        cout << endl;
    }

    return 0;
}