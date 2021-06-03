/*

Given N cartesian points in a 2D plane, count the number of right-angled triangles that
can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

Example 1

Input : {(0, 0), (2, 0), (0, 1)}
Output: 1

Input : {(1, 2), (2, 0), (2, 2), (2, 3), (4, 2)}
Output: 4

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	vector<Point> points{Point(1, 2), 
						 Point(2, 0), 
						 Point(2, 2), 
						 Point(2, 3), 
						 Point(4, 2)};

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	for(Point p : points) {
		xFreqMap[p.x]++;
		yFreqMap[p.y]++;
	}

	int count = 0;
	for(Point p : points) {
		// let p be the vertex at which the right angle is formed
		int n = xFreqMap[p.x]; // #points with same x as p incl. p
		int m = yFreqMap[p.y]; // #points with same y as p incl. p
		count += (n-1) * (m-1);
	}

	cout << count << endl;

	return 0;
}