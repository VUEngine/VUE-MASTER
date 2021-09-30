/**
 * VUE-MASTER
 *
 * (c) STEREO BOY and KR155E
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
// 												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <Game.h>
#include <AdjustmentScreenState.h>
#include <TitleScreenState.h>
#include <VueMasterState.h>


//---------------------------------------------------------------------------------------------------------
// 										  GAME'S MAIN LOOP
//---------------------------------------------------------------------------------------------------------

int main(void)
{
	// initialize plugins
	SplashScreenState::setNextState(
		SplashScreenState::safeCast(AdjustmentScreenState::getInstance()),
		GameState::safeCast(TitleScreenState::getInstance())
	);

	// start the game
	Game_start(Game::getInstance(), GameState::safeCast(AdjustmentScreenState::getInstance()));
	//Game_start(Game::getInstance(), GameState::safeCast(VueMasterState::getInstance()));

	// end program
	return true;
}
