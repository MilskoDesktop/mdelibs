#ifndef __MDE_USERS_H__
#define __MDE_USERS_H__

#include <MDE/MachDep.h>

#ifdef __cplusplus
extern "C" {
#endif

void MDEListUsers(void(*call)(const char* name, void* user), void* user);

#ifdef __cplusplus
}
#endif

#endif
