

// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
 
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r, int *count)
{
   int i;
   
   if (l == r){
     printf("%s\n", a);
     *count=*count+1;
 	}
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r, count);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
    
    int *count;
	count = (int)malloc(sizeof(int));
    *count = 0;
	char str[] = "ABCDE";
    int n = strlen(str);
    // Pass the string and her length.
    
    permute(str, 0, n-1, count);
    
    printf("\n Number of permutations: %d\n", *count);
    
    return 0;
    
}
