#include "Include.h"
#include "il2cpp-main/il2cpp_memary.h"
#include "MainClasses.hpp"
#include "Hook.hpp"

bool Inst = false;
BOOL WINAPI MainThread(HMODULE module) {
 
   
    if (!Inst)
    {

        mem::game_assembly_base = LI_MODULE_SAFE_(xorstr("GameAssembly.dll"));
        mem::unity_player_base = LI_MODULE_SAFE_(xorstr("UnityPlayer.dll"));
        il2cpp::init();
        InitClass();
  
        Hook::InitHook();
        Inst = true;
    }
 
    mem::hook_virtual_function(xorstr("BasePlayer"), xorstr("ClientInput"), &Hook::InputStatet);


    return 0;
}

BOOL APIENTRY DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpvReserved
) {
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        Beep(200, 400);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainThread, 0, 0, 0);
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}