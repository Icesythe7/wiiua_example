#include "wiiua_wrapper.hpp"

namespace wiiua_wrapper {

	void open_engine(sol::this_state L) {
		lua = std::make_unique<sol::state_view>(L);

		lua->new_enum<WIIUSE_WIIMOTE_TYPE>("WIIMOTE_TYPE", {
			{"REGULAR", WIIUSE_WIIMOTE_REGULAR},
			{"MOTION_PLUS_INSIDE", WIIUSE_WIIMOTE_MOTION_PLUS_INSIDE}
		});

		lua->new_usertype<wiimote_t>(
			sol::no_constructor,
			"btns", &wiimote_t::btns,
			"btns_held", &wiimote_t::btns_held,
			"btns_released", &wiimote_t::btns_released
		);

		lua->new_usertype<Wiiua>("wiiua",
			sol::constructors<Wiiua()>(),
			"someFunc", &Wiiua::someFunc
		);
	}

} // namespace wiiua_wrapper

extern "C" int luaopen_wiiua(lua_State * L) {
	sol::stack::call_lua(L, 1, wiiua_wrapper::open_engine);
	return 0;
}