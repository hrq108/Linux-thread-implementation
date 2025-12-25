# Linux Implementation of Threads

This project demonstrates the implementation of threads in Linux using C and POSIX threads (pthread).

## Project Overview
The program acts as a thread manager, allowing the user to create and execute different types of threads through a menu-driven interface. Each thread performs a distinct task to showcase concurrent execution and synchronization using pthread_join().

## Features
- Creation of multiple threads
- Shared process ID across threads
- Display of thread IDs
- Synchronised execution and completion

## Key Concepts Demonstrated
- Thread creation using pthread_create()
- Thread synchronization using pthread_join()
- Shared Process ID (PID) across all threads
- Unique Thread IDs (TID) for each thread
- Concurrent execution within a single process
- Use of sleep() to visualize thread scheduling

## File Structure
Linux-thread-implementation/
│
├── threads.c
├── README.md

## Technologies Used
- C programming language
- POSIX Threads (pthread)
- Linux / Ubuntu

## How to Run
gcc threads.c -o threads -lpthread
./threads
