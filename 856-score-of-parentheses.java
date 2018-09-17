class Solution {
    String text;
    int pos;

    public int scoreOfParentheses(String s) {
        text = s;
        pos = 0;

        return expr();
    }
    
    // expr is 0 or more terms concatenated.
    public int expr() {
        int result = 0;
        while (pos < text.length() && text.charAt(pos) == '(') {
            result += term();
        }
        return result;
    }

    // term is expr wrapped in parenthese; or just ().
    public int term() {
        pos++; // Assume '('
        if (text.charAt(pos) == ')') {
            pos++;
            return 1;
        }
        int exprValue = expr();
        pos++; // Assume ')'
        return exprValue * 2;
    }
}
