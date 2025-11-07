// Emacs style mode select   -*- C++ -*- 
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	Main program, simply calls D_DoomMain high level loop.
//
//-----------------------------------------------------------------------------

static const char
rcsid[] = "$Id: i_main.c,v 1.4 1997/02/03 22:45:10 b1 Exp $";


#include "SDL.h"

#include "doomdef.h"

#include "m_argv.h"
#include "d_main.h"

#include <debug.h>
#include <kernel.h>
#include <iopcontrol.h>
#include <loadfile.h>
#include <iopcontrol_special.h>
#include <sifrpc.h>
#include <sbv_patches.h>
#include <string.h>
#include <fileio.h>
#include <tamtypes.h>

int dealWithIOP() {
    FlushCache(0);
    FlushCache(2);
    SifInitRpc(0);
#ifdef IOPRP
	while (!SifIopRebootBuffer(ioprp_img, size_ioprp_img)) {};
#else
	while (!SifIopReset("", 0)) {};
#endif
    while (!SifIopSync()) {};
    SifInitRpc(0);
	sbv_patch_enable_lmb(); // fixes SifExecModuleBuffer
	sbv_patch_disable_prefix_check(); // castrates MODLOAD capability of checking if the IRX is loaded from a place that needs an KIRX
    //SifLoadStartModule("rom0:XSIO2MAN", 0, NULL, NULL);
    //SifLoadStartModule("rom0:XMCMAN", 0, NULL, NULL); 
    //SifLoadStartModule("rom0:XMCSERV", 0, NULL, NULL);
    //SifLoadStartModule("rom0:XPADMAN", 0, NULL, NULL);
    //SifLoadStartModule("rom0:DAEMON", 0, NULL, NULL);
    return 0;
}

int
main
( int		argc,
  char**	argv ) 
{ 
    myargc = argc; 
    myargv = argv; 
    dealWithIOP();
    D_DoomMain (); 

    return 0;
} 
