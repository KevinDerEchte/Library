uintptr_t base = (uintptr_t)GetModuleHandle(NULL);
uintptr_t GameAssembly = (uintptr_t)GetModuleHandle("GameAssembly.dll");


//set_Emote Hook
bool(__fastcall* o_Has_Emote)(DWORD*, const char*, DWORD*);
bool __stdcall h_Has_Emote(DWORD* __this, const char* emoteID, DWORD* method)
{
	printf("Hooked Has_Emote!");
	return true;
	//return o_set_Emote(__this, emoteID, method);
}


//has_Skin Hook
bool(__fastcall* o_Has_Skin)(DWORD*, const char*, DWORD*);
bool __stdcall h_Has_Skin(DWORD* __this, const char* skinID, DWORD* method)
{
	printf("Hooked Has_Skin!");
	return true;
	//return o_set_Skin(__this, skinID, method);
}


//has_Animation Hook
bool(__fastcall* o_Has_Animation)(DWORD*, const char*, DWORD*);
bool __stdcall h_Has_Animation(DWORD* __this, const char* animationID, DWORD* method)
{
	printf("Hooked Has_Animation!");
	return true;
	//return o_set_Animation(__this, animationID, method);
}


//has_footstep Hook
bool(__fastcall* o_Has_Footstep)(DWORD*, const char*, DWORD*);
bool __stdcall h_Has_Footstep(DWORD* __this, const char* footstepID, DWORD* method)
{
	printf("Hooked Has_Footstep!");
	return true;
	//return o_set_Footstep(__this, footstepID, method);
}

void UnlockEmotes() {
	MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssembly + offsets::HasEmoteOffset), h_Has_Emote, (LPVOID*)o_Has_Emote);
	MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssembly + offsets::HasEmoteOffset));
}

void UnlockSkins() {
	MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssembly + offsets::HasSkinOffset), h_Has_Emote, (LPVOID*)o_Has_Skin);
	MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssembly + offsets::HasSkinOffset));
}

void UnlockAnimations() {
	MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssembly + offsets::hasAnimationOffset), h_Has_Animation, (LPVOID*)o_Has_Animation);
	MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssembly + offsets::hasAnimationOffset));
}

void UnlockFootstep() {
	MH_CreateHook(reinterpret_cast<LPVOID*>(GameAssembly + offsets::hasFootstepOffset), h_Has_Footstep, (LPVOID*)o_Has_Footstep);
	MH_EnableHook(reinterpret_cast<LPVOID*>(GameAssembly + offsets::hasFootstepOffset));
}