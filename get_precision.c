/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<math.h>
const int MAX_SIZE = 8;
int arr[8] = { 0 };

int font = -1, back = -1;

int
push (int x)
{

  if (back == -1)
    {
      font++;
      back++;
      arr[back] = x;

    }
  else
    {
      if (((back + 1) % MAX_SIZE) == font)
	{
	  font = (font + 1) % MAX_SIZE;
	  back = (back + 1) % MAX_SIZE;
	  arr[back] = x;
	}else{
	    
	  back = (back + 1) % MAX_SIZE;
	  arr[back] = x;
	}

    }
  //printf ("push -> : %d\n ", arr[back]);
}

float
get_probability (int item)
{

  //printf("item -> r : %d\n , ",item);
  int tfont = font;
  int tback = back;
  int counter = 0;
  int n = 1;
//   while (tfont != tback)
//     {
//       //   print (arr[font], end = ",");
   

//     }
    for(int i=font;i!=back;i=(i+1)%MAX_SIZE){
    //printf("%d , ",arr[i]);

      if (arr[i] == item)
	{
	  counter += 1;

	}
      
      n += 1;

        
    }
    //printf("\n");
    
     // printf("counter : %d ,n: %d \n",counter,n);

  return ((float)counter /(float) n) * 100.0;

}



int
main ()
{

  int data[] =
    { 8, 8, 8, 9, 9, 0, 8, 8, 7, 7, 6, 12, 12, 12, 12, 39, 13, 13 };
  int len = sizeof (data) / sizeof (data[0]);
  for (int i = 0; i < len; i++)
    {
        
  static int last_counter = -1;
        
      push (data[i]);
      if (last_counter == -1)
	{
	  last_counter = data[i];

	}
      int rate_of_Change = (int) (abs (last_counter - data[i]));
      //printf("rate_of_Change %d \n",rate_of_Change);

      if (rate_of_Change >= 1 && rate_of_Change <= 2)
	{

	  last_counter =
	    last_counter +
	    (int) ((sinh (data[i] - last_counter)) * rate_of_Change);

	}
      else
	{

	  float prob = get_probability (data[i]);
    //printf("prob %f ,",prob);
	  if (prob > 30)
	    {
	      last_counter = data[i];
	      printf("prob %f ,",prob);
	    }
	}
      printf ("k %d \n", last_counter);

    }


  return 0;
}
