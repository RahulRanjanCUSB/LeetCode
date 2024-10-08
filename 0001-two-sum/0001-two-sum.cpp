//Approach 2: using Map

// Approach 1: Aleady submitted using brute force.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int idx = 0;
        std::unordered_map<int, int> intmap;
        std::unordered_map<int, int>::const_iterator iter;
        std::unordered_map<int, int>::const_iterator end = intmap.end();
        
        for (auto num : nums) {
            iter = intmap.find(target-num);
            if (iter == end) {
                intmap[num] = idx;
                idx++;
            }
            else { break; }
        }
        return {iter->second, idx};            
    }
};
