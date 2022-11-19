class Solution {
    public String simplifyPath(String path) {
        String[] paths = path.split("/");
        Deque<String> stc = new LinkedList<String>();
        
        for(String pathPart: paths) {
            if(pathPart.equals(".") || pathPart.length() < 1)
                continue;
            else if(pathPart.equals("..")) {
                if(stc.size() > 0) stc.removeFirst();
            }
            else stc.addFirst(pathPart);
        }
        
        StringBuilder res = new StringBuilder("");
        
        while(stc.size() > 0) {
            res.append('/');
            res.append(stc.pollLast());
        }
        
        return res.length() > 0 ? res.toString() : "/";
    }
}