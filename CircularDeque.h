#pragma once
#include "CircularQueue.h"
#include <iostream>

class CircularDeque : public CircularQueue {
public:
	CircularDeque() {}
	void addRear(string n) { enqueue(n); }
	string deleteFront() { return dequeue(); }
	string getFront() { return peek(); }
	void addFront(string n) {
		if (isFuLL()) { error("Error : Deque is Full!!"); }
		else {
			data[front] = n;
			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
		}
	}
	string deleteRear() {
		if (isEmpty()) { error("Error : Deque is Empty!!"); }
		else {
			string popdata = data[rear];
			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
			return popdata;
		}
	}
	string getRear() {
		if (isEmpty()) { error("Error : Deque is Empty!!"); }
		else return data[rear];
	}
	void display() {
		std::cout << "µ¦ÀÇ °¹¼ö´Â : ";
		if (front < rear)
			std::cout << (rear - front) % MAX_QUEUE_SIZE << std::endl;
		else
			std::cout << (rear + MAX_QUEUE_SIZE - front) % MAX_QUEUE_SIZE << std::endl;
		std::cout << "---------------Deque---------------" << std::endl;
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++) {
			std::cout << data[i % MAX_QUEUE_SIZE] << std::endl;
		}
	}
	string getindex(int i) {
		return data[i];
	}
	int numcount() {
		int count = 0;
		for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
			if (data[i] != "") {
				count++;
			}
		}
		return count;
	}
};