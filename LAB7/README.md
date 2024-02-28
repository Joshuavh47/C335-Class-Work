1. In the multithreaded program, one thread took 1892.244 ms to read "football" from "clickstream-enwiki-2019-09.tsv", and the other took 1093.425 ms to read "username" from "enwik9". The main thread time was 2986.040 ms. In my single-threaded implementation of this program, this finished in 67426.595 ms, which is slower, but I implemented it a different way (way slower and more confusing/hard to follow than the one I implemented in the multithreaded version.)

2. In the multithreaded program, the main thread time is almost exactly equal to both of the other threads added together. (1892.244+1093.425≈2986.040)

3. While my multithreaded program being faster than the singlethreaded version could be partially due to implementation, this is mostly caused because the theads in the multithreaded program can run concurrently unlike the singlethreaded version. 

4. There are 2 possible outputs in step 4 because the threads could finish in a different order based on how the processor schedules the them. 