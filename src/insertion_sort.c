#include "insertion_sort.h"
#include "linked_list.h"

void sort(linked_list *llPtr)
{
 // Add your sort function here

   /* 
    * Starten af hver ny 'peger-på' er prev 
    * vores 'tidligere' node, så vi sætter
    * llPtr->head i starten.
    */

    node_t* currentNode = llPtr->head->next;
    node_t* prev = llPtr->head;
    node_t* temp;

    /*
     * Laver et while-loop, der kører
     * igennem listen, indtil vores
     * 'current'-node er lig med NULL
     */
    
    while(currentNode != NULL)
    {
       /*
        * Laver et If-statement; 
        * Hvis current node
        * er mindre in den tidligere, skal 
        * den sorteres.
        */
       
       if(currentNode->data < prev->data)
       {
        /*
         * Nested if-statement for at tjekke
         * om de for første elementer skal
         * bytte plads.
         */

            if(prev == llPtr->head)
            {
            /*
             * Bytter om på det første 
             * og andet element.
             */
            
            prev->next = currentNode->next;
            currentNode->next = prev;
            llPtr->head = currentNode;
            }
            else
            {
                temp = llPtr->head;

                if(currentNode->data < temp->data)
                {
                    prev->next = currentNode->next;
                    currentNode->next = temp;
                    llPtr->head = currentNode;
                }
                else
                {
                    while(temp->next->data <= currentNode->data)
                    {
                        temp = temp->next;
                    }
                }

                /*
                 * Når while-loopet har kørt ved vi at temp->data
                 * < CurrentNode->Data < temp->next->next
                 */

                if (temp->next->next == currentNode)
                {
                    temp->next->next == currentNode->next;

                    /*
                     * CurrentNode skal pege mod prev
                     */

                    currentNode->next = temp->next;

                    /*
                     * Vores temp skal pege mode CurrentNode
                     */

                    temp->next = currentNode;
                }
                /*
                 * Hvis vores if-betingelse ikke er opfyldt
                 * betyder det, at vores CurrentNode->next == NULL
                 */
                else 
                {
                    /*
                     * Prev skal pege mod CurrentNode->, som er NULL
                     */
                    prev->next = currentNode->next;

                    /*
                     * CurrentNode skal pege mod temp->next
                     */

                    currentNode->next = temp->next;

                    /*
                     * temp skal pege mode currentNode
                     */
                    temp->next = currentNode;
                }
            }
       }
       prev = currentNode;
       currentNode = currentNode->next;
    }
    return;
}
