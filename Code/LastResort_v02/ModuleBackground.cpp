#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

#define STREET_LIGHTS_A 15
#define STREET_LIGHTS_B 13
#define STREET_LIGHTS_FRONT_A 8
#define STREET_LIGHTS_FRONT_B 6
#define TUNNEL_LIGHTS 8
#define BLUE_LASERS 5


ModuleBackground::ModuleBackground()
{

	//background lvl1 last resort
	bgRect.x = 0;
	bgRect.y = 0;
	bgRect.w = 803;
	bgRect.h = 160;

	//midground lvl1 last resort
	mgRect.x = 0;
	mgRect.y = 0;
	mgRect.w = 1303;
	mgRect.h = 160;

	//foreground lvl1 last resort
	fgRect.x = 0;
	fgRect.y = 0;
	fgRect.w = 4408;
	fgRect.h = 239;

	//streetlights source position rect animation cycle frames
	//Street lights pattern A
	//-----------------------------------------------------------------
	for (int i = 0; i < STREET_LIGHTS_A; ++i)
	{
		streetLightA[i].PushBack({ 0,0,48,65 });
		streetLightA[i].PushBack({ 49,0,48,65 });
		streetLightA[i].PushBack({ 98,0, 48,65 });
		streetLightA[i].PushBack({ 147,0,48,65 });
		streetLightA[i].PushBack({ 196,0,48,65 });
		streetLightA[i].PushBack({ 147,0,48,65 });
		streetLightA[i].PushBack({ 98,0,48,65 });
		streetLightA[i].PushBack({ 49,0,48,65 });
		streetLightA[i].speed = 0.143f; //0.16f
	}

	for (int i = 0; i < STREET_LIGHTS_B; ++i)
	{
		streetLightB[i].PushBack({ 196,0,48,65 });
		streetLightB[i].PushBack({ 147,0,48,65 });
		streetLightB[i].PushBack({ 98,0,48,65 });
		streetLightB[i].PushBack({ 49,0,48,65 });
		streetLightB[i].PushBack({ 0,0,48,65 });
		streetLightB[i].PushBack({ 49,0,48,65 });
		streetLightB[i].PushBack({ 98,0,48,65 });
		streetLightB[i].PushBack({ 147,0,48,65 });
		streetLightB[i].speed = 0.143f;
	}
	//------------------------------------------------------------------
	//Street lights Front pattern A
	for (int i = 0; i < STREET_LIGHTS_FRONT_A; ++i)
	{
		streetLightsFrontA[i].PushBack({ 0,66,61, 20 }); 
		streetLightsFrontA[i].PushBack({ 62 ,66 , 61,20 });
		streetLightsFrontA[i].PushBack({ 124 ,66,61,20 });
		streetLightsFrontA[i].PushBack({ 186, 66, 61,20 });
		streetLightsFrontA[i].PushBack({ 0,87,66,20 });
		streetLightsFrontA[i].PushBack({ 186, 66, 61,20 });
		streetLightsFrontA[i].PushBack({ 124 ,66,61,20 });
		streetLightsFrontA[i].PushBack({ 62 ,66 , 61,20 });
		streetLightsFrontA[i].speed = 0.143f;
	}
	//Street lights Front pattern B
	for (int i = 0; i < STREET_LIGHTS_FRONT_B; ++i)
	{
		streetLightsFrontB[i].PushBack({ 0,87,66,20 });
		streetLightsFrontB[i].PushBack({ 186, 66, 61,20 });
		streetLightsFrontB[i].PushBack({ 124 ,66,61,20 });
		streetLightsFrontB[i].PushBack({ 62 ,66 , 61,20 });
		streetLightsFrontB[i].PushBack({ 0,66,61,20 });
		streetLightsFrontB[i].PushBack({ 62 ,66 , 61,20 });
		streetLightsFrontB[i].PushBack({ 124 ,66,61,20 });
		streetLightsFrontB[i].PushBack({ 186, 66, 61,20 });
		streetLightsFrontB[i].speed = 0.143f;
	}
	//tunnel lights
	for (int i = 0; i < TUNNEL_LIGHTS; ++i)
	{
		tunnelLights[i].PushBack({ 1,1,116,167 });
		tunnelLights[i].PushBack({ 118,1,116,167 });
		tunnelLights[i].PushBack({ 235,1,116,167 });
		tunnelLights[i].PushBack({ 352,1,116,167 });
		
		tunnelLights[i].PushBack({ 1,169,116,167 });
		tunnelLights[i].PushBack({ 118,169,116,167 });
		tunnelLights[i].PushBack({ 235,169,116,167 });
		tunnelLights[i].PushBack({ 352,169,116,167 });

		tunnelLights[i].speed = 0.143f;
	}

	//background light patterns----------------------------------
	//building 1
	backgroundLights[0].PushBack({ 1,1,89,78 });
	backgroundLights[0].PushBack({ 91,1,89,78 });
	backgroundLights[0].PushBack({ 181,1,89,78 });
	backgroundLights[0].PushBack({ 271,1,89,78 });
	backgroundLights[0].PushBack({ 361,1,89,78 });
	backgroundLights[0].PushBack({ 1,80,89,78 });
	backgroundLights[0].PushBack({ 91,80,89,78 });
	backgroundLights[0].PushBack({ 181,80,89,78 });
	backgroundLights[0].speed = 0.143f;
	//building 1
	backgroundLights[1].PushBack({ 271,80,12,16 });
	backgroundLights[1].PushBack({ 284,80,12,16 });
	backgroundLights[1].PushBack({ 297,80,12,16 });
	backgroundLights[1].PushBack({ 310,80,12,16 });
	backgroundLights[1].PushBack({ 323,80,12,16 });
	backgroundLights[1].PushBack({ 336,80,12,16 });
	backgroundLights[1].PushBack({ 349,80,12,16 });
	backgroundLights[1].PushBack({ 362,80,12,16 });
	backgroundLights[1].speed = 0.143f;
	//building 1
	backgroundLights[2].PushBack({ 1,161,64,75 });
	backgroundLights[2].PushBack({ 66,161,64,75 });
	backgroundLights[2].PushBack({ 131,161,64,75 });
	backgroundLights[2].PushBack({ 196,161,64,75 });
	backgroundLights[2].PushBack({ 261,161,64,75 });
	backgroundLights[2].PushBack({ 326,161,64,75 });
	backgroundLights[2].PushBack({ 391,161,64,75 });
	backgroundLights[2].PushBack({ 1,239,64,75 });
	backgroundLights[2].speed = 0.143f;
	//building 2 - (texture 1)
	backgroundLights[3].PushBack({ 1,585,31,58 });
	backgroundLights[3].PushBack({ 33,585,31,58 });
	backgroundLights[3].PushBack({ 65,585,31,58 });
	backgroundLights[3].PushBack({ 97,585,31,58 });
	backgroundLights[3].PushBack({ 129,585,31,58 });
	backgroundLights[3].PushBack({ 161,585,31,58 });
	backgroundLights[3].PushBack({ 193,585,31,58 });
	backgroundLights[3].PushBack({ 225,585,31,58 });
	backgroundLights[3].speed = 0.143f;
	//building2 - (texture 2)
	backgroundLights[4].PushBack({ 1,644,47,51, });
	backgroundLights[4].PushBack({ 49,644,47,51 }); 
	backgroundLights[4].PushBack({ 97,644,47,51 });
	backgroundLights[4].PushBack({ 145,644,47,51 });
	backgroundLights[4].PushBack({ 193,644,47,51 });
	backgroundLights[4].PushBack({ 241,644,47,51 });
	backgroundLights[4].PushBack({ 289,644,47,51 });
	backgroundLights[4].PushBack({ 337,644,47,51 });
	backgroundLights[4].speed = 0.143f;

	//building 3
	backgroundLights[5].PushBack({ 1,315,167,89 });
	backgroundLights[5].PushBack({ 169,315,167,89 });
	backgroundLights[5].PushBack({ 337,315,167,89 });
	backgroundLights[5].PushBack({ 1,405,167,89 });
	backgroundLights[5].PushBack({ 169,405,167,89 });
	backgroundLights[5].PushBack({ 337,405,167,89 });
	backgroundLights[5].PushBack({ 1,495,167,89 });
	backgroundLights[5].PushBack({ 169,495,167,89 });
	backgroundLights[5].speed = 0.143f;

	//building lasers
	//blue lasers
	for (int i = 0; i < BLUE_LASERS; ++i)
	{
		buildingLasers[i].PushBack({ 0,0,38,88 });
		buildingLasers[i].PushBack({ 38,0,30,88 });
		buildingLasers[i].PushBack({ 68,0,-5,88 }); //-5
		buildingLasers[i].PushBack({ 73,0,27, 88 });
		buildingLasers[i].PushBack({ 100, 0, 32,79 });
		buildingLasers[i].PushBack({ 73,0,27, 88 });
		buildingLasers[i].PushBack({ 68,0,5,88 });
		buildingLasers[i].PushBack({ 38,0,30,88 });
		buildingLasers[i].speed = 0.143f;
	}

	//orange laser (differents speeds while move,simulated with frame repetition)
	//mid to right
	orangeLaser.PushBack({ 132,0,25,144 });
	orangeLaser.PushBack({ 132,0,0,0 }); //flash
	orangeLaser.PushBack({ 157,0,38,145 });
	orangeLaser.PushBack({ 157,0,0,0 });
	orangeLaser.PushBack({ 195,0,52,145 });
	orangeLaser.PushBack({ 195,0,0,0 });
	orangeLaser.PushBack({ 247,0,65,144 });
	orangeLaser.PushBack({ 247,0,0,0 });
	orangeLaser.PushBack({ 247,0,65,144 });
	orangeLaser.PushBack({ 247,0,0,0 });
	orangeLaser.PushBack({ 312,0,81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 312,0,81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 312,0,81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 393,0,99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 393,0,99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 393,0,99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 0,145,121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 121,145,142,142 });
	orangeLaser.PushBack({ 121,145,0,0 });
	orangeLaser.PushBack({ 121,145,142,142 });
	orangeLaser.PushBack({ 121,145,0,0 });
	orangeLaser.PushBack({ 121,145,142,142 });
	orangeLaser.PushBack({ 121,145,0,0 });
	orangeLaser.PushBack({ 121,145,142,142 });
	orangeLaser.PushBack({ 121,145,0,0 });
	orangeLaser.PushBack({ 0,145,121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 393,0,99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 393,0,99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 393,0,99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 312,0,81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 312,0,81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 247,0,65,144 });
	orangeLaser.PushBack({ 247,0,0,0 });
	orangeLaser.PushBack({ 247,0,65,144 });
	orangeLaser.PushBack({ 247,0,0,0 });
	orangeLaser.PushBack({ 195,0,52,145 });
	orangeLaser.PushBack({ 195,0,0,0 });
	orangeLaser.PushBack({ 195,0,52,145 });
	orangeLaser.PushBack({ 195,0,0,0 });
	orangeLaser.PushBack({ 157,0,38,145 });
	orangeLaser.PushBack({ 157,0,0,0 }); 
	//mid to left - flipped
	orangeLaser.PushBack({ 132,0,-25,144 });
	orangeLaser.PushBack({ 132,0,0,0 }); //flash
	orangeLaser.PushBack({ 157,0,-38,145 });
	orangeLaser.PushBack({ 157,0,0,0 });
	orangeLaser.PushBack({ 195,0,-52,145 });
	orangeLaser.PushBack({ 195,0,0,0 });
	orangeLaser.PushBack({ 247,0,-65,144 });
	orangeLaser.PushBack({ 247,0,0,0 });
	orangeLaser.PushBack({ 247,0,-65,144 });
	orangeLaser.PushBack({ 247,0,0,0 });
	orangeLaser.PushBack({ 312,0,-81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 312,0,-81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 312,0,-81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 393,0,-99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 393,0,-99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 393,0,-99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 0,145,-121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,-121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,-121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 121,145,-142,142 });
	orangeLaser.PushBack({ 121,145,0,0 });
	orangeLaser.PushBack({ 121,145,-142,142 });
	orangeLaser.PushBack({ 121,145,0,0 });
	orangeLaser.PushBack({ 121,145,-142,142 });
	orangeLaser.PushBack({ 121,145,0,0 });
	orangeLaser.PushBack({ 121,145,-142,142 });
	orangeLaser.PushBack({ 121,145,0,0 });
	orangeLaser.PushBack({ 0,145,-121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,-121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,-121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 0,145,-121,144 });
	orangeLaser.PushBack({ 0,145,0,0 });
	orangeLaser.PushBack({ 393,0,-99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 393,0,-99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 393,0,-99,145 });
	orangeLaser.PushBack({ 393,0,0,0 });
	orangeLaser.PushBack({ 312,0,-81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 312,0,-81,145 });
	orangeLaser.PushBack({ 312,0,0,0 });
	orangeLaser.PushBack({ 247,0,-65,144 });
	orangeLaser.PushBack({ 247,0,0,0 });
	orangeLaser.PushBack({ 247,0,-65,144 });
	orangeLaser.PushBack({ 247,0,0,0 });
	orangeLaser.PushBack({ 195,0,-52,145 });
	orangeLaser.PushBack({ 195,0,0,0 });
	orangeLaser.PushBack({ 195,0,-52,145 });
	orangeLaser.PushBack({ 195,0,0,0 });
	orangeLaser.PushBack({ 157,0,-38,145 });
	orangeLaser.PushBack({ 157,0,0,0 });
	
	orangeLaser.speed = 1.0f;

	//midground lights rect1
	midgroundLights[0].PushBack({1,1,96,86});
	midgroundLights[0].PushBack({ 98,1,96,86 });
	midgroundLights[0].PushBack({ 195,1,96,86 });
	midgroundLights[0].PushBack({ 292,1,96,86 });
	midgroundLights[0].PushBack({ 389,1,96,86 });
	midgroundLights[0].PushBack({ 1,88,96,86 });
	midgroundLights[0].PushBack({ 1,1,96,86 });
	midgroundLights[0].PushBack({ 98,88,96,86 });
	midgroundLights[0].speed = 0.143f;

	//midground lights rect2
	midgroundLights[1].PushBack({ 195,114,37,61 });
	midgroundLights[1].PushBack({ 233,114,37,61 });
	midgroundLights[1].PushBack({ 271,114,37,61 });
	midgroundLights[1].PushBack({ 309,114,37,61 });
	midgroundLights[1].PushBack({ 347,114,37,61 });
	midgroundLights[1].PushBack({ 385, 114,37,61 });
	midgroundLights[1].PushBack({ 195,114,37,61 });
	midgroundLights[1].PushBack({ 423,114,37,61 });
	midgroundLights[1].speed = 0.143f;

	//midground lights rect3
	midgroundLights[2].PushBack({ 1,175, 108,47 });
	midgroundLights[2].PushBack({ 110,175,108,47 });
	midgroundLights[2].PushBack({ 219,175,108,47 });
	midgroundLights[2].PushBack({ 328,175,108,47 });
	midgroundLights[2].PushBack({ 1,223,108,47 });
	midgroundLights[2].PushBack({ 110, 223,108,47 });
	midgroundLights[2].PushBack({ 1,175, 108,47 });
	midgroundLights[2].PushBack({ 219,223,108,47 });
	midgroundLights[2].speed = 0.143f;

	//midground lights rect4
	midgroundLights[3].PushBack({ 1,271,15,12 });
	midgroundLights[3].PushBack({ 17,271,15,12 });
	midgroundLights[3].PushBack({ 33,271,15,12 });
	midgroundLights[3].PushBack({ 49,271,15,12 });
	midgroundLights[3].PushBack({ 65,271,15,12 });
	midgroundLights[3].PushBack({ 81,271,15,12 });
	midgroundLights[3].PushBack({ 1,271,15,12 });
	midgroundLights[3].PushBack({ 97,271,15,12 });
	midgroundLights[3].speed = 0.143f;

	//midground lights rect5
	midgroundLights[4].PushBack({ 1,284,48,93 });
	midgroundLights[4].PushBack({ 50,284,48,93 });
	midgroundLights[4].PushBack({ 99,284,48,93 });
	midgroundLights[4].PushBack({ 148,284,48,93 });
	midgroundLights[4].PushBack({ 197,284,48,93 });
	midgroundLights[4].PushBack({ 246,284,48,93 });
	midgroundLights[4].PushBack({ 1,284,48,93 });
	midgroundLights[4].PushBack({ 295,284,48,93 });
	midgroundLights[4].speed = 0.143f;

	//midground lights rect6
	midgroundLights[5].PushBack({ 1,378,61,77 });
	midgroundLights[5].PushBack({ 63,378,61,77 });
	midgroundLights[5].PushBack({ 125,378,61,77 });
	midgroundLights[5].PushBack({ 187,378,61,77 });
	midgroundLights[5].PushBack({ 249,378,61,77 });
	midgroundLights[5].PushBack({ 311,378,61,77 });
	midgroundLights[5].PushBack({ 1,378,61,77 });
	midgroundLights[5].PushBack({ 373,378,61,77 });
	midgroundLights[5].speed = 0.143f;

}

ModuleBackground::~ModuleBackground()
{}

bool ModuleBackground::Init()
{

	cameraSpeed = 0.5f * SCREEN_SIZE;

	bgMovY.maxLoops = 12; //13 is to go to mid pos
	bgMovY.currentLoops = 1;

	updatePos = true;
	bgMovY.mg_y = 32; //midground y coordinate value = maxPixelOnTexture(mg) + spawnPointFirstBuildingOnGame

	//speeds for up and down moves
	bgMovY.speedMg = 0.23f;// 0.18
	bgMovY.speedfg = 0.5f;//0.41

	bgMovY.fgTemp = 0; //defines correct temp values foreground y (stores the floating increment to further cast int)
	bgMovY.mgTemp = bgMovY.mg_y;//defines correct temp values midground y

	bgMovY.fgTargetDown = 16; //target position of foreground texture max/up y value
	bgMovY.fgTargetUp = -15;
	bgMovY.fgMidPosition = 0;

	bgMovY.mgTargetDown = 40;
	bgMovY.mgTargetUp = 25;
	bgMovY.mgMidPosition = 32;

	bgMovY.distanceWaitToMov = 91 * SCREEN_SIZE; //distance between activate movements

	scrollX = true; //activates x scroll

	return true;
}

// Load assets
bool ModuleBackground::Start()
{

	LOG("Loading background assets");
	bool ret = true;

	////lvl1 background textures
	bg = App->textures->Load("assets/lvl1_bg.png");
	mg = App->textures->Load("assets/lvl1_mg.png");
	fg = App->textures->Load("assets/lvl1_fg.png");
	boss = App->textures->Load("assets/lvl1_boss.png");
	roadLights = App->textures->Load("assets/lvl1_streetLightsAndSpots.png");
	tunelLights = App->textures->Load("assets/tunnelLights.png");
	bgLights = App->textures->Load("assets/bg_lights.png");
	midgroundLightsTexture = App->textures->Load("assets/midgroundLights.png");
	buildingLasersTexture = App->textures->Load("assets/lvl1_buildingLasers.png");

	return ret;

}

update_status ModuleBackground::PreUpdate()
{
	if (App->render->currentCameraPosX <= -4408 * SCREEN_SIZE)
	{
		scrollX = false;
	}

	//check if scroll
	if (scrollX)
	{
		App->render->currentCameraPosX -= cameraSpeed;
		App->render->camera.x = App->render->currentCameraPosX;
	}

	//-------------------background up and down movement -------------------------------
	//distance activation checker
	if ((abs(App->render->camera.x) - abs(bgMovY.lastMovPosX)) >= (bgMovY.distanceWaitToMov) && updatePos &&
		bgMovY.currentLoops <= bgMovY.maxLoops)
	{
		bgMovY.lastMovPosX = App->render->currentCameraPosX;
		updatePos = false;
		bgMovY.move = true;
		//bgMovY.fgRendezvous = false; //new call, no rendezvous
		//bgMovY.mgRendezvous = false;

		++bgMovY.currentLoops;
		if (bgMovY.currentLoops >= bgMovY.maxLoops)
			bgMovY.lastLoop = true;
	}

	if (bgMovY.move) //movement logic
	{

		if (bgMovY.up)
		{
			bgMovY.down = false; //updates the next move bool
			bgMovY.moveUp = true; //activates the update camera position
			bgMovY.up = false;

		}
		if (bgMovY.down)
		{

			bgMovY.up = false;
			bgMovY.moveDown = true;
			bgMovY.down = false;
		}
	}

	//updates sprite position
	if (bgMovY.moveUp)
	{
		if (!bgMovY.fgRendezvous)
		{
			bgMovY.fgTemp -= bgMovY.speedfg;
			bgMovY.fg_y = (int)bgMovY.fgTemp;
		}
		if (bgMovY.fg_y <= bgMovY.fgTargetUp) //check if foreground reach the target position
		{
			bgMovY.fgRendezvous = true;
		}
		if (!bgMovY.mgRendezvous)
		{
			bgMovY.mgTemp -= bgMovY.speedMg; //midground speed
			bgMovY.mg_y = (int)bgMovY.mgTemp;
		}
		if (bgMovY.mg_y <= bgMovY.mgTargetUp)
		{
			bgMovY.mgRendezvous = true;
		}

		if (bgMovY.fgRendezvous && bgMovY.mgRendezvous)
		{
			bgMovY.lastMovPosX = App->render->camera.x; //updates the last x position
			updatePos = true;
			bgMovY.down = true; //and the next mov will be down
			bgMovY.move = false;
			bgMovY.moveUp = false;

			bgMovY.fgRendezvous = false; //prepare for next call, no rendezvous
			bgMovY.mgRendezvous = false;
		}
	}

	if (bgMovY.moveDown)
	{
		if (!bgMovY.fgRendezvous)
		{
			bgMovY.fgTemp += bgMovY.speedfg;
			bgMovY.fg_y = (int)bgMovY.fgTemp;
		}
		if (bgMovY.fg_y >= bgMovY.fgTargetDown) //check if foreground reach the target position
		{
			bgMovY.fgRendezvous = true;
		}
		if (!bgMovY.mgRendezvous)
		{
			bgMovY.mgTemp += bgMovY.speedMg; //midground speed
			bgMovY.mg_y = (int)bgMovY.mgTemp;
		}
		if (bgMovY.mg_y >= bgMovY.mgTargetDown)
		{
			bgMovY.mgRendezvous = true;
		}

		if (bgMovY.fgRendezvous && bgMovY.mgRendezvous) //when midground and foreground reaches its target...
		{
			bgMovY.lastMovPosX = App->render->camera.x; //updates the last x position
			updatePos = true;
			bgMovY.up = true; //and the next mov will be down
			bgMovY.move = false;
			bgMovY.moveDown = false;

			bgMovY.fgRendezvous = false; //cleanup before next call
			bgMovY.mgRendezvous = false;
		}

	}

	//last loop = before tunnel position
	if (bgMovY.lastLoop && (abs(App->render->camera.x) - abs(bgMovY.lastMovPosX)) >= (bgMovY.distanceWaitToMov))//!bgMovY.move) //lastLoop in this specific case, always occurrs when we go up
	{
		//foreground move
		if (!bgMovY.fgRendezvous)
		{
			bgMovY.fgTemp -= bgMovY.speedfg;
			bgMovY.fg_y = (int)bgMovY.fgTemp;
		}
		if (bgMovY.fg_y <= 0) // 0= midposition
		{
			bgMovY.fgRendezvous = true;
			bgMovY.lastLoop = false;
		}
		//midground move //ON THE ORIGINAL GAME, the midground is stuck before tunnel lastTravel (don't move)
		/*if (!bgMovY.mgRendezvous)
		{
		bgMovY.mgTemp -= bgMovY.speedMg;
		bgMovY.mg_y = (int)bgMovY.mgTemp;
		}
		if (bgMovY.mg_y <= 32) // 32 = midground start level y coord.
		{
		bgMovY.mgRendezvous = true;
		}*/

	}

	return UPDATE_CONTINUE;

	//----------------------------------------------------------------------------------------------------
}

// Update: draw background
update_status ModuleBackground::Update()
{
	
	// Draw everything --------------------------------------
	
	App->render->Blit(bg, 0, 0, &bgRect, 0.25f,1.0f); //bg1 last resort----------------------
	
	//background draw -------------------------------------------------------------------------

	//only repeats twice (on two occasions), we don't need to create and array of patterns etc...
	//the reason to multiply for 4 the screen size is because we pass a parameter speed 4times little
	//foreground pass a parallax speed of 1.0, background 0.25

	//background building 1 - 3 texture lights ------------------------------------------------

	if (App->render->currentCameraPosX <= -146 * SCREEN_SIZE * 4) //while the desired target is not seen
	{
		App->render->Blit(bgLights, 504, 0, &(backgroundLights[0].GetCurrentFrame()), 0.25f);
		App->render->Blit(bgLights, 634, 10, &(backgroundLights[1].GetCurrentFrame()), 0.25f);
		App->render->Blit(bgLights, 600, 50, &(backgroundLights[2].GetCurrentFrame()), 0.25f);
	}
	else
	{
		App->render->Blit(bgLights,  -8,  0, &(backgroundLights[0].GetCurrentFrame()), 0.25f);
		App->render->Blit(bgLights, 122, 10, &(backgroundLights[1].GetCurrentFrame()), 0.25f);
		App->render->Blit(bgLights,  88, 50, &(backgroundLights[2].GetCurrentFrame()), 0.25f);
	}

	//background building 2 - 2 textures
	//texture 1

	if (App->render->currentCameraPosX <= -300 * SCREEN_SIZE * 4)
	{
		App->render->Blit(bgLights, 682,0, &(backgroundLights[3].GetCurrentFrame()), 0.25f);
	}
	else
	{
		App->render->Blit(bgLights, 169, 0, &(backgroundLights[3].GetCurrentFrame()), 0.25f);
	}

	//texture 2

	App->render->Blit(bgLights, 240, 32, &(backgroundLights[4].GetCurrentFrame()), 0.25f);

	//only one (building "3") - 1 texture
	App->render->Blit(bgLights, 321, 0, &(backgroundLights[5].GetCurrentFrame()), 0.25f);

	//------------------------------------------------------------------------------------------

	//orange laser

	Animation* current_animation = &orangeLaser;
	SDL_Rect r = current_animation->GetCurrentFrame();
	App->render->Blit(buildingLasersTexture, 334 - pivotArrayOrangeLaser[(int)current_animation->current_frame] + 1, 0, &r, 0.25f);

	//boss

	if (App->render->currentCameraPosX <= -3824 * SCREEN_SIZE) //desired target pixels
		App->render->Blit(boss, 0, 0, NULL, 0.0f);

	//midground and foreground layer -----------------------------------------------------------
	//blue lasers
	for (int i = 0; i < BLUE_LASERS; ++i)
	{
		Animation* current_animation = &buildingLasers[i];
		SDL_Rect r = current_animation->GetCurrentFrame();
		App->render->Blit(buildingLasersTexture, positionArrayBlueLasersX[i] - pivotArrayBlueLasersPosition[(int)current_animation->current_frame] + 1, bgMovY.mg_y + positionArrayBlueLasersY[i] - r.h, &r, 0.5f);
	}

	App->render->Blit(mg, 0, bgMovY.mg_y, &mgRect, 0.5f);//0.45f); //midground lvl1 last resort -----

	//midground lights -------------------------------------- from top texture midgroundTexture + initial height
	if (App->render->currentCameraPosX <= -749 * SCREEN_SIZE * 2)
	{
		App->render->Blit(midgroundLightsTexture, 1064, bgMovY.mg_y + 28, &(midgroundLights[0].GetCurrentFrame()), 0.5f);

	}

	else if (App->render->currentCameraPosX <= -246 * SCREEN_SIZE * 2) //while the desired target is not seen
	{
		App->render->Blit(midgroundLightsTexture, 552, bgMovY.mg_y + 28, &(midgroundLights[0].GetCurrentFrame()), 0.5f);
		App->render->Blit(midgroundLightsTexture, 696, bgMovY.mg_y + 18, &(midgroundLights[1].GetCurrentFrame()), 0.5f);
	}
	else
	{
		App->render->Blit(midgroundLightsTexture, 40, bgMovY.mg_y + 28, &(midgroundLights[0].GetCurrentFrame()), 0.5f);
		App->render->Blit(midgroundLightsTexture, 184, bgMovY.mg_y + 18, &(midgroundLights[1].GetCurrentFrame()), 0.5f);
	}

	//-------------

	if (App->render->currentCameraPosX <= -440 * SCREEN_SIZE * 2) //while the desired target is not seen
	{
		App->render->Blit(midgroundLightsTexture, 746, bgMovY.mg_y + 97, &(midgroundLights[2].GetCurrentFrame()), 0.5f);
		App->render->Blit(midgroundLightsTexture, 841, bgMovY.mg_y + 2, &(midgroundLights[3].GetCurrentFrame()), 0.5f);
		App->render->Blit(midgroundLightsTexture, 904, bgMovY.mg_y + 50, &(midgroundLights[4].GetCurrentFrame()), 0.5f);
	}
	else
	{
		App->render->Blit(midgroundLightsTexture, 234, bgMovY.mg_y + 97, &(midgroundLights[2].GetCurrentFrame()), 0.5f);
		App->render->Blit(midgroundLightsTexture, 329, bgMovY.mg_y + 2, &(midgroundLights[3].GetCurrentFrame()), 0.5f);
		App->render->Blit(midgroundLightsTexture, 392, bgMovY.mg_y + 50, &(midgroundLights[4].GetCurrentFrame()), 0.5f);
	}

	//-------------
	
	if (App->render->currentCameraPosX <= -540 * SCREEN_SIZE * 2) //while the desired target is not seen
	{
 		App->render->Blit(midgroundLightsTexture, 983, bgMovY.mg_y + 36, &(midgroundLights[5].GetCurrentFrame()), 0.5f);
	}
	else
	{
		App->render->Blit(midgroundLightsTexture, 471, bgMovY.mg_y + 36, &(midgroundLights[5].GetCurrentFrame()), 0.5f);
	}

	//-----------------------------------------------------------------------------------------------------------
	
	App->render->Blit(fg, 0, bgMovY.fg_y, &fgRect, 1.0f); //foreground lvl1 last resort

	//tunnel lights draw ----------------------------------------------------------------------------
	//tunnel lights are speed dependent of foreground, only screen size multiplier (and fg speed parallax multiplier)
	if (App->render->currentCameraPosX <= -1740 * SCREEN_SIZE)
	{
		for (int i = 0; i < TUNNEL_LIGHTS; ++i)
		{
			App->render->Blit(tunelLights, positionArrayTunnel[i], bgMovY.fg_y, &(tunnelLights[i].GetCurrentFrame()), 1.0f);
		}
	}

	//back street lights draw------------------------------------------------------------------------

	for (int i = 0; i < STREET_LIGHTS_A; ++i)
	{
		App->render->Blit(roadLights, positionsArrayPatternA[i], bgMovY.fg_y + 136, &(streetLightA[i].GetCurrentFrame()),1.0f);
	}
	for (int i = 0; i < STREET_LIGHTS_B; ++i)
	{
		App->render->Blit(roadLights, positionsArrayPatternB[i], bgMovY.fg_y + 136, &(streetLightB[i].GetCurrentFrame()),1.0f);
	}

	//-----------------------------------------------------------------------------------------------
	//front street lights draw ----------------------------------------------------------------------
	//(217 is y from top screen to desired point ---
	//PATTERN A

	for (int i = 0; i < STREET_LIGHTS_FRONT_A; ++i)
	{
		App->render->Blit(roadLights, positionArrayFrontA[i], bgMovY.fg_y + 217, &(streetLightsFrontA[i].GetCurrentFrame()), 1.0f);
	}
	//PATTERN B
	for (int i = 0; i < STREET_LIGHTS_FRONT_B; ++i)
	{
		App->render->Blit(roadLights, positionArrayFrontB[i], bgMovY.fg_y + 217, &(streetLightsFrontB[i].GetCurrentFrame()), 1.0f);
	}

	//-----------------------------------------------------------------------------------------------
	
	//App->render->Blit(App->textures->textures[6], 0, bgMovY.fg_y, &fgRect, 1.0f); //testing purposes


	return UPDATE_CONTINUE;
}