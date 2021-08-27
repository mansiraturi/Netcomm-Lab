#include<bits/stdc++.h>
#include <stdio.h>

int s[4][8]={{1,3,5,7,9,11,13,15},
            {2,3,6,7,10,11,14,15},
            {4,5,6,7,12,13,14,15},
            {8,9,10,11,12,13,14,15}
            };
void errorDetection (int code[],int n,int r) {
    printf("\nCodeWord Received on Receiver Side: ");
    for(int i=r+n-1;i>=0;i--)  
    printf("code[i]: ");
    int e[r],s1=0;
    for(int x=0;x<r;x++) {
        int j=0,c=0;
        while (s[x][j++]-1 <r+n) {
            if(code[s[x][j-1]-1]==1)
            c++;
        }
        if(c%2==0)  
        e[r-x-1]=0;
        else 
        e[r-x-1]=1;
    }
    printf("\nRedundant bits on receiver side gives binary number: ");
    for(int i=0;i<r;i++)    {
        s1=s1+e[i]*(int)pow(2,r-i-1);
        printf("e[i] ");
    }
    if(s1==0)        
    printf("\n\nSince the result is 0, there has been no error in message.";
    else {
        printf("\n\n There has been an error in bit no. %d",r+n-s1+1);
        if(code[s1-1]==1) 
        code[s1-1]=0;
        else code[s1-1]=1;
        printf("\n\nCorrected CodeWord: ";
        for(int i=r+n-1;i>=0;i--)  
        printf(code[i])" ";
    }
}
void generateHammingCode(int m[],int n) {
    int r = 1;
    while(pow(2,r)<(n+r+1)) {
        r++;
    }
    int code[r+n];
    for (int i = 0; i < r; ++i) {
        code[(int)pow(2, i) - 1] = -1;
    }
    int j = 0;
    for (int i=r+n-1;i>=0;i--) {
        if (code[i] != -1) {
            code[i]= m[j++];
        }
    }
    printf("\nGenerating CodeWord");
    for(int i=0;i<r+n;i++) {
        if (code[i]!=-1) {
            continue;
        }
        int x=log2(i+1);
        j=1;
        int c=0;
        while (s[x][j++]-1 <r+n) {
            if(code[s[x][j-1]-1]==1)
            c++;
        }
        if(c%2==0)  
        code[i]=0;
        else 
        code[i]=1;
    }
    printf("Codeword Generated: ");
    for(int i=r+n-1;i>=0;i--)  
        printf("code[%d]" , i);
    printf("\n\nSending Code to receiver Side\n");
    printf("\nDo you want to modify the input before sending to the receiver?\n 1.Yes     2. No   : ");
    int c;
    scanf("%d", &c);
    if(c == 1){
        if(code[2]==1) 
        code[2]=0;
        else code[2]=1;
    }
    errorDetection(code,n,r);
}
int main(){
    int n;
    printf("Enter size of message: ");
    scanf("%d", &n);
    int m[n];
    printf("Enter message: ");
    for(int i=0;i<n;i++){
        scanf("%d", &m[i]);
    }
    generateHammingCode(m,n);
}