// testexplicit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <Windows.h>

using namespace  std;

int main(int argc, char *argv[])
{
    
    if(argc < 2){
        cout << "Argument error." << endl;
        exit(1);
    }
    
    float a = 3.7, b = 2.9;
    char *libname = nullptr;

    for(int i = 0; i < argc; ++i){
        printf("argv[%d]: %s\n", i, argv[i]);
        if(i == 1)
            libname = argv[1]; 
        if(i == 2)
            a = atof(argv[2]);
        if(i == 3)
            b = atof(argv[3]);
    }

    //open the lib
    HMODULE hMod = LoadLibraryA(libname);
    if(hMod == NULL){
        cout << "Load " << libname << " failed." << endl;
       exit(1);
	}else{
		cout << "Load " << libname << " successfully." << endl;
	}
    //get function pointer
    typedef float (*pf_t)(float, float);
    pf_t add = (pf_t)GetProcAddress(hMod, "add");
    pf_t sub = (pf_t)GetProcAddress(hMod, "sub");
    pf_t mul = (pf_t)GetProcAddress(hMod, "mul");
	
    if(!(add && sub && mul)){
        cout << "Can't find symbol function." << endl;
		FreeLibrary(hMod);
        exit(1);
	}else{
		cout << "Find this symbol function." << endl; 
	}
    //call library function
    cout << "a + b = " << add(a, b) << endl;
    cout << "a - b = " << sub(a, b) << endl;
    cout << "a * b = " << mul(a, b) << endl;
    //close the lib
    if(!FreeLibrary(hMod)){
        cout << "Close " << libname << " failed." << endl;
        exit(1);
    }

    return 0;
}

