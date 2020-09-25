#ifdef _EXPORTING
   #define _DECLSPEC __declspec(dllexport)
#else
   #define _DECLSPEC __declspec(dllimport)
#endif

_DECLSPEC int f();
