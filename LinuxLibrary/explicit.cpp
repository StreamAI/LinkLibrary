#include <cstdlib>
#include <iostream>
#include <dlfcn.h>

using namespace  std;

int main(int argc, char *argv[])
{
    
    if(argc < 2){
        cout << "Argument error." << endl;
        exit(1);
    }
    
    float a = 3.7, b = 2.9;
    char *libname = nullptr;
    char *err = nullptr;

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
    void *handle = dlopen(libname, RTLD_NOW);
    if(!handle){
        cout << "Load" << libname << "failed" << dlerror() << endl;
        exit(1);
    }
    //clear error info
    dlerror();
    //get function pointer
    typedef float (*pf_t)(float, float);
    pf_t add = (pf_t)dlsym(handle, "add");
    pf_t sub = (pf_t)dlsym(handle, "sub");
    pf_t mul = (pf_t)dlsym(handle, "mul");
    err = dlerror();
    if(err){
        cout << "Can't find symbol function" << err << endl;
        exit(1);
    }
    //call library function
    cout << "a + b = " << add(a, b) << endl;
    cout << "a - b = " << sub(a, b) << endl;
    cout << "a * b = " << mul(a, b) << endl;
    //close the lib
    dlclose(handle);
    if(dlerror()){
        cout << "Close" << libname << "failed" << dlerror() << endl;
        exit(1);
    }

    return 0;
}