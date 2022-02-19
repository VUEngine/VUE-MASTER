/**
 * VUE-MASTER
 *
 * © STEREO BOY and KR155E
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

extern uint32 HiColorSwitchTiles[];
extern uint32 HiColorSwitchTilesFrameOffsets[];
extern uint16 HiColorSwitchMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

AnimationFunctionROMSpec HiColorSwitchHiColorAnimation =
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
AnimationFunctionROMSpec HiColorSwitch4ColorAnimation =
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
AnimationDescriptionROMSpec HiColorSwitchAnimation =
{
	// animation functions
	{
		(AnimationFunction*)&HiColorSwitchHiColorAnimation,
		(AnimationFunction*)&HiColorSwitch4ColorAnimation,
		NULL,
	}
};

CharSetROMSpec HiColorSwitchCharset =
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

	// pointer to the frames offsets
	HiColorSwitchTilesFrameOffsets,
};

TextureROMSpec HiColorSwitchTexture =
{
	// charset spec
	(CharSetSpec*)&HiColorSwitchCharset,

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

BgmapSpriteROMSpec HiColorSwitchSprite =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture spec
		(TextureSpec*)&HiColorSwitchTexture,

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

BgmapSpriteROMSpec* const HiColorSwitchSprites[] =
{
	&HiColorSwitchSprite,
	NULL
};

AnimatedEntityROMSpec HiColorSwitchEntity =
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
		(SpriteSpec**)HiColorSwitchSprites,

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
	(AnimationDescription*)&HiColorSwitchAnimation,

	// initial animation
	"HiColor",
};
