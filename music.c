#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char data[40];
    struct node*next;
    struct node*prev;
}*head=NULL;
char temp[40];
struct node*currentnode=NULL;

void insert()
{
    struct  node*newnode=malloc(sizeof(struct node));
   
    printf("Enter the music Name:\n");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);//storing the name of th music
    strcpy(newnode->data,temp);
    if(head==NULL)
    {
        newnode->next=newnode->prev=newnode;
        head=currentnode=newnode;
        return ;
    }
    struct node*last=head->prev;
    newnode->prev=last;
    last->next=newnode;
    newnode->next=head;
    head->prev=newnode;
}

void delete_element()
{
    if(head==NULL)
    {
            printf("PLaylist is empty\n");
            return ;
    }
    printf("Enter the Music Name to delete:\n");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);
    printf("\n");
    struct node*ptr=head;
    do
    {
        if(ptr->next==ptr && strcmp(ptr->data,temp)==0)
        {
            printf("One File deleted! Playlist is empty now!\n");
            head=NULL;
            free(ptr);
        }
        else  if(strcmp(ptr->data,temp)==0)
        {
              struct node*prev=ptr->prev;
              struct node*next=ptr->next;
              prev->next=next;
              next->prev=prev;
              head=next;
              free(ptr);
              printf("Muisc deleted\n");
              return ;
        }
        ptr=ptr->next;

    } while (ptr!=head);
    printf("No music file is there!\n");   
}

void show()
{
    int i=1;
     if(head==NULL)
     {
        printf("PlayList is Empty\n");
        return  ;
     }
     struct node*show_ptr=head;
     printf("\n");
    printf("Displaying playlist:\n");
    do
    {
        printf("%d.%s\n",i,show_ptr->data);
        i++;
        show_ptr=show_ptr->next;
        
    } while (show_ptr!=head);
}
void next_node()
{
    if(currentnode==NULL)
    {
        printf("No song in PLaylist!\n");
    }
    else
    {
        currentnode=currentnode->next;
        printf("Playing song:%s\n",currentnode->data);

    }
}
void prev_node()
{
    if(currentnode==NULL)
    {
        printf("No song in PLaylist!\n");
    }
    else
    {
        currentnode=currentnode->prev;
        printf("Playing Previous  song:%s\n",currentnode->data);

    }
}
void first_node()
{
    if(head==NULL)
    {
        printf("Playlist is empty!\n");
    }
    else
    {
        printf("First song :%s\n",head->data);
    }
}
void last_node()
{
    if(head==NULL)
    {
        printf("Playlist is empty!\n");
    }
    else
    {
        printf("First song :%s\n",head->prev->data);
    }
}
void specific_node()
{
 int flag=0;
    if(head==NULL)
    {
        printf("Playlist is empty\n");
        return ;
    }
    printf("Enter the music name you are looking for:\n");
    while((getchar())!='\n');
    scanf("%[^\n]%*c",temp);
    printf("\n");
    struct node*ptr=head;
    do
    {
        if(strcmp(ptr->data,temp)==0)
        {
            printf("Music found!\n");
            printf("Playing music:%s\n",ptr->data);
            flag=1;

        }
        ptr=ptr->next;
    } while(ptr!=head);
    if(flag==0)
           printf("There is  no music file with this name!\n");
    

}
int main()
{
    int choice;
    menu:
    printf("\n...........MENU FOR PLAYLIST..........\n");
    printf("1.Add Music\n");
    printf("2.Remove Music\n");
    printf("3.Show PLaylist\n");
    printf("4.Play Next Music\n");
    printf("5.Play Previous Music\n");
    printf("6.Play First Music\n");
    printf("7.Play Last Music\n");
    printf("8.Play Specific  File\n");
    printf("9.Exit\n");
    scanf("%d",&choice);
    if(choice==1)
        insert();
    else if(choice==2)
         delete_element();
    else if(choice==3)
         show();
    else if(choice==4)
         next_node();
    else if(choice==5)
         prev_node();
    else if(choice==6)
         first_node();
    else if(choice==7)
         last_node();
    else if(choice==8)
         specific_node();
    else 
         exit(0);  


         goto menu;                                      


    
}