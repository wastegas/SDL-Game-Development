#include "vector2d.h"

// Length
float Vector2D::length()
{
  return sqrt(m_x * m_x + m_y * m_y);
}

// Addition of 2 vectors
Vector2D Vector2D::operator+(const Vector2D& v2) const
{
  return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
}

Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
{
  v1.m_x += v2.m_x;
  v1.m_y += v2.m_y;

  return v1;
}

// Scalar multiplication
Vector2D Vector2D::operator*(float scalar)
{
  return Vector2D(m_x * scalar, m_y * scalar);
}

Vector2D& Vector2D::operator*=(float scalar)
{
  m_x *= scalar;
  m_y *= scalar;

  return *this;
}

// subtraction of two vectors
Vector2D Vector2D::operator-(const Vector2D& v2) const
{
  return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
}

Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)
{
  v1.m_x -= v2.m_x;
  v1.m_y -= v2.m_y;

  return v1;
}

// division by a salar
Vector2D Vector2D::operator/(float scalar)
{
  return Vector2D(m_x / scalar, m_y / scalar);
}

Vector2D& Vector2D::operator/=(float scalar)
{
  m_x /= scalar;
  m_y /= scalar;

  return *this;
}

// normalizing a vector
void Vector2D::normalize()
{
  float l = length();
  if (l > 0) // prevent div by zero
    {
      (*this) *= 1 / l;
    }
}
   
  
