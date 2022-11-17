extern "C"{
    // Add the header files required to run your main 

    /*
     * Tilføjer, så der kan testes
     */
    #include "linked_list.h"
    #include "list_queue.h"
    #include "insertion_sort.h"
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{

    queue q;
    /*
     * Variabler 
     */

    int x = 4;
    int x0 = 10;
    int x1 = 15;
    int y;
    int y0;
    int y1;

    /*
     * Kører tests
     */

    /* Første test, initqueue */
    printf("\nTEST A:\n");
    init_queue(&q);
    if(empty(&q) == 1)
    {
        printf("TEST A SUCCESFULD!\n");
    }
    else
    {
        printf("TEST A FEJL!\n");
        abort();
    }

    /* Anden test, enqueue/dequeue */
    printf("\nTEST B:\n");
    enqueue(&q, x);
    y = dequeue(&q);
    if(x == y && empty(&q) == 1)
    {
        printf("TEST B SUCCESFULD!\n");
    }
    else
    {
        printf("TEST A FEJL!\n");
        abort();
    }

    /* Trejde test, enqueue/dequeue x 2 */
    enqueue(&q, x0);
    enqueue(&q, x1);
    y0 = dequeue(&q);
    y1 = dequeue(&q);

    if(x0 == y0 && x1 == y1 && empty(&q))
    {
        printf("TEST C SUCCESFULD!\n");
    }
    else
    {
        printf("TEST C FEJL!\n");
        abort();
    }

    return 0;
}