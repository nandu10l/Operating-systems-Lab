#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
int main()
{
int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
printf(&quot;Enter the number of Requests\n&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Enter the Requests sequence\n&quot;);
for(i=0;i&lt;n;i++)
scanf(&quot;%d&quot;,&amp;RQ[i]);
printf(&quot;Enter initial head position\n&quot;);
scanf(&quot;%d&quot;,&amp;initial);
printf(&quot;Enter total disk size\n&quot;);
scanf(&quot;%d&quot;,&amp;size);
printf(&quot;Enter the head movement direction for high 1 and for low 0\n&quot;);
scanf(&quot;%d&quot;,&amp;move);
// logic for C-Scan disk scheduling
/*logic for sort the request array */
for(i=0;i&lt;n;i++)
{
for( j=0;j&lt;n-i-1;j++)
{
if(RQ[j]&gt;RQ[j+1])
{
int temp;
temp=RQ[j];
RQ[j]=RQ[j+1];
RQ[j+1]=temp;
}
}
}
int index;
for(i=0;i&lt;n;i++)
{
if(initial&lt;RQ[i])
{
index=i;
break;
}
}
// if movement is towards high value
if(move==1)
{
for(i=index;i&lt;n;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
initial=RQ[i];
}
// last movement for max size
TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
/*movement max to min disk */
TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
initial=0;
for( i=0;i&lt;index;i++)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
initial=RQ[i];
}
}
// if movement is towards low value
else
{
for(i=index-1;i&gt;=0;i--)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
initial=RQ[i];
}
// last movement for min size
TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
/*movement min to max disk */
TotalHeadMoment=TotalHeadMoment+abs(size-1-0);
initial =size-1;
for(i=n-1;i&gt;=index;i--)
{
TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
initial=RQ[i];
}
}
printf(&quot;Total head movement is %d&quot;,TotalHeadMoment);
return 0;
}
