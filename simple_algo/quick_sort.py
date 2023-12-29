
import secrets

class QuickSort:
    def __init__(self,arr):
        self.arr=arr
        self.n=len(arr)
        
        
    def getlist(self):
        self.quick_sort(self.n,0,self.n-1)
        return self.arr 
        
    def partition(self,n,start,end):
        
        if start==end:
            return start
        k,i,j=start,start+1,end
        while not(i>j):
            while True:
                if  i<n and arr[k]>=arr[i] :
                    i+=1
                else:
                    break
            while True:
                if j>=0 and arr[k]<arr[j]  :
                    j-=1
                else:
                    break
            if i<n and j>-1 and not i>j:
                temp=self.arr[i]
                self.arr[i]=self.arr[j]
                self.arr[j]=temp 
                # print('s', i , j,self.arr[i],self.arr[j])
        if(j>0 and j<n):  
            temp=arr[k]
            self.arr[k]=self.arr[j]
            self.arr[j]=temp 
            return j 
        else:
            return k
            
        # while not (i>j):
        #     if  self.arr[k]<self.arr[i] and self.arr[k]>=self.arr[j]:
        #         temp=self.arr[i]
        #         self.arr[i]=self.arr[j]
        #         self.arr[j]=temp 
        #         # print('{},{} s'.format(arr[i],arr[j]),end="*")
                
        #     if self.arr[k]>self.arr[i]:
        #         i+=1
        #     if self.arr[k]<=self.arr[j]:
        #         j-=1
            
                
        #     # print(i,j)
        # if(j>0 and j<n):  
        #     temp=arr[k]
        #     self.arr[k]=self.arr[j]
        #     self.arr[j]=temp 
        #     return j 
        # else:
        #     return k
        
    def quick_sort(self,n,s,e):
        '''
        s: starting index 
        e: last index 
        n: size of the list 
        
        list should be globaly declare 
        '''
        # print(s,e)
        
        if(e<0 or s>n or e==s or s>e):
            return
        
        k=self.partition(n,s,e)
        # print(self.arr)
        # print(k)
        self.quick_sort(n,s,k-1)
        self.quick_sort(n,k+1,e)
    


arr=[5,9,2,6,20,1,3,6,2,7,58,5,6,7,5,8,85,1,65,7,2,5,8,7,1,558,8,4,5,85258,548,5,85555558,4]

secrets.SystemRandom().shuffle(arr)
print(arr)
qs=QuickSort(arr)
arr=qs.getlist()
# quick_sort(len(arr),0,len(arr)-1)
print(arr)
