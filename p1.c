#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
//#include<time.h>

pthread_t t1,t2,t3,t4,t5;
pthread_mutex_t l1,l2;
int x;
int pcnt=0;
int teach=0;
int stud=0;
int staff=0;
int h;
int tme;

void *teacher()
{   
	pthread_mutex_lock(&l1);
	teach++;
	printf("TEACHER %d IS PLAYING\n",teach);
	pcnt++;

	pthread_mutex_unlock(&l1);
	pthread_exit(NULL);
}
void *stff()
{
	pthread_mutex_lock(&l2);
	staff++;
	pcnt++;
	printf("STAFF %d is PLAYING\n",staff);
	pthread_mutex_unlock(&l2);
		pthread_exit(NULL);
}
void *student()
{
	pthread_mutex_lock(&l1);
	pcnt++;
	stud++;
	printf("\nSTUDENT %d is PLAYING\n",stud);
	pthread_mutex_unlock(&l1);
	
    	pthread_exit(NULL);
}
void *login()
{
	
printf("\n1.Staff\n2. Student\n3. Teacher\n4. Exit\n\nEnter Your category for login :: ");
scanf("%d",&x);

//int pswd;
	if(1<=x<=3){
	if (x == 1 ) {
		printf("Computer center Staff Login \n");
		printf("Staff logged in\n");
		pthread_create(&t3,NULL,stff,NULL);
		pthread_join(t3,NULL);
		}

	 else if(x==2){

	 	if ((24>=tme && tme>=22) || (1<=tme && tme<=6))
	 	{
	 		printf("%d",tme);
			printf("\nStudent  Login \n");
			printf("\nStu logged in\n");
			pthread_create(&t4,NULL,student,NULL);
			pthread_join(t4,NULL);
	 	} 	
		else{
			printf("student cannot login in this time duration\n" );
		}}

		if (x == 3)
		{
			if((17<=tme && tme<=24) || (1<=tme && tme<=8)){

			printf(" Teacher Login \n");
			printf("Teacher logged in\n");
			pthread_create(&t5,NULL,teacher,NULL);
			pthread_join(t5,NULL);}
			else{
				printf("teacher cannot login in this time duration" );
			}
		}
	     
		}
		
		else{
			 pthread_exit(NULL);
		}
	}
	      
	
void main()
{
	printf("\nEnter how many person want to login :: \n");
	int i;
	scanf("%d",&h);
	printf("\nEnter the current time (in 24hr clock)" );
	scanf("%d",&tme);
	if(h>=0 && tme>=1 && tme<=24){
	for(i=0;i<h;i++)
	{
		pthread_create(&t1,NULL,login,NULL);
		pthread_join(t1,NULL);
		printf("TOTAL NO. OF USERS %d \n",pcnt);
	}
	}
	else{printf("\nInvalid Input!!");
         printf("\nenter once again");
          main();}

	}
