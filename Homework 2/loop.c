int loop (int x , int n)
{
	int result = 0;
	int mask;
	for(mask = 1; mask !=0; mask = mask << (n & oxFF))
	{
		result ^= ( mask & x);
	}
	return result;
}

/* 
A.
mask: %edx
x: %r8
n: %rdx
result : %rax
B.
result =0 ; $0 ,  %eax
mask =1;  $1 , %edx
C.
testq %rdx , %rdx  
D.
it get update by shift left 8 bits, which is the line 10 %cl , %rdx
E.
it gets updated with the exclusive bitwise operator equal to the and operator of the mask and x 
which is line 9 orq %r8 , % rax
*/
