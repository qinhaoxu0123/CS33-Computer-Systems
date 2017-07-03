#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

struct thread_info{
  int g;
  int l;
  int n;

};

void *thread(void *vargp);
int main( int argc, char* argv[])
{
  if (argc!=2)
    {
      fprintf(stderr, "You must pass two argvs");
      return 1; 
    }

  long input = atoll(argv[1]);
  struct thread_info *p = malloc(sizeof (struct thread_info));
  p->g = input;
  p->n = 0;
  p->l = 1;
  thread ((void*)p);
  return 0;
}

void *thread(void *vargp)
{
  struct thread_info *p  = malloc (sizeof (struct thread_info));
  p = (struct thread_info*)vargp;
      
  if(p->l > p->g)
    {
      return NULL;
    }

  struct thread_info *tmp1 = malloc(sizeof ( struct  thread_info));
  tmp1->l = p->l+1;
  tmp1->n = p->n*2 +1;
  tmp1->g = p->g;
  struct thread_info *tmp2 = malloc(sizeof ( struct  thread_info));
  tmp2->l = p->l+1;
  tmp2->n = p->n*2 +2;
  tmp2->g = p->g;
    // creating threads
  pthread_t left;
  pthread_t right;
  pthread_create ( &left, NULL , thread, (void*)tmp1);
  pthread_create ( &right,  NULL, thread,(void*)tmp2);
  pthread_join (left , NULL);
  pthread_join (right,  NULL);
  printf("Thread %d done\n", p->n);
      
}
