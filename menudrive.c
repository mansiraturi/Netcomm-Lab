#include<stdio.h> 
#include<string.h> 
#include <math.h>
void vrc() { 
int n; 
 printf("Enter the no. of bits "); 
 scanf("%d", &n); 
 int a[n]; 
 int i, c = 0; 
 printf("\nEnter the string "); 
 for (i = 0; i < n; i++) { 
 scanf("%d", &a[i]); 
 }  
 for (i = 0; i < n; i++) { 
 if ((a[i]==0) || (a[i]==1)) {
 	printf("%d", a[i]);
 }
 else {
 	printf("data invalid");
 	return 0;
 } 
}
 for (i = 0; i < n; i++) { 
 if (a[i] == 1) 
 c++; 
 }
 int parity, ch; 
 printf("\nEnter 1 for odd parity generator and 2 for even parity generator"); 
 scanf("%d", & ch); 
 switch (ch) { 
 case 1: 
 printf("Odd parity generator\t"); 
 if (c % 2 == 0) parity = 1; 
 else parity = 0; 
 break; 
 case 2: 
 printf("Even parity generator\t"); 
 if (c % 2 == 0) parity = 0; 
 else parity = 1; 
 break; 
 default: 
 printf("Invalid"); 
 } 
 printf("parity bit="); 
 printf("%d", parity); 
 printf("\nReceived data: ");
 printf("%d", parity);
 for (i = 0; i < n; i++) {
 printf("%d", a[i]);
} 
}
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
void lrc(){
      int i, j, k;
int m;
int a[10][10], newdata[10][10], rowparity[10][1];
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
int compare(int a)
{
if (a == 0)
return 1;
else
return 0;
}
void checkSum()
{
int i, j, k;
int m;
int a[10][10], newdata[10][10];
int complement[10], checksum[10];
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
printf("\nThe complement: "); 
for (i = 0; i < m; i++)
{
complement[i] = compare(newdata[i][k]);
printf("%d", complement[i]);
}
}
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
int crc()
{
encode();
receivedata();
decode();
return (0);
}
int data[50], code[32];
void hammingCode()
{
	int n,i,a = 0,b,j,k;
	printf("\nEnter the no. of databits: ");
	scanf("%d",&n);
	printf("\nEnter the data word:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
printf("\nYour data: ");
for (int i = 0; i < n; i++) 
  {
    if((data[i]==0) || (data[i]==1)){
        printf("%d", data[i]);}
    else{ 
printf("\nData invalid."); 
                return 0;
            }
        }
	i=0;
	while(n>(int)pow(2,i)-(i+1))
	{
		a++;
		i++;
	}
		
	b = a + n;

	j=k=0;
	for(i=0;i<b;i++)
	{
		
		if(i==((int)pow(2,k)-1))
		{
			code[i]=0;
			k++;
		}
		else
		{
			code[i]=data[j];
			j++;
		}
	}
	for(i=0;i<a;i++)
	{
		int posn = (int)pow(2,i);
		int value = ham_enc(posn,b);
		code[posn-1]=value;
	}
	printf("\nThe calculated Code Word is: ");
	for(i=0;i<b;i++)
		printf("%d",code[i]);
	printf("\n");
	printf("Please enter the received Code Word:\n");
	for(i=0;i<b;i++)
		scanf("%d",&code[i]);

	int errorposn = 0;
	for(i=0;i<a;i++)
	{
		int posn = (int)pow(2,i);
		int value = ham_enc(posn,b);
		if(value != 0)
			errorposn+=posn;
	}
	if(errorposn == 1)
		printf("The received Code Word is correct.\n");
	else
		printf("Error at bit position: %d\n",errorposn);
}
int ham_enc(int posn,int b)
{
	int count=0,i,j;
	i=posn-1;
	while(i<b)
	{
		for(j=i;j<i+posn;j++)
		{
			if(code[j] == 1)
				count++;
		}
		i=i+2*posn;
	}
	if(count%2 == 0)
		return 0;
	else
		return 1;
}
int main() { 
printf("19BCE0488 MANSI RATURI");
 int choice; 
 printf("\n1. VRC\n"); 
 printf("2. LRC\n"); 
 printf("3. Check Sum\n"); 
 printf("4. CRC\n"); 
 printf("5. Hamming code\n"); 
 printf("6. Exit\n"); 
 printf("Enter your choice: "); 
 scanf("%d", &choice); 
 switch (choice) {  
 case 1: 
 vrc(); 
 break; 
 case 2: 
 lrc(); 
 break; 
 case 3: 
 checkSum(); 
 break; 
 case 4: 
 crc(); 
 break; 
 case 5: 
 hammingCode(); 
 break; 
 case 6: 
 exit(0); 
 break; 
 default: 
 printf("Enter valid choice"); 
 }  
 return 0; 
}