# Merge Two Sorted Lists

## Problem
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

## Solution

簡單歸併操作

```c
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode *p = l1, *q = l2, *result = NULL, *k = NULL;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (p -> val <= q->val) {
		result = p;
		p = p->next;
	} else {
		result = q;
		q = q->next;
	}
	k = result;
	while (p && q) {
		if (p->val <= q->val) {
			k->next = p;
			p = p->next;
		} else {
			k->next = q;
			q = q->next;
		}
		k = k->next;
	}
	while (p) {
		k->next = p;
		p = p->next;
		k = k->next;
	}
	while (q) {
		k->next = q;
		q = q->next;
		k = k->next;
	}
	return result;
}
```
## 擴展

* [Merge Two Sorted Lists](../MergeTwoSortedLists): 合併兩個鏈表
* [Merge k Sorted Lists](../MergekSortedLists): 合併K個鏈表
* [Merge Sorted Array](../MergeSortedArray): 合併兩個數組
* [Sort List](../SortList): 歸併排序兩個鏈表
