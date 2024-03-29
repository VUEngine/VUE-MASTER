/**
 * VUE-MASTER
 *
 * © STEREO BOY and KR155E
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <string.h>

#include <Game.h>
#include <Camera.h>
#include <Printing.h>
#include <VIPManager.h>
#include <I18n.h>
#include <VueMasterState.h>
#include <KeypadManager.h>
#include <MessageDispatcher.h>
#include <TitleScreenState.h>
#include <VueMasterImageSpec.h>


//---------------------------------------------------------------------------------------------------------
// 												DEFINES
//---------------------------------------------------------------------------------------------------------

#define __NUMBER_INDICATOR_X_POS				42
#define __NUMBER_INDICATOR_Y_POS				1

#define __HI_COLOR_INDICATOR_X_POS				46
#define __HI_COLOR_INDICATOR_Y_POS				26

#define __VIDEO_CONTROLS_INDICATOR_X_POS		1
#define __VIDEO_CONTROLS_INDICATOR_Y_POS		1


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec VueMasterSt;


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void VueMasterState::constructor()
{
	Base::constructor();

	// init members
	this->currentImage = 0;
	this->showNumber = false;
	this->imageEntity = NULL;
	this->animationPlaying = false;
	this->currentIsVideo = false;
}

void VueMasterState::destructor()
{
	// destroy base
	Base::destructor();
}

void VueMasterState::enter(void* owner __attribute__ ((unused)))
{
	// call base
	Base::enter(this, owner);

	// disable user input
	Game::disableKeypad(Game::getInstance());

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&VueMasterSt, NULL, true, false);

	// init members
	this->currentImage = 0;
	this->showNumber = false;

	// get image entity from stage
	this->imageEntity = AnimatedEntity::safeCast(Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"ImageEntity",
		false
	));

	// set initial image's color config
	VueMasterImageROMSpec* vueMasterImageSpec = VUE_MASTER_ENTITIES[this->currentImage];
	ColorConfig colorConfig = vueMasterImageSpec->colorConfig;
	VueMasterState::setColorConfig(this, colorConfig);

	// determine if initial image is video
	AnimatedEntityROMSpec* animatedEntitySpec = (AnimatedEntitySpec*)&(vueMasterImageSpec->animatedEntitySpec);
	this->currentIsVideo = (animatedEntitySpec->animationDescription != NULL);

	// set coordinates of printing layer
	Printing::setWorldCoordinates(Printing::getInstance(), 0, 0, -1, 0);

	// print minimal gui
	Printing::setPalette(Printing::getInstance(), 3);
	VueMasterState::printImageNumber(this);
	VueMasterState::printVideoControls(this);
	//VueMasterState::printHiColorIndicator(this);

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// start fade in effect
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		&colorConfig.brightness, // target brightness
		0, // delay between fading steps (in ms)
		(EventListener)VueMasterState::onFadeInComplete, // callback function
		Object::safeCast(this) // callback scope
	);
}

void VueMasterState::exit(void* owner)
{
	// call base
	Base::exit(this, owner);
}

void VueMasterState::printImageNumber()
{
#if(__NUMBER_OF_VIEWER_IMAGES < 10)
	if (this->showNumber)
	{
		Printing::text(Printing::getInstance(), "./.", __NUMBER_INDICATOR_X_POS + 2, __NUMBER_INDICATOR_Y_POS, "Number");
		Printing::int32(Printing::getInstance(), this->currentImage + 1, __NUMBER_INDICATOR_X_POS + 2, __NUMBER_INDICATOR_Y_POS, "Number");
		Printing::int32(Printing::getInstance(), __NUMBER_OF_VIEWER_IMAGES, __NUMBER_INDICATOR_X_POS + 4, __NUMBER_INDICATOR_Y_POS, "Number");
	}
	else
	{
		Printing::text(Printing::getInstance(), "...", __NUMBER_INDICATOR_X_POS + 2, __NUMBER_INDICATOR_Y_POS, "Number");
	}
#else
	if (this->showNumber)
	{
		Printing::text(Printing::getInstance(), "00/..", __NUMBER_INDICATOR_X_POS, __NUMBER_INDICATOR_Y_POS, "Number");
		Printing::int32(Printing::getInstance(), this->currentImage + 1, (this->currentImage>8 ? __NUMBER_INDICATOR_X_POS : __NUMBER_INDICATOR_X_POS + 1), __NUMBER_INDICATOR_Y_POS, "Number");
		Printing::int32(Printing::getInstance(), __NUMBER_OF_VIEWER_IMAGES, __NUMBER_INDICATOR_X_POS + 3, __NUMBER_INDICATOR_Y_POS, "Number");
	}
	else
	{
		Printing::text(Printing::getInstance(), ".....", __NUMBER_INDICATOR_X_POS, __NUMBER_INDICATOR_Y_POS, "Number");
	}
#endif
}

void VueMasterState::printVideoControls()
{
	if(this->currentIsVideo)
	{
		if (this->animationPlaying)
		{
			// print playing
			Printing::text(Printing::getInstance(), ";", __VIDEO_CONTROLS_INDICATOR_X_POS, __VIDEO_CONTROLS_INDICATOR_Y_POS, "Number");
		}
		else
		{
			// print paused
			Printing::text(Printing::getInstance(), ":", __VIDEO_CONTROLS_INDICATOR_X_POS, __VIDEO_CONTROLS_INDICATOR_Y_POS, "Number");
		}
	}
	else
	{
		// print whitespace
		Printing::text(Printing::getInstance(), ".", __VIDEO_CONTROLS_INDICATOR_X_POS, __VIDEO_CONTROLS_INDICATOR_Y_POS, "Number");
	}
}

void VueMasterState::printHiColorIndicator()
{
	Printing::text(Printing::getInstance(), "<", __HI_COLOR_INDICATOR_X_POS, __HI_COLOR_INDICATOR_Y_POS, "Number");
}

void VueMasterState::switchImage()
{
	// Prevent more user inputs before the image has been switched
	Game::disableKeypad(Game::getInstance());

	// hide screen
	Camera::startEffect(Camera::getInstance(), kHide);

	if (__NUMBER_OF_VIEWER_IMAGES <= this->currentImage)
	{
		this->currentImage = __NUMBER_OF_VIEWER_IMAGES;
	}

	if(0 > this->currentImage)
	{
		this->currentImage = 0;
	}

	// replace sprites
	Entity::releaseSprites(Entity::safeCast(this->imageEntity));
	VueMasterImageROMSpec* vueMasterImageSpec = VUE_MASTER_ENTITIES[this->currentImage];
	AnimatedEntityROMSpec* animatedEntitySpec = (AnimatedEntitySpec*)&(vueMasterImageSpec->animatedEntitySpec);
	Entity::addSprites(Entity::safeCast(this->imageEntity), animatedEntitySpec->entitySpec.spriteSpecs);

	this->currentIsVideo = (animatedEntitySpec->animationDescription != NULL);

	if(this->currentIsVideo)
	{
		// replace animation spec and play animation
		AnimatedEntity::setAnimationDescription(this->imageEntity, animatedEntitySpec->animationDescription);
		AnimatedEntity::playAnimation(this->imageEntity, animatedEntitySpec->initialAnimation);
		this->animationPlaying = true;
	}
	VueMasterState::printVideoControls(this);
	
	// set color config
	ColorConfig colorConfig = vueMasterImageSpec->colorConfig;
	VueMasterState::setColorConfig(this, colorConfig);

	// print image number
	VueMasterState::printImageNumber(this);

	// delayed fade in to hide graphical corruption that occurs during rewriting of chars and maps in memory
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		100, // initial delay (in ms)
		&colorConfig.brightness, // target brightness
		0, // delay between fading steps (in ms)
		(EventListener)VueMasterState::onSwitchImageFadeIn, // callback function
		Object::safeCast(this) // callback scope
	);
}

void VueMasterState::onSwitchImageFadeIn(Object eventFirer __attribute((unused)))
{
	Game::enableKeypad(Game::getInstance());
}

void VueMasterState::processUserInput(UserInput userInput)
{
	if(userInput.pressedKey)
	{
		if(K_LL & userInput.pressedKey || K_RL & userInput.pressedKey)
		{
			this->currentImage = (this->currentImage > 0)
				? this->currentImage - 1
				: (__NUMBER_OF_VIEWER_IMAGES - 1);
			VueMasterState::switchImage(this);
			return;
		}
		else if(K_LR & userInput.pressedKey || K_RR & userInput.pressedKey)
		{
			this->currentImage = (this->currentImage < (__NUMBER_OF_VIEWER_IMAGES - 1))
				? this->currentImage + 1
				: 0;
			VueMasterState::switchImage(this);
			return;
		}
		else if(K_B & userInput.pressedKey)
		{
			// Prevent more user inputs
			Game::disableKeypad(Game::getInstance());

			// start fade out effect
			Brightness brightness = (Brightness){0, 0, 0};
			Camera::startEffect(Camera::getInstance(),
				kFadeTo, // effect type
				0, // initial delay (in ms)
				&brightness, // target brightness
				0, // delay between fading steps (in ms)
				(void (*)(Object, Object))VueMasterState::onFadeOutComplete, // callback function
				Object::safeCast(this) // callback scope
			);
			return;
		}
		else if(K_SEL & userInput.pressedKey)
		{
			this->showNumber = !this->showNumber;
			VueMasterState::printImageNumber(this);
		}
		else if(
			(userInput.pressedKey & K_LU) || ((userInput.holdKey & K_LU) && (userInput.holdKeyDuration > 12)) ||
			(userInput.pressedKey & K_RU) || ((userInput.holdKey & K_RU) && (userInput.holdKeyDuration > 12))
		)
		{
			// pause animation
			if(this->animationPlaying)
			{
				AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->imageEntity), true);
				//AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->arrowsEntity), "Visible");
				this->animationPlaying = !this->animationPlaying;
			}
			VueMasterState::printVideoControls(this);

			// show next frame
			AnimatedEntity::nextFrame(AnimatedEntity::safeCast(this->imageEntity));
		}
		else if(
			(userInput.pressedKey & K_LD) || ((userInput.holdKey & K_LD) && (userInput.holdKeyDuration > 12)) ||
			(userInput.pressedKey & K_RD) || ((userInput.holdKey & K_RD) && (userInput.holdKeyDuration > 12))
		)
		{
			// pause animation
			if(this->animationPlaying)
			{
				AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->imageEntity), true);
				//AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->arrowsEntity), "Visible");
				this->animationPlaying = !this->animationPlaying;
			}
			VueMasterState::printVideoControls(this);

			// show previous frame
			AnimatedEntity::previousFrame(AnimatedEntity::safeCast(this->imageEntity));
		}
		else if(userInput.pressedKey & K_STA)
		{
			// pause/resume animation
			AnimatedEntity::pauseAnimation(AnimatedEntity::safeCast(this->imageEntity), this->animationPlaying);
			this->animationPlaying = !this->animationPlaying;
			VueMasterState::printVideoControls(this);
			if(this->animationPlaying)
			{
				//AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->arrowsEntity), "Hidden");
			}
			else
			{
				//AnimatedEntity::playAnimation(AnimatedEntity::safeCast(this->arrowsEntity), "Visible");
			}
		}
	}
}

void VueMasterState::setColorConfig(ColorConfig colorConfig)
{
	// background color
	VIPManager::setBackgroundColor(VIPManager::getInstance(), colorConfig.backgroundColor);

	// brightness repeat
	BrightnessRepeatSpec* brightnessRepeat = colorConfig.brightnessRepeat;
	if(brightnessRepeat)
	{
		VIPManager::setupBrightnessRepeat(VIPManager::getInstance(), colorConfig.brightnessRepeat);
	}
}

// handle event
void VueMasterState::onFadeInComplete(Object eventFirer __attribute__ ((unused)))
{
	// enable user input
	Game::enableKeypad(Game::getInstance());
}

// handle event
void VueMasterState::onFadeOutComplete(Object eventFirer __attribute__ ((unused)))
{
	Game::changeState(Game::getInstance(), GameState::safeCast(TitleScreenState::getInstance()));
}
