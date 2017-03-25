// Use a variation of the Boyer-Moore majority vote algorithm to find the two most frequent number,
// and go through the array again to determine whether they appear more than floor(n/3) times.

class Solution {
    bool isMajority(vector<int>& nums, int x) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                count++;
            }
        }
        return count > nums.size() / 3;
    }
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        int x, nx, y, ny;
        x = y = -1;
        nx = ny = 0;
        for (int i = 0; i < nums.size(); i++) {
            int z = nums[i];
            if (z == x) {
                nx++;
            } else if (z == y) {
                ny++;
            } else if (nx > 0 && ny > 0) {
                nx--;
                ny--;
            } else if (nx == 0) {
                nx = 1;
                x = z;
            } else { // ny == 0
                ny = 1;
                y = z;
            }
        }
        vector<int> ans;
        if (nx > 0 && isMajority(nums, x)) {
            ans.push_back(x);
        }
        if (ny > 0 && isMajority(nums, y)) {
            ans.push_back(y);
        }
        return ans;
    }
};
