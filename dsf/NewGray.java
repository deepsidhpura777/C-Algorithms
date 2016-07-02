import java.io.*;
class NewGray
{
int c1,c2,c3,times=0;
void recursion(String l1[],String l2[],int n,int length1)
{
c1=0;c2=0;c3=0;
if(times<n-1)
{
times++;
while(c1<length1)
{
l2[c1]="1"+l1[(length1-1)-c1];
c1++;
}

while(c2<length1)
{
l1[c2]="0"+l1[c2];
c2++;
}
while(c3<c1)
{
l1[length1]=l2[c3];
c3++;
length1++;
}
recursion(l1,l2,n,length1);
}
}




public static void main(String args[])throws IOException
{
String L1[]=new String[1000];
String L2[]=new String[1000];
int length1=0;
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter the bits:");
int n=Integer.parseInt(br.readLine());
L1[0]="0";length1++;
L1[1]="1";length1++;
NewGray obj=new NewGray();
obj.recursion(L1,L2,n,length1);
int s=(int)Math.pow(2.0,n);
for(int i=0;i<s;i++)
{
System.out.println(i+"="+L1[i]);
//System.out.println("L2="+L2[i]);
}
}
}