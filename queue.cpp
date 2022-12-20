#include "queue.h"

/*Note that the exit statements in these functions are here for simplicity. The queue in this project should never actually use them. I added it so that if the exit
statement(s) was ever executed, it would be obvious that something is wrong with the code for this queue.*/

//Pre-condition: The object's class must be defined
//Post-condition: The object's variables are initialized 
queue::queue() {
    front = 0;
    rear = SIZE - 1;
    count = 0;
    //intitialize the array to -1 to signify empty
    for (int i = 0; i < SIZE; i++) {
        arr[i] =  -1;
    }
}

//Pre-conditon: The function must recieve an integer that is an index in the queue (index of the array)
//Post-condition: The index is incremented by reference (no return needed), and if it reaches the end of the queue, it is set to 0 (circular array)
void queue::advance(int &index) {
    index++; //increment the index. At the start of the program, this will make rear be equal to size, then it will be set to 0 below
    if (index == SIZE) {
        index = 0; //if front or rear reaches the end of the array, set it to 0
    }
}

//Pre-condition: The function must recieve an integer that is the value to be added to the queue
//Post-condition: Rear is incremented and the value is added to the rear of the queue
void queue::enqueue(int value) {
    //if the queue is full
    if(count == SIZE) {
        std::cerr << "Queue is full" << std::endl;
        std::exit(1);
    }
    
    else {
        advance(rear); //increment rear
        arr[rear] = value; //add the value to the rear of the queue
        count++; //increment the count 
    }
}

//Pre-condition: Nothing, but the queue must not be empty or the function will throw an exit statement
//Post-condition: Front of the queue is set to -1 to signify empty and then front is incremented
void queue::dequeue() {
    //if the queue is empty
    if(isEmpty()) {
        std::cerr << "Queue is empty" << std::endl;
        std::exit(1);
    }

    else {
        arr[front] = -1; //set the front of the queue to -1 to signify that it is empty
        advance(front); //increment front to remove the first element in the queue
        count--; //decrement the count
    }
}

//Pre-condition: Nothing, except the assumption that the class is defined
//Post-condition: The function returns true if the queue is empty, false otherwise
bool queue::isEmpty() {
    if (count == 0) { //if the count is 0, the queue is empty
        return true;
    }

    else {
        return false;
    }
}

//Pre-condition: Nothing, but the queue must not be empty or the function will throw an exit statement
//Post-condition: The function returns, not deletes, the value at the front of the queue
int queue::frontOfQueue() {
    if(isEmpty()) { //if the queue is empty
        std::cerr << "Queue is empty" << std::endl;
        std::exit(1);
    }
    return arr[front]; //return the front of the queue
}

//Pre-condition: Nothing, but the queue must not be empty
//Post-condition: The queue is printed to the screen
void queue::printQueue() {
    if(isEmpty()) { //if the queue is empty
        std::cout << "Queue is empty" << std::endl;
    }

    else {
        std::cout << "The queue is: " << std::endl;
        for (int i = 0; i < SIZE; i++) { //iterate through the queue and print the elements
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}
