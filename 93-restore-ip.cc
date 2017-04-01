class Solution {
    bool ok(const string& s, int i, int j) {
        if (j-i > 3) {
            return false;
        }
        const char *ss = s.substr(i, j-i).c_str();
        if (j-i > 1 && ss[0] == '0') {
            return false;
        }
        return atoi(ss) <= 255;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        int i, j, k, l = s.length();
        for (i = 1; i <= min(3, l); i++) {
            if (!ok(s, 0, i)) {
                continue;
            }
            for (j = i+1; j <= min(i+3, l); j++) {
                if (!ok(s, i, j)) {
                    continue;
                }
                for (k = j+1; k <= min(j+3, l-1); k++) {
                    if (!ok(s, j, k) || !ok(s, k, l)) {
                        continue;
                    }
                    results.push_back(
                        s.substr(0, i) + "." + s.substr(i, j-i) + "."
                        + s.substr(j, k-j) + "." + s.substr(k, l-k));
                }
            }
        }
        return results;
    }
};
