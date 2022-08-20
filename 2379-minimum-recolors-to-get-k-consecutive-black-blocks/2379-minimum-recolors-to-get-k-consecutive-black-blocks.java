class Solution {
    public int minimumRecolors(String blocks, int k) {
        int res = Integer.MAX_VALUE, st = 0, temp = 0;
        for(int en=0;en<blocks.length();en++) {
            if(blocks.charAt(en) == 'W') temp++;
            while(en - st + 1 >= k) {
                //System.out.println(en + " " + st + " " + temp);
                res = Math.min(res, temp);
                if(blocks.charAt(st) == 'W') temp--;
                st++;
            }
        }
        return res;
    }
}