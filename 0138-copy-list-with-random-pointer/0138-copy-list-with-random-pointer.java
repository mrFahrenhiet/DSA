/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        HashMap<Node, Node> nodeMap = new HashMap<Node, Node>();
        
        Node temp = head;
        
        while(temp != null) {
            Node newList = new Node(temp.val);
            
            nodeMap.put(temp, newList);
            
            temp = temp.next;
        }
        
        for(Node key: nodeMap.keySet()) {
            nodeMap.get(key).next = nodeMap.get(key.next);
            nodeMap.get(key).random = nodeMap.get(key.random);
        }
        
        return nodeMap.get(head);
    }
}