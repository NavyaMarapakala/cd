#include"stdio.h"  
#include"ctype.h"  
#include"string.h"  
  char stack[10], gram[10][10], input[10];  
  int size, elem[5], sizei, sizes;  
  int getGram(){  
       int i,j,k;  
       char ch;  
       printf("\nEnter Number of Rules : ");  
       scanf("%d",&size);  
       printf("\nEnter Rule as 'E=E+T' : ");  
       for(i=0;i<size;i++){  
                 scanf("%s%c",gram[i],&ch);  
       }  
       for(i=0;i<size;i++)  
            printf("\n%s",gram[i]);  
  }  
  int getInput(){  
       char ch;  
       printf("\nEnter size of input by element : ");  
       scanf("%d",&sizei);  
       sizei+=1;  
       printf("\nEnter Input as 'a+b' followed by '$' : ");  
       scanf("%s%c",input,&ch);  
       printf("\nInput is %s",input);  
  }  
 char validate(){  
       int i,j,flag=0,pos;  
       char ch='q';  
       printf("\n\tStackTop : %c\n\tStack : %s",stack[sizes-1],stack);  
       for(i=0;i<size;i++){  
            if(stack[sizes-1]==gram[i][2]){  
                 flag=1;  
                 pos=i;  
               break;  
           }  
       }  
       if(flag==1){  
            ch=gram[pos][0];  
            printf("\nReduce %s",gram[pos]);  
       }  
       return ch;  
  }  
  int applyOp(){  
       char ch;  
       int i;  
       for(i=0;i<sizei;i++){  
            if(input[i]!='$'){  
                 stack[sizes]=input[i];  
                 printf("\nShift %c",input[i]);  
                 input[i]=' ';  
                 sizes=strlen(stack);  
            }  
           /*if(stack[i]=='a'||'b')  
                 stack[i]='E';  
            else */  
            ch=validate();  
            if(ch!='q'){  
                 stack[sizes-1]=ch;  
            }  
      }  
      for(i=0;i<size;i++){  
           if(gram[i][3]==stack[2])  
                 printf("\nReduce %s\n",gram[i]);  
       }  
  }  
  int main(){  
      stack[0]='$';  
      sizes=strlen(stack);  
      getGram();  
      getInput();  
       applyOp();  
  }  
