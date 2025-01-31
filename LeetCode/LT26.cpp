class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
            if(nums_map.find(nums[i]) != nums_map.end()){
                nums_map[nums[i]] = 1;
            }
            else{
                nums_map[nums[i]] += 1;
            }
        }

        

    // Iterate over the map and store keys in the vector
        int index = 0;
        for (const auto& pair : nums_map) {
            nums[index] = pair.first;
            index++;
        }
        return nums_map.size();


        }
        
        
        
        
    };