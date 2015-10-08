

#ifdef WIN32
    #include <windows.h>
    #include <map>

    typedef DWORD ThreadID;
    std::map<dword , HANDLE > g_handlemap;
#else
    #include <pthread.h>
    #include <unistd.h>

    typedef pthread_t ThreadID;
#endif
