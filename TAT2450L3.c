#include<stdio.h>
int main(){
    int bt[10]={0},at[10]={0},tat[10]={0},wt[10]={0},ct[10]={0};
    int n,i;
    float totalTAT=0,totalWT=0;
    printf("Enter no. of processes");
    scanf("%d",&n);
    printf("Enter Arrival Time and Burst Time for each process\n\n");
    for(int i=0;i<n;i++){
        printf("Arrival time of process[%d]",i+1);
        scanf("%d",&at[i]);
          printf("Burst time of process[%d]",i+1);
        scanf("%d",&bt[i]);
        printf("\n");
    }

    // Calculate CompletionTime of Processes
    int sum=at[0]; //Here ->AT[0]=0
for(int j=0;j<n;j++){
    sum=sum+bt[j]; //sum:0+5=5,5+7=12,12+6=18,18+2=20,20+4=24
    ct[j]=sum;
}

// Calculate TurnAroundTime(TAT) and WaitingTime(WT)
for(int k=0;k<n;k++){
    tat[k]=ct[k]-at[k];
    totalTAT=totalTAT+tat[k]; 

}
for(int k=0;k<n;k++){
    wt[k]=tat[k]-bt[k];
    totalWT =totalWT+wt[k];
}

printf("\nSolution:\n");
printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
}
    printf("\n \n Average TurnAround Time =%f\n",totalTAT/n);
printf("Average Waiting Time=%f\n\n",totalWT/n);
    return 0;

}


