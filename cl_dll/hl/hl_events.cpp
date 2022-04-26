/***
 *
 *	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
 *
 *	This product contains software technology licensed from Id
 *	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
 *	All Rights Reserved.
 *
 *   Use, distribution, and modification of this source code and/or resulting
 *   object code is restricted to non-commercial enhancements to products from
 *   Valve LLC.  All other use, distribution, or modification is prohibited
 *   without written permission from Valve LLC.
 *
 ****/
#include "../hud.h"
#include "../cl_util.h"
#include "event_api.h"

extern "C" {
// CZDS
/*
void EV_FireUSP(struct event_args_s* args);
void EV_FireMP5N(struct event_args_s* args);
void EV_FireAK47(struct event_args_s* args);
void EV_FireAug(struct event_args_s* args);
void EV_FireDeagle(struct event_args_s* args);
void EV_FireG3SG1(struct event_args_s* args);
void EV_FireSG550(struct event_args_s* args);
void EV_FireGlock18(struct event_args_s* args);
void EV_FireM249(struct event_args_s* args);
void EV_FireM60(struct event_args_s* args);
void EV_FireM3(struct event_args_s* args);
void EV_FireM4A1(struct event_args_s* args);
void EV_FireMac10(struct event_args_s* args);
void EV_FireP90(struct event_args_s* args);
void EV_FireP228(struct event_args_s* args);
void EV_FireAWP(struct event_args_s* args);
void EV_FireScout(struct event_args_s* args);
void EV_FireSG552(struct event_args_s* args);
void EV_FireTMP(struct event_args_s* args);
void EV_FireFiveSeven(struct event_args_s* args);
void EV_FireUMP45(struct event_args_s* args);
void EV_FireXM1014(struct event_args_s* args);
void EV_FireEliteLeft(struct event_args_s* args);
void EV_FireEliteRight(struct event_args_s* args);
void EV_Knife(struct event_args_s* args);
void EV_FireGalil(struct event_args_s* args);
void EV_FireCamera(struct event_args_s* args);
void EV_FireFiberOpticCamera(struct event_args_s* args);
void EV_FireFamas(struct event_args_s* args);
void EV_RemoveAllDecals(struct event_args_s* args);
void EV_FireShieldGun(struct event_args_s* args);
void EV_HolsterBlowtorch(struct event_args_s* args);
void EV_IdleBlowtorch(struct event_args_s* args);
void EV_FireBlowtorch(struct event_args_s* args);
void EV_FireRadioControlledBomb(struct event_args_s* args);
void EV_FireLaws(struct event_args_s* args);
void EV_FireBriefcase(struct event_args_s* args);
void EV_FireMedkit(struct event_args_s* args);
void EV_FireSyringe(struct event_args_s* args);
void EV_FireRadio(struct event_args_s* args);
void EV_FireZipline(struct event_args_s* args);
void EV_CreateGlass(struct event_args_s* args);
void EV_GrenadeExplosion(struct event_args_s* args);
*/

void EV_TrainPitchAdjust(struct event_args_s* args);
}

/*
======================
Game_HookEvents

Associate script file name with callback functions.  Callback's must be extern "C" so
 the engine doesn't get confused about name mangling stuff.  Note that the format is
 always the same.  Of course, a clever mod team could actually embed parameters, behavior
 into the actual .sc files and create a .sc file parser and hook their functionality through
 that.. i.e., a scripting system.

That was what we were going to do, but we ran out of time...oh well.
======================
*/
void Game_HookEvents(void)
{
	/*
	gEngfuncs.pfnHookEvent("events/usp.sc",EV_FireUSP);
	gEngfuncs.pfnHookEvent("events/mp5n.sc",EV_FireMP5N);
	gEngfuncs.pfnHookEvent("events/ak47.sc",EV_FireAK47);
	gEngfuncs.pfnHookEvent("events/aug.sc",EV_FireAug);
	gEngfuncs.pfnHookEvent("events/deagle.sc",EV_FireDeagle);
	gEngfuncs.pfnHookEvent("events/g3sg1.sc",EV_FireG3SG1);
	gEngfuncs.pfnHookEvent("events/sg550.sc",EV_FireSG550);
	gEngfuncs.pfnHookEvent("events/glock18.sc",EV_FireGlock18);
	gEngfuncs.pfnHookEvent("events/m249.sc",EV_FireM249);
	gEngfuncs.pfnHookEvent("events/m60.sc",EV_FireM60);
	gEngfuncs.pfnHookEvent("events/m3.sc",EV_FireM3);
	gEngfuncs.pfnHookEvent("events/m4a1.sc",EV_FireM4A1);
	gEngfuncs.pfnHookEvent("events/mac10.sc",EV_FireMac10);
	gEngfuncs.pfnHookEvent("events/p90.sc",EV_FireP90);
	gEngfuncs.pfnHookEvent("events/p228.sc",EV_FireP228);
	gEngfuncs.pfnHookEvent("events/awp.sc",EV_FireAWP);
	gEngfuncs.pfnHookEvent("events/scout.sc",EV_FireScout);
	gEngfuncs.pfnHookEvent("events/sg552.sc",EV_FireSG552);
	gEngfuncs.pfnHookEvent("events/tmp.sc",EV_FireTMP);
	gEngfuncs.pfnHookEvent("events/fiveseven.sc",EV_FireFiveSeven);
	gEngfuncs.pfnHookEvent("events/ump45.sc",EV_FireUMP45);
	gEngfuncs.pfnHookEvent("events/xm1014.sc",EV_FireXM1014);
	gEngfuncs.pfnHookEvent("events/elite_left.sc",EV_FireEliteLeft);
	gEngfuncs.pfnHookEvent("events/elite_right.sc",EV_FireEliteRight);
	gEngfuncs.pfnHookEvent("events/knife.sc",EV_Knife);
	gEngfuncs.pfnHookEvent("events/galil.sc",EV_FireGalil);
	gEngfuncs.pfnHookEvent("events/camera.sc",EV_FireCamera);
	gEngfuncs.pfnHookEvent("events/fiberopticcamera.sc",EV_FireFiberOpticCamera);
	gEngfuncs.pfnHookEvent("events/famas.sc",EV_FireFamas);
	gEngfuncs.pfnHookEvent("events/decal_reset.sc",EV_RemoveAllDecals);
	gEngfuncs.pfnHookEvent("events/shieldgun.sc",EV_FireShieldGun);
	gEngfuncs.pfnHookEvent("events/blowtorchholster.sc",EV_HolsterBlowtorch);
	gEngfuncs.pfnHookEvent("events/blowtorchidle.sc",EV_IdleBlowtorch);
	gEngfuncs.pfnHookEvent("events/blowtorch.sc",EV_FireBlowtorch);
	gEngfuncs.pfnHookEvent("events/radiocontrolledbomb.sc",EV_FireRadioControlledBomb);
	gEngfuncs.pfnHookEvent("events/laws.sc",EV_FireLaws);
	gEngfuncs.pfnHookEvent("events/briefcase.sc",EV_FireBriefcase);
	gEngfuncs.pfnHookEvent("events/medkit.sc",EV_FireMedkit);
	gEngfuncs.pfnHookEvent("events/syringe.sc",EV_FireSyringe);
	gEngfuncs.pfnHookEvent("events/radio.sc",EV_FireRadio);
	gEngfuncs.pfnHookEvent("events/zipline.sc",EV_FireZipline);
	gEngfuncs.pfnHookEvent("events/create_glass.sc",EV_CreateGlass);
	gEngfuncs.pfnHookEvent("events/explosion.sc",EV_GrenadeExplosion);
	*/
}
