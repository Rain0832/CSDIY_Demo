#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

#define MAX 50
// 全局变量
int number;

// thread mutex
pthread_rwlock_t rwlock;

// 线程处理函数
void* read_num(void* arg)
{
    for(int i=0; i<MAX; ++i)
    {
	pthread_rwlock_rdlock(&rwlock);
        printf("Thread read, id = %lu, number = %d\n", pthread_self(), number);
	pthread_rwlock_unlock(&rwlock);
	usleep(rand()%5);
    }

    return NULL;
}

void* write_num(void* arg)
{
    for(int i=0; i<MAX; ++i)
    {
	pthread_rwlock_wrlock(&rwlock);	
        int cur = number;
        cur++;
        number = cur;
        printf("Thread write, id = %lu, number = %d\n", pthread_self(), number);
	pthread_rwlock_unlock(&rwlock);
        usleep(5);
    }

    return NULL;
}

int main(int argc, const char* argv[])
{
    pthread_t p_read[5], p_write[3];
    pthread_rwlock_init(&rwlock, NULL);

    // 创建两个子线程
    for(int i = 0; i < 5; i++)
    {
    	pthread_create(&p_read[i], NULL, read_num, NULL);
    }

    for(int i = 0; i < 3; i++)
    {
    	pthread_create(&p_write[i], NULL, write_num, NULL);
    }

    // 阻塞，资源回收
    
    for(int i = 0; i < 3; i++)
    {
	pthread_join(p_write[i], NULL);
    }

      
    for(int i = 0; i < 5; i++)
    {
    	pthread_join(p_read[i], NULL);
    }

    pthread_rwlock_destroy(&rwlock);
    return 0;
}
