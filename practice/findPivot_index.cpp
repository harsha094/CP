class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        unordered_map<int, int> lSum;
        unordered_map<int, int> rSum;

        int temp = 0;
        for(int i=0; i<nums.size(); i++) {
            lSum[i] = temp;
            temp += nums[i];
        }

        temp = 0;
        for(int j=nums.size()-1; j>=0; j--) {
            rSum[j] = temp;
            temp += nums[j];
        }

        for(int i=0; i<nums.size(); i++) {
            if(lSum[i] == rSum[i]) return i;
        }
        return -1;
    }
};