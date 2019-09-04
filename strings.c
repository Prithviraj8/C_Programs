#include <stdio.h>
//#include<conio.h>
#include<string.h>
#include<stdlib.h>
 
int length(char str[]);
void reverse(char str[]);
int palindrome(char str[]);
void copy(char str1[], char str2[]);
int compare(char str1[], char str2[]);
void concat(char str1[], char str2[]);
void search(char str1[], char str2[]);
void count(char str1[]);
 
void main() {
   char a[100], b[100];
   int result, option;
   do {
      printf("\n1.Length of a string");
      printf("\n2.Reverse the Given String");
      printf("\n3.Check for Palindrome");
      printf("\n4.Copy");
      printf("\n5.String Comparison");
      printf("\n6.String Concatenation");
      printf("\n7.String Searching");
      printf("\n8.Counting of Words,Characters & Special Characters");
      printf("\n9.Quit");
      printf("\n\nEnter Your Choice:");
      scanf("%d", &option);
 
//      flushall();
      switch (option) {
      case 1:
         printf("\nEnter a String:");
         gets(a);
         result = length(a);
         printf("\nLength of %s=%d", a, result);
         printf("\nPress a Character");

         break;
 
      case 2:
         printf("\nEnter a String:");
         gets(a);
         reverse(a);
         printf("\nResult=%s", a);
         printf("\nPress a Character");

         break;
 
      case 3:
         printf("\n Enter a String:");
         gets(a);
         result = palindrome(a);
         if (result == 0)
            printf("\nNot a palindrome");
         else
            printf("\nA palindrome");
         printf("\nPress a Character");

         break;
 
      case 4:
         printf("\nEnter a String:");
         gets(a);
         copy(b, a);
         printf("\nResult=%s", b);
         printf("\nPress a Character");

         break;
 
      case 5:
         printf("\nEnter 1st string:");
         gets(a);
         printf("\nEnter 2nd string:");
         gets(b);
         result = compare(a, b);
         if (result == 0)
            printf("\nboth are same");
         else if (result > 0)
            printf("\n1st>2nd");
         else
            printf("\n1st<2nd");
         printf("\nPress a Character");

         break;
 
      case 6:
         printf("\nEnter 1st string:");
         gets(a);
         printf("\nEnter 2nd string:");
         gets(b);
         concat(a, b);
         printf("\nresult=%s", a);
         printf("\nPress a Character");

         break;
 
      case 7:
         printf("\nEnter 1st string:");
         gets(a);
         printf("\nEnter 2nd string:");
         gets(b);
         search(a, b);
         printf("\nPress a Character");

         break;
 
      case 8:
         printf("\nEnter a string:");
         gets(a);
         count(a);
         printf("\nPress a Character");

         break;
 
      default:
         printf("\nInvalid Choice:");
         break;
      }
 
   } while (option != 9);
}
 
int length(char str[]) {
   int i = 0;
   while (str[i] != '\0')
      i++;
   return (i);
}
 
void reverse(char str[]) {
   int i, j;
   char temp;
   i = j = 0;
   while (str[j] != '\0')
      j++;
   j--;
   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
}
 
int palindrome(char str[]) {
   int i, j;
   i = j = 0;
   while (str[j] != '\0')
      j++;
   while (i < j) {
      if (str[i] != str[j - 1])
         return (0);
      i++;
      j--;
   }
   return (1);
}
 
void copy(char str2[], char str1[]) {
   int i = 0;
   while (str1[i] != '\0') {
      str2[i] = str1[i];
      i++;
   }
   str2[i] = '\0';
}
 
int compare(char str1[], char str2[]) {
   int i;
   i = 0;
   while (str1[i] != '\0') {
      if (str1[i] > str2[i])
         return (1);
      if (str1[i] < str2[i])
         return (-1);
      i++;
   }
   return (0);
}
 
void concat(char str1[], char str2[]) {
   int i, j;
   i = 0;
   while (str1[i] != '\0')
      i++;
   for (j = 0; str2[j] != '\0'; i++, j++)
      str1[i] = str2[j];
   str1[i] = '\0';
}
 
void search(char str1[], char str2[]) {
   int i, j, lena, lenb;
   for (lena = 0; str1[lena] != '\0'; lena++);
   for (lenb = 0; str2[lenb] != '\0'; lenb++);
 
   for (i = 0; i <= lena - lenb + 1; i++) {
      for (j = 0; str1[i + j] == str2[j] && str2[j] != '\0'; j++);
      if (str2[j] == '\0')
         printf("\nString found at location : %d", i + 1);
   }
}
 
void count(char str[]) {
   int words = 0, characters = 0, spchar = 0, i;
   for (i = 0; str[i] != '\0'; i++) {
      if (isalnum(str[i]) && (i == 0 || !isalnum(str[i - 1])))
         words++;
      characters++;
      if (!isalnum(str[i]) && !isspace(str[i]))
         spchar++;
   }
   printf("\nNo of characters = %d", characters);
   printf("\nNo of special characters = %d", spchar);
   printf("\nNo of words = %d", words);
}
