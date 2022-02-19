/**
 * VUE-MASTER
 *
 * © STEREO BOY and KR155E
 *
 * For the full copyright and license information, please view the LICENSE file
 * that was distributed with this source code.
 */

#include <VueMasterState.h>
#if(__NUMBER_OF_VIEWER_IMAGES >= 30)


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <AnimatedEntity.h>
#include <BgmapSprite.h>
#include <VueMasterState.h>


//---------------------------------------------------------------------------------------------------------
// 												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern uint32 VueMasterImage30Tiles[];
extern uint16 VueMasterImage30LMap[];
extern uint16 VueMasterImage30RMap[];


//---------------------------------------------------------------------------------------------------------
// 												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

CharSetROMSpec VueMasterImage30Charset =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	2033,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__NOT_ANIMATED,

	// char spec
	VueMasterImage30Tiles,

	// pointer to the frames offsets
	NULL,
};

TextureROMSpec VueMasterImage30LeftTexture =
{
	// charset spec
	(CharSetSpec*)&VueMasterImage30Charset,

	// bgmap spec
	VueMasterImage30LMap,

	// cols (max 64)
	48,

	// rows (max 64)
	28,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE, _SHARED, _SHARED_COORDINATED, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	true,

	// vertical flip
	false,

	// horizontal flip
	false,
};

TextureROMSpec VueMasterImage30RightTexture =
{
	// charset spec
	(CharSetSpec*)&VueMasterImage30Charset,

	// bgmap spec
	VueMasterImage30RMap,

	// cols (max 64)
	48,

	// rows (max 64)
	28,

	// padding for affine/hbias transformations (cols, rows)
	{0, 0},

	// number of frames, depending on charset's allocation type:
	// __ANIMATED_SINGLE, _SHARED, _SHARED_COORDINATED, __NOT_ANIMATED: 1
	// __ANIMATED_MULTI: total number of frames
	1,

	// palette number (0-3)
	0,

	// recyclable
	true,

	// vertical flip
	false,

	// horizontal flip
	false,
};

BgmapSpriteROMSpec VueMasterImage30LeftSprite =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&VueMasterImage30LeftTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJ or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_LON,
};

BgmapSpriteROMSpec VueMasterImage30RightSprite =
{
	{
		// sprite's type
		__TYPE(BgmapSprite),

		// texture spec
		(TextureSpec*)&VueMasterImage30RightTexture,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJ or __WORLD_HBIAS)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_RON,
};

BgmapSpriteROMSpec* const VueMasterImage30Sprites[] =
{
	&VueMasterImage30LeftSprite,
	&VueMasterImage30RightSprite,
	NULL
};

VueMasterImageROMSpec VueMasterImage30Entity =
{
	// animated entity spec
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
			(SpriteSpec**)VueMasterImage30Sprites,

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
		(AnimationDescription*)NULL,

		// initial animation
		NULL
	},

	// colors config
	{
		// background color
		__COLOR_BLACK,

		// brightness
		// these values times the repeat values specified in the column table (max. 16) make the final
		// brightness values on the respective regions of the screen. maximum brightness is 128.
		{
			// dark red
			__BRIGHTNESS_DARK_RED,
			// medium red
			__BRIGHTNESS_MEDIUM_RED,
			// bright red
			__BRIGHTNESS_BRIGHT_RED,
		},

		// brightness repeat
		(BrightnessRepeatSpec*)NULL,
	},
};


#endif
