class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        for(int i=0;i<strs.length;i++) {
            char[] charStr = strs[i].toCharArray();
            Arrays.sort(charStr);
            String strsSorted = new String(charStr);
            map.computeIfAbsent(strsSorted, k -> new ArrayList<>()).add(strs[i]);
        }
        for(String key: map.keySet()) res.add(map.get(key));
        
        return res;
    }
}