/* VUEngine - Virtual Utopia Engine <http://vuengine.planetvb.com/>
 * A universal game engine for the Nintendo Virtual Boy
 *
 * Copyright (C) 2007, 2018 by Jorge Eremiev <jorgech3@gmail.com> and Christian Radke <chris@vr32.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 * LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


//---------------------------------------------------------------------------------------------------------
//												INCLUDES
//---------------------------------------------------------------------------------------------------------

#include <AnimatedEntity.h>
#include <BgmapAnimatedSprite.h>


//---------------------------------------------------------------------------------------------------------
//												DECLARATIONS
//---------------------------------------------------------------------------------------------------------

extern BYTE ViewtualBoyArrowsTiles[];
extern BYTE ViewtualBoyArrowsMap[];


//---------------------------------------------------------------------------------------------------------
//												DEFINITIONS
//---------------------------------------------------------------------------------------------------------

// a function which defines the frames to play
AnimationFunctionROMDef VIEWTUAL_BOY_ARROWS_HIDDEN_ANIM =
{
	// number of frames of this animation function
	1,

	// frames to play in animation
	{0},

	// number of cycles a frame of animation is displayed
	4,

	// whether to play it in loop or not
	false,

	// method to call on function completion
	NULL,

	// function's name
	"Hidden",
};

// a function which defines the frames to play
AnimationFunctionROMDef VIEWTUAL_BOY_ARROWS_VISIBLE_ANIM =
{
	// number of frames of this animation function
	2,

	// frames to play in animation
	{1, 2},

	// number of cycles a frame of animation is displayed
	16,

	// whether to play it in loop or not
	true,

	// method to call on function completion
	NULL,

	// function's name
	"Visible",
};

// an animation definition
AnimationDescriptionROMDef VIEWTUAL_BOY_ARROWS_ANIM =
{
	// animation functions
	{
		(AnimationFunction*)&VIEWTUAL_BOY_ARROWS_HIDDEN_ANIM,
		(AnimationFunction*)&VIEWTUAL_BOY_ARROWS_VISIBLE_ANIM,
		NULL,
	}
};

CharSetROMDef VIEWTUAL_BOY_ARROWS_CH =
{
	// number of chars, depending on allocation type:
	// __ANIMATED_SINGLE*, __ANIMATED_SHARED*: number of chars of a single animation frame (cols * rows)
	// __ANIMATED_MULTI, __NOT_ANIMATED: sum of all chars
	38,

	// allocation type
	// (__ANIMATED_SINGLE, __ANIMATED_SINGLE_OPTIMIZED, __ANIMATED_SHARED, __ANIMATED_SHARED_COORDINATED, __ANIMATED_MULTI or __NOT_ANIMATED)
	__ANIMATED_SINGLE,

	// char definition
	ViewtualBoyArrowsTiles,
};

TextureROMDef VIEWTUAL_BOY_ARROWS_TX =
{
	// charset definition
	(CharSetDefinition*)&VIEWTUAL_BOY_ARROWS_CH,

	// bgmap definition
	ViewtualBoyArrowsMap,

	// cols (max 64)
	19,

	// rows (max 64)
	2,

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
};

BgmapSpriteROMDef VIEWTUAL_BOY_ARROWS_SP =
{
	{
		// sprite's type
		__TYPE(BgmapAnimatedSprite),

		// texture definition
		(TextureDefinition*)&VIEWTUAL_BOY_ARROWS_TX,

		// transparent (__TRANSPARENCY_NONE, __TRANSPARENCY_EVEN or __TRANSPARENCY_ODD)
		__TRANSPARENCY_NONE,

		// displacement
		{0, 0, 0, 0},
	},

	// bgmap mode (__WORLD_BGMAP, __WORLD_AFFINE, __WORLD_OBJECT or __WORLD_HBIAS)
	// make sure to use the proper corresponding sprite type throughout the definition (BgmapSprite or ObjectSprite)
	__WORLD_BGMAP,

	// pointer to affine/hbias manipulation function
	NULL,

	// display mode (__WORLD_ON, __WORLD_LON or __WORLD_RON)
	__WORLD_ON,
};

BgmapSpriteROMDef* const VIEWTUAL_BOY_ARROWS_SPRITES[] =
{
	&VIEWTUAL_BOY_ARROWS_SP,
	NULL
};

AnimatedEntityROMDef VIEWTUAL_BOY_ARROWS_AG =
{
	{
		// class allocator
		__TYPE(AnimatedEntity),

		// sprites
		(SpriteROMDef**)VIEWTUAL_BOY_ARROWS_SPRITES,

		// collision shapes
		(ShapeDefinition*)NULL,

		// size
		// if 0, width and height will be inferred from the first sprite's texture's size
		{0, 0, 0},

		// gameworld's character's type
		kNoType,

		// physical specification
		(PhysicalSpecification*)NULL,
	},

	// pointer to the animation definition for the item
	(AnimationDescription*)&VIEWTUAL_BOY_ARROWS_ANIM,

	// initial animation
	"Hidden",
};
