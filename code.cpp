//zub
#include<bits/stdc++.h>
using namespace std ;
typedef struct node
{
    int a_time,s_time,c_time ;
    char name[20] ;
    node* next;

}* simu_ptr;

simu_ptr front=NULL, rear=NULL,top=NULL,temp  ;
int stime=0 ,endtime=0;

void input();
void cust_arrive();

void add_history();
void cust_leave();


int work_time();
void serve();

void show_history();


int main()
{
    int counter=0 ;
    int enter ;
    int c = 1 ;

    while(1)
    {
        cout << "\t\tEnter negative value to show history"<<endl;
        cout << "How many Customer arrived : " ;
        cin >> enter ;

        if(enter<0)
        {
            show_history() ;
            continue;
        }

        counter = counter+ enter ;

        if(counter==0)
            break;
        int x = 0 ;
        while(1)
        {
              if(x==enter)
                break;
            cust_arrive();
                x++ ;
        }


        serve() ;
        if(c==1)
            cout << "1st Customer leaved";
        if(c==2)
            cout << "2nd Customer leaved" ;
        if(c==3)
            cout << "3rd Customer leaved" ;
        if(c>3)
            cout << c<<"th Customer leaved"  ;
        cout << " at " << endtime <<endl<<endl  ;
        c++ ;
        counter-- ;
        cout << counter << " Customer is in the line" <<endl ;
        cout << endl <<endl;

    }
    show_history() ;



    return 0 ;
}


void cust_arrive()
{
    simu_ptr n = new node ;
    n->next = NULL ;

    cout << "name : " ;
    cin >> n->name ;
    cout << "arriving time : " ;
    cin >> n->a_time ;

    int m = n->a_time;
    while(stime >m)
    {
        cout << "invalid time enter again : " ;
        cin >> n->a_time ;
         m = n->a_time;
    }

    if(stime<m)
        stime=m;

    if(rear==NULL )
    {

       front = n ;
       rear = n ;

    }
    else
    {
        rear->next = n ;
        rear = n ;
    }

}


void input()
{

    /*
    do
    {

        cout << "starting time : " ;
        cin >> n->s_time ;
    }
    while(n->a_time > n->s_time)


    cout << "processing time : " ;
    cin >> n->p_time ;*/
}
void serve()
{
    temp = front ;
    temp->s_time = stime ;                  // initiate work
    temp->c_time = temp->s_time + work_time() ;     // calculatitng finishing time

    endtime =temp->c_time;
    if(stime<temp->c_time)                 // for next work time sotre
        stime=temp->c_time;

    cust_leave() ;

}
int work_time()
{
    srand(time(0));
    return (rand() % ((rand() %20)+1))+1 ;  // random work time
}

void cust_leave()
{
    if(front ->next!=NULL)
        front = front ->next ;
    else
    {
        front = NULL ;
        rear = NULL ;
    }

    //temp->next = NULL ;
    add_history();


}

void add_history()
{


    if (top == NULL)
    {
        temp -> next = NULL ;
        top = temp ;

    }

    else
    {
        temp -> next = top ;
        top = temp ;

    }

}




void show_history()
{
    simu_ptr print;
    print = top ;

    cout << "\t\t\thistory" <<  endl ;
    while (print != NULL)
    {
        cout <<"name :"<< print->name <<endl;
        cout <<"arriving time :"<< print->a_time <<endl;
        cout <<"starting time :"<< print->s_time <<endl;
        cout <<"ending time :"<< print->c_time <<endl;
        cout << "______________" << endl ;
        print = print->next  ;
    }
}



