/*
 * create a taskpool with the given number of threads
 *
 * This function allocates and returns a thread pool with n
 * threads.
 */
struct taskpool *taskpool_make(int n);

/*
 * execute the given task
 *
 * A task is specified as a function (task parameter), which
 * takes a single argument (dat parameter).  If all threads
 * in the pool are busy, the task shall be executed when
 * one of the threads becomes idle and all previously added
 * threads are running or finished.  This function returns
 * an identifier which can be passed to taskpool_wait() function.
 */
int taskpool_task(struct taskpool *pool, void (*task)(void *), void *dat);

/*
 * wait until the given task is finished
 *
 * The id parameter is the identifier of the task to wait for.
 * If id is -1, this function waits until all tasks get finished.
 */
int taskpool_wait(struct taskpool *pool, int id);

/*
 * free the given taskpool structure
 *
 * This function waits for all running tasks (but does not
 * start outstanding tasks) and then frees the resources
 * allocated for the given taskpool.
 */
void taskpool_free(struct taskpool *pool);
