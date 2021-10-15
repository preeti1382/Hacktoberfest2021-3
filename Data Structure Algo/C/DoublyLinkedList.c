#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert_beginning();
void insert_end();
void insert_after();
void del();
void display();
struct node
{
    int data;
    struct node *prev , *next;
}*head;
int main()
{
    int ch;
    do
    {
        printf("===DOUBLY LINKED LIST====\n");
        printf(" 1.Insert at beginning\n 2.Insert at end\n 3.Insert at Kth position\n 4. delete\n 5.Display\n 6.Exit\n");
        printf("enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insert_beginning();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_after();
            break;
        case 4:
            del();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
            break;
        default:
            printf("Invalid choice....\n");
        }
    }while(ch != 6);
    return 0;
}
void insert_beginning()
{
            struct node *ptr;
            int val;
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->prev = NULL;
            if(ptr == NULL){printf("overflow..\n");}
            else{
                    printf("enter value:");
                    scanf("%d",&val);
                    ptr->data = val;
                    if(head == NULL){ptr->next = NULL;}
                    else{ptr->next = head;
                          head->prev = ptr;}
                    head = ptr;
            }
            printf("value inserted..\n");
}
void insert_end()
{
            struct node *ptr , *temp;
            int val;
            printf("enter value:");
            scanf("%d",&val);
            ptr = (struct node*)malloc(sizeof(struct node));
            ptr->data = val;
            ptr->next = NULL;
            ptr->prev = NULL;
            if(head == NULL){
                ptr->prev = head;
                head = ptr;
            }
            else{
                temp = head;
                if(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = ptr;
                ptr->prev = temp;
                ptr->next = NULL;
            }
            printf("value inserted at end....\n");
}
void insert_after()
{
            struct node *ptr , *temp;
            int val , key;
            ptr = (struct node*)malloc(sizeof(struct node));
            printf("enter key:");
            scanf("%d" , &key);
            temp = head;
            while(temp->data != key && temp != NULL){
                temp = temp->next;
            }
            if(temp == NULL){
                printf("Key not found..\n");
            }
            else{
                printf("enter value:");
                scanf("%d",&val);
                ptr->data = val;
                ptr->next = temp->next;
                ptr->prev = temp;
                temp->next = ptr;
                temp->next->prev = ptr;
                printf("value inserted....\n");
            }
}
void display()
{
            struct node  *temp;
            temp = head;
            if(head == NULL)
            {
                printf("linked list is empty..\n");
            }
            else
            {
                while(temp != NULL)
                {
                    printf("%d " , temp->data);
                    temp = temp->next;
                }
                printf("\n");
            }
}
void del()
{
    struct node *ptr , *temp  , *temp1;
    ptr = (struct node*)malloc(sizeof(struct node));
    int key;

    if(head == NULL){
        printf("Linked List is empty...\n");
    }
    else{
        printf("enter key:");
        scanf("%d",&key);

        temp=head;
        if(head->data == key){
            temp->next->prev = head;
            head = temp->next;
            temp = temp->next;
            printf("first value deleted...\n");
        }
        else{

            while(temp->data != key && temp!=NULL){
                temp = temp->next;
            }
            if(temp == NULL){
                printf("key not found...\n");
            }


            else{
                if(temp->next != NULL){
                    temp = temp->next;
                }
                else if(temp->next == NULL){
                    temp->prev->next = NULL;
                    printf("last value deleted...\n");
                }
                else{

                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                    free(temp);

                    printf("value deleted...\n");
                }

            }
        }
    }
}
