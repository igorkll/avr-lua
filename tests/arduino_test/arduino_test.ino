extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}

void setup() {
  Serial.begin(9600);

  Serial.println(F("try start lua"));
  lua_State* lua = luaL_newstate();
  luaL_openlibs(lua);
  if (luaL_dostring(lua, "print('test')") != LUA_OK) {
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
