class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0, j = 0;
        HashSet<Character> charSet = new HashSet<>();
        for(int i=0;i<s.length();i++) {
            while(charSet.contains(s.charAt(i))) charSet.remove(s.charAt(j++));
            //if(charSet.contains(s.charAt(j))) charSet.remove(s.charAt(j++));
            
            charSet.add(s.charAt(i));
            
            res = Math.max(res, i - j + 1);
        }
        return res;
    }
}