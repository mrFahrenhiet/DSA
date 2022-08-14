class Solution {
    public String smallestNumber(String pattern) {
        StringBuilder res = new StringBuilder("");
        for(int i=1;i<=pattern.length()+1;i++) {
            char temp = (char)(i + '0');
            res.append(temp);
        }
        
        System.out.println(res);
        int change = 1;
        while(change > 0) {
            change = 0;
            for(int i=0;i<res.length()-1;i++) {
                if(pattern.charAt(i) == 'I' && res.charAt(i) > res.charAt(i+1)) {
                    char x = res.charAt(i+1);
                    res.setCharAt(i+1, res.charAt(i));
                    res.setCharAt(i, x);
                    change++;
                }
                
                if(pattern.charAt(i) == 'D' && res.charAt(i) < res.charAt(i+1)) {
                    char x = res.charAt(i+1);
                    res.setCharAt(i+1, res.charAt(i));
                    res.setCharAt(i, x);
                    change++;
                }
            }
        }
        return res.toString();
    }
}