//202219410 정렬 가능 여부 확인 프로그램
#include <iostream>
#include "CircularQueue.h"
#include "Stack.h"
int main() {
	CircularQueue inputQueue;
	CircularQueue outputQueue;
	ArrayStack stack;
	int n; // 원소의 갯수
	char approach; // 오름차순, 내림차순 구분
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