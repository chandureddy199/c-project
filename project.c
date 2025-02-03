#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct election
{
    char candidates[50];
    int votes;
};
struct voters
{
    char voter_name[50];
    int voter_id;
    int votecount;
    char password[20];
};
int n=0,m=0,index1=0,index2=0,p,q=0,id,max=0,w=0,votes=0;
char pass[50];
struct election a[10];
struct voters b[100]; 

void addcandidates()
{
    printf("enter no of candidates: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("candidate %d: ",i+1);
        scanf("%s",a[index1].candidates);
        a[index1].votes=0;
        index1++;
    }
}
void viewcandidates()
{
    for(int i=0;i<index1;i++)
    {
        printf("Candidate %d: %s\tvotes: %d\n",i+1,a[i].candidates,a[i].votes);
    }
}
void registervoters()
{
    printf("enter no of voters: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        printf("voter name %d: ",i+1);
        scanf("%s",b[index2].voter_name);
        b[index2].votecount=0;
        printf("enter voter id: ");
        scanf("%d",&b[index2].voter_id);
        printf("set password:");
        scanf("%s",b[index2].password);
        index2++;
    }
}
void castvote()
{
    for(int i=0;i<index2;i++)
    {
        printf("enter your voter id: ");
        scanf("%d",&id);
        printf("enter password: ");
        scanf("%s",&pass);
        if(strcmp(pass,b[i].password)==0&&id==b[i].voter_id)
        {
            if(q<index2)
            {
                if(b[q].votecount==0)
                {
                    printf("enter your vote, %s:\n",b[q].voter_name);
                    b[q].votecount++;
                    viewcandidates();
                    scanf("%d",&p);
                    a[p-1].votes++;
                    q++;
                }    
            }
        }
    }
}
void viewvoters()
{
    for(int i=0;i<index2;i++)
    {
        printf("voters %d: %s\n",i+1,b[i].voter_name);
    }
}
void displayresults()
{
    for(int i=0;i<index1;i++)
    {
        if(a[i].votes>max)
        {
            max=a[i].votes;
            w=i;
        }
    }
    printf("candidate %d: %d",a[w].candidates,max);
}
void main(){
    int choice;
    while(1)
    {
        printf("1.add candidates\n2.view candidates\n3.register voters\n4.view voters\n5.cast vote\n6.Display results\n7.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addcandidates();
                break;
            case 2:
                viewcandidates();
                break;
            case 3:
                registervoters();
                break;
            case 4:
                viewvoters();
                break;
            case 5:
                printf("\nhi\n");
                castvote();
                break;
            case 6:
                displayresults();
                break;
            case 7:
                exit(0);
                break;
        }
    }
}