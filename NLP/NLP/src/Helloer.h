#pragma once
#ifdef MYDLLPROJECT_EXPORTS
#define MYDLLPROJECT_API __declspec(dllexport)
#else
#define MYDLLPROJECT_API __declspec(dllimport)
#endif

MYDLLPROJECT_API void SayHello();
