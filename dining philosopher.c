#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_cond_t philosophers[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int philosopher_id = *(int *)arg;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking.\n", philosopher_id);
        sleep(rand() % 3);

        
        printf("Philosopher %d is hungry.\n", philosopher_id);

        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);

       
        printf("Philosopher %d is eating.\n", philosopher_id);
        state[philosopher_id] = 1;


       
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);

        
        state[philosopher_id] = 0;

        
        pthread_cond_signal(&philosophers[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
        pthread_cond_signal(&philosophers[(philosopher_id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS]);
    }
}

int main() {
    int i;
    int philosopher_ids[NUM_PHILOSOPHERS];
    pthread_t philosophers_threads[NUM_PHILOSOPHERS];

   
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        pthread_cond_init(&philosophers[i], NULL);
        state[i] = 0;
    }

    
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers_threads[i], NULL, philosopher, &philosopher_ids[i]);
    }

    
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers_threads[i], NULL);
    }

    
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
        pthread_cond_destroy(&philosophers[i]);
    }

    return 0;
}