#pragma once

#include "GameScene.hpp"
#include "../ESGLib.h"

class clearScene : public CGameScene {
public:
	clearScene()
	{
//		ContentRootDirectory(_T("Content"));
	}

	virtual ~clearScene()
	{
		Finalize();

#ifdef _INC_SQUIRREL
		Squirrel.ReleaseAllScripts();
#endif
#ifdef _INC_NUI
		NUI.ReleaseAllKinects();
#endif
#ifdef _INC_LIVE2D
		Live2D.ReleaseAllModels();
#endif
#ifdef _INC_EFFEKSEER
		Effekseer.ReleaseAllEffects();
#endif
#ifdef _INC_DIRECT2D
		Direct2D.ReleaseAllResources();
#endif
		MediaManager.ReleaseAllMedia();

		SoundDevice.ReleaseAllMusics();
		SoundDevice.ReleaseAllSounds();

		GraphicsDevice.ReleaseAllRenderTargets();
		GraphicsDevice.ReleaseAllStateBlocks();
		GraphicsDevice.ReleaseAllFonts();
		GraphicsDevice.ReleaseAllSprites();
		GraphicsDevice.ReleaseAllAnimationModels();
		GraphicsDevice.ReleaseAllModels();
		GraphicsDevice.ReleaseAllVertexBuffers();
		GraphicsDevice.ReleaseAllEffects();
	}

	virtual bool Initialize();

	virtual int  Update();
	virtual void Draw();

private:
	void Finalize();

private:
	// 変数宣言
	SPRITE clear_;
	SPRITE a;
	SPRITE b;
	SPRITE c;
	float a_roll;
	float a_big;
	float b_big;
	float c_roll;
	int count;
	FONT txt;
	FONT bigtxt;
	SOUND big_se;
	SOUND small_se;
	SOUND tin_se;

	// 関数プロトタイプ

};
