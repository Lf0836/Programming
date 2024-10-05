#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long double FPS = 1e-8;

struct pt {
  long double x, y;
  pt() {}
  pt(long double x, long double y) : x(x), y(y) {}
  pt(pt a, pt b) : x(b.x - a.x), y(b.y - a.y) {}
  long double operator*(pt a) const {
    return ((long double)(1) * x * a.y) - ((long double)(1) * y * a.x);
  }
  pt operator+(pt a) const { return pt(a.x + x, a.y + y); }
  pt operator*(long double d) const { return pt(d * x, d * y); }
  pt operator/(long double d) const { return pt(x / d, y / d); }
  long double operator^(pt a) const {
    return ((long double)(1) * x * a.x) + ((long double)(1) * y * a.y);
  }
  bool operator==(pt a) const { return (a.x == x && a.y == y); }
  long double len() { return sqrt(x * x + y * y); }
};
struct line {
  long double a, b, c;
  line() {}
  line(long double a1, long double b1, long double c1) : a(a1), b(b1), c(c1) {}
  line(long double k, long double b) : a(k), b(-1), c(b) {}
  line(pt a1, pt a2) : a(a2.y - a1.y), b(a1.x - a2.x), c(-((a * a1.x) + (b * a1.y))) {}
};
struct circle {
  pt o;
  long double r;
  circle() {}
  circle(pt o, long double r) : o(o), r(r) {}
};
istream& operator>>(istream& in, pt& a) {
  long double x, y;
  in >> x >> y;
  a.x = x;
  a.y = y;
  return in;
}
istream& operator>>(istream& in, circle& a) {
  pt x;
  long double y;
  in >> x >> y;
  a.o = x;
  a.r = y;
  return in;
}
istream& operator>>(istream& in, line& l1) {
  long double a, b, c;
  in >> a >> b >> c;
  l1 = line(a, b, c);
  return in;
}
ostream& operator<<(ostream& out, pt& a) {
  out << a.x << ' ' << a.y;
  return out;
}
ostream& operator<<(ostream& out, line& a) {
  out << a.a << ' ' << a.b << ' ' << a.c;
  return out;
}
long double dis(pt a, line l1) {
  return abs(l1.a * a.x + l1.b * a.y + l1.c) / sqrt(l1.a * l1.a + l1.b * l1.b);
}
pt proj(pt a, line l1) {
  long double dist = dis(a, l1);
  pt ab = pt(l1.a, l1.b);
  pt project1 = ab / ab.len() * dist;
  pt ab1 = pt(-l1.a, -l1.b);
  pt project2 = ab1 / ab1.len() * dist;
  pt project;
  if (abs(l1.a * (project1.x + a.x) + l1.b * (project1.y + a.y) + l1.c) <=
      FPS) {
    project = project1;
  } else {
    project = project2;
  }
  project = project + a;
  return project;
}
pt xc(line l1, long double d, pt a) {
  pt ab = pt(-l1.b, l1.a);
  pt col = ab / ab.len() * d;
  col = col + a;
  return col;
}
int main() {
  circle a;
  line l1;
  cin >> a >> l1;
  if (dis(a.o, l1) > a.r) {
    cout << 0 << endl;
  } else if (abs(dis(a.o, l1) - a.r) < FPS) {
    pt ans = proj(a.o, l1);
    cout << 1 << endl << fixed << setprecision(10) << ans << endl;
  } else {
    long double d = sqrt(a.r * a.r - dis(a.o, l1) * dis(a.o, l1));
    pt res1 = xc(l1, d, proj(a.o, l1));
    pt res2 = xc(l1, -d, proj(a.o, l1));
    xc(l1, d, proj(a.o, l1));
    cout << 2 << endl
         << fixed << setprecision(10) << res2 << endl
         << res1 << endl;
  }
  return 0;
}
