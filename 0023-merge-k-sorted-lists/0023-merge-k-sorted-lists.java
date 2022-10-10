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
    private ListNode merge(ListNode l1, ListNode l2) {
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        
        if(l1.val > l2.val) {
            l2.next = merge(l1, l2.next);
            return l2;
        }
        else {
            l1.next = merge(l1.next, l2);
            return l1;
        }  
    }
    private ListNode partition(ListNode[] lists, int st, int en) {
        if(st == en) return lists[st];
        if(st > en) return null;
        int mid = (st + (en - st)/2);
        ListNode l1 = partition(lists, st, mid);
        ListNode l2 = partition(lists, mid + 1, en);
        return merge(l1, l2);
    }
    public ListNode mergeKLists(ListNode[] lists) {
        return partition(lists, 0, lists.length-1);
    }
}