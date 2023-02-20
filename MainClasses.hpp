#pragma once
#include "il2cpp-main/il2cpp_memary.h"
#include "RustFunc.hpp"
class r_BasePlayer;
class r_InpitStaete;


//Player 
uintptr_t PlayerFlag = il2cpp::value(xorstr("BasePlayer"), xorstr("playerFlags"));



void InitClass() {
	PlayerFlag = il2cpp::value(xorstr("BasePlayer"), xorstr("playerFlags"));

}


class r_BasePlayer {
public:
	void SetFlag(Rust::FlagsPlayer flag) {
		int Flags = *reinterpret_cast<int*>((uintptr_t)this + PlayerFlag);
		*reinterpret_cast<int*>((uintptr_t)this + PlayerFlag) = Flags |= (int)flag;
	}


};