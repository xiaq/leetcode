import java.util.List;
import java.util.LinkedList;
import java.lang.StringBuilder;

class Solution {
    interface Node {
        void write(StringBuilder sb);
    }

    // SimpleNode is a sequence of non-special characters, like "abc".
    class SimpleNode implements Node {
        String str;
        SimpleNode(String s) {
            str = s;
        }
        public void write(StringBuilder sb) {
            sb.append(str);
        }
    }

    // RepeatNode is a number followed by something in brackets, like "4[x]".
    // The thing inside brackets can have its own internal structure; in
    // "4[x]" it is simply a SimpleNode, but in "4[abc5[y]]", it is a
    // SequenceNode. In fact, the parser always parses a SequenceNode, since
    // SimpleNode and RepeatNode are both equivalent to a SequenceNode with
    // just one child.
    class RepeatNode implements Node {
        int time;
        Node node;
        RepeatNode(int t, Node n) {
            time = t;
            node = n;
        }
        public void write(StringBuilder sb) {
            String s = writeNode(node);
            for (int i = 0; i < time; i++) {
                sb.append(s);
            }
        }
    }

    // SequenceNode is a sequence of nodes that run together, like "ab4[x]",
    // which contains a SimpleNode and a RepeatNode. It is the top-level node:
    // the input is parsed into a SequenceNode.
    class SequenceNode implements Node {
        List<Node> nodes;
        SequenceNode(List<Node> n) {
            nodes = n;
        }
        public void write(StringBuilder sb) {
            for (Node n: nodes) {
                n.write(sb);
            }
        }
    }

    public String writeNode(Node n) {
        StringBuilder sb = new StringBuilder();
        n.write(sb);
        return sb.toString();
    }

    class Parser {
        // Full text of the code to parse.
        final String text;
        // Index of the next character to parse.
        int pos;

        Parser(String t) {
            text = t;
            pos = 0;
        }

        // Each of the parse* methods parses a node, and move pos to the next
        // character to be parsed.

        SimpleNode parseSimple() {
            int start = pos;
            while (pos < text.length()) {
                char c = text.charAt(pos);
                if (Character.isDigit(c) || c == '[' || c == ']') {
                    break;
                }
                pos++;
            }
            return new SimpleNode(text.substring(start, pos));
        }

        SequenceNode parseSequence() throws SyntaxError {
            List<Node> nodes = new LinkedList<>();
            while (pos < text.length()) {
                char c = text.charAt(pos);
                if (Character.isDigit(c)) {
                    nodes.add(parseRepeat());
                } else if (c == ']') {
                    break;
                } else {
                    nodes.add(parseSimple());
                }
            }
            return new SequenceNode(nodes);
        }

        RepeatNode parseRepeat() throws SyntaxError {
            int t = 0;
            while (pos < text.length()) {
                char c = text.charAt(pos);
                if (!Character.isDigit(c)) {
                    break;
                }
                t = t * 10 + (int) (c - '0');
                pos++;
            }
            if (pos == text.length() || text.charAt(pos) != '[') {
                throw new SyntaxError(pos, "should be [");
            }
            pos++;

            Node n = parseSequence();
            if (pos == text.length() || text.charAt(pos) != ']') {
                throw new SyntaxError(pos, "should be ]");
            }
            pos++;

            return new RepeatNode(t, n);
        }
    }

    class SyntaxError extends Exception {
        int pos;
        String message;

        SyntaxError(int p, String m) {
            pos = p;
            message = m;
        }

        public String toString() {
            return "Syntax error at position " + pos + ": " + message;
        }
    }

    public String decodeString(String s) {
        try {
            return writeNode(new Parser(s).parseSequence());
        } catch (SyntaxError e) {
            return e.toString();
        }
    }
}
