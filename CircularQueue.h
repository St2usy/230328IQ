#pragma once
const int MAX_QUEUE_SIZE = 100;
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
	string data[MAX_QUEUE_SIZE];
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
	void enqueue(string n) {
		if (isFuLL()) { error("Error :: Queue is Full !!"); }
		else {
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			data[rear] = n;
		}
	}
	string dequeue() {
		if (isEmpty()) { error("Error :: Queue is Empty !!"); }
		else {
			front = (front + 1) % MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	string peek() {
		if (isEmpty()) { error("Error :: Queue is Empty !!"); }
		else {
			return data[(front + 1) % MAX_QUEUE_SIZE];
		}
	}
	void display() {
		std::cout << rear - front << " ";
	}
};