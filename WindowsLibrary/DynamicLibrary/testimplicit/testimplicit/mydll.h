#pragma once
#ifdef DYNAMIC_H_
#define DLL_EXPORT_IMPORT extern "C" __declspec(dllexport)
#else
#define DLL_EXPORT_IMPORT extern "C" __declspec(dllimport)
#endif

DLL_EXPORT_IMPORT float add(float a, float b);
DLL_EXPORT_IMPORT float sub(float a, float b);
DLL_EXPORT_IMPORT float mul(float a, float b);