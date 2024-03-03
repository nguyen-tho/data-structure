#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

struct queue
{
    node *front;
    node *back;
};

queue *createQueue()
{
    queue *qu = new queue;
    qu->front = qu->back = NULL;
    return qu;
}

int isEmpty(queue *qu)
{
    return qu->back == NULL;
}

void enQueue(queue *qu, int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;

    if (!isEmpty(qu))
    {
        qu->back->next = temp;
        qu->back = temp;
    }
    else
    {
        qu->front = qu->back = temp;
    }
}

void deQueue(queue *qu)
{
    if (isEmpty(qu))
    {
        printf("The queue is empty, cannot dequeued\n");
    }
    else
    {
        node *temp = new node;
        temp = qu->front;

        int xtemp = temp->data;
        qu->front = temp->next;
        delete temp;

        if (qu->front == NULL)
        {
            qu->back = NULL;
        }
    }
}

void display(queue *qu)
{
    node *cur = qu->front;
    while (cur)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void menu1(queue *queue)
{
    int choice1, stop1 = 0;
    do
    {
        cout << "\n*****************************************************\n";
        cout << "\n\t1. enQueue";
        cout << "\n\t2. deQueue";
        cout << "\n\t3. Check the queue";
        cout << "\n\t0. Back";
        cout << "\n\n************************RESULT***********************\n\n";
        cout << "Choice: ";
        cin >> choice1;

        switch (choice1)
        {
        case 0:
            stop1 = 1;
            break;

        case 1:
        {
            int k;
            cout << "\nEnter value: ";
            cin >> k;
            enQueue(queue, k);
        }
        break;

        case 2:
        {
            deQueue(queue);
        }
        break;

        case 3:
        {
            if (isEmpty(queue))
            {
                cout << "\nEmpty queue" << endl;
            }
            else
            {
                cout << "\nQueue have items" << endl;
            }
        }
        break;
        }
    } while (stop1 == 0);
}

int main()
{
    int choice, stop = 0;
    do
    {
        cout << "\n*****************************************************\n";
        cout << "\n\t1. Create Queue";
        cout << "\n\t0. Stop";
        cout << "\n\n*****************************************************\n";
        cin >> choice;

        switch (choice)
        {
        case 0:
            stop = 1;
            break;

        case 1:
        {
            queue *queue = createQueue();
            menu1(queue);
        }
        break;
        }
    } while (stop == 0);

    cout << endl;
    return 0;
}