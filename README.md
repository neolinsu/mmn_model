# How to run?

## basic

```
mkdir build
cd build
cmake ..
make
./mmn_model
```

## change parameter

Change parameter in mmn_model.cpp.

```c++
static float param_avg_arrive_time = 5;
static float param_avg_serve_time = 3;
static int param_client_num = 20;
static int max_length = 15;
```

