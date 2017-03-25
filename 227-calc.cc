// Recursive descent parser that evaluates the input on the fly.

class Solution {
    string src;
    int idx;

    void skipspaces() {
        while (idx < src.length() && src[idx] == ' ') {
            idx++;
        }
    }
    int num() {
        skipspaces();
        int r = 0;
        while (idx < src.length() && '0' <= src[idx] && src[idx] <= '9') {
            r = r * 10 + src[idx] - '0';
            idx++;
        }
        cout << r << endl;
        return r;
    }
    int muldiv() {
        int r = num();
        skipspaces();
        while (idx < src.length()) {
            if (src[idx] == '*') {
                idx++;
                r *= num();
            } else if (src[idx] == '/') {
                idx++;
                r /= num();
            } else {
                break;
            }
            skipspaces();
        }
        return r;
    }
    int addsub() {
        int r = muldiv();
        skipspaces();
        while (idx < src.length()) {
            if (src[idx] == '+') {
                idx++;
                r += muldiv();
            } else if (src[idx] == '-') {
                idx++;
                r -= muldiv();
            } else {
                break; // actually an error
            }
            skipspaces();
        }
        return r;
    }
public:
    int calculate(string s) {
        src = s;
        idx = 0;
        return addsub();
    }
};
