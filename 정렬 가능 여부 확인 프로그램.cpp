//202219410 정렬 가능 여부 확인 프로그램
#include <iostream>
const int MAX_QUEUE_SIZE = 100;
#include <string>
using std::string;

//오류 처리 함수
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
#define MAX_STACK_SIZE 100

//오류 처리 함수
inline void error1(const char* message) {
	std::cout << message << std::endl;
	exit(1);
}

class ArrayStack {
private:
	int top;
	int data[MAX_STACK_SIZE] = { 0 };
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
	int pop() { // 수식 변환 할때 char형으로 바꾼다.
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
			return data[top - 1];
		}
	}
	void display() {
		std::cout << "스택 갯수는 : " << top + 1 << std::endl;
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

int Target;
bool Switch;
int next_Target() {
	if (Switch == true) // 오름차순
		return Target++;
	else // 내림차순
		return Target--;
}
int main() {
	CircularQueue inputQueue;
	CircularQueue outputQueue;
	ArrayStack stack;
	int temparray[20]; // 임시 배열
	int n; // 원소의 갯수
	char approach; // 오름차순, 내림차순 구분
	int num;
	int empty = 0;
	std::cin >> n >> approach;
	if (approach == 'a') {
		Target = 1;
		Switch = true;
	}
	else {
		Target = n;
		Switch = false;
	}
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		inputQueue.enqueue(num);
	}
	while (empty != -1) {
		while (1) {
			empty = stack.peek();

			if (empty == -1)
				break;

			stack.pop();

			if (empty == Target) {
				outputQueue.enqueue(next_Target());
			}
			else {
				stack.push(empty);
				break;
			}
		}
		empty = inputQueue.dequeue();
		if (empty == Target) {
			outputQueue.enqueue(next_Target());
		}
		else {
			stack.push(empty);
		}
	}

	if (Target == 0 && Switch == false)
		std::cout << "Yes";
	else if (Switch = true && Target == n + 1)
		std::cout << "Yes";
	else
		std::cout << "No";
	return 0;
}