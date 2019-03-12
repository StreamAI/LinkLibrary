// dynamic.cpp : 定义 DLL 应用程序的导出函数。
//
#define DYNAMIC_H_
#include "stdafx.h"
#include "mydll.h"

float add(float a, float b)
{
    return a + b;
}

float sub(float a, float b)
{
    return a - b;
}

float mul(float a, float b)
{
    return a * b;
}

