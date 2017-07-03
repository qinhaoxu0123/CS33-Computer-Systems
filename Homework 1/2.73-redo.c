#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
  int sum = x+y;
  int temp;
  int sizeofbit = (sizeof(int)<<3); // get the size of the interger 
  int xMin = x >> (sizeofbit-1); // shift to the left by 31 bit so [11111...] wil become [0000...000000001]
  int yMin = y >> (sizeofbit-1);
  int sumMin  = __builtin_add_overflow(x,y,&temp);
    sumMin= sumMin >> (sizeofbit-1);

  int neg_over = xMin  &  yMin & sumMin;
  /// negative overflow when x and y are negatives and sum is positive
  int pos_over = ~xMin & ~yMin & sumMin;
  /// positive overflow when x and y are postive and sum is negative;
  int not_over = ~sumMin;
  // when it is not positve overflow or negative overflow we negate it to 0 
  
  neg_over= neg_over >> (sizeofbit-1);
  pos_over= pos_over >> (sizeofbit-1);


  return (neg_over & INT_MIN)|(pos_over & INT_MAX)|(not_over & sum);
} 

/*
int main()
{
  int x = 4294967295;
  int y= 1;

  int res = saturating_add(x,y);
  printf("%d\n", res);

}
*/
