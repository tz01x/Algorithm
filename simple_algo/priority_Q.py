
class PQ:
    def __init__(self,size=10):
        self.arr=list()
        self.arr.append(None)#[None for _ in range(size)]
        self.size=0
        self.totalsize=size
        
    def insert(self,item):
        self.size+=1
        self.arr.insert(self.size,item)
        self.swim(self.size)
        
    def swim(self,k):
        
        while  k//2>1 and self.less(k//2,k):
            self.swap(k,k//2)
            k=k//2
    def pop(self):
        root=self.arr[1]
        self.arr[1]=self.arr[self.size]
        self.arr[self.size]=None
        self.size-=1
        self.srink(1)      
        return root 
    
    def srink(self,k):
        while(k*2<=self.size):
            j=k*2
            if j<self.size and self.less(j,j+1):
                j+=1
            if not self.less(k,j):
                break
            self.swap(k,j)
            k=j
            
    
            
    def less(self,low,up):
        return self.arr[low]<self.arr[up]
        
    def swap(self,ti,tii):
        temp=self.arr[ti]
        self.arr[ti]=self.arr[tii]
        self.arr[tii]=temp
        
    def display(self):
        print(self.arr)
        
        
        
q=PQ()
q.insert('T')
q.insert('S')
q.insert('A')
q.insert('C')
q.insert('D')
q.insert('H')
q.display()
q.pop()
q.display()
q.insert('k')
q.display()
