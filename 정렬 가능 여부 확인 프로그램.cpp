//202219410 ���� ���� ���� Ȯ�� ���α׷�
#include <iostream>
#include "CircularQueue.h"
#include "Stack.h"
int main() {
	CircularQueue inputQueue;
	CircularQueue outputQueue;
	ArrayStack stack;
	int n; // ������ ����
	char approach; // ��������, �������� ����
	int num;
	std::cin >> n >> approach;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		inputQueue.enqueue(num);
	}
	while (!inputQueue.isEmpty() || !stack.isEmpty()) {
	}
	return 0;
}