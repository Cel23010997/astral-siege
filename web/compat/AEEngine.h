#pragma once
// Browser compatibility interface written for this portfolio port.
// This is not the DigiPen Alpha Engine SDK and contains no SDK implementation.
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
using s8=int8_t; using s16=int16_t; using s32=int32_t; using u8=uint8_t; using u16=uint16_t; using u32=uint32_t; using f32=float; using f64=double;
struct AEVec2 { float x,y; };
struct AEMtx33 { float m[3][3]; };
struct WebVertex { float x,y,u,v,r,g,b,a; };
struct AEGfxVertexList { std::vector<WebVertex> vertices; };
struct AEGfxTexture { int id; };
struct AEAudio { void* fmod_sound; };
struct AEAudioGroup { void* fmod_group; };
enum {AE_GFX_RM_COLOR=0,AE_GFX_RM_TEXTURE=1,AE_GFX_MDM_TRIANGLES=0,AE_GFX_BM_NONE=0,AE_GFX_BM_BLEND=1,AE_GFX_BM_ADD=2};
enum {AEVK_LBUTTON=1,AEVK_RBUTTON=2,AEVK_RETURN=13,AEVK_ESCAPE=27,AEVK_SPACE=32,AEVK_4=52,AEVK_5=53,VK_LBUTTON=1,VK_RBUTTON=2};
#ifdef M_PI
#undef M_PI
#endif
constexpr float PI = 3.14159265358979323846f;
template<size_t N,typename... A> int sprintf_s(char(&b)[N],const char* f,A... a){return std::snprintf(b,N,f,a...);}
template<typename... A> int sprintf_s(char*b,size_t n,const char*f,A...a){return std::snprintf(b,n,f,a...);}
#define sscanf_s std::sscanf
#define AE_Allocate(type,count) ((type*)std::calloc((count),sizeof(type)))
void AESysInit(void*,int,int,int,int,int,bool,void*);
void AESysSetWindowTitle(const char*); void AESysFrameStart(); void AESysFrameEnd(); bool AESysDoesWindowExist(); void AESysExit(); void AESysReset();
float AEFrameRateControllerGetFrameTime();
int AEInputCheckCurr(int);int AEInputCheckTriggered(int);int AEInputCheckReleased(int);void AEInputGetCursorPosition(s32*,s32*);
void AEVec2Set(AEVec2*,float,float);void AEVec2Zero(AEVec2*);void AEVec2Add(AEVec2*,const AEVec2*,const AEVec2*);void AEVec2Sub(AEVec2*,const AEVec2*,const AEVec2*);void AEVec2Scale(AEVec2*,const AEVec2*,float);void AEVec2Normalize(AEVec2*,const AEVec2*);float AEVec2SquareDistance(const AEVec2*,const AEVec2*);
void AEMtx33Identity(AEMtx33*);void AEMtx33Trans(AEMtx33*,float,float);void AEMtx33Scale(AEMtx33*,float,float);void AEMtx33Rot(AEMtx33*,float);void AEMtx33Concat(AEMtx33*,const AEMtx33*,const AEMtx33*);
float AEDegToRad(float);float AERandFloat();int AETestPointToRect(AEVec2*,AEVec2*,float,float);int AETestCircleToCircle(AEVec2*,float,AEVec2*,float);
void AEGfxMeshStart();void AEGfxTriAdd(float,float,u32,float,float,float,float,u32,float,float,float,float,u32,float,float);AEGfxVertexList* AEGfxMeshEnd();void AEGfxMeshFree(AEGfxVertexList*);void AEGfxMeshDraw(AEGfxVertexList*,int);
AEGfxTexture* AEGfxTextureLoad(const char*);void AEGfxTextureUnload(AEGfxTexture*);void AEGfxTextureSet(AEGfxTexture*,float,float);
void AEGfxSetTransform(const float[3][3]);void AEGfxSetRenderMode(int);void AEGfxSetBlendMode(int);void AEGfxSetColorToMultiply(float,float,float,float);void AEGfxSetColorToAdd(float,float,float,float);void AEGfxSetTransparency(float);void AEGfxSetBackgroundColor(float,float,float);
void AEGfxSetCamPosition(float,float);void AEGfxGetCamPosition(float*,float*);s32 AEGfxGetWindowWidth();s32 AEGfxGetWindowHeight();float AEGfxGetWinMinX();float AEGfxGetWinMaxX();float AEGfxGetWinMinY();float AEGfxGetWinMaxY();
s8 AEGfxCreateFont(const char*,u32);void AEGfxDestroyFont(s8);void AEGfxFontSystemStart();void AEGfxPrint(s8,const char*,float,float,float,float,float,float,float);void AEGfxGetPrintSize(s8,const char*,float,float*,float*);
s32 AEAudioInit();AEAudio AEAudioLoadMusic(const char*);AEAudio AEAudioLoadSound(const char*);AEAudioGroup AEAudioCreateGroup();s32 AEAudioIsValidAudio(AEAudio);s32 AEAudioIsValidGroup(AEAudioGroup);void AEAudioPlay(AEAudio,AEAudioGroup,float,float,int);void AEAudioStopGroup(AEAudioGroup);void AEAudioPauseGroup(AEAudioGroup);void AEAudioResumeGroup(AEAudioGroup);void AEAudioSetGroupVolume(AEAudioGroup,float);void AEAudioSetGroupPitch(AEAudioGroup,float);void AEAudioUnloadAudio(AEAudio);void AEAudioUnloadAudioGroup(AEAudioGroup);
