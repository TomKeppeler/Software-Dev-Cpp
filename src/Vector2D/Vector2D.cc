#include <iostream>
#include "Vector2D.hh"
namespace linalg
{
  std::ostream& operator<<(std::ostream& os,
                           Vector2D const& v)
  {
    os << "(" << v.x() << "," << v.y() << ")";
    return os;
  }
  std::istream& operator>>(std::istream& is, Vector2D& v)
  {
    char c;
    is >> c; // '(';
    is >> v.x_;
    is >> c; // ',';
    is >> v.y_;
    is >> c; // ')';
    return is;
  }

  Vector2D &operator+(Vector2D &v1, Vector2D::Coord const &v2)
  {
    v1.setX(v1.x()+v2);
    v1.setY(v1.y()+v2);
    return v1;
  }

  Vector2D &operator+(Vector2D &v1, Vector2D const &v2)
  {
    v1.setX(v1.x()+v2.x());
    v1.setY(v1.y()+v2.y());
    return v1;
  }

  Vector2D &operator-(Vector2D &v1, Vector2D::Coord const &v2)
  {
    v1.setX(v1.x()-v2);
    v1.setY(v1.y()-v2);
    return v1;
  }

  Vector2D &operator-(Vector2D &v1, Vector2D const &v2)
  {
    v1.setX(v1.x()-v2.x());
    v1.setY(v1.y()-v2.x());
    return v1;
  }

  Vector2D &operator*(Vector2D &v1, Vector2D::Coord const &v2)
  {
    v1.setX(v1.x()*v2);
    v1.setY(v1.y()*v2);
    return v1;
  }

  Vector2D &operator*(Vector2D &v1, Vector2D const &v2)
  {
    v1.setX(v1.x()*v2.x());
    v1.setY(v1.y()*v2.y());
    return v1;
  }

  Vector2D &operator/(Vector2D &v1, Vector2D::Coord const &v2)
  {
    v1.setX(v1.x()/v2);
    v1.setX(v1.x()/v2);
    return v1;
  }

  Vector2D &operator/(Vector2D &v1, Vector2D const &v2)
  {
    v1.setX(v1.x()/v2.x());
    v1.setY(v1.y()/v2.y());
    return v1;
  }
}

