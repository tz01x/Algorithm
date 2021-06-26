#maxmimum number of prize 
hasmap=dict()
def append(key,val):
    global hasmap 
    if key in hasmap.keys():
        hasmap[key].append(val)
    else:
        hasmap[key]=[]
        hasmap[key].append(val)
        
        
def func(n,itr,d):
    global hasmap
    n=n-itr 
    
    
    if (n==0):
        hasmap[d]=[]
        hasmap[d].append(itr)
        return (True,d)
        
    if (n<itr):
        return (False,d)
    
    left=func(n,itr+1,d+1)
    right=func(n,itr+2,d+1)
    
    if left[0] and right[0]:
        if left[1]>right[1]:
            append(left[1],itr)
            return (True,left[1])
        else:
            append(right[1],itr)
            return (True,right[1])
    
    if left[0] and not right[0]:
        append(left[1],itr)
        return (True,left[1])
    elif not left[0] and right[0]:
        append(right[1],itr)
        return (True,right[1])
        
    return (False,d)

n=8
func(n,0,0)
print(hasmap)   
# hasmap key holds the all k integer numbers  that represent as the sum k pairwise distinct positive integers.
# and value represnt k pirewise distinct positive int that sum up to n
            
        
        
        
