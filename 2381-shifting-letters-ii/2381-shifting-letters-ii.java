class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        char[] charArr = s.toCharArray();
        int[] line = new int[s.length() + 1];
        for(int[] shift: shifts) {
            line[shift[0]] += (shift[2] == 1 ? 1 : -1);
            line[shift[1]+1] += (shift[2] == 1 ? -1 : 1);
        }
        for(int i=1;i<line.length;i++) line[i] += line[i-1];
        for(int i=0;i<charArr.length;i++) {
            int inc = (charArr[i] - 'a' + line[i]) % 26;
            inc = (inc + 26) % 26;
            int x = (int)'a' + inc;
            charArr[i] = (char)x; 
        }
        return String.valueOf(charArr);
    }
}