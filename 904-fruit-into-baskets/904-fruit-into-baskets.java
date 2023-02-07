class Solution {
    public int totalFruit(int[] fruits) {
        HashMap<Integer, Integer> fruitTypes = new HashMap<>();
        int res = 1;
        for(int i=0, j=0;i<fruits.length;i++) {
            if(fruitTypes.size() >= 2 && !fruitTypes.containsKey(fruits[i])) {
                int minIdx = fruits.length, minKey = -1;
                for(int key: fruitTypes.keySet()) {
                    if(minIdx > fruitTypes.get(key)) {
                        minIdx = fruitTypes.get(key);
                        minKey = key;
                    }
                }
                
                fruitTypes.remove(minKey);
                j = minIdx+1;
            }
            
            fruitTypes.put(fruits[i], i);
            res = Math.max(res, i - j + 1);

        }
        
        return res;
    }
}