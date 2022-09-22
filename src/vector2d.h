#ifndef __VECTOR2D_H__
#define __VECTOR2D_H__

#include <math.h>

class Vector2D
{
public:
  Vector2D(float x, float y) :
    m_x(x), m_y(y) {}

  float getX() { return m_x; }
  float getY() { return m_y; }

  void setX(float x) { m_x = x; }
  void setY(float y) { m_y = y; }

  // operations
  float length();
  Vector2D operator+(const Vector2D& v2) const;
  friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2);
  Vector2D operator*(float scalar);
  Vector2D& operator*=(float scalar);
  Vector2D operator-(const Vector2D& v2) const;
  friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2);
  Vector2D operator/(float scalar);
  Vector2D& operator/=(float scalar);
  void normalize();
  

private:
  float m_x;
  float m_y;
};

#endif // __VECTOR2D_H__
