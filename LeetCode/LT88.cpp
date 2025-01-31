#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++)
        {
            nums1[m+i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
        
    }
};

int main() {
    Solution sol;

    // Test case 1: Merging two non-empty arrays
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2_1 = {2, 5, 6};
    sol.merge(nums1_1, 3, nums2_1, 3);
    cout << "Test case 1 result: ";
    for (int num : nums1_1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2: nums1 has no initial elements, nums2 has all elements
    vector<int> nums1_2 = {1};
    vector<int> nums2_2 = {};
    sol.merge(nums1_2, 1, nums2_2, 0);
    cout << "Test case 2 result: ";
    for (int num : nums1_2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3: nums2 is empty
    vector<int> nums1_3 = {1, 2, 3, 4};
    vector<int> nums2_3 = {};
    sol.merge(nums1_3, 4, nums2_3, 0);
    cout << "Test case 3 result: ";
    for (int num : nums1_3) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 4: nums1 is empty, nums2 has all elements
    vector<int> nums1_4 = {0};
    vector<int> nums2_4 = {1};
    sol.merge(nums1_4, 0, nums2_4, 1);
    cout << "Test case 4 result: ";
    for (int num : nums1_4) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}