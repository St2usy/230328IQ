#pragma once
const int MAX_QUEUE_SIZE = 10;
#include <iostream>
#include <string>
using std::string;

// 오류 처리 함수
inline void error(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class CircularDeque {
protected:
	int rear;
	int front;
	string data[MAX_QUEUE_SIZE];
	int count = 0;
public:
	CircularDeque()
		: rear(MAX_QUEUE_SIZE - 1), front(0) {}
	~CircularDeque() {}
	bool isEmpty() {
		if (front == 0 && rear == MAX_QUEUE_SIZE - 1) return true;
		else return false;
	}
	bool rearEmpty() {
		if (rear == MAX_QUEUE_SIZE - 1) return true;
		else return false;
	}
	bool frontEmpty() {
		if (front == 0) return true;
		else return false;
	}
	bool isFuLL() {
		if (front == rear) return true;
		else return false;
	}
	void addfront(string n) {
		if (isFuLL()) { error("Error :: Queue is Full !!"); }
		else {
			data[front] = n;
			front += 1;
		}
	}
	void enqueue(string n) {
		if (isFuLL()) { error("Error :: Queue is Full !!"); }
		else {
			data[rear] = n;
			rear -= 1;
		}
	}
	string deleterear() {
		if (rearEmpty()) { error("Error :: Queue is Empty !!"); }
		else {
			string popdata = data[rear];
			rear += 1;
			return popdata;
		}
	}
	string dequeue() {
		if (frontEmpty()) { error("Error :: Queue is Empty !!"); }
		else {
			string popdata = data[front];
			front -= 1;
			return popdata;
		}
	}
	string getfront() {
		if (isEmpty()) { return ""; }
		else {
			return data[front];
		}
	}
	string getrear() {
		if (isEmpty()) { return ""; }
		else {
			return data[rear];
		}
	}
	string getindex(int n) {
		return data[n];
	}
	int Dequecount() {
		int count = 0;
		for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
			if (data[i] != "") count++;
		}
		return count;
	}
};