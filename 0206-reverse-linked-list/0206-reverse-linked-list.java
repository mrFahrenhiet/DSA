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
    private ListNode helper(ListNode head) {
        if(head == null) return null;
        
        ListNode nextNode = helper(head.next);
        
        if(nextNode != null) nextNode.next = head;
        
        return head;
    }
    public ListNode reverseList(ListNode head) {
        if(head == null) return null;
        
        ListNode tail = head;
        
        while(tail.next != null) tail = tail.next;
        
        ListNode end = helper(head);
        
        if(end != null) end.next = null;
        
        return tail;
    }
}