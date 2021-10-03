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
#include <Actor.h>
#include <MessageDispatcher.h>
#include <AnimatedEntity.h>
#include <I18n.h>
#include <Languages.h>
#include <TitleScreenState.h>
#include <VueMasterState.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern StageROMSpec TITLE_SCREEN_ST;


//---------------------------------------------------------------------------------------------------------
// 												CLASS'S METHODS
//---------------------------------------------------------------------------------------------------------

void TitleScreenState::constructor()
{
	Base::constructor();
}

void TitleScreenState::destructor()
{
	// destroy base
	Base::destructor();

	// init members
	this->hiColorMode = true;
	this->hiColorEntity = NULL;
	this->logoEntity = NULL;
}

void TitleScreenState::enter(void* owner __attribute__ ((unused)))
{
	// call base
	Base::enter(this, owner);

	// disable user input
	Game::disableKeypad(Game::getInstance());

	// register input events to be caught
	KeypadManager::registerInput(KeypadManager::getInstance(), __KEY_PRESSED | __KEY_RELEASED | __KEY_HOLD);

	// load stage
	GameState::loadStage(GameState::safeCast(this), (StageSpec*)&TITLE_SCREEN_ST, NULL, true, false);

	// get entities
	this->hiColorEntity = AnimatedEntity::safeCast(Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"HiColor",
		false
	));
	this->logoEntity = AnimatedEntity::safeCast(Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"Logo",
		false
	));

	// print reel title and credits
	const char* strReelTitle = I18n::getText(I18n::getInstance(), STR_REEL_TITLE);
	const char* strReelCredits = I18n::getText(I18n::getInstance(), STR_REEL_CREDITS);
	FontSize strReelTitleSize = Printing::getTextSize(Printing::getInstance(), strReelTitle, NULL);
	FontSize strReelCreditsSize = Printing::getTextSize(Printing::getInstance(), strReelCredits, NULL);
	Printing::setPalette(Printing::getInstance(), 0);
	Printing::text(
		Printing::getInstance(),
		strReelTitle,
		(__HALF_SCREEN_WIDTH_IN_CHARS) - (strReelTitleSize.x >> 1),
		12,
		NULL
	);
	Printing::setPalette(Printing::getInstance(), 3);
	Printing::text(
		Printing::getInstance(),
		strReelCredits,
		(__HALF_SCREEN_WIDTH_IN_CHARS) - (strReelCreditsSize.x >> 1),
		13 + strReelTitleSize.y,
		NULL
	);

	// move "press start" according to height of reel title and credits
	Container pressStartEntity = Container::getChildByName(
		Container::safeCast(Game::getStage(Game::getInstance())),
		"PrssStrt",
		false
	);
	Vector3D localPosition = {
		__PIXELS_TO_METERS(192),
		__PIXELS_TO_METERS(128 + ((strReelTitleSize.y  + strReelCreditsSize.y) << 3)),
		__PIXELS_TO_METERS(0),
	};
	Container::setLocalPosition(pressStartEntity, &localPosition);

	// start clocks to start animations
	GameState::startClocks(GameState::safeCast(this));

	// start fade in effect
	Camera::startEffect(Camera::getInstance(), kHide);
	Camera::startEffect(Camera::getInstance(),
		kFadeTo, // effect type
		0, // initial delay (in ms)
		NULL, // target brightness
		0, // delay between fading steps (in ms)
		(void (*)(Object, Object))TitleScreenState::onFadeInComplete, // callback function
		Object::safeCast(this) // callback scope
	);
}

void TitleScreenState::processUserInput(UserInput userInput)
{
	if((userInput.pressedKey & K_A) || (userInput.pressedKey & K_STA))
	{
		// disable user input
		Game::disableKeypad(Game::getInstance());

		// start fade out effect
		Brightness brightness = (Brightness){0, 0, 0};
		Camera::startEffect(Camera::getInstance(),
			kFadeTo, // effect type
			0, // initial delay (in ms)
			&brightness, // target brightness
			0, // delay between fading steps (in ms)
			(void (*)(Object, Object))TitleScreenState::onFadeOutComplete, // callback function
			Object::safeCast(this) // callback scope
		);
	}
	else if(userInput.pressedKey & (K_LL|K_RL|K_LR|K_RR))
	{
		this->hiColorMode = !this->hiColorMode;
		AnimatedEntity::playAnimation(this->hiColorEntity, this->hiColorMode ? "HiColor" : "4Color");
		AnimatedEntity::playAnimation(this->logoEntity, this->hiColorMode ? "HiColor" : "4Color");
	}
}

void TitleScreenState::onFadeInComplete(Object eventFirer __attribute__ ((unused)))
{
	// enable user input
	Game::enableKeypad(Game::getInstance());

}

void TitleScreenState::onFadeOutComplete(Object eventFirer __attribute__ ((unused)))
{
	Game::changeState(Game::getInstance(), GameState::safeCast(VueMasterState::getInstance()));
}
