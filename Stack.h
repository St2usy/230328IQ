#pragma once
#pragma once
#define MAX_STACK_SIZE 20
#include <iostream>

// ���� ó�� �Լ�
inline void error1(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class ArrayStack {
private:
	int top;
	int data[MAX_STACK_SIZE]={0};
public:
	ArrayStack()
		: top(-1) {}
	~ArrayStack() {}
	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}
	bool isFuLL() {
		if (top == MAX_STACK_SIZE - 1) return true;
		else return false;
	}
	void push(int n) {
		if (isFuLL()) { error1("Error : Stack is FULL!!"); }
		else {
			top += 1;
			data[top] = n;
		}
	}
	int pop() { // ���� ��ȯ �Ҷ� char������ �ٲ۴�.
		if (isEmpty()) { return -1; }
		else {
			int popdata = data[top];
			top -= 1;
			return popdata;
		}
	}
	int peek() {
		if (isEmpty()) { return -1; }
		else {
			return data[top];
		}
	}
	int peeknext() {
		if (isEmpty()) { error1("Error :: Stack is Empty !!"); }
		else {
			return data[top-1];
		}
	}
	void display() {
		std::cout << "���� ������ : " << top + 1 << std::endl;
		std::cout << "---------------Stack---------------" << std::endl;
		for (int i = 0; i <= top; i++) {
			std::cout << data[i] << std::endl;
		}
	}
	int min() {
		int min = NULL;
		for (int i = 0; i < MAX_STACK_SIZE; i++) {
			min = data[0];
			if (min > data[i]) {
				min = data[i];
			}
		}
		return min;
	}
};
