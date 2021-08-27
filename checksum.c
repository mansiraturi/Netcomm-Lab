#include <stdio.h>
int add(int x, int y)
{
static int carry = 0;
if (x == 1 && y == 1 && carry == 0)
{
carry = 1;
return 0;
}
else if (x == 1 && y == 0 && carry == 0)
{
carry = 0;
return 1;
}
else if (x == 1 && y == 1 && carry == 1)
{
carry = 1;
return 1;
}
else if (x == 1 && y == 0 && carry == 1)
{
carry = 1;
return 0;
}
else if (x == 0 && y == 1 && carry == 0)
{
carry = 0;
return 1;
}
else if (x == 0 && y == 1 && carry == 1)
{
carry = 1;
return 0;
}
else if (x == 0 && y == 0 && carry == 0)
{
carry = 0;
return 0;
}
else
{
carry = 0;
return 1;
}
}
int compare(int a)
{
if (a == 0)
return 1;
else
return 0;
}
void main()
{
int i, j, k;
int m;
int a[10][10], newdata[10][10];
int complement[10], checksum[10];
printf("19BCE0488 MANSI RATURI");
printf("\nEnter no. of data inputs: ");
scanf("%d", &k);
printf("\nEnter the no. of bits:"); 
scanf("%d",&m);
printf("\nEnter your Data: ");
for (j = 0;j < k; j++)
    {
        for (i = 0; i < m; i++)
        {
            scanf("%d", &a[i][j]);
        }
    }
printf("\nYour Data: ");
for (j = 0;j < k; j++)
    {
        for (i = 0; i < m; i++) 
        {
            if((a[i][j]==0) || (a[i][j]==1)){
            printf("%d", a[i][j]);}
            else { 
printf("\nData invalid."); 
                return 0;
            }
        }
        printf("\n");
    }
for(j=0; j<k; j++){
for (i = m - 1; i >= 0; i--)
{
newdata[i][j+1] = add(a[i][j], a[i][j+1]);
}
}
printf("\nYour New data => ");
for (i = 0; i < m; i++)
{
printf("%d", newdata[i][k]);
}
printf("\nThe Checksum => ");
for (i = 0; i < m; i++)
{
checksum[i] = compare(newdata[i][k]);
printf("%d", checksum[i]);
}
printf("\n\nTHE RECEIVER SIDE");
printf("\nReceiver's Data: ");
for (j = 0; j < k; j++)
    {
        for (i = 0; i < m; i++)
        {
            printf("%d", a[i][j]);
        }
        printf(" ");
    }
for (i = 0; i < m; i++)
printf("%d", checksum[i]);
printf("\nThe Addition: ");
for (i = m - 1; i >= 0; i--) {
newdata[i][k] = add(newdata[i][k], checksum[i]);
}
for (i = 0; i < m; i++)
{
printf("%d", newdata[i][k]);
}
printf("\nThe Complement: "); 
for (i = 0; i < m; i++)
{
compliment[i] = compare(newdata[i][k]);
printf("%d", compliment[i]);
}
}