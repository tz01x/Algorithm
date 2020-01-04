class queen:
    def __init__(self,n):
        self.n=n
        self.arr=[[0 for j in range(n)]  for i in range(n)]
    def solve(self,col):
        if(self.n==col):
            return True
        else :
            for row in range(self.n):
                if(self.isvalid(row,col)):
                    self.arr[row][col]=1
                    self.printbord()
                    if not self.solve(col+1):
                        self.arr[row][col]=0
                    else:
                        return True
            return False
    def isvalid(self,row,col):
        #same row 
        for i in range(self.n):
            if self.arr[row][i]==1:
                return False
        #top left to buttom rignt 
        i=row
        j=col
        for k in range(j,self.n):
            if not i<self.n or not j<self.n:
                break
            if self.arr[i][j]==1:
                return False
            i+=1
            j+=1
        i=row
        j=col
        for k in range(i,-1,-1):
            if  i>=0 or  j>=0:
                if self.arr[k][j]==1:
                    return False
            else:
                break
            
            j-=1
        


        i=row
        j=col
        # print('hi')

        while True:
            if not i>=0 or not j<self.n:
                break
            if self.arr[i][j]==1:
                return False
            
            i-=1
            j+=1
        i=row
        j=col
        while True:
            if not j>=0 or not i<self.n:
                break
            if self.arr[i][j]==1:
                return False
            
            i+=1
            j-=1
        return True


        


                    


                    
                
    def printbord(self):
        for i in self.arr:
            for j in i:
                print (j,end=" ")
            print("")
        print()
        


if __name__ == "__main__":
    
    q=queen(4)
    # q.printbord()
    if q.solve(0):
        print('solution  is')
        q.printbord()
    else:
        print('no solution ')
    