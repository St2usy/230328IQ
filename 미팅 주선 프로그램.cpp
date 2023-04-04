//202219410 �����ּ����α׷� ��ö��
#include <iostream>
#include "CircularDeque.h"

int main() {
	int n; // ���üҿ� ���� �� �ο� ��
	int time; // �ð���
	string name; // �̸�
	char sex; // ����
	char location; // ��ġ
	int count = 0; // ��Ī �����
	CircularDeque Male;
	CircularDeque Female;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> time >> name >> sex >> location;

		if (sex == 'm') {
			if (location == 'R') Male.enqueue(name);
			else Male.addFront(name);
		}
		else {
			if (location == 'R') Female.enqueue(name);
			else Female.addFront(name);
		}
		if (!Male.isEmpty() && !Female.isEmpty()) //���� ���� �ѽ��� �̷� ��� 
		{
			std::cout << "Ŀ���� ź���߽��ϴ�! " << Male.deleteFront() << "�� " << Female.deleteFront() << std::endl;
			count++;
		}
	}

	std::cout << count << " " << Male.numcount() - count << " " << Female.numcount();
}