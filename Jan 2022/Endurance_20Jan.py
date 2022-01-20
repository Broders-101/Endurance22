#!/usr/bin/env python
# coding: utf-8

# # 232. Implement Queue using Stacks

# In[ ]:


# Wrong test case
class MyQueue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        self.stack1.append(x)
        

    def pop(self) -> int:
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop()
    
    def peek(self) -> int:
        if self.stack2:
            return self.stack2[-1]
        else:
            return self.stack1[0]
        
    def size(self):
        return len(self.stack2)

    def empty(self) -> bool:
        return self.size() == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()


# # 875. Koko Eating Bananas (Medium)

# In[7]:


import math
def minEatingSpeed(piles,h):
    minspeed = 1
    maxspeed = 1000000000
    while minspeed<maxspeed:
        speed = math.floor((minspeed+maxspeed)/2)
        hour_spent = 0
        for pile in piles:
            hour_spent += math.ceil(pile/speed)
        if hour_spent <= h:
            maxspeed = speed
        else:
            minspeed = speed+1
    return minspeed 
        
        


# In[8]:


piles = [3,6,7,11]
h = 8
minEatingSpeed(piles,h)


# # 622. Design Circular Queue (Medium)

# In[ ]:


class Node:
    
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None
        
class MyCircularQueue:

    def __init__(self, k: int):
        self.length = k
        self.size = 0
        self.frontList = None
        self.rearList = None

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        newNode = Node(value)
        if self.size == 0:
            self.frontList = newNode
            self.rearList = newNode
        else:
            self.rearList.next = newNode
            newNode.prev = self.rearList
            self.rearList = newNode
        self.size += 1
        return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        self.frontList = self.frontList.next
        if self.frontList:
            self.frontList.prev = None
        self.size -= 1
        return True

    def Front(self) -> int:
        if isEmpty():
            return -1
        return self.frontList.value

    def Rear(self) -> int:
        if isEmpty():
            return -1
        return self.rearList.value

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.length == self.size


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()

