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


## result
```
 static float param_avg_arrive_time = 5;
 static float param_avg_serve_time = 6;
 static int param_client_num = 1000;
 static int max_length = 1000;

average number of customers in queue: 83.1768
average delay in the queue: 227.61
utilisation of server: 0.999167

----------

 static float param_avg_arrive_time = 4;
 static float param_avg_serve_time = 6;
 static int param_client_num = 1000;
 static int max_length = 1000;

average number of customers in queue: 166.389
average delay in the queue: 1844.73
utilisation of server: 0.999334

----------

 static float param_avg_arrive_time = 4;
 static float param_avg_serve_time = 6;
 static int param_client_num = 1000;
 static int max_length = 1000;

average number of customers in queue: 249.626
average delay in the queue: 130.067
utilisation of server: 0.9995

```
