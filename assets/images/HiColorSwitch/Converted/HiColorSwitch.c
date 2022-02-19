//---------------------------------------------------------------------------------------------------------
//
//  HiColorSwitch
//  • 40×144 pixels
//  • 90 tiles, unreduced, not compressed
//  • 5×18 map, not compressed
//  • 3 animation frames, 5×6, spritesheet
//  Size: 1444 + 180 = 1624
//
//---------------------------------------------------------------------------------------------------------

const uint32 HiColorSwitchTiles[361] __attribute__((aligned(4))) =
{
    0x00000000,0xAAACFFF0,0xAAABAAAB,0xAAABAAAB,0xAAABAAAB,0xAAAAFFFF,0xAAAAAAAA,0xAAAAAAAA,
    0x9AAA6AAA,0xAAAAFFFF,0xA9DAAA6A,0x9FFDA7F6,0xDFFD7FFF,0xAAAAFFFF,0xAAAAAAAA,0xAAAAAAAA,
    0xAAA9AAAA,0x3AAA0FFF,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,0xAAABAAAB,0xAAABAAAB,0xAAABAAAB,
    0x5AAB6AAB,0xA9AAA6AA,0xA91AAA6A,0x9001A406,0x10014000,0xFDDAF7F6,0xFD9AFF6A,0xDAA9F6A6,
    0x9AA96AAA,0xAA9FAAA7,0xA9DFAA7F,0x9FFDA7F7,0xDFFD7FFF,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,
    0xEAA9EAAA,0x55AB56AB,0x55AB556B,0x5AAB56AB,0xAAAB6AAB,0x01150405,0x01950055,0x1AA906A5,
    0xAAAA6AAA,0xA990A6A4,0xA990AA40,0x9AA9A6A4,0xAAAA6AAA,0xFDDAF7F6,0xFD9AFF6A,0xDAA9F6A6,
    0xAAAA6AAA,0xEA9FEAA7,0xEA9FEA7F,0xEAA9EAA7,0xEAAAEAAA,0xAAABAAAB,0xFBEBFBEB,0xFBEBFFEB,
    0xAAABFBEB,0xAAAAAAAA,0xEFAAFEBE,0xEFBEAFBE,0xAAAAFEBE,0xAAAAAAAA,0xAFEBAAAA,0xBEFBBEFA,
    0xAAAAAFEA,0xAAAAAAAA,0xFEAFAAAF,0xEFAFEFAF,0xAAAAFEBE,0xEAAAEAAA,0xEBEAEAAA,0xEAFBEAFB,
    0xEAAAEAFA,0xEAABEAAB,0xEAABEAAB,0xAAABEAAB,0xFFFFAAAB,0xAFEFAFAB,0xEFBBEFFF,0xAAAAAFAB,
    0xFFFFAAAA,0xFABFAAAA,0xBEFBBEFB,0xAAAAFABF,0xFFFFAAAA,0xBFAFAAAF,0xBFEFFBEF,0xAAAAFFAF,
    0xFFFFAAAA,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,0xFFFFEAAA,0xBFFFFFFF,0xABFFAFFF,0xBFFFAFFF,
    0xFFF0FFFC,0x7FFFFFFF,0x5FFF5FFF,0x7FFF5FFF,0xFFFFFFFF,0xFFF5FFFF,0x75D755D7,0x75F575D7,
    0xFFFFFFFF,0xFFFFFFFF,0xFFFDFFFF,0xFFFDFFFD,0xFFFFFFFF,0xFFFEFFFF,0xFFEAFFFA,0xFFFEFFFA,
    0x0FFF3FFF,0xAAACFFF0,0xAAABAAAB,0xAAABAAAB,0xAAABAAAB,0xAAAAFFFF,0xAAAAAAAA,0xAAAAAAAA,
    0x5AAA6AAA,0xAAAAFFFF,0xA95AAA6A,0x9555A556,0x15555555,0xAAAAFFFF,0xAAAAAAAA,0xAAAAAAAA,
    0xAAA9AAAA,0x3AAA0FFF,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,0xAAABAAAB,0xAAABAAAB,0xAAABAAAB,
    0x5AAB6AAB,0x55AA56AA,0x555A556A,0x55555556,0x15555555,0x01550555,0x01150055,0x10010405,
    0x90014000,0xAA90AAA4,0xA990AA40,0x9AA9A6A4,0xDAA96AAA,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,
    0xEAA9EAAA,0x55AB56AB,0x55AB556B,0x5AAB56AB,0xAAAB6AAB,0x01550555,0x01950055,0x1AA906A5,
    0xAAAA6AAA,0xA910A404,0xA990AA40,0x9AA9A6A4,0xAAAA6AAA,0xFD9AF6A6,0xFD9AFF6A,0xDAA9F6A6,
    0xAAAA6AAA,0xEA9FEAA7,0xEA9FEA7F,0xEAA9EAA7,0xEAAAEAAA,0xAAABAAAB,0xFBEBFBEB,0xFBEBFFEB,
    0xAAABFBEB,0xAAAAAAAA,0xEFAAFEBE,0xEFBEAFBE,0xAAAAFEBE,0xAAAAAAAA,0xAFEBAAAA,0xBEFBBEFA,
    0xAAAAAFEA,0xAAAAAAAA,0xFEAFAAAF,0xEFAFEFAF,0xAAAAFEBE,0xEAAAEAAA,0xEBEAEAAA,0xEAFBEAFB,
    0xEAAAEAFA,0xEAABEAAB,0xEAABEAAB,0xAAABEAAB,0xFFFFAAAB,0xAFEFAFAB,0xEFBBEFFF,0xAAAAAFAB,
    0xFFFFAAAA,0xFABFAAAA,0xBEFBBEFB,0xAAAAFABF,0xFFFFAAAA,0xBFAFAAAF,0xBFEFFBEF,0xAAAAFFAF,
    0xFFFFAAAA,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,0xFFFFEAAA,0xBFFFFFFF,0xABFFAFFF,0xBFFFAFFF,
    0xFFF0FFFC,0x7FFFFFFF,0x5FFF5FFF,0x7FFF5FFF,0xFFFFFFFF,0xFFF5FFFF,0x75D755D7,0x75F575D7,
    0xFFFFFFFF,0xFFFFFFFF,0xFFFDFFFF,0xFFFDFFFD,0xFFFFFFFF,0xFFFEFFFF,0xFFEAFFFA,0xFFFEFFFA,
    0x0FFF3FFF,0xAAACFFF0,0xAAABAAAB,0xAAABAAAB,0xAAABAAAB,0xAAAAFFFF,0xAAAAAAAA,0xAAAAAAAA,
    0x9AAA6AAA,0xAAAAFFFF,0xA9DAAA6A,0x9FFDA7F6,0xDFFD7FFF,0xAAAAFFFF,0xAAAAAAAA,0xAAAAAAAA,
    0xAAA9AAAA,0x3AAA0FFF,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,0xAAABAAAB,0xAAABAAAB,0xAAABAAAB,
    0x5AAB6AAB,0xA9AAA6AA,0xA91AAA6A,0x9001A406,0x10014000,0xFDDAF7F6,0xFD9AFF6A,0xDAA9F6A6,
    0x9AA96AAA,0xAA9FAAA7,0xA9DFAA7F,0x9FFDA7F7,0xDFFD7FFF,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,
    0xEAA9EAAA,0x55AB56AB,0x55AB556B,0x5AAB56AB,0xAAAB6AAB,0x01150405,0x01950055,0x1AA906A5,
    0xAAAA6AAA,0xA990A6A4,0xA990AA40,0x9AA9A6A4,0xAAAA6AAA,0xFDDAF7F6,0xFD9AFF6A,0xDAA9F6A6,
    0xAAAA6AAA,0xEA9FEAA7,0xEA9FEA7F,0xEAA9EAA7,0xEAAAEAAA,0xAAABAAAB,0xFBEBFBEB,0xFBEBFFEB,
    0xAAABFBEB,0xAAAAAAAA,0xEFAAFEBE,0xEFBEAFBE,0xAAAAFEBE,0xAAAAAAAA,0xAFEBAAAA,0xBEFBBEFA,
    0xAAAAAFEA,0xAAAAAAAA,0xFEAFAAAF,0xEFAFEFAF,0xAAAAFEBE,0xEAAAEAAA,0xEBEAEAAA,0xEAFBEAFB,
    0xEAAAEAFA,0xEAABEAAB,0xEAABEAAB,0xAAABEAAB,0xFFFFAAAB,0xAFEFAFAB,0xEFBBEFFF,0xAAAAAFAB,
    0xFFFFAAAA,0xFABFAAAA,0xBEFBBEFB,0xAAAAFABF,0xFFFFAAAA,0xBFAFAAAF,0xBFEFFBEF,0xAAAAFFAF,
    0xFFFFAAAA,0xEAAAEAAA,0xEAAAEAAA,0xEAAAEAAA,0xFFFFEAAA,0xBFFFFFFF,0xABFFAFFF,0xBFFFAFFF,
    0xFFF0FFFC,0x5FFFFFFF,0xD7FFD7FF,0x5FFFD7FF,0xFFFFFFFF,0xF5FDFFFF,0x75757D75,0x7D7D7D75,
    0xFFFFFFFF,0xFFF5FFFF,0xFFF5FFFD,0xFFFDFFFD,0xFFFFFFFF,0xFFFEFFFF,0xFFEAFFFA,0xFFFEFFFA,
    0x0FFF3FFF,
};

const uint16 HiColorSwitchMap[90] __attribute__((aligned(4))) =
{
    0x0000,0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,
    0x0008,0x0009,0x000A,0x000B,0x000C,0x000D,0x000E,0x000F,
    0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,
    0x0018,0x0019,0x001A,0x001B,0x001C,0x001D,0x001E,0x001F,
    0x0020,0x0021,0x0022,0x0023,0x0024,0x0025,0x0026,0x0027,
    0x0028,0x0029,0x002A,0x002B,0x002C,0x002D,0x002E,0x002F,
    0x0030,0x0031,0x0032,0x0033,0x0034,0x0035,0x0036,0x0037,
    0x0038,0x0039,0x003A,0x003B,0x003C,0x003D,0x003E,0x003F,
    0x0040,0x0041,0x0042,0x0043,0x0044,0x0045,0x0046,0x0047,
    0x0048,0x0049,0x004A,0x004B,0x004C,0x004D,0x004E,0x004F,
    0x0050,0x0051,0x0052,0x0053,0x0054,0x0055,0x0056,0x0057,
    0x0058,0x0059,
};

const uint32 HiColorSwitchTilesFrameOffsets[3] __attribute__((aligned(4))) =
{
    0x00000001,0x00000079,0x000000F1,
};
