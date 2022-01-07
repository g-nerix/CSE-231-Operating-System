#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define NUM 5								// Number of Philosopher

#define EATING 0							// Enumerated Eating
#define HUNGRY 1							// Enumerated Hungry
#define THINKING 2							// Enumerated Thinking

#define LEFT (philosopher_id + NUM-1) % NUM	// Assuming it is a circular Array
#define RIGHT (philosopher_id + 1 ) % NUM	// Assuming it is a circular Array

int state[NUM];
int philosopher_list[NUM] = { 0, 1, 2, 3, 4 };

sem_t lock;									// declaring Semaphore
sem_t semArr[NUM];							// declaring array of semaphore

void check(int philosopher_id){
	if (state[philosopher_id] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		state[philosopher_id] = EATING;
		usleep(1000);
		printf("Philosopher %d has fork %d and %d\n", philosopher_id + 1, LEFT + 1, philosopher_id + 1);
		printf("Philosopher %d is Eating\n", philosopher_id + 1);
		sem_post(&semArr[philosopher_id]);
	}
}

void leaveFork(int philosopher_id){
	sem_wait(&lock);
	state[philosopher_id] = THINKING;
	printf("Philosopher %d put down fork %d and %d \n", philosopher_id + 1, LEFT + 1, philosopher_id + 1);
	printf("Philosopher %d is thinking\n", philosopher_id + 1);

	check(LEFT);
	check(RIGHT);

	sem_post(&lock);
}

void pickupFork(int philosopher_id){
	sem_wait(&lock);
	state[philosopher_id] = HUNGRY;
	printf("Philosopher %d is Hungry\n", philosopher_id + 1);
	check(philosopher_id);
	sem_post(&lock);
	sem_wait(&semArr[philosopher_id]);
	usleep(1000);
}

void* philosopher(void* id){
	while (true) {							// Infinite loop cointainting the method to be followed
		int* i = id;
		sleep(1);
		pickupFork(*i);
		leaveFork(*i);
	}
}

int main(){
	
	pthread_t thread_id[NUM];				// Declaring an Array of thread for each Philosopher

	sem_init(&lock, 0, 1);

	for (int i = 0; i < NUM; i++){
		sem_init(&semArr[i], 0, 0);			// Initialising semaphore with 0
	}

	for (int i = 0; i < NUM; i++) {				// Dividing task into multiple philosopher threads
		pthread_create(&thread_id[i], NULL, philosopher, &philosopher_list[i]);
		printf("Philosopher %d is thinking\n", i + 1);
	}

	for (int i = 0; i < NUM; i++){
        pthread_join(thread_id[i], NULL);
    }
}
