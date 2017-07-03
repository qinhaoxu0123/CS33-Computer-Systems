
/*
Qinhao Xu
UID: 704439324
*/
//2.90
union uf
{
	unsigned int u;
	float t;
}

static float u2f(unsigned u)
{ 
	union{
		unsigned o;
		float p;
	} q;
	
	q.o= u;
	return u.p;
}



float fpwr4(int x)
{
	/* Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;

	if(x< -74){
		/* Too small. Return 0.0*/
		exp=0;
		frac=0;
	} else if(x<-63){
		/* Denormalized result */
		exp= 0 ;
		frac= 1 << (x*2+149);
	} else if (x < 64 ){
		/* Normalized result */
		exp= x*2+127;
		frac=0 ;
	} else {
		/* Too big . Return +oo */
		exp= 255;
		frac= 0;
	}

/* pack exp and frac into 32 bits */
	u=exp << 23 | frac;
	/* Return as float */
return u2f(u);

}
