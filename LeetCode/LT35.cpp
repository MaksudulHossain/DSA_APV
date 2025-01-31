#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        int mid;
        while (left<=right)
        {
            mid = (left + right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                right = mid - 1;
            }

            else{
                left = mid + 1;
            }
        }
        if(target>nums[mid]) return mid+1;
        else if(target<nums[mid]) return mid;
        else if(mid==0) return 0;
        else return mid-1;
        
        
    }
};

int main() {
    Solution sol;

    // Test case 1: Normal case where target is found in the array
    vector<int> nums1 = {1, 2,4,5};
    int target1 = 3;
    cout << "Test case 1 result: " << sol.searchInsert(nums1, target1) << endl;  // Expected output: 2

    return 0;
}