//202219410 미팅주선프로그램 신철언
#include <iostream>
#include "CircularDeque.h"

int main() {
	int n; // 미팅소에 들어올 총 인원 수
	int time; // 시간대
	string name; // 이름
	char sex; // 성별
	char location; // 위치
	int count = 0; // 매칭 성사시
	CircularDeque Male;
	CircularDeque Female;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> time >> name >> sex >> location;

		if (sex == 'm') {
			if (location == 'R') Male.addRear(name);
			else Male.addFront(name);
		}
		else {
			if (location == 'R') Female.addRear(name);
			else Female.addFront(name);
		}
	}
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (Male.getFront() != "") {
			if (Female.getFront() != "") count++;
			else {
				if (Female.getRear() != "") count++;
			}
		}
		else if (Male.getRear() != "") {
			if (Female.getFront() != "") count++;
			else {
				if (Female.getRear() != "") count++;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		std::cout << "Matched : ";
		if (Male.isEmpty() || Female.isEmpty()) {
			if (Male.getFront() != "") {
				if (Female.getFront() != "") std::cout << Male.getFront() << " " << Female.getFront();
				else std::cout << Male.getFront() << " " << Female.getRear();
			}
			else  {
				if (Female.getFront() != "") std::cout << Male.getRear() << " " << Female.getFront();
				else std::cout << Male.getRear() << " " << Female.getRear();
			}
		}
		std::cout << std::endl;
	}
	std::cout << count << " ";
	Male.display();
	Female.display();
	return 0;
}