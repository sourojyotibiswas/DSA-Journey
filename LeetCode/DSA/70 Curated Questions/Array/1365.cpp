class Solution {
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
            vector<int> sortedNums = nums;
            sort(sortedNums.begin(), sortedNums.end());
    
            unordered_map<int, int> countMap;
            for (int i = 0; i < sortedNums.size(); i++) {
                if (countMap.find(sortedNums[i]) == countMap.end()) {
                    countMap[sortedNums[i]] = i;
                }
            }
    
            vector<int> result;
            for (int num : nums) {
                result.push_back(countMap[num]);
            }
            return result;
        }
    };
    