#include<stdio.h>
int frames[10],pages[50],frame_usage[10];

int findLRU(int n_frames){
    int min=frame_usage[0];
    int pos=0;
    for(int i=1;i<n_frames;i++){
        if(frame_usage[i]<min){
            min=frame_usage[i];
            pos=i;
        }
    }
    return pos;
}

void main(){
    int no_0f_frames,no_of_page,i,pf=0,ph=0;
    printf("Enter no of pages:");
    scanf("%d",&no_of_page);
    printf("Enter the no of frame:");
    scanf("%d",&no_0f_frames);
    printf("Enter the requests:");
    for(i=0;i<no_of_page;i++){
        scanf("%d",&pages[i]);
    }
    for(i=0;i<no_0f_frames;i++){
        frames[i]=-1;
        frame_usage[i]=0;
    }
    printf("PAGE \t FRAMES \n");
    for(int i=0;i<no_of_page;i++){
        int page=pages[i];
        int flag=0;

        for(int j=0;j<no_0f_frames;j++){
            if(frames[j]==page){
                frame_usage[j]=i+1;
                 flag=1;
                 break;
            }            
        }
        if(flag==0){
            int tru_pos=findLRU(no_0f_frames);
            frames[tru_pos]=page;
            frame_usage[tru_pos]=i+1;
            pf++;
        }
        else{
            ph++;
        }
        printf("%d\t",page);
        if(flag==1){
            printf("page hit");
        }
        else{
            for(int j=0;j<no_0f_frames;j++){
                if(frames[j]==-1){
                    printf("-\t");
                }
                else{
                    printf("%d\t",frames[j]);
                }
            }
        }
        printf("\n");
    }
     printf("No of page fault=%d\n",pf);  
      printf("No of page hit=%d\n",ph);  
}
