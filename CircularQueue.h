#pragma once
const int MAX_QUEUE_SIZE = 20;
#include <iostream>
#include <string>
using std::string;

// 오류 처리 함수
inline void error(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class CircularQueue {
protected:
	int rear;
	int front;
	int data[MAX_QUEUE_SIZE];
public:
	CircularQueue()
		: rear(0), front(0) {}
	~CircularQueue() {}
	bool isEmpty() {
		if (front == rear) return true;
		else return false;
	}
	bool isFuLL() {
		if ((rear + 1) % MAX_QUEUE_SIZE == front) return true;
		else return false;
	}
	void enqueue(int n) {
		if (isFuLL()) { error("Error :: Queue is Full !!"); }
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	int dequeue() {
		if (isEmpty()) { return -1; }
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek() {
		if (isEmpty()) { return -1; }
		else {
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
	int peeknext() {
		if (isEmpty()) { error("Error :: Queue is Empty !!"); }
		else {
			return data[(front + 2) % MAX_QUEUE_SIZE];
		}
	}
	void display() {
		std::cout << "큐 갯수는 : " << rear - front << std::endl;
		std::cout << "---------------Queue---------------" << std::endl;
		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
		for (int i = front + 1; i <= maxi; i++) {
			std::cout << data[i % MAX_QUEUE_SIZE] << std::endl;
		}
	}
	int min() {
		int min = data[0];
		for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
			if (data[i] < min) min = data[i];
		}
		return min;
	}
};