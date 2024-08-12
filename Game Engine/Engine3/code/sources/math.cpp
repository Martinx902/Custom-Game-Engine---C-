// Martin Pérez Villabrille
//Copyrigth 2023+ (c) 

#include "..\headers\math.hpp"
#include "..\headers\Point.hpp"

namespace Mgine
{
    template<>
    float distance(const Point3& point_A, const Point3& point_B)
    {
        float delta_X = point_B.coordinates[0] - point_A.coordinates[0];
        float delta_Y = point_B.coordinates[1] - point_A.coordinates[1];
        float delta_Z = point_B.coordinates[2] - point_A.coordinates[2];

        //Raiz cuadrada de la suma de cuadrados
        return sqrtf(delta_X * delta_X + delta_Y * delta_Y + delta_Z * delta_Z);
    }
}