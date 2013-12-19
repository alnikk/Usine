#ifndef __TOURNIQUET_H
#define __TOURNIQUET_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include "object.h"

#define NBCASE			16
#define TIME_TOURNE	100 // ms
#define TIME_WAIT		2		// s		

object_t* tourne[NBCASE];		// Tourniquet cases
int nbObjectsIn;					// Nb objects in the tourniquet
int state_tourne;					// State of the ring : 0 -> Stop | 1 -> in work 
pthread_t th_tourne;				// Thread tourniquet
pthread_mutex_t mutex_tourne;	// Mutex tourniquet

/**
 * Initialize thread
 */
void ring_init();

/**
 * Main of the thread
 */
void* ring_main();

/**
 * Stop the ring
 */
void ring_stop();

/**
 * Rotate conveyor belt
 */
void ring_spin();

/**
 * Get objetc at position n
 */
object_t* ring_getObject(int n);

/**
 * Put objects at position n
 */
void ring_putObject(int n, object_t* obj);

#endif