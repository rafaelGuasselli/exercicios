#include<bits/stdc++.h>

using namespace std;
#include <random>
#define EPS 1e-9

struct Point {
    double x, y;
    Point () {
        x = 0; y = 0;
    }
    Point (double x1, double y1) {
        x = x1;
        y = y1;
    }
};

struct Circle {
    Point center;
    double radius;
    Circle () {
        center = {0, 0};
        radius = 0;
    }
    Circle (Point a, double r) {
        center = a;
        radius = r;
    }
};

Point get_circle_center(double bx, double by,
                        double cx, double cy)
{
    double B = bx * bx + by * by;
    double C = cx * cx + cy * cy;
    double D = bx * cy - by * cx;
    return { (cy * B - by * C) / (2 * D),
             (bx * C - cx * B) / (2 * D) };
}

double distanceBetween(const Point &a, const Point &b) {
    return pow(a.x-b.x, 2) + pow(a.y-b.y, 2);
}

int isInsideCircle(const Circle &c, const Point &p) {
    double dist = distanceBetween(c.center, p);
    return (dist - c.radius) <= EPS;
}

int validCircle(const Circle &c, const vector<Point> &points) {
    for (const Point &point: points) {
        if (!isInsideCircle(c, point)) {
            return 0;
        }
    }

    return 1;
}

Point centroidFrom(vector<Point> points) {
    double x = 0;
    double y = 0;
    double n = points.size();

    for (Point &point: points) {
        x += point.x;
        y += point.y;
    } 

    return {x/n, y/n};
}

Point centerFrom3Points(Point a, Point b, Point c) {
    Point point;
    Point director = get_circle_center(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
    point.x = a.x + director.x;
    point.y = a.y + director.y;
    return point; 
}

Circle buildCircle(vector<Point> points) {
    if (points.size() == 0) {
        return {};
    } else if (points.size() == 1) {
        return {points[0], 0};  
    } else if (points.size() == 2) {
        return {centroidFrom(points), distanceBetween(points[0], points[1])/4};
    } else if (points.size() == 3){
        for (int i = 0; i < 3; i++) {
            for (int j = i+1; j < 3; j++) {
                Circle circle = buildCircle({points[i], points[j]});
                if (validCircle(circle, points)) {
                    return circle;
                }
            }
        }

        Point c = centerFrom3Points(points[0], points[1], points[2]);
        return {c, distanceBetween(points[0], c)};
    } else {
        return {};
    }
}

Circle minCircle(vector<Point> &points, vector<Point> border, int n){
    if (n < 0 || border.size() == 3) {
        return buildCircle(border);
    }

    Circle c = minCircle(points, border, n-1);
    if (isInsideCircle(c, points[n])) {
        return c; 
    }

    border.push_back(points[n]);
    return minCircle(points, border, n-1);
}

int n; 
int main() {
    int instancia = 1;
    while(scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }

        vector<Point> points;
        for (int i = 0; i < n; i++) {
            double x, y; scanf("%lf %lf", &x, &y);
            points.push_back({x, y});
        }

        shuffle(points.begin(), points.end(), default_random_engine{});
        Circle c = minCircle(points, {}, points.size()-1);

        printf("Instancia %d\n", instancia++);
        printf("%.2lf %.2lf %.2lf\n", c.center.x, c.center.y, sqrt(c.radius));
        printf("\n");
    }
    return 0;
}