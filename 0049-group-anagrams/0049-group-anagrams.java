class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        
        for(int i=0;i<strs.length;i++) {
            char[] charMap = new char[26];
            for(int j=0;j<strs[i].length();j++)
                charMap[strs[i].charAt(j) - 'a']++;
            
            
            String strsSorted = String.valueOf(charMap);
            
            if(!map.containsKey(strsSorted)) map.put(strsSorted, new ArrayList<>());
            map.get(strsSorted).add(strs[i]);
        }
        
        for(String key: map.keySet()) res.add(map.get(key));
        
        return res;
    }
}