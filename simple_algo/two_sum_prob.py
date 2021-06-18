import random

def main():
    n=[random.randint(0,25)%25 for _ in range(5) ]
    print('numbers ',n)
    target=5;
    hasmap={} #initial hasmap
    for i in n:
        if target-i in hasmap.keys():
            return i,hasmap[target-i]
        else:
            hasmap[i]=i
    return -1,-1
    
    
if __name__ == '__main__':
    print(main())
