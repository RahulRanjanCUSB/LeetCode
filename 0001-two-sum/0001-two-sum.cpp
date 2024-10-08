class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int diff = 0;
        vector<int> index;
        for(int i=0; i<nums.size(); i++)
        {
            diff = target - nums[i];
            for(int j=i+1; j<nums.size(); j++)
            {
                if(diff == nums[j])
                {
                    index.push_back(i);
                    index.push_back(j);
                }
                    
            } diff = 0;
                       
        }
        return index;
        
    }
};