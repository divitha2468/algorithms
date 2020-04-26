import java.util.Scanner;
class knap{
    float w;
  float p;
  float r;
}
public class fraknap
{
	 static int n;
  static int m;
 static Scanner in=new Scanner(System.in);
 public static void main(String args[]){
     System.out.println("enter the value of n");
     n=in.nextInt();
     System.out.println("enter the value of m");
     m=in.nextInt();
     knap obj[]=new knap[n];
     for(int i=0;i<n;i++)
     {
         obj[i]=new knap();
     }
     readobjects(obj);
     knapsnack(obj);

 }
 public static void readobjects(knap obj[])
 {
     knap temp=new knap();
     System.out.println("enter weights");
     for(int i=0;i<n;i++)
       obj[i].w=in.nextFloat();
     System.out.println("enter profits");
     for(int i=0;i<n;i++)
       obj[i].p=in.nextFloat();
    for(int i=0;i<n;i++)
       obj[i].r=(obj[i].p/obj[i].w) ;
    for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<n-1-i;j++)
      {
          if(obj[j].r<obj[j+1].r)
          {
              temp=obj[j];
              obj[j]=obj[j+1];
              obj[j+1]=temp;
              
          }
      }
    }
 }

 public static void knapsnack(knap obj[])
 {
     float totalprofit=0;
     float u;
     int k;
     u=m;
     float x[]=new float[n];
     for(int i=0;i<n;i++)
     x[i]=0;
     for(k=0;k<n;k++)
     {
         if(obj[k].w >u)
          break;
        else{
            x[k]=1;
            totalprofit=totalprofit+obj[k].p;
            u=u-obj[k].w;
        }
     }
     System.out.println("i="+ k);
     if(k<n)
       x[k]=u/obj[k].w;
    totalprofit=totalprofit + (x[k]*obj[k].p);
     
     System.out.println(" vector X");
     for(int i=0;i<n;i++)
     System.out.println(x[i]);
     System.out.println("totalprofit is"+ totalprofit);
 }
}
