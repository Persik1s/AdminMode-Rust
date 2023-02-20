#pragma once
#include "MainClasses.hpp"
#include "RustFunc.hpp"

#include "Settings.hpp"
namespace Hook {
	namespace OrigHook {
		static auto input = reinterpret_cast<void (*)(r_BasePlayer*, r_InpitStaete*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(xorstr("BasePlayer"), xorstr("ClientInput"), -1, xorstr(""), xorstr(""))));
	}
	void InitHook() {
		OrigHook::input = reinterpret_cast<void (*)(r_BasePlayer*, r_InpitStaete*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(xorstr("BasePlayer"), xorstr("ClientInput"), -1, xorstr(""), xorstr(""))));
	}
	void InputStatet(r_BasePlayer* player, r_InpitStaete* staet) {
		if (player)
		{
			player->SetFlag(Rust::FlagsPlayer::IsAdmin);
		}
		OrigHook::input(player, staet);
	}

	
}