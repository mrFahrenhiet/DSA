class Solution {
    public boolean makeEqual(String[] words) {
        HashMap<Character, Integer> freqMap = new HashMap<Character, Integer>();
        
        for(String word: words) {
            for(int i=0;i<word.length();i++) {
                freqMap.put(word.charAt(i), freqMap.getOrDefault(word.charAt(i), 0) + 1);
            }
        }
        
        for(char k: freqMap.keySet()) {
            if(freqMap.get(k) % words.length != 0) return false;
        }
        
        return true;
    }
}