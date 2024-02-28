1. Only 2 characters are printed

2. Since the semaphore was only initialized to 2, after the first 2 `sem_wait()` calls, the semaphore is decremented twice. Because of this, once it is the last thread's turn to go, it is stuck because the semaphore is 0 and therefore locked.

3. ```c
	if(sem_init(&semaphore,1,2)!=0){
		perror("Error creating semaphore");
		exit(EXIT_FAILURE);
	}
	sem_post(&semaphore); // FIX for code issue
```
Here, I added a `sem_post()` method call to increment the semaphore and make it so that its value is set to 3 before creating any of the threads, so that the problem of the semaphore reaching 0 before all of the threads have executed no longer exists.
