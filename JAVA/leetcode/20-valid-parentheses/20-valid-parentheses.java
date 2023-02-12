class Solution {
    public boolean isValid(String s) {
        Stack<Character> stc = new Stack<Character>();
        for(int i=0;i<s.length();i++) {
            if(s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[')
                stc.push(s.charAt(i));
            else if(s.charAt(i) == ')' && !stc.isEmpty() && stc.peek() == '(') stc.pop();
            else if(s.charAt(i) == '}' && !stc.isEmpty() && stc.peek() == '{') stc.pop();
            else if(s.charAt(i) == ']' && !stc.isEmpty() && stc.peek() == '[') stc.pop();
            else return false;
        }
        return stc.isEmpty();
    }
}