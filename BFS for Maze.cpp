////202219410 BFS for Maze
//#include <queue>
//#include <iostream>
//#include "Location2d.h"
//using std::queue;
//char** map;
//
//bool isvalidloc(int r, int c, int n, int m) {
//	if (r < 0 || c < 0 || r >= n || c >= m) return false;
//	else return map[r][c] == '0' || map[r][c] == 'T'; // 
//}
//
//char** alloc2DInt(int rows, int cols) {
//	if (rows <= 0 || cols <= 0) return NULL;
//
//	char** mat = new char* [rows];
//
//	for (int i = 0; i < rows; i++) {
//		mat[i] = new char[cols];
//	}
//
//	return mat;
//}
//
//void free2DInt(char** mat, int rows = 0, int cols = 0) {
//	if (mat != NULL) {
//		for (int i = 0; i < rows; i++)
//			delete[] mat[i];
//		delete[] mat;
//	}
//}
//
//int main() {
//	int dist[50][50];
//	int n, m;
//	std::cin >> n >> m;
//	map = alloc2DInt(n, m); // 미로 설치
//	char temp;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			std::cin >> temp;
//			map[i][j] = temp;
//		}
//	}
//	queue<Location2D> locqueue; // 위치 큐 객체 생성
//	int entryrow = 0;
//	int entrycol = 0;
//	int flag = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			if (map[i][j] == 'S') {
//				entryrow = i;
//				entrycol = j;
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 1) break;
//	}
//	Location2D entry(entryrow, entrycol);
//	locqueue.push(entry);
//
//	dist[entryrow][entrycol] = 1; // 시작 위치의 거리는 1으로 설정
//
//	while (locqueue.empty() == false) {
//		Location2D here = locqueue.front();
//		locqueue.pop();
//		int r = here.row;
//		int c = here.col;
//		if (map[r][c] == 'T') {
//			std::cout << dist[r][c];
//			free2DInt(map, n, m);
//			return 0;
//		}
//		else {
//			map[r][c] = '.'; // 지나옴 처리
//			if (isvalidloc(r - 1, c, n, m)) // 상
//			{
//				locqueue.push(Location2D(r - 1, c));
//				dist[r - 1][c]=dist[r][c]+1;
//			}
//			if (isvalidloc(r + 1, c, n, m)) // 하
//			{
//				locqueue.push(Location2D(r + 1, c)); 
//				dist[r + 1][c] = dist[r][c] + 1;
//			}
//
//			if (isvalidloc(r, c - 1, n, m)) // 좌
//			{
//				locqueue.push(Location2D(r, c - 1));
//				dist[r][c-1] = dist[r][c] + 1;
//			}
//			if (isvalidloc(r, c + 1, n, m)) // 우
//			{
//				locqueue.push(Location2D(r, c + 1));
//				dist[r][c+1] = dist[r][c] + 1;
//			}
//		}
//	std::cout << 0 << std::endl;
//	free2DInt(map, n, m);
//}
//
