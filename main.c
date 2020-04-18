// A C Program to d
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
static int a=5;

/*typedef struct post
{
    char text[200];
    int post_number;
    struct post * next;

}post;

typedef struct postlist
{
    post * post_head;
}postlist;
*/

typedef struct user
{
   int index;
   char name[30];
   char bio[100];
  //  postlist *head;
    //int num_posts;

}user;





typedef struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
}AdjListNode;

// A structure to represent an adjacency list
typedef struct AdjList
{
	struct AdjListNode *head;
}AdjList;

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
typedef struct Graph
{
	int V;
	struct AdjList* array;
}Graph;

// A  function to create a new adjacency list node
AdjListNode * newAdjListNode(int dest)
{
    AdjListNode* newNode =(AdjListNode*) malloc(sizeof( AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}
/*
post * newpost( char *a)
{
    post * temppost =(post *)malloc(sizeof(post));
    strcpy(temppost->text,a);
    temppost->next=NULL;
    return temppost;

}
*/
// A utility function that creates a graph of V vertices
struct Graph* createGraph()
{
	struct Graph* graph =
		(struct Graph*) malloc(sizeof(struct Graph));

	graph->V = 100;

	// Create an array of adjacency lists. Size of
	// array will be V
	graph->array =
	(struct AdjList*) malloc(100 * sizeof(struct AdjList));

	// Initialize each adjacency list as empty by
	// making head as NULL
	int i;
	for (i = 0; i < 100; ++i)
		graph->array[i].head = NULL;

	return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
	// Add an edge from src to dest. A new node is
	// added to the adjacency list of src. The node
	// is added at the beginning
	struct AdjListNode* newNode;
	newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Since graph is undirected, add an edge from
	// dest to src also
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}
/*
void addpost(user *user_array,int v)
{

    char x[200];
	printf("Enter the post that you want to share: ");
	scanf("%s", x);

	post * newtemp_post;
	newtemp_post = newpost(x);
	newtemp_post->next = user_array[v].head    ;                  // graph->array[src].head;
	user_array[v].head = newtemp_post;
    user_array[v].num_posts++;

}
*/

// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph , user *user_array)
{
	int v;
	for (v = 0; v < graph->V; ++v)
	{
		struct AdjListNode* pCrawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n (or as  we could say %s )head  ", v,user_array[v].name );

		while (pCrawl)
		{
			printf("-> %d:%s", pCrawl->dest,user_array[pCrawl->dest].name );
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}
void addbio(user * user_array, int v)
{
    printf("Enter you new bio:");
    scanf("%s", user_array[v].bio);
}
void suggestfriend( Graph * graph, user * user_array, int v)
{
      point1:
printf("\n");

    int trp;
    struct AdjListNode* pCrawl = graph->array[v].head;
    if(pCrawl==NULL)
    {
        printf("You are a new user . Please add some friends so that we can suggest you better");

		printf("\n Tweetbook Users:\n  " );

		for (int k = 0; k < a; k++)
        {
			userdetails(graph,user_array,k);
			printf("\n");

		}
		printf("\n");
	}


    else{

    struct AdjListNode* innerCrawl= (AdjListNode*)malloc(sizeof(AdjListNode));
    int *check=(int*)malloc(graph->V * sizeof(int));
     for(int i=0;i<graph->V;i++)
        {
            check[i]=0;
        }
        while (pCrawl)
		{
			check[pCrawl->dest]=-1;
			pCrawl = pCrawl->next;
		}
		check[v]=-1;

        pCrawl = graph->array[v].head;


		printf("\n Suggesting Friends...\n ");
		while (pCrawl)
		{
			  innerCrawl = graph->array[pCrawl->dest].head;
			  printf("Possible friends from %s are --",user_array[pCrawl->dest].name);
			  // printf(" %s ,", user_array[innerCrawl->dest].name);

        while (innerCrawl)
		{
		    if(check[innerCrawl->dest]!=-1)
            {
            printf(" %s \n", user_array[innerCrawl->dest].name);
			check[innerCrawl->dest]=1;
            }
            innerCrawl = innerCrawl->next;

		}
		printf("\n");

			pCrawl = pCrawl->next;
		}

		check[v]=0;
		 pCrawl = graph->array[v].head;
		while (pCrawl)
		{
			check[pCrawl->dest]=0;
			pCrawl = pCrawl->next;
		}

		printf("SUGGESTED FOR YOU:");
        for(int i=0;i<graph->V;i++)
        {
            if(check[i]==1)
            {
                printf("\n%s",user_array[i].name);
            }
        }
    }
         char q[100];

        printf("\nEnter Friend's name:");
        scanf("%s",q);
       // printf("");
        int i=0;
        while(i<a)
        {
            if(strcmp(user_array[i].name,q)==0)
            {
                break;
            }

            i++;
        }
        if (i==a){
                 printf("account not found! Print 1 if you want to add another friend:") ;
                scanf("%d",&trp);
                if(trp==1)goto point1;


        }
        else {
                printf("adding %s!", user_array[i].name);
                addEdge(graph,v,i);
                 printf("\n Print 1 if you want to add another friend:") ;
                scanf("%d",&trp);
                if(trp==1)goto point1;
        }


        /*char *newfr;

        printf("Do you want to add friends?Enter the name of user:");
                scanf("%s",newfr);
                int i=0;



                   int trp;
        while(i<a)
        {
            if(strcmp(user_array[i].name,newfr)==0)
            {
                break;
            }

            i++;
        }

        if (i==a){

                printf("account not found! Print 1 if you want to add another friend:") ;
                scanf("%d",&trp);
                if(trp==1)goto point1;


        }



        else {
                addEdge(graph,v,i);
                printf("Friend added! Print 1 if you want to add another friend . any other key to return to main menu:") ;
                scanf("%d",&trp);
                if(trp==1)goto point1;
            }


*/


		printf("returning :\n");
}



void userdetails(struct Graph* graph , user *user_array, int v)
{
    printf("PrintIng the details of user:\n");
    printf("NAME:%s\n",user_array[v].name);
    printf("BIO: %s\n", user_array[v].bio);
    if(graph->array[v].head==NULL)
    {
        printf("No friends yet");
    }
    else{
    printf("Friends:\n");

    AdjListNode* pCrawl = graph->array[v].head;
		//printf("\n Adjacency list of vertex %d\n (or as  we could say %s )head  ", v,user_array[v].name );

		while (pCrawl)
		{
			printf("%s\t\n  ",user_array[pCrawl->dest].name );
			pCrawl = pCrawl->next;
		}
		printf("\n");


/*        post* pCrawl1 = user_array[v].head;

		printf("\n List of posts of %d %s ) ", v,user_array[v].name );

		while (pCrawl1)
		{
			printf("->%s\n", pCrawl1->text);
			pCrawl = pCrawl1->next;
			printf("\n");
		}
		printf("\n");

*/
    }
}



int login(user *user_array)
{
    int c;
    dest:
    printf("\nPress 1 to Create New Account. \nPress 2 if you already have an account! \n Press 3 To terminate Tweetbook. \n Your choice: ");
    scanf("%d", &c);

    if(c==1)
    {
        printf("Enter your name:");
        scanf("%s",user_array[a].name);
        printf("Account created.\n Welcome %s\n",user_array[a].name);
        a++;
        return a-1;


    }
    else if (c==2)
    {   char q[100];
        printf("\nenter your name:");
        scanf("%s",q);
        int i=0;
        while(i<a)
        {
            if(strcmp(user_array[i].name,q)==0)
            {
                break;
            }

            i++;
        }
        if (i==a){
                printf("account not found!") ;
                goto dest;
        }
        else {
                printf("Welcome %s!", user_array[i].name);
        }
       return i;
    }
    else if (c==3){  exit(1); }
}
// Driver program to test above functions
int main()
{
    user *user_array = (user *) malloc (100*sizeof(user));

    user_array[0].index=0;
    strcpy(user_array[0].name , "abhishek");

    strcpy(user_array[1].name , "abel");
    strcpy(user_array[2].name , "bella");
    strcpy(user_array[3].name , "ronaldo");
    strcpy(user_array[4].name , "messi");


    strcpy(user_array[0].bio , "student at vit");

    strcpy(user_array[1].bio , "artist from canada");

    strcpy(user_array[2].bio , "artist from canada");

    strcpy(user_array[3].bio , "athlete from portugal");

    strcpy(user_array[4].bio , "athlete from argentina");

    // create the graph given in above fugure
	int V = a;
	struct Graph* graph = createGraph();
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 2, 1);
	addEdge(graph, 3, 4);


int b;
printf("TWEETBOOK login Page!");
loginpt:
b=login(user_array);


while(1)
    {

printf("\t\tTWEETBOOK- A short lived social network\n\n");
printf("--------------------------------------------------------------------------------------------------------");
printf("\n So what are you up to this time?\n");/*\n 1.Share a new post 2.Delete an old post \n ");*/
printf("1.Show all users \n2. Set your bio \n3. Show your account details\n4. View a friends account \n5. Find a new friend \n6.log out \n7. Terminate program\n Your choice:");

int z;
scanf("%d",&z);
//system("cls");

printf("\t\tTWEETBOOK- A short lived social network\n\n");
switch(z){
case 1:


		printf("\n Tweetbook Users:\n  " );

		for (int k = 0; k < a; k++)
        {
			userdetails(graph,user_array,k);
			printf("\n");

		}
		printf("\n");

     break;

case 2: addbio(user_array,b);
   break;



case 3:userdetails(graph,user_array,b);

     break;

case 4: if(graph->array[b].head==NULL)
        {
            printf("You have not added any friends ! Please add some friends!\n");
        }
        else{
        printf("Choose the friend you want to view\n ");
        printf(" Your Friends:");
        int f=0;

    AdjListNode* pCrawl = graph->array[b].head;
		//printf("\n Adjacency list of vertex %d\n (or as  we could say %s )head  ", v,user_array[v].name );

		while (pCrawl)
		{
			printf("%s, ",user_array[pCrawl->dest].name );
			pCrawl = pCrawl->next;
		}

    pCrawl = graph->array[b].head;
		while (pCrawl)
		{
			printf("\n\nWAnt to view %s's profile?Press 1 to view!  ",user_array[pCrawl->dest].name );
			scanf("%d",&f);
			if(f==1){
			userdetails(graph,user_array,pCrawl->dest);
			}
			pCrawl = pCrawl->next;
		}
		/*
		char *name;
		printf("\nName:");
        scanf("%s",name);
        printf("You have chosen%s", name);
		/*int i=-1;
		pCrawl = graph->array[b].head;
        while (pCrawl)
		{
			if(strcmp(user_array[pCrawl->dest].name,name)==0)
            {
                i=pCrawl->dest;
                break;
            }

			pCrawl = pCrawl->next;
		}
		if(i==-1)
        {
            printf("Not found!");
        }

        int i=0;
        printf("goin in");
        while(i<a)
        { printf("1111%dand %d",i, a);
            if(strcmp(user_array[i].name,name)==0)
            {
                break;
            }

            i++;
        }
        if (i==a){
                printf("account not found!") ;

        }

        else
        {
        printf("printing details");
         userdetails(graph,user_array,i);
        }

*/
        }
    break;
case 5:suggestfriend(graph,user_array,b);

    break;
case 6:goto loginpt;
clrscr(); break;
case 7:exit(1);
break;
default: printf("invalid option.\n");


    }
}

	return 0;
}
/*
TWEETBOOK login Page!
Press 1 to Create New Account.
Press 2 if you already have an account!
 Press 3 To terminate Tweetbook.
 Your choice: 2

enter your name:abhishek
Welcome abhishek!               TWEETBOOK- A short lived social network

--------------------------------------------------------------------------------------------------------
 So what are you up to this time?
1.Show all users
2. Set your bio
3. Show your account details
4. View a friends account
5. Find a new friend
6.log out
7. Terminate program
 Your choice:1
                TWEETBOOK- A short lived social network


 Tweetbook Users:
  PrintIng the details of user:
NAME:abhishek
BIO: student at vit
Friends:
messi
  abel


PrintIng the details of user:
NAME:abel
BIO: artist from canada
Friends:
bella
  abhishek


PrintIng the details of user:
NAME:bella
BIO: artist from canada
Friends:
abel


PrintIng the details of user:
NAME:ronaldo
BIO: athlete from portugal
Friends:
messi


PrintIng the details of user:
NAME:messi
BIO: athlete from argentina
Friends:
ronaldo
  abhishek



                TWEETBOOK- A short lived social network

--------------------------------------------------------------------------------------------------------
 So what are you up to this time?
1.Show all users
2. Set your bio
3. Show your account details
4. View a friends account
5. Find a new friend
6.log out
7. Terminate program
 Your choice:2
                TWEETBOOK- A short lived social network

Enter you new bio:vitian
                TWEETBOOK- A short lived social network

--------------------------------------------------------------------------------------------------------
 So what are you up to this time?
1.Show all users
2. Set your bio
3. Show your account details
4. View a friends account
5. Find a new friend
6.log out
7. Terminate program
 Your choice:3
                TWEETBOOK- A short lived social network

PrintIng the details of user:
NAME:abhishek
BIO: vitian
Friends:
messi
  abel

                TWEETBOOK- A short lived social network

--------------------------------------------------------------------------------------------------------
 So what are you up to this time?
1.Show all users
2. Set your bio
3. Show your account details
4. View a friends account
5. Find a new friend
6.log out
7. Terminate program
 Your choice:4
                TWEETBOOK- A short lived social network

Choose the friend you want to view
  Your Friends:messi, abel,

WAnt to view messi's profile?Press 1 to view!  1
PrintIng the details of user:
NAME:messi
BIO: athlete from argentina
Friends:
ronaldo
  abhishek



WAnt to view abel's profile?Press 1 to view!  1
PrintIng the details of user:
NAME:abel
BIO: artist from canada
Friends:
bella
  abhishek

                TWEETBOOK- A short lived social network

--------------------------------------------------------------------------------------------------------
 So what are you up to this time?
1.Show all users
2. Set your bio
3. Show your account details
4. View a friends account
5. Find a new friend
6.log out
7. Terminate program
 Your choice:5
                TWEETBOOK- A short lived social network



 Suggesting Friends...
 Possible friends from messi are -- ronaldo

Possible friends from abel are -- bella

SUGGESTED FOR YOU:
bella
ronaldo
Enter Friend's name:bella
adding bella!
 Print 1 if you want to add another friend:1


 Suggesting Friends...
 Possible friends from bella are --
Possible friends from messi are -- ronaldo

Possible friends from abel are --
SUGGESTED FOR YOU:
ronaldo
Enter Friend's name:ronaldo
adding ronaldo!
 Print 1 if you want to add another friend:2
returning :
                TWEETBOOK- A short lived social network

--------------------------------------------------------------------------------------------------------
 So what are you up to this time?
1.Show all users
2. Set your bio
3. Show your account details
4. View a friends account
5. Find a new friend
6.log out
7. Terminate program
 Your choice:3
                TWEETBOOK- A short lived social network

PrintIng the details of user:
NAME:abhishek
BIO: vitian
Friends:
ronaldo
  bella
  messi
  abel

                TWEETBOOK- A short lived social network

--------------------------------------------------------------------------------------------------------
 So what are you up to this time?
1.Show all users
2. Set your bio
3. Show your account details
4. View a friends account
5. Find a new friend
6.log out
7. Terminate program
 Your choice:



*/
