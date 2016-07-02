import java.io.*;
class Gray
{

//String l2[]=new String[100];
int times=0;
int i,c,m,j,l;
void recursion(String l1[],String l2[],int n,int length)
{
i=0;
c=0;
m=0;
j=0;
l=0;
if(times<=n-1)
{
times++;
while(i<length)
{
l2[j]="1"+l1[length-j];
i++;
l++;
j++;
}
while(m<length)
{
l1[m]="0"+l1[m];
m++;
}


//System.out.println(i);
while(c<l)
{
l1[m]=l2[c];
c++;
m++;
length++;
}
//recursion(l1,l2,n);
}
}
public static void main(String args[])throws IOException
{
String L1[]=new String[100];
String L2[]=new String[100];
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
System.out.println("Enter the bits:");
int n=Integer.parseInt(br.readLine());
int k=0,length=0;
/*for(int i=0;i<(n*n);i++)
{
L1[i]="x";
L2[i]="x";
}*/
L1[0]="0";
length++;
L1[1]="1";
length++;
Gray obj=new Gray();
obj.recursion(L1,L2,n,length);
while(!("x".equals(L1[k])))
{
System.out.println(L1[k]);
System.out.println("L2="+L2[k]);
k++;
}
}

}