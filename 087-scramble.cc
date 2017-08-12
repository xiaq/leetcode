class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1.length() <= 1) {
            return s1 == s2;
        }
        int n = s1.length();
        unordered_map<char, int> m;
        for (int i = 0; i < n; i++) {
            m[s1[i]]++;
            m[s2[i]]--;
        }
        for (auto it = m.cbegin(); it != m.cend(); it++) {
            if (it->second != 0) {
                return false;
            }
        }
        for (int i = 1; i < n; i++) {
            bool b = (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
                     (isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n-i)));
            if (b) {
                return true;
            }
        }
        return false;
    }
};
