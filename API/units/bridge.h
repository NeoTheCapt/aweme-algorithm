#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int test(char* lib_path){
    void *dl = dlopen(lib_path,RTLD_LAZY); //打开动态库
    if (dl == NULL)
        fprintf(stderr,"Error:failed to load libary.\n");
    char *error = dlerror(); //检测错误
    if (error != NULL)
    {
        fprintf(stderr,"%s\n",error);
        //return -1;
    }
    int (*func)(int x, int y) = dlsym(dl,"test_sum"); // 获取函数地址
    error = dlerror(); //检测错误
    if (error != NULL)
    {
        fprintf(stderr,"%s\n",error);
        //return -1;
    }
    int rst = func(1, 2);
    dlclose(dl); //关闭动态库
    error = dlerror(); //检测错误
    if (error != NULL)
    {
        fprintf(stderr,"%s\n",error);
        //return -1;
    }
    return rst;
}

char* encode(char* lib_path, char* plain, int plainlength, char* key, int keylength){
    void *dl = dlopen(lib_path,RTLD_LAZY); //打开动态库
    if (dl == NULL)
        fprintf(stderr,"Error:failed to load libary.\n");
    char *error = dlerror(); //检测错误
    if (error != NULL)
    {
        fprintf(stderr,"%s\n",error);
        //return -1;
    }
    char* (*func)(char* plain, int plainlength, char* key, int keylength) = dlsym(dl,"Encode"); // 获取函数地址
    error = dlerror(); //检测错误
    if (error != NULL)
    {
        fprintf(stderr,"%s\n",error);
        //return -1;
    }
    char* rst = func(plain, plainlength, key, keylength);
    dlclose(dl); //关闭动态库
    error = dlerror(); //检测错误
    if (error != NULL)
    {
        fprintf(stderr,"%s\n",error);
        //return -1;
    }
    return rst;
}