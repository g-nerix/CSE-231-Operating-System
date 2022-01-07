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
 
int state[5];
int philospher[5] = { 0, 1, 2, 3, 4 };
int bowls[4] = {0, 1, 2, 3};
 
sem_t lock;                                 // declaring Semaphore
sem_t semArr[5];                            // declaring array of semaphore
 
void check_1(int philosopher_id)            // Checking for fork{
    if (state[philosopher_id] == 1 && state[LEFT]!=0 && state[RIGHT] !=0) {
        state[philosopher_id] = 0;
        usleep(1000);
        printf("Philosopher %d has fork %d and %d\n",philosopher_id + 1, RIGHT+ 1, philosopher_id + 1);
        printf("Philosopher %d is Eating from bowl %d\n", philosopher_id + 1, philosopher_id+1);
        sem_post(&semArr[philosopher_id]);
    }
}
void check_2(int philosopher_id){            // checking for bowl
    if (state[philosopher_id] == 1 && state[LEFT]!=0 && state[RIGHT] !=0) {
        state[philosopher_id] = 0;
        usleep(1000);
        printf("Philosopher %d has bowl %d \n",philosopher_id + 1, LEFT + 1, philosopher_id + 1);
        printf("Philosopher %d is Eating \n", philosopher_id + 1);
        sem_post(&semArr[philosopher_id]);
    }
}

void take_fork(int philosopher_id){
    sem_wait(&lock);
    state[philosopher_id] = 1;
    printf("Philosopher %d is Hungry\n", philosopher_id + 1);
    check_1(philosopher_id);
    sem_post(&lock);
    sem_wait(&semArr[philosopher_id]);
    usleep(1000);
}
 

void put_fork(int philosopher_id){
    sem_wait(&lock);
    state[philosopher_id] = 2;
    printf("Philosopher %d put down fork %d and %d \n",philosopher_id + 1, LEFT + 1, philosopher_id + 1);
    printf("Philosopher %d is thinking\n", philosopher_id + 1);
    check_1(LEFT);
    check_1(RIGHT); 
    sem_post(&lock);
}
void take_bowl(int philosopher_id){
    sem_wait(&lock);
    state[philosopher_id] = 1;
    printf("Philosopher %d is Hungry\n", philosopher_id + 1);
    check_2(philosopher_id);
    sem_post(&lock);
    sem_wait(&semArr[philosopher_id]);
    usleep(1000);
}
void put_bowl(int philosopher_id){
    sem_wait(&lock);
    state[philosopher_id] = 2;
    printf("Philosopher %d put down bowl %d \n",philosopher_id + 1, LEFT + 1, philosopher_id + 1);
    printf("Philosopher %d is thinking\n", philosopher_id + 1);
    check_2(LEFT);
    check_2(RIGHT);
    sem_post(&lock);
}
 
void* philosopher(void* num){           // Infinite loop cointainting the method to be followed
    while (true) {
        int* i = num;
        take_fork(*i);
        put_fork(*i);
    }
}

void* bowl(void *num){                  // Infinite loop cointainting the method to be followed
     while (true) {
        int* i = num;
        usleep(1000);
        take_bowl(*i);
        put_bowl(*i);
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
        pthread_create(&threadForki], NULL,philosopher, &philospher[i]);
        printf("Philosopher %d is thinking\n", i + 1);
        
        if(i<4)
        {
            pthread_create(&threadBowl[i], NULL,bowl, &bowls[i]);
            printf("Philosopher %d has bowl\n", i + 1);
        }
    }

 
    for (int i = 0; i < 5; i++){
        pthread_join(threadForki], NULL);
        if(i<4)
        {
          pthread_join(threadBowl[i], NULL);
        }
    }
 }