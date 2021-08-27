#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t mutex,rw;
int data = 0,rcount = 0;
void *writer(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&rw);
  data++;
  printf("Writer %d: modified count to %d\n",f,data);
  sleep(1);
  sem_post(&rw);
}
void *reader(void *arg)
{
  int f;
  f = ((int)arg);
  sem_wait(&mutex);
  rcount++;
  if(rcount==1)
   sem_wait(&rw);
  sem_post(&mutex);
  printf("Reader %d: read count as %d\n",f,data);
  sleep(1);
  sem_wait(&mutex);
  rcount--;
  if(rcount==0)
   sem_post(&rw);
  sem_post(&mutex);
}
int main()
{
  printf("19BCE0488 MANSI RATURI\n"); 
  int i,b; 
  pthread_t read[5],write[5];
  sem_init(&mutex,0,1);
  sem_init(&rw,0,1);
  for(i=0;i<=4;i++)
  {
    pthread_create(&write[i],NULL,writer,(void *)i);
    pthread_create(&read[i],NULL,reader,(void *)i);
  }
  for(i=0;i<=3;i++)
  {
    pthread_join(write[i],NULL);
    pthread_join(read[i],NULL);
  }
  return 0;
}