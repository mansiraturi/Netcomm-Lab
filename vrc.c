#include<stdio.h> 
#include<string.h> 
void main() { 
	printf("19BCE0488 MANSI RATURI");
int n; 
 printf("\nEnter the no. of bits "); 
 scanf("%d", &n); 
 int a[n];
 int b[n];
 int ch[n];
 int d[n]; 
 int i, c = 0; 
 
 printf("\nEnter the string "); 
 for (i = 0; i < n; i++) { 
 scanf("%d", &a[i]); 
 scanf("%d", &b[i]); 
 scanf("%d", &ch[i]); 
 scanf("%d", &d[i]); 
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

//  for (i = 0; i < n; i++) { 
//  if ((a[i]==0) || (a[i]==1)) {
//  	printf("%d", a[i]);
//  }
//  else {
//  	printf("data invalid");
//  	return 0;
//  } 
// }
 for (i = 0; i < n; i++) { 
 if (a[i] == 1) 
 c++; 
 }
 for (i = 0; i < n; i++) { 
 if (b[i] == 1) 
 c++; 
 }
 for (i = 0; i < n; i++) { 
 if (ch[i] == 1) 
 c++; 
 }
 for (i = 0; i < n; i++) { 
 if (d[i] == 1) 
 c++; 
 }
 int parity;
 // printf("\nEnter 1 for odd parity generator and 2 for even parity generator"); 
 // scanf("%d", & ch); 
 // switch (ch) { 
 // case 1: 
 // printf("Odd parity generator\t"); 
 // if (c % 2 == 0) parity = 1; 
 // else parity = 0; 
 // break; 
 // case 2: 
 printf("Even parity generator\t"); 
 if (c % 2 == 0) parity = 0; 
 else parity = 1; 
 // break; 
 // default: 
 // printf("Invalid"); 
 // } 
 printf("parity bit="); 
 printf("%d", parity); 
 printf("\nReceived data: ");
 printf("%d", parity);
 for (i = 0; i < n; i++) {
 printf("%d", a[i]);
 printf("%d", b[i]);
 printf("%d", ch[i]);
 printf("%d", d[i]);
} 
}
