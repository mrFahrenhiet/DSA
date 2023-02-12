class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int window_size = s1.length();
        int[] freqMap = new int[26];
        
        // fill hm
        for(int i=0;i<s1.length();i++) freqMap[s1.charAt(i) - 'a']++;
        
        int j = 0;
        for(int i=0;i<s2.length();i++) {
            while(freqMap[s2.charAt(i) - 'a'] == 0) {
                freqMap[s2.charAt(j) - 'a']++;
                j++;
            }
            if(freqMap[s2.charAt(i) - 'a'] != 0) freqMap[s2.charAt(i) - 'a']--;
            if(i - j + 1 == window_size) return true;
        }
        
        return false;
    }
}