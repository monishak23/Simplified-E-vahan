#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 7

struct node
{
    char data[15];
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

long int extract_value(char number[])
{
    int i=8,j=0;
    char temp[7],license[15];
    long int value=0;
    strcpy(license,number);
    while(i<15)
        {
            temp[j]=license[i];
            i++;
            j++;
        }
        temp[i]='\0';
        value=atol(temp);

    return value;
}

void insert(int value,char number[])
{
    struct node *newNode = malloc(sizeof(struct node));
    strcpy(newNode->data,number);
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty

    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {temp = temp->next;}
        temp->next = newNode;
    }
}

int search(int value,char number[15])
{
    int key=value%size;
    struct node *temp=chain[key];
        while(temp)
            {
           if( strcmp(temp->data,number)==0)
                return 1;
            temp=temp->next;
            }
return 0;
}

void details(char number[15])
{
    int i=0,j=0,k=2,c,year,p=0,q=4;
    char temp[3],license[15],t[3],a[5];
    strcpy(license,number);

    //extracting the state
    while(i<2)
        {
            temp[i]=license[i];
            i++;
        }
        temp[i]='\0';

    //extracting the city
    while(k<4)
        {
            t[j]=license[k];
            k++;
            j++;
        }
        t[j]='\0';
        c = atol(t);

    //extracting the year
    while(q<8)
    {
        a[p]=license[q];
        p++;
        q++;
    }
    a[p]='\0';
    year=atol(a);

        if(strcmp(temp,"TN")==0)
        {
            if(c==37)
               printf("\n\nState:\t\t(%s) TAMILNADU\nCity:\t\t(%d) COIMBATORE(SOUTH)\n",temp,c);
            else if(c==39)
               printf("\n\nState:\t\t(%s) TAMILNADU\nCity:\t\t(%d) TIRUPPUR\n",temp,c);
        }

        else if(strcmp(temp,"KL")==0)
        {
            if(c==02)
                printf("\n\nState:\t\t(%s) KERALA\nCity:\t\t(%d) KOLLAM",temp,c);
            else if(c==9)
                printf("\n\nState:\t\t(%s) KERALA\nCity:\t\t(%d) PALLAKAD",temp,c);
        }

        else if(strcmp(temp,"KA")==0)
        {
            if(c==9)
                printf("\n\nState:\t\t(%s) KARNATAKA\nCity:\t\t(%d) MYSORE",temp,c);
            else if(c==19)
                printf("\n\nState:\t\t(%s) KARNATAKA\nCity:\t\t(%d) MANGALORE",temp,c);
        }

        else if(strcmp(temp,"TS")==0)
        {
            if(c==9)
                printf("\n\nState:\t\t(%s)TELANGANA\nCity:\t\t(%d) HYDERABAD(CENTRAL)",temp,c);
            else if(c==19)
                printf("\n\nState:\t\t(%s)TELANGANA\nCity:\t\t(%d) MANCHERIAL",temp,c);
        }

        else if(strcmp(temp,"AP")==0)
        {
            if(c==03)
                printf("\n\nState:\t\t(%s)ANDHRA PRADESH\nCity:\t\t(%d) CHITTOR",temp,c);
            else if(c==04)
                printf("\n\nState:\t\t(%s)ANDHRA PRADESH\nCity:\t\t(%d) KADAP",temp,c);
        }

        if(strcmp(temp,"MH")==0)
        {
            if(c==01)
              printf("\nState:\t\t(%s) MAHARASHTRA\nCity:\t\t(%d) MUMBAI\n",temp,c);
            else if(c==12)
              printf("\nState:\t\t(%s)  MAHARASHTRA\nCity:\t\t(%d) PUNE\n",temp,c);
        }

        else if(strcmp(temp,"UP")==0)
        {
            if(c==32)
                printf("\nState:\t\t(%s) UTTAR PRADESH\nCity:\t\t(%d) LUCKNOW\n",temp,c);
            else if(c==80)
                printf("\nState:\t\t(%s) UTTAR PRADESH\nCity:\t\t(%d) AGRA\n",temp,c);
        }

        else if(strcmp(temp,"GJ")==0)
        {
            if(c==01)
                printf("\nState:\t\t(%s) GUJARAT\nCity:\t\t(%d) AHMEDABAD\n",temp,c);
            else if(c==05)
                printf("\nState:\t\t(%s) GUJART\nCity:\t\t(%d) SURAT\n",temp,c);
        }

        else if(strcmp(temp,"WB")==0)
        {
            if(c==05)
                printf("\nState:\t\t(%s) WEST BENGAL\nCity:\t\t(%d) KOLKATA\n",temp,c);
            else if(c==11)
                printf("\nState:\t\t(%s) WEST BENGAL\nCity:\t\t(%d) HOWRAH\n",temp,c);
        }

        else if(strcmp(temp,"HR")==0)
        {
            if(c==06)
                printf("\nState:\t\t(%s) HARYANA\nCity:\t\t(%d) PANIPAT\n",temp,c);
            else if(c==26)
                printf("\nState:\t\t(%s) HARYANA\nCity:\t\t(%d) GURGAON\n",temp,c);
        }

        printf("Year:\t\t%d\nLic. no.:\t%d\n",year,extract_value(license));
}


/*
* return 1, successful delete
* return 0, value not found
*/

int del(char number[15])
{
    long int value;
    value=extract_value(number);

    int key = value % size;
    struct node *temp = chain[key], *dealloc;
    if(temp != NULL)
    {
        if(strcmp(temp->data,number)==0)
        {
            dealloc = temp;
            temp = temp->next;
            free(dealloc);
            return 1;
        }
        else
        {
            while(temp->next)
            {
               if(strcmp(temp->data,number)==0)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    free(dealloc);
                    return 1;
                }
                temp = temp->next;
           }
        }
    }
    return 0;
}


int main()
{
    //initialize array of list to NULL
    init();
    int choice,ans,i=8,j=0;
    char license[15],number[15],temp[7];
    long int value;

    printf("***************************HASHING OF LICENSE NUMBER***************************");
    do
    {
    printf("\n1.Insert a record\n2.Delete a record\n3.Search a record\n4.Print all the records\n5.Exit\nEnter an option:\t");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
        printf("\nEnter the license number: ");
        scanf("%s",license);
        value=extract_value(license);
        insert(value,license);
        }
        break;

   case 2:
        printf("\nEnter the license number: ");
        scanf("%s",license);
        del(license);
        break;

   case 3:
        {
        printf("\nEnter the license number: ");
         scanf("%s",license);
        value=extract_value(license);
        if(search(value,license))
        {
            printf("\nSearch found\n\nREGISTRATION DETAILS OF %s ARE AS FOLLOWS:\n",license);
            details(license);
        }
        else
            printf("\nSearch not found");
        }

         break;

   case 4:
        {
            for(j = 0; j < size; j++)
                {
                    struct node *temp = chain[j];
                    printf("chain[%d]-->",j);
                    while(temp)
                        {
                            printf("%s -->",temp->data);
                            temp = temp->next;
                        }
                    printf("NULL\n");
                }
        }
        break;

   case 5:
        return 0;

   default:
        printf("\nPlease enter the available options\t");
    }
    printf("\nTo continue, Enter 1 or else enter 0\t");
    scanf("%d",&ans);

}
    while(ans==1);
    return 0;
}

