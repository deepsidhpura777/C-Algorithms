import java.io.*;
class NewPrefix
{
static String f="";
int prefixTopostfix(String prefix,String postfix)
{
char firstchar=prefix.charAt(0);
if(firstchar>=97 && firstchar<=122)
{
postfix+=firstchar;
f+=postfix;
return 1;
}
int nextprefix1=prefixTopostfix(prefix.substring(1),postfix);
int nextprefix2=prefixTopostfix(prefix.substring(nextprefix1+1),postfix);
postfix+=firstchar;
f+=postfix;
return nextprefix1+nextprefix2+1;

}
public static void main(String args[])throws IOException
{
String prefix,postfix="";
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter the expression:");
prefix=br.readLine();
NewPrefix obj=new NewPrefix();
obj.prefixTopostfix(prefix,postfix);
System.out.println(f);

}
}