// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
#include <bits/stdc++.h>
// #include <unordered_map>
// #include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            nums_map[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            int complement = target - nums[i];
            if(nums_map.find(complement) != nums_map.end() && nums_map[complement] != i){
                return {i, nums_map[complement]};
            }
        }
        return {};
        
        
    }
};


// **Main function to test the twoSum method**
int main() {
    Solution solution;

    // Example test case
    std::vector<int> nums = {3,3};
    int target = 6;

    // Call the function
    std::vector<int> result = solution.twoSum(nums, target);

    // Print the result
    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}



 