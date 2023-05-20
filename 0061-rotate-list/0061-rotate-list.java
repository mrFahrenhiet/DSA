/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k == 0) return head;
        
        ListNode main = head, prev = null, cur = null, res = null;
        int len = 0;
        
        while(main != null) {
            main = main.next;
            len++;
        }
        
        
        main = head;
        k %= len;
        
        if(k == 0) return head;
        
        for(int i=0;i<len - k;i++) {
            prev = main;
            main = main.next;
        }
        
        prev.next = null;        
        
        cur = main;                
        while(cur != null && cur.next != null) {
            cur = cur.next;
        }
        
        if(cur != null) cur.next = head;
                
        return main;
    }
}