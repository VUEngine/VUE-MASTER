/**
 * VUE-MASTER
 *
 * © STEREO BOY and KR155E
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#ifndef TitleScreenStATE_H_
#define TitleScreenStATE_H_


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <GameState.h>


//---------------------------------------------------------------------------------------------------------
// 											CLASS'S DECLARATION
//---------------------------------------------------------------------------------------------------------

singleton class TitleScreenState : GameState
{
	AnimatedEntity hiColorEntity;
	AnimatedEntity logoEntity;
	bool hiColorMode;

	static TitleScreenState getInstance();
	override void enter(void* owner);
	override void processUserInput(UserInput userInput);
}


#endif
