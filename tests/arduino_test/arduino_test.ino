extern "C" {
  #include <lua.h>
  #include <lauxlib.h>
  #include <lualib.h>
}

static int _uartout(lua_State* lua) {
  Serial.println(luaL_checkstring(lua, 1));
  return 0;
} 

void setup() {
  Serial.begin(9600);

  lua_State* lua = luaL_newstate();
  lua_pushcfunction(lua, _uartout);
  lua_setglobal(lua, "uartout");

  while (true) {
    String code = Serial.readString();
    
    Serial.println(F("lua start"));
    if (luaL_dostring(lua, code.c_str()) != LUA_OK) {
      const char* err = lua_tostring(lua, -1);
      Serial.print(F("lua crashed: "));
      Serial.println(err);
    } else {
      Serial.println(F("lua end"));
    }
  }
}

void loop() {
  
}
