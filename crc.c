#include <stdio.h>
#include <string.h>
char a[10], b[10], c[10];
void encode()
{
int m, n, i, k, j;
printf("\nEnter the message:");
scanf("%s", a);
printf("\nEnter the crc value:");
scanf("%s", b);
m = strlen(a);
n = strlen(b);
for (i = 0; i < n - 1; i++)
	{
a[m + i] = '0';
}
printf("\nHence the message after adding redundancy bits is: %s\n", a);
}
void receivedata()
{
printf("\nEnter the data at the receivers side :");
scanf("%s", &a);
}
void decode()
{
int m, n, i, k, j;
m = strlen(a);
n = strlen(b);
for (i = 0; i < m; i++)
{
c[i] = a[i];
}
k = n;
while (k != (m + 1))
{
if (c[0] == '1')
{
for (i = 1; i < n; i++)
{
if (c[i] == b[i])
{
c[i - 1] = '0';
}
else
{
c[i - 1] = '1';
}
}
if (k != (m))
{
c[n - 1] = a[k];
}
k += 1;
}
else
{
for (i = 1; i < n; i++)
{
c[i - 1] = c[i];
}if (k != (m))
{
c[n - 1] = a[k];
}
k += 1;
}
}
j = 0;
printf("\nThe remainder is ");
for (i = 0; i < n - 1; i++)
{
printf("%c", c[i]);
}
for (i = 0; i < n - 1; i++)
{
if (c[i] != '0')
{
j = 1;
break;
}
}
if (j == 0)
{
printf("\nThe received message is accepted\n");
}
else
{
printf("\n\nThe received message is corrupted, ask the receiver to resend it\n");
}
}
int main()
{
printf("19BCE0488 MANSI RATURI");
encode();
receivedata();
decode();
return (0);
}