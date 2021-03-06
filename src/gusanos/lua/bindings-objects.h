#ifndef LUA_BINDINGS_OBJECTS_H
#define LUA_BINDINGS_OBJECTS_H

#include "../luaapi/types.h"

class LuaContext;

namespace LuaBindings
{
	void initObjects(LuaContext& ctx);
}

void initBaseObjMetaTable(LuaContext& context, int indexClosureNum);

#endif //LUA_BINDINGS_OBJECTS_H
