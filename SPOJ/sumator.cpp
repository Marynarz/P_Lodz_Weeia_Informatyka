    #include <stdio.h>
     
    int funkcja(int x)
    {
	if(x<=1) return 1;
	else
	    x += funkcja(x-1);
	return x;
    } 
    int main()
    {
	int x;
	for(int i=0; i<10;i++)
	{
	    scanf("%d",&x);
	    x=funkcja(x);
	    printf("%d\n",x);
	}
	return 0;
    }