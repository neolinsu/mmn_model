/////////////////////////////////////////////
//Basic Math Func Lib
/////////////////////////////////////////////
#ifndef _MATH_LIB_HPP_
#define _MATH_LIB_HPP_

namespace mmn_model {
    class Math_lib {
        public:
            Math_lib();
            bool setBasicRandomFunc(float (*random_func)());
            float getRandom();
        
        private:
            float (*_random_func)();

    };
}

#endif // _END_MATH_LIB_HPP_