#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread functions
void* calculator(void* arg)
{
    int sum = 0;
    for(int i = 1; i <= 5; i++)
        sum += i;

    printf("Calculator Thread | Sum = %d | TID: %lu | PID: %d\n",
           sum, pthread_self(), getpid());
    return NULL;
}

void* printer(void* arg)
{
    for(int i = 1; i <= 3; i++)
    {
        printf("Printer Thread | Printing %d | TID: %lu | PID: %d\n",
               i, pthread_self(), getpid());
        sleep(1);
    }
    return NULL;
}

void* sleeper(void* arg)
{
    printf("Sleeper Thread | Sleeping... | TID: %lu | PID: %d\n",
           pthread_self(), getpid());
    sleep(3);
    printf("Sleeper Thread | Woke up | TID: %lu | PID: %d\n",
           pthread_self(), getpid());
    return NULL;
}

int main()
{
    int choice;
    pthread_t t1, t2, t3;

    while(1)
    {
        printf("\n===== THREAD MANAGER =====\n");
        printf("1. Calculator Thread\n");
        printf("2. Printer Thread\n");
        printf("3. Sleeper Thread\n");
        printf("4. Run All Threads\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                pthread_create(&t1, NULL, calculator, NULL);
                pthread_join(t1, NULL);
                break;

            case 2:
                pthread_create(&t2, NULL, printer, NULL);
                pthread_join(t2, NULL);
                break;

            case 3:
                pthread_create(&t3, NULL, sleeper, NULL);
                pthread_join(t3, NULL);
                break;

            case 4:
                pthread_create(&t1, NULL, calculator, NULL);
                pthread_create(&t2, NULL, printer, NULL);
                pthread_create(&t3, NULL, sleeper, NULL);

                pthread_join(t1, NULL);
                pthread_join(t2, NULL);
                pthread_join(t3, NULL);
                break;

            case 5:
                printf("Exiting Thread Manager\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
