#include "vector.h"


void vec3::sub(double x1, double y1, double z1, double x2, double y2, double z2, Vector &buf)
{
    buf.x = x1 + x2;
    buf.y = y1 + y2;
    buf.z = z1 + z2;
};

void vec3::mult(double x, double y, double z, double n, Vector &buf)
{
    buf.x = x * n;
    buf.y = y * n;
    buf.z = z * n;
};

void vec3::normalize(double x, double y, double z, Vector &buf)
{
    double len = length(x, y, z);
    buf.x = x / len;
    buf.y = y / len;
    buf.z = z / len;
};

double vec3::length(double x, double y, double z)
{
    return sqrt(x*x + y*y + z*z);
};

double vec3::dot(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return x1*x2 + y1*y2 + z1*z2;
};


