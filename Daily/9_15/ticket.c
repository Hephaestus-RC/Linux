#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>


int ticket = 100;
pthread_mutex_t lock;

void* route(void* arg)
{
	char* id = (char*)arg;
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(ticket > 0)
		{
			usleep(100000);
			printf("%s get a ticket,Surplus:%d\n",id,ticket--);
		}
		else
		{
			pthread_mutex_unlock(&lock);
			break;
		}
		pthread_mutex_unlock(&lock);
	}

}

int main()
{
	pthread_mutex_init(&lock,NULL);
	pthread_t t1,t2,t3,t4;
	pthread_create(&t1,NULL,route,"thread 1");
	pthread_create(&t2,NULL,route,"thread 2");
	pthread_create(&t3,NULL,route,"thread 3");
	pthread_create(&t4,NULL,route,"thread 4");

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	
	pthread_mutex_destroy(&lock);

}
