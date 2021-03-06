/******************************************************************************/
/* Important Fall 2014 CSCI 402 usage information:                            */
/*                                                                            */
/* This fils is part of CSCI 402 kernel programming assignments at USC.       */
/* Please understand that you are NOT permitted to distribute or publically   */
/*         display a copy of this file (or ANY PART of it) for any reason.    */
/* If anyone (including your prospective employer) asks you to post the code, */
/*         you must inform them that you do NOT have permissions to do so.    */
/* You are also NOT permitted to remove or alter this comment block.          */
/******************************************************************************/

#include "globals.h"
#include "errno.h"

#include "util/debug.h"

#include "proc/kthread.h"
#include "proc/kmutex.h"

/*
 * IMPORTANT: Mutexes can _NEVER_ be locked or unlocked from an
 * interrupt context. Mutexes are _ONLY_ lock or unlocked from a
 * thread context.
 */

void
kmutex_init(kmutex_t *mtx)
{
        /*NOT_YET_IMPLEMENTED("PROCS: kmutex_init");*/
	sched_queue_init(&mtx->km_waitq);
	mtx->km_holder=NULL;
}

/*
 * This should block the current thread (by sleeping on the mutex's
 * wait queue) if the mutex is already taken.
 *
 * No thread should ever try to lock a mutex it already has locked.
 */
void
kmutex_lock(kmutex_t *mtx)
{
        /*NOT_YET_IMPLEMENTED("PROCS: kmutex_lock");*/
	KASSERT(curthr && (curthr != mtx->km_holder));
	dbg(DBG_PRINT,"GRADING1A 5.a\n");
	if(mtx->km_holder==NULL)
	{
		dbg(DBG_PRINT,"GRADING1E 18\n");
		mtx->km_holder=curthr;
	}
	else
	{
		dbg(DBG_PRINT,"GRADING1E 19\n");
		sched_sleep_on(&mtx->km_waitq);
	}
}

/*
 * This should do the same as kmutex_lock, but use a cancellable sleep
 * instead.
 */
int
kmutex_lock_cancellable(kmutex_t *mtx)
{
        /*NOT_YET_IMPLEMENTED("PROCS: kmutex_lock_cancellable");*/
	KASSERT(curthr && (curthr != mtx->km_holder));
	dbg(DBG_PRINT,"GRADING1A 5.b\n");
	if(mtx->km_holder==NULL)
	{
		dbg(DBG_PRINT,"GRADING1E 20\n");
		mtx->km_holder=curthr;
        return 0;
	}
	else
	{
		dbg(DBG_PRINT,"GRADING1E 21\n");
		return sched_cancellable_sleep_on(&mtx->km_waitq);
	}
}

/*
 * If there are any threads waiting to take a lock on the mutex, one
 * should be woken up and given the lock.
 *
 * Note: This should _NOT_ be a blocking operation!
 *
 * Note: Don't forget to add the new owner of the mutex back to the
 * run queue.
 *
 * Note: Make sure that the thread on the head of the mutex's wait
 * queue becomes the new owner of the mutex.
 *
 * @param mtx the mutex to unlock
 */
void
kmutex_unlock(kmutex_t *mtx)
{
        /*NOT_YET_IMPLEMENTED("PROCS: kmutex_unlock");*/
	KASSERT(curthr && (curthr == mtx->km_holder));
	dbg(DBG_PRINT,"GRADING1A 5.c-1\n");
	kthread_t *new_thr=sched_wakeup_on(&mtx->km_waitq);
	mtx->km_holder=new_thr;
	KASSERT(curthr != mtx->km_holder);
	dbg(DBG_PRINT,"GRADING1A 5.c-2\n");
	
}
