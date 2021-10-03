/**
 * VUE-MASTER
 *
 * © STEREO BOY and KR155E
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef VUE_MASTER_STATE_H_
#define VUE_MASTER_STATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <GameState.h>
#include <AnimatedEntity.h>
#include <VIPManager.h>


//---------------------------------------------------------------------------------------------------------
// 												DEFINES
//---------------------------------------------------------------------------------------------------------

#define __NUMBER_OF_VIEWER_IMAGES	11


//---------------------------------------------------------------------------------------------------------
//											TYPE DEFINITIONS
//---------------------------------------------------------------------------------------------------------

typedef struct VueMasterImageSpec
{
	/// animated entity spec
	AnimatedEntitySpec animatedEntitySpec;

	/// stage color config
	ColorConfig colorConfig;

} VueMasterImageSpec;

typedef const VueMasterImageSpec VueMasterImageROMSpec;


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class VueMasterState : GameState
{
	AnimatedEntity imageEntity;
	bool showNumber;
	bool animationPlaying;
	bool currentIsVideo;
	int8 currentImage;

	static VueMasterState getInstance();
	override void enter(void* owner);
	override void exit(void* owner);
	override void processUserInput(UserInput userInput);
}


#endif
