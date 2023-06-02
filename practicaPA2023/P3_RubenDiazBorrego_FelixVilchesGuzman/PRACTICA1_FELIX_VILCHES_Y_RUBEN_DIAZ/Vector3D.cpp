#include "Vector3D.h"


Vector3D Vector3D::Add(const Vector3D& b) 
{
    Vector3D result(X + b.X, Y + b.Y, Z + b.Z);
    return result;
}

Vector3D Vector3D::operator+(const Vector3D& b) 
{
    Vector3D result(X + b.X, Y + b.Y, Z + b.Z);
    return result;
}

Vector3D Vector3D::Substract(const Vector3D& b) 
{
    Vector3D result;
    result.X = X - b.X;
    result.Y = Y - b.Y;
    result.Z = Z - b.Z;
    return result;
}

Vector3D Vector3D::operator-(const Vector3D& b) 
{
    Vector3D result;
    result.X = X - b.X;
    result.Y = Y - b.Y;
    result.Z = Z - b.Z;
    return result;
}

Vector3D Vector3D::Product(const float& b) 
{
    Vector3D result;
    result.X = X * b;
    result.Y = Y * b;
    result.Z = Z * b;
    return result;
}

Vector3D Vector3D::operator*(const float& b)
{
    Vector3D result;
    result.X = X * b;
    result.Y = Y * b;
    result.Z = Z * b;
    return result;
}

Vector3D Vector3D::operator*(const float& b) const
{
    Vector3D result;
    result.X = X * b;
    result.Y = Y * b;
    result.Z = Z * b;
    return result;
}

Vector3D Vector3D::Division(const float& m) 
{
    Vector3D result;
    result.X = X / m;
    result.Y = Y / m;
    result.Z = Z / m;
    return result;
}
Vector3D Vector3D::operator/(const float& m) 
{
    Vector3D result;
    result.X = X / m;
    result.Y = Y / m;
    result.Z = Z / m;
    return result;
}

float Vector3D::DotProduct(const Vector3D& v) {
    float result;
    result = X * v.X + Y * v.Y + Z * v.Z;
    return result;
}

float Vector3D::operator*(const Vector3D& v) {
    float result;
    result = X * v.X + Y * v.Y + Z * v.Z;
    return result;
}