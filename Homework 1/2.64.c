#include <stdio.h>

int any_odd_one(unsigned x)
{
  return !!(x & 0xaaaaaaaa);
}
