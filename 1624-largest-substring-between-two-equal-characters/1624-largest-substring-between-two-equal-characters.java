class NosPair {
    public int first;
    public int last;
    
    NosPair(int occ) {
        this.first = occ;
        this.last = occ;
    }
}

class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        HashMap<Character, NosPair> map = new HashMap<>();
        boolean eqCheck = false;
        int res = 0;
        
        for(int i=0;i<s.length();i++) {
            if(!map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), new NosPair(i));
            }
            else {
                eqCheck = true;
                NosPair temp = map.get(s.charAt(i));
                temp.last = i;
                
                res = Math.max(res, (temp.last - temp.first + 1 - 2));
                
                map.put(s.charAt(i), temp);
            }
        }
        
        return eqCheck ? res : -1;
    }
}