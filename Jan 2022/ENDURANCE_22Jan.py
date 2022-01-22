#!/usr/bin/env python
# coding: utf-8

# # 2. Add Two Numbers (Medium)

# In[ ]:


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode], c = 0) -> Optional[ListNode]:
        val = l1.val + l2.val + c
        c = val // 10
        ret = ListNode(val % 10)
        
        if (l1.next != None or l2.next != None or c != 0):
            if l1.next == None:
                l1.next = ListNode(0)
            if l2.next == None:
                l2.next = ListNode(0)
            
            ret.next = self.addTwoNumbers(l1.next,l2.next, c)
        return ret
# Using recursion        


# In[4]:


lst = [3,4,3]
print(lst.index(3))


# # 134. Gas Station (Medium)

# In[13]:


def canCompleteCircuit(gas, cost):
    min_cost = min(cost)
    available = 0
    starting_index = cost.index(min_cost)
    index = starting_index
    while True:
        if available < 0:
            starting_index += 1
            index = starting_index
        elif index == len(cost) - 1 :
            index = 0
        elif index == starting_index and available > 0:
            return starting_index
        else:
            return -1
        available += gas[index] - cost[index]
        index += 1


# In[14]:


gas = [1,2,3,4,5]
cost = [3,4,5,1,2]
canCompleteCircuit(gas, cost)


# In[ ]:




