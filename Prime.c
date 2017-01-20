    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <math.h>
     
    void pierwsze(int a, int c);
     
    int main(void) {
	int *tab;
	int n=0;
	int a=0;
	int i=0;
     
	scanf("%d",&n);
     
	tab=(int*)malloc(2*n*sizeof(*tab));
     
	n*=2;
     
	for(i=0;i<n;i+=2)
	{
	    scanf("%d %d",&tab[i],&tab[i+1]);
	}
     
	for(i=0;i<n;i+=2)
	{
	    a=tab[i];
     
	    while(a<=tab[i+1])
	    {
		pierwsze(a,tab[i]);
		a++;
	    }
	    printf("\n");
	}
	free(tab);
	return 0;
    }
     
    void pierwsze(int a, int c)
    {
	bool log = true;
	int b=2;
	if(c<=1)
	{
	    c=2;
	}
	while(b<=sqrt(a))
	{
	    if(a%b==0)
	    {
		log = false;
	    }	
	    b++;
	}
	if(log&&a>=c)
	    printf("%d\n",a);
    }