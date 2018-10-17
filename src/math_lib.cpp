#include "include/math_lib.hpp"

using namespace mmn_model;

Math_lib::Math_lib(){}

bool Math_lib::setBasicRandomFunc(float (*random_func)() )
{
    _random_func = random_func;
    return true;
}

float Math_lib::getRandom() {
    return _random_func();
}