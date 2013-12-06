#ifndef __TAPIS_H
#define __TAPIS_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Thread tapis
pthread_t th_tapis;

/************************
 Etat du tapis :
	0 : Arret
	1 : Marche
	2 : Finis
*************************/
int etat_tapis = 0;

/**
 * Initialize the conveyor belt
 */
void tapis_init();

/**
 * Add and remove objects from the conveyor belt
 */
void* life();

/**
 * Stop the conveyor belt
 */
void tapis_stop();

/**
 * Start the conveyor belt
 */
void tapis_start();

/**
 * Finish the thread
 */
void tapis_finish();

#endif
