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
    private ListNode helper(ListNode head, int k) {
        if(head == null) return null;
        
        ListNode tempTail = head;
        int tempLen = 0;
        
        while(tempTail != null && tempLen < k) {
            tempTail = tempTail.next;
            tempLen++;
        }
        
        if(tempLen < k) return head;
        
        ListNode cur = head, prev = null, nxt = head;
        int len = 0;
        
        while(cur != null && len < k) {
            nxt = nxt.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
            len++;
        }
        
        
        head.next = helper(cur, k);
        
        return prev != null ? prev : cur;
        
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        return helper(head, k);
    }
}