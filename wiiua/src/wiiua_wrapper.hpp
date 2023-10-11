#pragma once
#include "wiiua_api.hpp"
#include "sol.hpp"
#include "wiiuse.h"

extern "C" {
	struct lua_State;
}

inline std::unique_ptr<sol::state_view> lua;

namespace wiiua_wrapper {

	class Wiiua final {
	public:
		explicit Wiiua() {}

		~Wiiua() {
			lua.reset();
		}

		void someFunc(const std::string& text) {
			printf("%s\n", text.c_str());
		}
	};

} // namespace wiiua_wrapper

extern "C" MY_OBJECT_API int luaopen_wiiua(lua_State * L);