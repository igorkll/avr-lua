/*
** $Id: liolib.c,v 2.151.1.1 2017/04/19 17:29:57 roberto Exp $
** Standard I/O (and system) library
** See Copyright Notice in lua.h
*/

#define liolib_c
#define LUA_LIB

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

LUAMOD_API int luaopen_io (lua_State *L) {
  return 1;
}

