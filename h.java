Package 1 /Words Class:
package Pack1;
public class Words {
static final int OUT = 0;
static final int IN = 1;
public static int countNumWords(String str) {
int state = OUT;
int wordcount = 0; 
int i = 0;
while (i < str.length()) {
if (str.charAt(i) == ' ' || str.charAt(i) == '\n' || str.charAt(i) ==
'\t') {
state = OUT;
}
else if (state == OUT) {
state = IN;
++wordcount;
}
i++;
}
return wordcount;
}
}
Package 2/Length Class:
package Pack1.Pack2;
public class Length {
public static int strLength(String s)
{
 int length=0;
 char[] charArray=s.toCharArray();
 for(char c:charArray)
 {
 length++;
 }
 return length;
}
}
FindStringWordsAndLength CLASS(MAIN CLASS):
import Pack1.Words;
import Pack1.Pack2.Length;
import java.util.Scanner;
public class FindStringWordsAndLength {
public static void main(String[] args) {
System.out.println("Enter String: ");
Scanner sc=new Scanner(System.in);
String s=sc.nextLine();
System.out.println("Number of words in the string is :
"+Words.countNumWords(s));
System.out.println("Length of the string is :
"+Length.strLength(s));
}
}