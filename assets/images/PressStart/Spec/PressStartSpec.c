/**
 * VUE-MASTER
 *
 * (c) STEREO BOY and KR155E
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <AnimatedEntity.h>
#include <BgmapAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE PressStartTiles[];
extern BYTE PressStartMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// a function which defines the frames to play
AnimationFunctionROMSpec PRESS_START_DEFAULT_ANIM =
{
	// number of frames of this animation function
	2,

	// frames to play in animation
	{0, 2},

	// number of cycles a frame of animation is displayed
	32,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Default",
};

// an animation spec
AnimationDescriptionROMSpec PRESS_START_ANIM =
{
	// animation functions
	{
		(AnimationFunction*)&PRESS_START_DEFAULT_ANIM,
		NULL,
	}
};

CharSetROMSpec PRESS_START_CH =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	63,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE,

	// char spec
	PressStartTiles,
};

TextureROMSpec PRESS_START_TX =
{
	// charset spec
	(CharSetSpec*)&PRESS_START_CH,

	// bgmap spec
	PressStartMap,

	// cols (max 64)
	21,

	// rows (max 64)
	3,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
	1,

	// palette number (0-3)
	3,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

BgmapSpriteROMSpec PRESS_START_SP =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&PRESS_START_TX,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the spec (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMSpec* const PRESS_START_SPRITES[] =
{
	&PRESS_START_SP,
	NULL
};

AnimatedEntityROMSpec PRESS_START_AE =
{
	{
		// class allocator
		__TYPE(AnimatedEntity),

		// children
		NULL,

		// behaviors 
		NULL,

		// extra
		NULL,

		// sprites
		(SpriteSpec**)PRESS_START_SPRITES,

		// use z displacement in projection
		false,

		// collision shapes
		(ShapeSpec*)NULL,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		kTypeNone,

		// physical specification
		(PhysicalSpecification*)NULL,
	},

	// pointer to the animation spec for the item
	(AnimationDescription*)&PRESS_START_ANIM,

	// initial animation
	"Default",
};
