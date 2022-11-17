#include "list_queue.h"
#include <stdio.h>
#include <assert.h>


void init_queue(queue *q)
{
  // Add your init_queue

  /*
   * Skaber en queue 
   * og størrelse lig 0
   */

  q->front = NULL;
  q->rear = NULL;
  q->size = 0;

}

int empty(queue *q)
{
  // Add your empty function  

  /*
   * If-statement for at se om
   * queuen er tom. Er den 
   * Større end 0, returnerer
   * vi fejl
   */

  if (q->size == 0)
    return 1;
  else
    return 0;
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function

  /*
   * Lavler malloc for at skabe 
   * plads til en ny node 
   */

  qnode *new = (qnode *)malloc(sizeof(qnode));
  new->data = x;
  new->next = NULL;

  /*
   * Hvis q-noden er tom, så er *new 
   * forrest og bagerst. Hvis den
   * ikke er tom, så skal den
   * pege mod *new.
   */

  if(empty(q) == 1)
  {
    q->front = new;
  }
  else
  {
    q->rear->next = new;
  }

  q->rear = new;
  q->size = q->size + 1;

}

int dequeue(queue *q)
{
  // Add your dequeue function

  /*
   * Tjekker om q er tom. 
   * Assert, hvis den er det
   */

  assert(empty(q) == 0);

  /*
   * Gem dataen i temp
   */
  
  int temp = q->front->data;

  /*
   * Før vi opdaterer fronten, gemmer vi i formerfront
   */

  qnode *forFront = q->front;

  /*
   * Opdater front til næste element i queuen
   */

  q->front = q->front->next;
  free(forFront);

  /*
   * Opdater størrelsen
   * og retuner temp 
   */
  
  q->size = q->size - 1;

  return temp;
}
