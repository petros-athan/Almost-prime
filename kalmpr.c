#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MINNUM 100
#define MAXNUM 100000
#define MAXK 4
#define COMPUTATIONS 20

int main(int argc, char const *argv[])
{
	printf("Checking numbers in [%d,%d]\n\n", MINNUM, MAXNUM);
	int semiprime = 0, almost = 0; 
	
		
	for (int number = MINNUM; number <= MAXNUM; ++number){
		int div = 2, k = 0, num = number, x = 0, y = 0;

		//ελενχει αν ο αριθμος διερειται ακριβος με τον διαιρετη
		while (num != 1){
			if (num % div == 0){
				num = num/div;
				k++;
				if (k == 1)
					x = div;
				if (k == 2)
					y = div;
				if (k > MAXK){
					k = 0;
					break;
				}
			}else
				div++;
		}

		//ελενχει αν ο αριθμος ειναι Κ-σχεδον πρωτος εως το ΜΑΧΚ
		if ((k >= 2) && (k <= MAXK)){
			almost++;
			if ( k == 2){
				semiprime++;
				if (((y-x)  < (0.01 * y)) && (y>x))
					printf("%d * %d = %d is an interesting semiprime\n",x, y, number );
			}
		}
	}

	printf("\nFound %d k-almost prime mumbers (2 <= k <= %d)\n", almost, MAXK);
	printf("Found %d semiprime\n",semiprime);
	
	long curtime = time(NULL);
	srand((unsigned int) curtime);
	printf("\nCurrent time is %ld\n",curtime );

	printf("\nChecking %d random numbers\n\n",COMPUTATIONS );

	for (int i = 0; i < COMPUTATIONS; i++)
	{
		int h = rand();
		int z = rand();
		int q = ((h % 32768) + 1) * ((z % 32768) + 1) + 1;
		int div = 2, k = 0, num = q, x = 0, y = 0;

		//ελενχει αν ο αριθμος διερειται ακριβος με τον διαιρετη
		while (num != 1){
			if (num % div == 0){
				num = num/div;
				k++;
			
			}else
				div++;
		}	

		printf("%d is a %d-almost prime number\n",q, k );
	}
	return 0;
}