class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++)
        {
            // keep vector elemenets in map key,val pair
            if(nums_map.find(nums[i]) != nums_map.end()){
                nums_map[nums[i]] += 1;
            }
            else{
                nums_map[nums[i]] = 1;
            }
        }


        //erasing the key,val pair that equals target value
        for (auto it = nums_map.begin(); it != nums_map.end(); ) {
            if (it->first == val) {
                it = nums_map.erase(it); 
            } else {
                ++it; 
            }
        }

        //writing the key:val in the original vector val times say 2:3 it will write val 2 three times
        int j = 0; 
        for (const auto& pair : nums_map) {
            for (int i = 0; i < pair.second && j < nums.size(); i++) {
                nums[j++] = pair.first;
            }
        }

        //calculating total values from remaining map
        int sum = 0;  

        for (const auto& pair : nums_map) {
            sum += pair.second;
        }

        return sum;
        
        
    }
};