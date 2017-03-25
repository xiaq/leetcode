// Boyer-Moore majority vote algorithm.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = nums[0];
        int nx = 1;
        for (int i = 1; i < nums.size(); i++) {
            int e = nums[i];
            if (nx == 0) {
                nx = 1;
                x = e;
            } else if (x == e) {
                nx++;
            } else { // nx > 0 && x != e
                nx--;
            }
        }
        return x;
    }
};
