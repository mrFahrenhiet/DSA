class Solution {
    private List<String> res;
    private void helper(String s, HashSet<String> dict, StringBuilder sent) {
        if(s.length() <= 0) {
            sent.deleteCharAt(sent.length() - 1);
            res.add(new String(sent.toString()));
            sent.append(" ");
            return;
        }
        
        for(int i=1;i<=s.length();i++) {
            String temp = s.substring(0, i);
            if(dict.contains(temp)) {
                // System.out.println(temp);
                int stIdx = sent.length();
                sent.append(temp);
                sent.append(" ");
                helper(s.substring(i), dict, sent);
                
                if(sent.charAt(sent.length() - 1) == ' ')
                    sent.deleteCharAt(sent.length() - 1);
                
                sent.delete(stIdx, stIdx + temp.length());
            }
        }
        
        return;
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        res = new ArrayList<String>();
        StringBuilder temp = new StringBuilder();
        HashSet<String> dict = new HashSet<String>(wordDict);
        helper(s, dict, temp);
        return res;
    }
}