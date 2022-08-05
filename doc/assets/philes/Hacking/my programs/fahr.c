#include <stdio.h>

main()
{
int fahr, celsius;
int lower_limit, upper_limit, step;

lower_limit = -30;
upper_limit = 135;
step = 5;

fahr = lower_limit;
while(fahr <= upper_limit) {
celsius = 5 * (fahr-32) /9;
printf("%d\t%d\n", fahr, celsius);
fahr = fahr + step;
	}
}
 
