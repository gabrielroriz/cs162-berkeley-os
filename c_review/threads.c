#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_one_function(void *arg){
    printf("Starting thread A!\n");
    sleep(4);
    printf("Hello from thread A!\n");
    // pthread_exit passes the return value to pthread_join
    pthread_exit((void *) 42);
}

void *thread_two_function(void *arg){
    printf("Starting thread B!\n");
    sleep(2);
    pthread_exit((void *) 7);
    printf("Hello from thread B!\n");
}

int main(){

    pthread_t t1, t2;
    void *ret1, *ret2;

    pthread_create(&t1, NULL, thread_one_function, NULL);
    pthread_create(&t2, NULL, thread_two_function, NULL);

    pthread_join(t1, &ret1);
    pthread_join(t2, &ret2);

    printf("Thread A returned: %ld\n", (long) ret1);
    printf("Thread B returned: %ld\n", (long) ret2);

    return 0;
}
