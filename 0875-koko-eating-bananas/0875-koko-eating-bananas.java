class Solution {
    private boolean canKokoFinish(int[] piles, int h, int k) {
        for(int pile: piles) {
            h -= (pile / k) + (pile % k == 0 ? 0 : 1);
            if(h < 0) return false;
        }
        
        return true;
    }
    
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1, high = 0;
        for(int pile: piles) high = Math.max(pile, high);
                
        while(low < high) {
            int mid = (low + ((high - low) / 2));
            
            if(canKokoFinish(piles, h, mid)) high = mid;
            else low = mid + 1;
        }
        
        return low;
    }
}