// Count all the possible sums of a+b (a \in A, b \in B).

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> absum;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                absum[A[i] + B[j]]++;
            }
        }
        int r = 0;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                r += absum[-C[i]-D[j]];
            }
        }
        return r;
    }
};
