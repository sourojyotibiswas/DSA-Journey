class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> temp(nums.begin(), nums.end()); 
        vector<int> ans;

        for(int i = 1; i <= nums.size(); i++) {  
            if(temp.find(i) == temp.end()) ans.push_back(i);
        }
        return ans;
    }
};
