#define _XOPEN_SOURCE 600
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 3

pthread_barrier_t barreira;

void* contar(void* arg) {
    char* nome = (char*)arg;

    printf("%s pronta\n", nome);

    pthread_barrier_wait(&barreira);

    for (int i = 0; i < 100; i++) {
        printf("%s: %d\n", nome, i);
    }

    printf("\n%s TERMINOU A CONTAGEM\n\n", nome);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    pthread_barrier_init(&barreira, NULL, NUM_THREADS);

    pthread_create(&t1, NULL, contar, "THREAD_A");
    pthread_create(&t2, NULL, contar, "THREAD_B");
    pthread_create(&t3, NULL, contar, "THREAD_C");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
 
    pthread_barrier_destroy(&barreira);

    return 0;
}