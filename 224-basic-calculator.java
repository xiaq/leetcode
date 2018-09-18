class Solution {
    String text;
    int pos;

    public int calculate(String s) {
        s = s.replace(" ", "");
        text = s;
        pos = 0;
        return expr();
    }

    char cur() {
        return pos < text.length() ? text.charAt(pos) : 0;
    }

    int expr() {
        int result = term();
        while (cur() == '+' || cur() == '-') {
            if (cur() == '+') {
                pos++;
                result += term();
            } else {
                pos++;
                result -= term();
            }
        }
        return result;
    }

    int term() {
        if (cur() == '(') {
            pos++; // Skip '('
            int result = expr();
            pos++; // Assume ')'
            return result;
        }
        int num = 0;
        while ('0' <= cur() && cur() <= '9') {
            num = num * 10 + (cur() - '0');
            pos++;
        }
        return num;
    }
}
