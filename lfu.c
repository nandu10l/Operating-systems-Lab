#include<stdio.h>
void main()
{
  int pages[50], i, j, k, no_page, no_frame, cntr[20], frames[20], min, pf=0;
  printf("\nEnter number of page references -- ");
  scanf("%d",&no_page);
  printf("\nEnter the reference string -- ");
  for(i=0;i<no_page;i++)
  scanf("%d",&pages[i]);
  printf("\nEnter the available no. of frames -- ");
  scanf("%d",&no_frame);
   for(i=0;i<no_frame;i++)
   {
     cntr[i]=0; frames[i]=-1;
   }
  printf("\nThe Page Replacement Process is- \n");
  for(i=0;i<no_page;i++)
  {
 
    for(j=0;j<no_frame;j++)
      if(pages[i]==frames[j])
      {
        cntr[j]++;
        break;
	}
       if(j==no_frame)
       {     min = 0;    
         for(k=1;k<no_frame;k++)
             if(cntr[k]<cntr[min])
             min=k;
             frames[min]=pages[i]; cntr[min]=1;
             pf++;
       }
         printf("\n");
         for(j=0;j<no_frame;j++)
         printf("\t%d",frames[j]);
         
     }
     printf("\n\nTotal number of page faults -- %d",pf);
}
