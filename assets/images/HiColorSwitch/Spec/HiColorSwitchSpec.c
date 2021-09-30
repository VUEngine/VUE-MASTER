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

extern BYTE HiColorSwitchTiles[];
extern BYTE HiColorSwitchMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec HI_COLOR_SWITCH_HI_COLOR_ANIM =
{
	// number of frames of this animation function
	2,

	// frames to play in animation
	{0, 1},

	// number of cycles a frame of animation is displayed
	1,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"HiColor",
};
AnimationFunctionROMSpec HI_COLOR_SWITCH_4_COLOR_ANIM =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{2},

	// number of cycles a frame of animation is displayed
	1,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"4Color",
};

// an animation spec
AnimationDescriptionROMSpec HI_COLOR_SWITCH_ANIM =
{
	// animation functions
	{
		(AnimationFunction*)&HI_COLOR_SWITCH_HI_COLOR_ANIM,
		(AnimationFunction*)&HI_COLOR_SWITCH_4_COLOR_ANIM,
		NULL,
	}
};

CharSetROMSpec HI_COLOR_SWITCH_CH =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	5*6,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE,

	// char spec
	HiColorSwitchTiles,
};

TextureROMSpec HI_COLOR_SWITCH_TX =
{
	// charset spec
	(CharSetSpec*)&HI_COLOR_SWITCH_CH,

	// bgmap spec
	HiColorSwitchMap,

	// cols (max 64)
	5,

	// rows (max 64)
	6,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
	1,

	// palette number (0-3)
	1,

	// recyclable
	false,

	// vertical flip
	false,

	// horizontal flip
	false,
};

BgmapSpriteROMSpec HI_COLOR_SWITCH_SP =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&HI_COLOR_SWITCH_TX,

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

BgmapSpriteROMSpec* const HI_COLOR_SWITCH_SPRITES[] =
{
	&HI_COLOR_SWITCH_SP,
	NULL
};

AnimatedEntityROMSpec HI_COLOR_SWITCH_AE =
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
		(SpriteSpec**)HI_COLOR_SWITCH_SPRITES,

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
	(AnimationDescription*)&HI_COLOR_SWITCH_ANIM,

	// initial animation
	"HiColor",
};
