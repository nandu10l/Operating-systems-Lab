#include&lt;stdio.h&gt;
int head,a[20],i,distance,n,seektime;
int main()
{
printf(&quot;\nEnter Head position:&quot;);
scanf(&quot;%d&quot;,&amp;head);
printf(&quot;\nEnter number of disk requests:&quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;\nEnter the disk requests:&quot;);
for(i=1; i&lt;=n; i++)
scanf(&quot;%d&quot;,&amp;a[i]);
a[0]=head;
printf(&quot;*****FCFS DISK SCHEDULING*****************\n&quot;);
for(i=0;i&lt;n;i++)
{
distance=(a[i]&gt;a[i+1])?a[i]-a[i+1]:a[i+1]-a[i];
printf(&quot;Head movement from %d to %d : %d\n&quot;,a[i],a[i+1],distance);
seektime=seektime+distance;
}
printf(&quot;Total seek time is : %d\n&quot;,seektime);
}
