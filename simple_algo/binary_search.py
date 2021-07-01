def binarySearch(listitem,terget):
  '''take a sorted listitem and a terget as an argument. return idx number of the list item  '''  
  lo=0
  hi=len(listitem)
  
  while True:
      mid=(lo+hi)//2
      print("low: ",lo," high: ",hi," mid: ",mid)
      
      if(listitem[mid]==terget):
          return mid
      if(mid==0 or mid==len(listitem)-1):
          break
      if(listitem[mid]<terget):
          lo=mid
      if(listitem[mid]>terget):
          hi=mid
       
  return None
