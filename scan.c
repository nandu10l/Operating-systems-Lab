#include&lt;stdio.h&gt;
int absoluteValue(int); // Declaring function absoluteValue
void main()
{
int queue[25],n,headposition,i,j,k,seek=0, maxrange,
difference, temp, queue1[20], queue2[20], temp1=0, temp2=0;
float averageSeekTime;
// Reading the maximum Range of the Disk.
printf(&quot;Enter the maximum range of Disk: &quot;);
scanf(&quot;%d&quot;, &amp;maxrange);
// Reading the number of Queue Requests (Disk access requests)
printf(&quot;Enter the number of queue requests: &quot;);
scanf(&quot;%d&quot;,&amp;n);
// Reading the initial head position. (ie. the starting point of execution)
printf(&quot;Enter the initial head position: &quot;);
scanf(&quot;%d&quot;, &amp;headposition);
// Reading disk positions to be read in the order of arrival
printf(&quot;Enter the disk positions to be read(queue): &quot;);
for(i=1;i&lt;=n;i++) // Note that i varies from 1 to n instead of 0 to n-1
{
scanf(&quot;%d&quot;,&amp;temp); //Reading position value to a temporary variable
//Now if the requested position is greater than current headposition,
//then pushing that to array queue1
if(temp&gt;headposition)
{
queue1[temp1]=temp; //temp1 is the index variable of queue1[]
temp1++; //incrementing temp1
}
else //else if temp &lt; current headposition,then push to array queue2[]
{
queue2[temp2]=temp; //temp2 is the index variable of queue2[]
temp2++;
}
}
//Now we have to sort the two arrays
//SORTING array queue1[] in ascending order
for(i=0;i&lt;temp1-1;i++)
{
for(j=i+1;j&lt;temp1;j++)
{
if(queue1[i]&gt;queue1[j])
{
temp=queue1[i];
queue1[i]=queue1[j];
queue1[j]=temp;
}
}
}
//SORTING array queue2[] in descending order
for(i=0;i&lt;temp2-1;i++)
{
for(j=i+1;j&lt;temp2;j++)
{
if(queue2[i]&lt;queue2[j])
{
temp=queue2[i];
queue2[i]=queue2[j];
queue2[j]=temp;
}
}
}
//Copying first array queue1[] into queue[]
for(i=1,j=0;j&lt;temp1;i++,j++)
{
queue[i]=queue1[j];
}
//Setting queue[i] to maxrange because the head goes to
//end of disk and comes back in scan Algorithm
queue[i]=maxrange;
//Copying second array queue2[] after that first one is copied, into queue[]
for(i=temp1+2,j=0;j&lt;temp2;i++,j++)
{
queue[i]=queue2[j];
}
//Setting queue[i] to 0. Because that is the innermost cylinder.
queue[i]=0;
//At this point, we have the queue[] with the requests in the
//correct order of execution as per scan algorithm.
//Now we have to set 0th index of queue[] to be the initial headposition.
queue[0]=headposition;
// Calculating SEEK TIME. seek is initially set to 0 in the declaration part.
for(j=0; j&lt;=n; j++) //Loop starts from headposition. (ie. 0th index of queue)
{
// Finding the difference between next position and current position.
difference = absoluteValue(queue[j+1]-queue[j]);
// Adding difference to the current seek time value
seek = seek + difference;
// Displaying a message to show the movement of disk head
printf(&quot;Disk head moves from position %d to %d with Seek %d \n&quot;,
queue[j], queue[j+1], difference);
}
// Calculating Average Seek time
averageSeekTime = seek/(float)n;
//Display Total and Average Seek Time(s)
printf(&quot;Total Seek Time= %d\n&quot;, seek);
printf(&quot;Average Seek Time= %f\n&quot;, averageSeekTime);
}
// Defining function absoluteValue
int absoluteValue(int x)
{
if(x&gt;0)
{
return x;
}
else
{
return x*-1;
}
}
