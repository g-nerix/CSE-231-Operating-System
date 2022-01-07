#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define NUM 5								// Number of Philosopher
#define NUMBOWL 4                           // Number of Bowls

#define EATING 0							// Enumerated Eating
#define HUNGRY 1							// Enumerated Hungry
#define THINKING 2							// Enumerated Thinking

#define LEFT (philosopher_id + NUM-1) % NUM // Assuming it is a circular Array
#define RIGHT (philosopher_id + 1 ) % NUM   // Assuming it is a circular Array
 
int state[NUM];
int philosopher_list[NUM] = { 0, 1, 2, 3, 4 };
int bowls[NUMBOWL] = {0, 1, 2, 3};
int bowlnum = 0;

sem_t lock;                                 // declaring Semaphore
sem_t semArr[5];                            // declaring array of semaphore
 
void check(int philosopher_id){
    if (state[philosopher_id] == HUNGRY && state[LEFT]!= EATING && state[RIGHT] != EATING) {
        state[philosopher_id] = EATING;
        usleep(1000);
        bowlnum = philosopher_id+1;
        printf("Philosopher %d took fork %d\n", LEFT + 1, philosopher_id + 1);
        printf("Philosopher %d took bowl %d \n",philosopher_id + 1, LEFT + 1, bowlnum);
        printf("Philosopher %d is Eating from bowl %d\n", philosopher_id + 1);
        sem_post(&semArr[philosopher_id]);
    }
}

void pickupFork(int philosopher_id){
    sem_wait(&lock);
    printf("Philosopher %d is Hungry\n", philosopher_id + 1);
    state[philosopher_id] = HUNGRY;
    check(philosopher_id);
    sem_post(&lock);
    sem_wait(&semArr[philosopher_id]);
    usleep(1000);
}

void leaveFork(int philosopher_id){
    sem_wait(&lock);
    check(LEFT);
    check(RIGHT);
    state[philosopher_id] = THINKING;
    printf("Philosopher %d put down fork\n",philosopher_id + 1, LEFT + 1, philosopher_id + 1);
    printf("Philosopher %d is thinking\n", philosopher_id + 1);
    sem_post(&lock);
}

void pickupBowl(int philosopher_id){
    sem_wait(&lock);
    printf("Philosopher %d has bowl\n", philosopher_id + 1);
    check(philosopher_id);
    sem_post(&lock);
    sem_wait(&semArr[philosopher_id]);
    state[philosopher_id] = HUNGRY;
    usleep(1000);
}
void leaveBowl(int philosopher_id){
    sem_wait(&lock);
    printf("Philosopher %d put down bowl %d\n",philosopher_id + 1, LEFT + 1, philosopher_id + 1);
    printf("Philosopher %d is thinking\n", philosopher_id + 1);
    check(LEFT);
    check(RIGHT);
    state[philosopher_id] = THINKING;
    sem_post(&lock);
}
 
void* philosopher(void* num){
    while (true) {                          // Infinite loop cointainting the method to be followed
        int* i = num;
        pickupFork(*i);
        leaveFork(*i);
    }
}
void* bowl(void *num){
     while (true) {                         // Infinite loop cointainting the method to be followed
        int* i = num;
        usleep(1000);
        pickupBowl(*i);
        leaveBowl(*i);
    }
}
 
int main(){
    pthread_t threadFork[5];                // Declaring an Array of thread for each Fork
    pthread_t threadBowl[4];                // Declaring an Array of thread for each Bowl

    sem_init(&lock, 0, 1);                  // Initialising semaphore with 1
 
    for (int i = 0; i < 5; i++){
        sem_init(&semArr[i], 0, 0);         // Initialising semaphore with 0
    }
        
    for (int i = 0; i < 5; i++) {       
        pthread_create(&threadFork[i], NULL,philosopher, &philosopher_list[i]);
        printf("Philosopher %d is thinking\n", i + 1);
    }

    for (int i = 0; i < 4; i++) {           // For Bowl
        pthread_create(&threadBowl[i], NULL,bowl, &bowls[i]);
        printf("Philosopher %d has bowl\n", i + 1);
        pthread_join(threadFork[i], NULL);
    }
 
    for (int i = 0; i < 5; i++){            // For Fork
        pthread_join(threadFork[i], NULL);
    }
}