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
#ifndef WEAPONS_H
#define WEAPONS_H

#include "effects.h"

class CBasePlayer;
extern int gmsgWeapPickup;

void DeactivateSatchels(CBasePlayer* pOwner);

// Contact Grenade / Timed grenade / Satchel Charge
class CGrenade: public CBaseMonster
{
public:
	void Spawn(void);

	typedef enum
	{
		SATCHEL_DETONATE = 0,
		SATCHEL_RELEASE
	} SATCHELCODE;

	static CGrenade* ShootTimed(entvars_t* pevOwner, Vector vecStart, Vector vecVelocity, float time);
	static CGrenade* ShootContact(entvars_t* pevOwner, Vector vecStart, Vector vecVelocity);
	static CGrenade* ShootSatchelCharge(entvars_t* pevOwner, Vector vecStart, Vector vecVelocity);
	static void UseSatchelCharges(entvars_t* pevOwner, SATCHELCODE code);

	void Explode(Vector vecSrc, Vector vecAim);
	void Explode(TraceResult* pTrace, int bitsDamageType);
	void EXPORT Smoke(void);

	void EXPORT BounceTouch(CBaseEntity* pOther);
	void EXPORT SlideTouch(CBaseEntity* pOther);
	void EXPORT ExplodeTouch(CBaseEntity* pOther);
	void EXPORT DangerSoundThink(void);
	void EXPORT PreDetonate(void);
	void EXPORT Detonate(void);
	void EXPORT DetonateUse(CBaseEntity* pActivator, CBaseEntity* pCaller, USE_TYPE useType, float value);
	void EXPORT TumbleThink(void);

	virtual void BounceSound(void);
	virtual int BloodColor(void) { return DONT_BLEED; }
	virtual void Killed(entvars_t* pevAttacker, int iGib);

	BOOL m_fRegisteredSound; // whether or not this grenade has issued its DANGER sound to the world sound list yet.
};


// constant items
#define ITEM_HEALTHKIT 1
#define ITEM_ANTIDOTE 2
#define ITEM_SECURITY 3
#define ITEM_BATTERY 4

#define WEAPON_NONE 0
#define WEAPON_P228 1
#define WEAPON_SCOUT 2
#define WEAPON_XM1014 3
#define WEAPON_MAC10 4
#define WEAPON_AUG 5
#define WEAPON_ELITE 6
#define WEAPON_FIVESEVEN 7
#define WEAPON_UMP45 8
#define WEAPON_SG550 9
#define WEAPON_USP 10
#define WEAPON_GLOCK18 11
#define WEAPON_MP5N 12
#define WEAPON_AWP 13
#define WEAPON_M249 14
#define WEAPON_M3 15
#define WEAPON_M4A1 16
#define WEAPON_TMP 17
#define WEAPON_G3SG1 18
#define WEAPON_DEAGLE 19
#define WEAPON_SG552 20
#define WEAPON_AK47 21
#define WEAPON_P90 22
#define WEAPON_M60 23
#define WEAPON_FAMAS 24
#define WEAPON_GALIL 25
#define WEAPON_SHIELDGUN 26
#define WEAPON_BLOWTORCH 27

#define WEAPON_FLASHBANG 28 // Decompiled ID: 4
#define WEAPON_HEGRENADE 29 // Decompiled ID: 5
#define WEAPON_C4 30 // Decompiled ID: 6
#define WEAPON_SMOKEGRENADE 31 // Decompiled ID: 7
#define WEAPON_KNIFE 32 // Decompiled ID: 9
#define WEAPON_RADIO 33 // Decompiled ID: 11
#define WEAPON_HOLSTER 34 // Decompiled ID: 17
#define WEAPON_CAMERA 35 // Decompiled ID: 18
#define WEAPON_RADIOCONTROLLEDBOMB 36 // Decompiled ID: 20
#define WEAPON_LAWS 37 // Decompiled ID: 21
#define WEAPON_BRIEFCASE 38 // Decompiled ID: 22
#define WEAPON_MEDKIT 39 // Decompiled ID: 23
#define WEAPON_SYRINGE 40 // Decompiled ID: 24
#define WEAPON_ZIPLINE 41 // Decompiled ID: 25
#define WEAPON_FIBEROPTICCAMERA 42 // Decompiled ID: 26

#define WEAPON_ALLWEAPONS (~(1 << WEAPON_SUIT))

#define WEAPON_SUIT 43

#define MAX_WEAPONS 32

#define MAX_NORMAL_BATTERY 100

// weapon weight factors (for auto-switching)   (-1 = noswitch)
#define AK47_WEIGHT 25
#define AUG_WEIGHT 25
#define AWP_WEIGHT 30
#define BLOWTORCH_WEIGHT 5
#define BRIEFCASE_WEIGHT 5
#define C4_WEIGHT 3
#define CAMERA_WEIGHT 5
#define DEAGLE_WEIGHT 7
#define ELITE_WEIGHT 5
#define FAMAS_WEIGHT 75
#define FIBEROPTICCAMERA_WEIGHT 5
#define FIVESEVEN_WEIGHT 5
#define FLASHBANG_WEIGHT 1
#define G3SG1_WEIGHT 20
#define GALIL_WEIGHT 25
#define GLOCK18_WEIGHT 5
#define HEGRENADE_WEIGHT 2
#define HOLSTER_WEIGHT 5
#define KNIFE_WEIGHT 0
#define LAWS_WEIGHT 2
#define M249_WEIGHT 25
#define M3_WEIGHT 20
#define M4A1_WEIGHT 25
#define M60_WEIGHT 25
#define MAC10_WEIGHT 25
#define MEDKIT_WEIGHT 2
#define MP5N_WEIGHT 25
#define P228_WEIGHT 5
#define P90_WEIGHT 26
#define RADIO_WEIGHT 5
#define RADIOCONTROLLEDBOMB_WEIGHT 3
#define SCOUT_WEIGHT 30
#define SG550_WEIGHT 20
#define SG552_WEIGHT 25
#define SHIELDGUN_WEIGHT 50
#define SMOKEGRENADE_WEIGHT 1
#define SYRINGE_WEIGHT 2
#define TMP_WEIGHT 25
#define UMP45_WEIGHT 25
#define USP_WEIGHT 5
#define XM1014_WEIGHT 20
#define ZIPLINE_WEIGHT 2

// weapon clip/carry ammo capacities
#define AK47_MAX_CARRY 90
#define AUG_MAX_CARRY 90
#define AWP_MAX_CARRY 30
#define C4_MAX_CARRY 1
#define DEAGLE_MAX_CARRY 35
#define ELITE_MAX_CARRY 120
#define FAMAS_MAX_CARRY 75
#define FIVESEVEN_MAX_CARRY 100
#define FLASHBANG_MAX_CARRY 3
#define G3SG1_MAX_CARRY 90
#define GALIL_MAX_CARRY 70
#define GLOCK18_MAX_CARRY 120
#define HEGRENADE_MAX_CARRY 3
#define LAWS_MAX_CARRY 1
#define M249_MAX_CARRY 200
#define M3_MAX_CARRY 32
#define M4A1_MAX_CARRY 90
#define M60_MAX_CARRY 200
#define MAC10_MAX_CARRY 100
#define MEDKIT_MAX_CARRY 1
#define MP5N_MAX_CARRY 120
#define P228_MAX_CARRY 52
#define P90_MAX_CARRY 100
#define RADIOCONTROLLEDBOMB_MAX_CARRY 5
#define SCOUT_MAX_CARRY 90
#define SG550_MAX_CARRY 90
#define SG552_MAX_CARRY 90
#define SHIELDGUN_MAX_CARRY 100
#define SMOKEGRENADE_MAX_CARRY 3
#define SYRINGE_MAX_CARRY 3
#define TMP_MAX_CARRY 120
#define UMP45_MAX_CARRY 100
#define USP_MAX_CARRY 100
#define XM1014_MAX_CARRY 32

// the maximum amount of ammo each weapon's clip can hold
#define WEAPON_NOCLIP -1

#define AK47_MAX_CLIP 30
#define AUG_MAX_CLIP 30
#define AWP_MAX_CLIP 10
#define BLOWTORCH_MAX_CLIP WEAPON_NOCLIP
#define BRIEFCASE_MAX_CLIP WEAPON_NOCLIP
#define C4_MAX_CLIP WEAPON_NOCLIP
#define CAMERA_MAX_CLIP 20
#define DEAGLE_MAX_CLIP 7
#define ELITE_MAX_CLIP 30
#define FAMAS_MAX_CLIP 25
#define FIBEROPTICCAMERA_MAX_CLIP WEAPON_NOCLIP
#define FIVESEVEN_MAX_CLIP 20
#define FLASHBANG_MAX_CLIP WEAPON_NOCLIP
#define G3SG1_MAX_CLIP 20
#define GALIL_MAX_CLIP 35
#define GLOCK18_MAX_CLIP 20
#define HEGRENADE_MAX_CLIP WEAPON_NOCLIP
#define HOLSTER_MAX_CLIP 20
#define KNIFE_MAX_CLIP WEAPON_NOCLIP
#define LAWS_MAX_CLIP 0
#define M249_MAX_CLIP 100
#define M3_MAX_CLIP 8
#define M4A1_MAX_CLIP 30
#define M60_MAX_CLIP 100
#define MAC10_MAX_CLIP 30
#define MEDKIT_MAX_CLIP WEAPON_NOCLIP
#define MP5N_MAX_CLIP 30
#define P228_MAX_CLIP 13
#define P90_MAX_CLIP 50
#define RADIO_MAX_CLIP WEAPON_NOCLIP
#define RADIOCONTROLLEDBOMB_MAX_CLIP WEAPON_NOCLIP
#define SCOUT_MAX_CLIP 10
#define SG550_MAX_CLIP 30
#define SG552_MAX_CLIP 30
#define SHIELDGUN_MAX_CLIP 20
#define SMOKEGRENADE_MAX_CLIP WEAPON_NOCLIP
#define SYRINGE_MAX_CLIP 3
#define TMP_MAX_CLIP 30
#define UMP45_MAX_CLIP 25
#define USP_MAX_CLIP 12
#define XM1014_MAX_CLIP 7
#define ZIPLINE_MAX_CLIP WEAPON_NOCLIP

// the default amount of ammo that comes with each gun when it spawns
#define AK47_DEFAULT_GIVE 30
#define AUG_DEFAULT_GIVE 30
#define AWP_DEFAULT_GIVE 10
#define BLOWTORCH_DEFAULT_GIVE WEAPON_NOCLIP
#define BRIEFCASE_DEFAULT_GIVE WEAPON_NOCLIP
#define C4_DEFAULT_GIVE 1
#define CAMERA_DEFAULT_GIVE WEAPON_NOCLIP
#define DEAGLE_DEFAULT_GIVE 7
#define ELITE_DEFAULT_GIVE 30
#define FAMAS_DEFAULT_GIVE 25
#define FIBEROPTICCAMERA_DEFAULT_GIVE WEAPON_NOCLIP
#define FIVESEVEN_DEFAULT_GIVE 20
#define FLASHBANG_DEFAULT_GIVE 1
#define G3SG1_DEFAULT_GIVE 20
#define GALIL_DEFAULT_GIVE 35
#define GLOCK18_DEFAULT_GIVE 20
#define HEGRENADE_DEFAULT_GIVE 1
#define HOLSTER_DEFAULT_GIVE WEAPON_NOCLIP
#define LAWS_DEFAULT_GIVE 1
#define M249_DEFAULT_GIVE 100
#define M3_DEFAULT_GIVE 8
#define M4A1_DEFAULT_GIVE 30
#define M60_DEFAULT_GIVE 100
#define MAC10_DEFAULT_GIVE 30
#define MEDKIT_DEFAULT_GIVE 1
#define MP5N_DEFAULT_GIVE 30
#define P228_DEFAULT_GIVE 13
#define P90_DEFAULT_GIVE 50
#define RADIO_DEFAULT_GIVE WEAPON_NOCLIP
#define RADIOCONTROLLEDBOMB_DEFAULT_GIVE 5
#define SCOUT_DEFAULT_GIVE 10
#define SG550_DEFAULT_GIVE 30
#define SG552_DEFAULT_GIVE 30
#define SHIELDGUN_DEFAULT_GIVE 20
#define SMOKEGRENADE_DEFAULT_GIVE 1
#define SYRINGE_DEFAULT_GIVE 3
#define TMP_DEFAULT_GIVE 30
#define UMP45_DEFAULT_GIVE 25
#define USP_DEFAULT_GIVE 12
#define XM1014_DEFAULT_GIVE 7
#define ZIPLINE_DEFAULT_GIVE WEAPON_NOCLIP

// The amount of ammo given to a player by an ammo item.
#define AMMO_338MAGNUM_GIVE 10
#define AMMO_357SIG_GIVE 13
#define AMMO_45ACP_GIVE 12
#define AMMO_50AE_GIVE 7
#define AMMO_556NATO_GIVE 30
#define AMMO_556NATOBOX_GIVE 60
#define AMMO_57MM_GIVE 50
#define AMMO_66MM_GIVE 1
#define AMMO_762NATO_GIVE 30
#define AMMO_762NATOBOX_GIVE 60
#define AMMO_9MM_GIVE 30
#define AMMO_BOMB_GIVE 5
#define AMMO_BUCKSHOT_GIVE 3
#define AMMO_LAWS_GIVE 1
#define AMMO_SYRINGE_GIVE 3

// bullet types
typedef enum
{
	BULLET_NONE = 0,
	BULLET_PLAYER_9MM,		// glock
	BULLET_PLAYER_MP5,		// mp5
	BULLET_PLAYER_357,		// python
	BULLET_PLAYER_BUCKSHOT, // shotgun
	BULLET_PLAYER_CROWBAR,	// crowbar swipe
	BULLET_MONSTER_9MM,
	BULLET_MONSTER_MP5,
	BULLET_MONSTER_12MM,
	BULLET_PLAYER_45ACP,
	BULLET_PLAYER_338MAG,
	BULLET_PLAYER_762MM,
	BULLET_PLAYER_556MM,
	BULLET_PLAYER_50AE,
	BULLET_PLAYER_57MM,
	BULLET_PLAYER_BLOWTORCH,
} Bullet;


#define ITEM_FLAG_SELECTONEMPTY 1
#define ITEM_FLAG_NOAUTORELOAD 2
#define ITEM_FLAG_NOAUTOSWITCHEMPTY 4
#define ITEM_FLAG_LIMITINWORLD 8
#define ITEM_FLAG_EXHAUSTIBLE 16 // A player can totally exhaust their ammo supply and lose this weapon

#define WEAPON_IS_ONTARGET 0x40

typedef struct
{
	int iSlot;
	int iPosition;
	const char* pszAmmo1; // ammo 1 type
	int iMaxAmmo1;		  // max ammo 1
	const char* pszAmmo2; // ammo 2 type
	int iMaxAmmo2;		  // max ammo 2
	const char* pszName;
	int iMaxClip;
	int iId;
	int iFlags;
	int iWeight; // this value used to determine this weapon's importance in autoselection.
	bool bIsAccessory;
} ItemInfo;

typedef struct
{
	const char* pszName;
	int iId;
} AmmoInfo;

// Items that the player has in their inventory that they can use
class CBasePlayerItem: public CBaseAnimating
{
public:
	virtual void SetObjectCollisionBox(void);

	virtual int Save(CSave& save);
	virtual int Restore(CRestore& restore);

	static TYPEDESCRIPTION m_SaveData[];

	virtual int AddToPlayer(CBasePlayer* pPlayer);					   // return TRUE if the item you want the item added to the player inventory
	virtual int AddDuplicate(CBasePlayerItem* pItem) { return FALSE; } // return TRUE if you want your duplicate removed from world
	void EXPORT DestroyItem(void);
	void EXPORT DefaultTouch(CBaseEntity* pOther); // default weapon touch
	void EXPORT FallThink(void);				   // when an item is first spawned, this think is run to determine when the object has hit the ground.
	void EXPORT Materialize(void);				   // make a weapon visible and tangible
	void EXPORT AttemptToMaterialize(void);		   // the weapon desires to become visible and tangible, if the game rules allow for it
	CBaseEntity* Respawn(void);					   // copy a weapon
	void FallInit(void);
	void CheckRespawn(void);
	virtual int GetItemInfo(ItemInfo* p) { return 0; }; // returns 0 if struct not filled out
	virtual BOOL CanDeploy(void) { return TRUE; };
	virtual BOOL Deploy() // returns is deploy was successful
	{
		return TRUE;
	};

	virtual BOOL CanHolster(void) { return TRUE; }; // can this weapon be put away right now?
	virtual void Holster(int skiplocal = 0);
	virtual void UpdateItemInfo(void) { return; };

	virtual void ItemPreFrame(void) { return; }	 // called each frame by the player PreThink
	virtual void ItemPostFrame(void) { return; } // called each frame by the player PostThink

	virtual void Drop(void);
	virtual void Kill(void);
	virtual void AttachToPlayer(CBasePlayer* pPlayer);

	virtual int PrimaryAmmoIndex() { return -1; };
	virtual int SecondaryAmmoIndex() { return -1; };

	virtual int UpdateClientData(CBasePlayer* pPlayer) { return 0; }

	virtual CBasePlayerItem* GetWeaponPtr(void) { return NULL; };

	static ItemInfo ItemInfoArray[MAX_WEAPONS];
	static AmmoInfo AmmoInfoArray[MAX_AMMO_SLOTS];

	CBasePlayer* m_pPlayer;
	CBasePlayerItem* m_pNext;
	int m_iId; // WEAPON_???

	virtual int iItemSlot(void) { return 0; } // return 0 to MAX_ITEMS_SLOTS, used in hud

	int iItemPosition(void) { return ItemInfoArray[m_iId].iPosition; }
	const char* pszAmmo1(void) { return ItemInfoArray[m_iId].pszAmmo1; }
	int iMaxAmmo1(void) { return ItemInfoArray[m_iId].iMaxAmmo1; }
	const char* pszAmmo2(void) { return ItemInfoArray[m_iId].pszAmmo2; }
	int iMaxAmmo2(void) { return ItemInfoArray[m_iId].iMaxAmmo2; }
	const char* pszName(void) { return ItemInfoArray[m_iId].pszName; }
	int iMaxClip(void) { return ItemInfoArray[m_iId].iMaxClip; }
	int iWeight(void) { return ItemInfoArray[m_iId].iWeight; }
	int iFlags(void) { return ItemInfoArray[m_iId].iFlags; }
	bool bIsAccessory(void) { return ItemInfoArray[m_iId].bIsAccessory; }

	// int		m_iIdPrimary;										// Unique Id for primary ammo
	// int		m_iIdSecondary;										// Unique Id for secondary ammo
};


// inventory items that
class CBasePlayerWeapon: public CBasePlayerItem
{
public:
	virtual int Save(CSave& save);
	virtual int Restore(CRestore& restore);

	static TYPEDESCRIPTION m_SaveData[];

	// generic weapon versions of CBasePlayerItem calls
	virtual int AddToPlayer(CBasePlayer* pPlayer);
	virtual int AddDuplicate(CBasePlayerItem* pItem);

	virtual int ExtractAmmo(CBasePlayerWeapon* pWeapon);	 //{ return TRUE; };			// Return TRUE if you can add ammo to yourself when picked up
	virtual int ExtractClipAmmo(CBasePlayerWeapon* pWeapon); // { return TRUE; };			// Return TRUE if you can add ammo to yourself when picked up

	virtual int AddWeapon(void)
	{
		ExtractAmmo(this);
		return TRUE;
	}; // Return TRUE if you want to add yourself to the player

	// generic "shared" ammo handlers
	BOOL AddPrimaryAmmo(int iCount, char* szName, int iMaxClip, int iMaxCarry);
	BOOL AddSecondaryAmmo(int iCount, char* szName, int iMaxCarry);

	virtual void UpdateItemInfo(void){}; // updates HUD state

	virtual BOOL PlayEmptySound(void);
	virtual void ResetEmptySound(void);

	virtual void SendWeaponAnim(int iAnim, int skiplocal = 1, int body = 0); // skiplocal is 1 if client is predicting weapon animations

	virtual BOOL CanDeploy(void);
	virtual BOOL IsUseable(void);
	BOOL DefaultDeploy(char* szViewModel, char* szWeaponModel, int iAnim, char* szAnimExt, int skiplocal = 0, int body = 0);
	int DefaultReload(int iClipSize, int iAnim, float fDelay, int body = 0);

	virtual void ItemPostFrame(void); // called each frame by the player PostThink
	// called by CBasePlayerWeapons ItemPostFrame()
	virtual void PrimaryAttack(void) { return; }		// do "+ATTACK"
	virtual void SecondaryAttack(void) { return; }		// do "+ATTACK2"
	virtual void Reload(void) { return; }				// do "+RELOAD"
	virtual void WeaponIdle(void) { return; }			// called when no buttons pressed
	virtual int UpdateClientData(CBasePlayer* pPlayer); // sends hud info to client dll, if things have changed
	virtual void RetireWeapon(void);
	virtual BOOL ShouldWeaponIdle(void) { return FALSE; };
	virtual void Holster(int skiplocal = 0);
	virtual BOOL UseDecrement(void) { return FALSE; };

	int PrimaryAmmoIndex();
	int SecondaryAmmoIndex();

	void PrintState(void);

	virtual CBasePlayerItem* GetWeaponPtr(void) { return (CBasePlayerItem*)this; };

	float m_flNextPrimaryAttack;
	float m_flNextSecondaryAttack;
	float m_flTimeWeaponIdle;
	int m_iPrimaryAmmoType;
	int m_iSecondaryAmmoType;
	int m_iClip;
	int m_iDefaultAmmo;
	int m_iClientClip;
	int m_iClientWeaponState;
	int m_fInReload;
	int m_fInSpecialReload;
	int m_iShellId;
	bool m_bDelayFire;
	int m_iDirection;
	bool m_bSecondarySilencerOn;
	float m_flAccuracy;
	float m_flLastFire;
	int m_iShotsFired;
	Vector m_vVecAiming;
	string_t model_name;
	float m_flGlock18Shoot;
	int m_iGlock18ShotsFired;
	float m_flFamasShoot;
	int m_iFamasShotsFired;
	float m_fBurstSpread;
	int m_iWeaponState;
	float m_flNextReload;
	float m_flDecreaseShotsFired;
	int m_iPlayEmptySound;
	int m_fFireOnEmpty;
	unsigned short m_usFireGlock18;
	unsigned short m_usFireFamas;
	unsigned short m_WeaponState;
};


class CBasePlayerAmmo: public CBaseEntity
{
public:
	virtual void Spawn(void);
	void EXPORT DefaultTouch(CBaseEntity* pOther); // default weapon touch
	virtual BOOL AddAmmo(CBaseEntity* pOther) { return TRUE; };

	CBaseEntity* Respawn(void);
	void EXPORT Materialize(void);
};


extern DLL_GLOBAL short g_sModelIndexLaser; // holds the index for the laser beam
extern DLL_GLOBAL const char* g_pModelNameLaser;

extern DLL_GLOBAL short g_sModelIndexLaserDot;	 // holds the index for the laser beam dot
extern DLL_GLOBAL short g_sModelIndexFireball;	 // holds the index for the fireball
extern DLL_GLOBAL short g_sModelIndexSmoke;		 // holds the index for the smoke cloud
extern DLL_GLOBAL short g_sModelIndexWExplosion; // holds the index for the underwater explosion
extern DLL_GLOBAL short g_sModelIndexBubbles;	 // holds the index for the bubbles model
extern DLL_GLOBAL short g_sModelIndexBloodDrop;	 // holds the sprite index for blood drops
extern DLL_GLOBAL short g_sModelIndexBloodSpray; // holds the sprite index for blood spray (bigger)

extern void ClearMultiDamage(void);
extern void ApplyMultiDamage(entvars_t* pevInflictor, entvars_t* pevAttacker);
extern void AddMultiDamage(entvars_t* pevInflictor, CBaseEntity* pEntity, float flDamage, int bitsDamageType);

extern void DecalGunshot(TraceResult* pTrace, int iBulletType);
extern void SpawnBlood(Vector vecSpot, int bloodColor, float flDamage);
extern int DamageDecal(CBaseEntity* pEntity, int bitsDamageType);
extern void RadiusDamage(Vector vecSrc, entvars_t* pevInflictor, entvars_t* pevAttacker, float flDamage, float flRadius, int iClassIgnore, int bitsDamageType);

typedef struct
{
	CBaseEntity* pEntity;
	float amount;
	int type;
} MULTIDAMAGE;

extern MULTIDAMAGE gMultiDamage;


#define LOUD_GUN_VOLUME 1000
#define NORMAL_GUN_VOLUME 600
#define QUIET_GUN_VOLUME 200

#define BRIGHT_GUN_FLASH 512
#define NORMAL_GUN_FLASH 256
#define DIM_GUN_FLASH 128

#define BIG_EXPLOSION_VOLUME 2048
#define NORMAL_EXPLOSION_VOLUME 1024
#define SMALL_EXPLOSION_VOLUME 512

#define WEAPON_ACTIVITY_VOLUME 64

#define VECTOR_CONE_1DEGREES Vector(0.00873, 0.00873, 0.00873)
#define VECTOR_CONE_2DEGREES Vector(0.01745, 0.01745, 0.01745)
#define VECTOR_CONE_3DEGREES Vector(0.02618, 0.02618, 0.02618)
#define VECTOR_CONE_4DEGREES Vector(0.03490, 0.03490, 0.03490)
#define VECTOR_CONE_5DEGREES Vector(0.04362, 0.04362, 0.04362)
#define VECTOR_CONE_6DEGREES Vector(0.05234, 0.05234, 0.05234)
#define VECTOR_CONE_7DEGREES Vector(0.06105, 0.06105, 0.06105)
#define VECTOR_CONE_8DEGREES Vector(0.06976, 0.06976, 0.06976)
#define VECTOR_CONE_9DEGREES Vector(0.07846, 0.07846, 0.07846)
#define VECTOR_CONE_10DEGREES Vector(0.08716, 0.08716, 0.08716)
#define VECTOR_CONE_15DEGREES Vector(0.13053, 0.13053, 0.13053)
#define VECTOR_CONE_20DEGREES Vector(0.17365, 0.17365, 0.17365)

//=========================================================
// CWeaponBox - a single entity that can store weapons
// and ammo.
//=========================================================
class CWeaponBox: public CBaseEntity
{
	void Precache(void);
	void Spawn(void);
	void Touch(CBaseEntity* pOther);
	void KeyValue(KeyValueData* pkvd);
	BOOL IsEmpty(void);
	int GiveAmmo(int iCount, char* szName, int iMax, int* pIndex = NULL);
	void SetObjectCollisionBox(void);

public:
	void EXPORT Kill(void);
	int Save(CSave& save);
	int Restore(CRestore& restore);
	static TYPEDESCRIPTION m_SaveData[];

	BOOL HasWeapon(CBasePlayerItem* pCheckItem);
	BOOL PackWeapon(CBasePlayerItem* pWeapon);
	BOOL PackAmmo(int iszName, int iCount);

	CBasePlayerItem* m_rgpPlayerItems[MAX_ITEM_TYPES]; // one slot for each

	int m_rgiszAmmo[MAX_AMMO_SLOTS]; // ammo names
	int m_rgAmmo[MAX_AMMO_SLOTS];	 // ammo quantities

	int m_cAmmoTypes; // how many ammo types packed into this box (if packed by a level designer)
};

#ifdef CLIENT_DLL
bool bIsMultiplayer(void);
void LoadVModel(char* szViewModel, CBasePlayer* m_pPlayer);
#endif

#endif // WEAPONS_H
