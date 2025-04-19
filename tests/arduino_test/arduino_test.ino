extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}

static int _uartout(lua_State* lua) {
  Serial.println(luaL_checkstring(lua, 0));
  return 0;
} 

void setup() {
  Serial.begin(9600);

  Serial.println(F("try start lua"));
  lua_State* lua = luaL_newstate();
  lua_pushcfunction(lua, _uartout);
  lua_setglobal(lua, "uartout");
  if (luaL_dostring(lua, "uartout('hello, avr-lua!')") != LUA_OK) {
    const char* err = lua_tostring(lua, -1);
    Serial.print(F("lua crashed: "));
    Serial.println(err);
  } else {
    Serial.println(F("lua end"));
  }
  lua_close(lua);
}

void loop() {
  
}
