#!/usr/bin/env python
# coding: utf-8

# # 438. Find All Anagrams in a String (Medium)

# In[9]:


def findAnagrams(s,p):
    ans=[]
    m,n=len(s),len(p)
    if m<n:
        return ans 
    pcount,scount={},{}
    for i in range(n):
        if p[i] in pcount:
            pcount[p[i]]+=1
        else:
            pcount[p[i]]=1
        if s[i] in scount:
            scount[s[i]]+=1
        else:
            scount[s[i]]=1
    if pcount==scount:
        ans.append(0)
    start,end=0,n
    while end<m:
        new_to_scount=s[end]
        if new_to_scount in scount:
            scount[new_to_scount]+=1
        else:
            scount[new_to_scount]=1
        remaining_at_scount=s[start]
        if scount[remaining_at_scount]>1:
            scount[remaining_at_scount]-=1
        else:
            scount.pop(remaining_at_scount)
        if (scount==pcount):
            ans.append(start+1)
        start+=1
        end+=1
    return ans 


# In[ ]:





# # Starters 24 (CodeChef)

# In[ ]:


# cook your dish here
#Question 1
T = int(input())
for i in range(T):
    P = int(input())
    print((P//2) +1)


# In[1]:


#Question 2
T = int(input())
for i in range(T):
    X,Y = map(int,input().split())
    normalRoom = X - Y
    if normalRoom:
        infected = Y + Y
    else:
        infected = Y + (Y-1)
    print(normalRoom+infected)


# In[ ]:


#Question 3 
T = int(input())
for i in range(T):
    A,B,C,P,Q,R = map(int,input().split())
    chefVotes = A + B + C
    totalVotes = P + Q + R
    if 2*(chefVotes - A + P) > totalVotes:
        print('yes')
    elif 2*(chefVotes - B + Q) > totalVotes:
        print('yes')
    elif 2*(chefVotes - C + R) > totalVotes:
        print('yes')
    else:
        print('no')


# In[8]:


# Question 4
4 & 6


# In[ ]:




