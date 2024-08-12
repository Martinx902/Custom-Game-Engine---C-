// Martin Pérez Villabrille
// Copyrigth 2023+ (c)

#include <Scene.hpp>

using namespace Mgine;

int main()
{

    Scene scene("../../assets/xml/xmlExample.xml");

    scene.execute();

    return (EXIT_SUCCESS);
}