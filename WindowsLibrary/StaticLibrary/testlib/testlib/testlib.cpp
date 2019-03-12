// testlib.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "mylib.h"
#include <cstdlib>
#include <iostream>
#pragma comment(lib, "staticlib.lib")

using namespace  std;

int main(int argc, char *argv[])
{
    float a = 3.7, b = 2.9;

    for(int i = 0; i < argc; ++i){
        printf("argv[%d]: %s\n", i, argv[i]);
        if(i == 1)
            a = atof(argv[1]);
        if(i == 2)
            b = atof(argv[2]);
    }

    cout << "a + b = " << add(a, b) << endl;
    cout << "a - b = " << sub(a, b) << endl;
    cout << "a * b = " << mul(a, b) << endl;

    return 0;
}

