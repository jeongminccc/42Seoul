#include <stdio.h>
#include <unistd.h>

void init(char *c)
{
	while(*c)
	{
		write(1, c, 1);
		c++;
	}
}

int main()
{
	int a[5][5] = {{5,5}};
	char c[10] = { 'a', 'b', 'c', 'd'};
	init(c);

	int i=0;
	while(++i < 5){
		int j=0;
		while(++j < 5){
			printf("%d,%d : %d\n",i,j, a[i][j]);
		}
	}
	return 0;
}
