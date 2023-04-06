//#include <iostream>
//int target;
//bool Switch;
//
//class MyQueue
//{
//private:
//	int f_pos = 0, r_pos = 0, arr[21] = { 0, };
//public:
//	void push(int val)
//	{
//		arr[r_pos++] = val;
//	}
//	void pop()
//	{
//		f_pos++;
//	}
//	int front()
//	{
//		if (f_pos == r_pos)
//			return -1;
//
//		return arr[f_pos];
//	}
//};
//
//class MyStack
//{
//private:
//	int tos = -1, st[21] = { 0, };
//public:
//	void push(int val)
//	{
//		st[++tos] = val;
//	}
//	void pop()
//	{
//		tos--;
//	}
//	int top()
//	{
//		if (tos == -1)
//			return -1;
//
//		return st[tos];
//	}
//};
//
//int next_target()
//{
//	if (Switch == true)
//		return target++;
//	else
//		return target--;
//}
//
//int main()
//{
//	MyQueue inQ, outQ;
//	MyStack St;
//	int n, val, empty = 0;
//	char Sort = NULL;
//
//	std::cin >> n >> Sort;
//	std::cin.ignore();     // char형을 입력 받았으니 버퍼를 비워줌
//	if (Sort == 'a')
//	{
//		target = 1;
//		Switch = true;
//	}
//	else
//	{
//		target = n;
//		Switch = false;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> val;
//		inQ.push(val);
//	}
//
//	while (empty != -1)
//	{
//		while (1)
//		{
//			empty = St.top(); // empty에 스택을 pop
//
//			if (empty == -1)
//				break;
//			St.pop();
//
//			if (empty == target)
//			{
//				outQ.push(next_target());
//			}
//			else
//			{
//				St.push(empty);
//				break;
//			}
//		}
//		empty = inQ.front();
//		inQ.pop();
//		if (empty == target)
//		{
//			outQ.push(next_target());
//		}
//		else
//		{
//			St.push(empty);
//		}
//	}
//
//	if (target == 0 || target == n + 1)
//		std::cout << "Yes\n";
//	else
//		std::cout << "No\n";
//	return 0;
//}