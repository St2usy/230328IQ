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
			if (location == 'R') Male.enqueue(name);
			else Male.addFront(name);
		}
		else {
			if (location == 'R') Female.enqueue(name);
			else Female.addFront(name);
		}
		if (!Male.isEmpty() && !Female.isEmpty()) //여자 남자 한쌍을 이룰 경우 
		{
			std::cout << "커플이 탄생했습니다! " << Male.deleteFront() << "와 " << Female.deleteFront() << std::endl;
			count++;
		}
	}

	std::cout << count << " " << Male.numcount() - count << " " << Female.numcount();
}