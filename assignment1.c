#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void find_roots(long double a, long double b, long double c)
{
    if(a == 0 && b == 0)
    {
        if(c == 0)
        {
            printf("Infinite solutions\n");
            return;
        }
        else
        {
            printf("No solution\n");
            return ;
        }
    }
    if (a== 0)
    {
        printf("Root is: %Lf\n",-c/b);
        return;
    }
	long double D = b*b - 4*a*c;
	if(D<0)
    {
        printf("No real roots\n");
        return;
    }
	long double rootD = sqrt(D);
    long double roots[2];
	roots[0] = (-b + rootD)/(2*a);
	roots[1] = (-b - rootD)/(2*a);
    printf("Roots are: %Lf and %Lf\n",roots[0],roots[1]);
	return ;
}
int main()
{
	printf("This is a quadratic equation solver.\nPlease enter how would you like to give input,\nEnter 1 for direct input.\nEnter 2 for file input.\n");
	int method = 1;
	scanf("%d",&method);
    long double a,b,c;
	if(method ==1)
	{
        printf("Enter a: ");
        if (scanf("%Lf", &a) != 1) {
            printf("Invalid input\n");
            return 0;
        }
        printf("Enter b: ");
        if (scanf("%Lf", &b) != 1) {
            printf("Invalid input\n");
            return 0;
        }
        printf("Enter c: ");
        if (scanf("%Lf", &c) != 1) {
            printf("Invalid input\n");
            return 0;
        }
        find_roots(a, b, c);
	}
	else 
	{
        printf("Enter the file name: ");
        char file_name[100];
        scanf("%s",file_name);
        FILE *file = fopen(file_name,"r");
        if(file == NULL)
        {
            printf("File not found\n");
            return 0;
        }

        long double vals[3];
        int count = 0;
        char buf[256];
        while (count < 3 && fgets(buf, sizeof(buf), file) != NULL) {
            char *ptr = buf;
            while (isspace((unsigned char)*ptr)) ptr++;
            while (*ptr != '\0' && count < 3) {
                char *end;
                long double num = strtold(ptr, &end);
                if (ptr == end) {
                    printf("Invalid number format\n");
                    fclose(file);
                    return 0;
                }
                vals[count++] = num;
                ptr = end;
                while (isspace((unsigned char)*ptr)) ptr++;
            }
        }
        if (count < 3) {
            printf("Invalid input: exactly 3 numbers required\n");
            fclose(file);
            return 0;
        }
        fclose(file);
        find_roots(vals[0], vals[1], vals[2]);
	}
	return 0;
}
