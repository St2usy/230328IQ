////202219410 �����ּ����α׷� ��ö��
//const int MAX_QUEUE_SIZE = 100;
//#include <iostream>
//#include <string>
//using std::string;
//
//// ���� ó�� �Լ�
//inline void error(const char* message) {
//	std::cout << message << std::endl;
//	exit(1);
//}
//
//class CircularQueue {
//protected:
//	int rear;
//	int front;
//	string data[MAX_QUEUE_SIZE];
//public:
//	CircularQueue()
//		: rear(0), front(0) {}
//	~CircularQueue() {}
//	bool isEmpty() {
//		if (front == rear) return true;
//		else return false;
//	}
//	bool isFuLL() {
//		if ((rear + 1) % MAX_QUEUE_SIZE == front) return true;
//		else return false;
//	}
//	void enqueue(string n) {
//		if (isFuLL()) { error("Error :: Queue is Full !!"); }
//		else {
//			rear = (rear + 1) % MAX_QUEUE_SIZE;
//			data[rear] = n;
//		}
//	}
//	string dequeue() {
//		if (isEmpty()) { error("Error :: Queue is Empty !!"); }
//		else {
//			front = (front + 1) % MAX_QUEUE_SIZE;
//			return data[front];
//		}
//	}
//	string peek() {
//		if (isEmpty()) { error("Error :: Queue is Empty !!"); }
//		else {
//			return data[(front + 1) % MAX_QUEUE_SIZE];
//		}
//	}
//	void display() {
//		std::cout << "ť ������ : " << rear - front << std::endl;
//		std::cout << "---------------Queue---------------" << std::endl;
//		int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
//		for (int i = front + 1; i <= maxi; i++) {
//			std::cout << data[i % MAX_QUEUE_SIZE] << std::endl;
//		}
//	}
//};
//
//class CircularDeque : public CircularQueue {
//public:
//	CircularDeque() {}
//	void addRear(string n) { enqueue(n); }
//	string deleteFront() { return dequeue(); }
//	string getFront() { return peek(); }
//	void addFront(string n) {
//		if (isFuLL()) { error("Error : Deque is Full!!"); }
//		else {
//			data[front] = n;
//			front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
//		}
//	}
//	string deleteRear() {
//		if (isEmpty()) { error("Error : Deque is Empty!!"); }
//		else {
//			string popdata = data[rear];
//			rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
//			return popdata;
//		}
//	}
//	string getRear() {
//		if (isEmpty()) { error("Error : Deque is Empty!!"); }
//		else return data[rear];
//	}
//	void display() {
//		if (front < rear)
//			std::cout << (rear - front) % MAX_QUEUE_SIZE;
//		else
//			std::cout << (rear + MAX_QUEUE_SIZE - front) % MAX_QUEUE_SIZE;
//	}
//};
//
//int main() {
//	int n; // ���üҿ� ���� �� �ο� ��
//	int time; // �ð���
//	string name; // �̸�
//	char sex; // ����
//	char location; // ��ġ
//	int count = 0; // ��Ī �����
//	CircularDeque Male;
//	CircularDeque Female;
//	std::cin >> n;
//	for (int i = 0; i < n; i++) {
//		std::cin >> time >> name >> sex >> location;
//
//		if (sex == 'm') {
//			if (location == 'R') Male.enqueue(name);
//			else Male.addFront(name);
//		}
//		else {
//			if (location == 'R') Female.enqueue(name);
//			else Female.addFront(name);
//		}
//		if (!Male.isEmpty() && !Female.isEmpty()) //���� ���� �ѽ��� �̷� ��� 
//		{
//			std::cout << "Matched : " << Male.deleteFront() << " " << Female.deleteFront() << std::endl;
//			count++;
//		}
//	}
//	std::cout << count << " ";
//	Male.display();
//	std::cout << " ";
//	Female.display();
//}