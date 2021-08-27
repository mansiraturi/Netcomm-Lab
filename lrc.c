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
int rowadd(int x, int y)
{
if (x == 1 && y == 1)
{
return 0;
}
else if (x == 1 && y == 0)
{
return 1;
}
else if (x == 0 && y == 1)
{
return 1;
}
else
{
return 0;
}
}
void main(){
      int i, j, k;
int m;
int a[10][10], newdata[10][10], rowparity[10][1];
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
            if((a[i][j]==0) || (a[i][j]==1))
            {
            printf("%d", a[i][j]);
            }
            else 
            { 
printf("\nData invalid."); 
                return 0;
            }
        }
        printf("\n");
    }
for(j=0; j<k; j++)
{
for (i = m - 1; i >= 0; i--)
{
newdata[i][j+1] = add(a[i][j], a[i][j+1]);
}
}
for(j=0; j<k; j++){
for (i = 0; i < m; i++)
{
rowparity[j][i] = rowadd(a[j][i], a[j][i+1]);
}
}
printf("The final code: ");
for (j = 0;j < k; j++)
    {
        for (i = 0; i < m; i++) 
        {
            printf("%d", a[i][j]);
        }
        printf("%d",  rowparity[j][1]);
        printf("\n");
    }
for (i = 0; i < m; i++)
{
printf("%d", newdata[i][k]);
}
for (i = 0; i < m; i++)
{
rowparity[k][1] = rowadd(newdata[k][i], newdata[k][i+1]);
}
printf("%d",  rowparity[k][1]);
}
