/*
 * Optimizing Vector runtime
 */

#include <iostream>
#include <vector>
#include <chrono>


class Point{
public:
	static int cnt;
	int _x, _y;
	Point(int x, int y)
	{
		_x = 0;
		_y = 0;
	}

	Point(const Point& pt)
		:_x(pt._x), _y(pt._y)
	{
		cnt++;
		std::cout << "copied! (" << cnt << ")\n";
	}
};

int Point::cnt = 0;

int main(int argc, char **argv) {
	std::vector<Point> vec;
	auto start = std::chrono::high_resolution_clock::now();
	vec.reserve(3);
	vec.emplace_back(1, 2);
	vec.emplace_back(4, 5);
	vec.emplace_back(7, 8);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	std::cout << "exec-time: " << duration.count() << std::endl;

	start = std::chrono::high_resolution_clock::now();
	vec.push_back(Point(1, 2));
	vec.push_back(Point(4, 5));
	vec.push_back(Point(7, 8));
	stop = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	std::cout << "exec-time: " << duration.count() << std::endl;

	return 0;
}
