// fifo.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "FQueue.h"
#include <iostream>

int main()
{

    FQueue* queue = new FQueue;
    try {
       
        queue->FQEnqueue(new FQINFO(1));
        queue->FQEnqueue(new FQINFO(2));
        queue->FQEnqueue(new FQINFO(3));
        queue->FQEnqueue(new FQINFO(4));
           //queue->PrintQueue();


        cout << '\n'<<"Kolejka po usunieciu dwoch elementow" << '\n';
        queue->FQDequeue();
        queue->FQDequeue();
       // queue->PrintQueue();

        cout << '\n' << "Kolejka po usunieciu zawartosci" << '\n';
        queue->FQClear();
        //queue->PrintQueue();
    }

    catch (FifoException error)

    {
        cerr << error.getReason() << endl;
    }

    return 0;

}

