class Solution {
    public int secondsToRemoveOccurrences(String s) {
        StringBuilder str = new StringBuilder(s);
        int res = 0;
        
        boolean flag = false;
        while(true) {
            int i = 1;
            flag = false;
            while(i < str.length()) {
                if(str.charAt(i) == '1' && str.charAt(i-1) == '0') {
                    flag = true;
                    str.setCharAt(i, '0');
                    str.setCharAt(i-1, '1');
                    i += 2;
                }
                else if(str.charAt(i) == '1' && str.charAt(i-1) != '0') i += 2;
                else if(str.charAt(i) == '0') i++;
                else i++;
            }
            if(flag) res++;
            else break;
        }
        return res;
    }
}