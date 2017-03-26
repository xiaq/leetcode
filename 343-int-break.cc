// Without the "at least 2" constraint,
// f(n) = n          for n < 5
//      = 3 * f(n-3) otherwise
// With the constraint:
// f'(2) = 1, f'(3) = 2, f'(4) = 4
// f'(n) = f(n) for n >= 5

class Solution {
    int pow(int x, int p) {
        if (p == 0) {
            return 1;
        } else if (p == 1) {
            return x;
        } else {
            int y = pow(x, p/2);
            if (p % 2) {
                return y * y * x;
            } else {
                return y * y;
            }
        }
    }
public:
    int integerBreak(int n) {
        int acc = 1;
        if (n == 2) {
            return 1;
        } else if (n == 3) {
            return 2;
        } else if (n % 3 == 2) {
            return 2 * pow(3, (n-2) / 3);
        } else if (n % 3 == 0) {
            return 3 * pow(3, (n-3) / 3);
        } else if (n % 3 == 1) {
            return 4 * pow(3, (n-4) / 3);
        }
    }
};
